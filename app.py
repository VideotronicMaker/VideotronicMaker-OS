# =========================================================================
# VTM OS - Community Edition (MIT License)
# Copyright (C) 2025 Tishin Padilla. VTM OS All Rights Reserved.
# Core IP: VTM Personality Core & VTM-BioLink Protocol Client
# =========================================================================

import os
import time
import random
from flask import Flask, render_template, request, jsonify
import google.generativeai as genai
import psutil
import sys
# Set a conservative recursion limit to prevent stack exhaustion
sys.setrecursionlimit(1000)

# --- RESTORED AUTHENTICATION ---
# This allows Gemini to use the service_account.json as ADC
os.environ["GOOGLE_APPLICATION_CREDENTIALS"] = "service_account.json"
genai.configure(api_key=os.environ.get("GEMINI_API_KEY"))

app = Flask(__name__)

# --- PATH SETUP ---
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
STATIC_DIR = os.path.join(BASE_DIR, "static")

# --- INITIALIZATION ---
def load_system_instruction():
    try:
        with open(os.path.join(BASE_DIR, "system_message.txt"), "r") as f:
            return f.read()
    except FileNotFoundError:
        return "You are the VTM Personality Core. Do not repeat what I say. Answer my questions."

# Initialize Gemini
model = genai.GenerativeModel(
    model_name='gemini-2.0-flash',
    system_instruction=load_system_instruction()
)
chat_session = model.start_chat(history=[])

# --- SYSTEM TELEMETRY ---
def get_system_stats():
    try:
        cpu = psutil.cpu_percent(interval=None)
        ram = psutil.virtual_memory().percent
        temp = random.randint(98, 115) 
        return {"cpu": cpu, "ram": ram, "temp": temp}
    except:
        return {"cpu": 0, "ram": 0, "temp": 0}

# --- ROUTES ---

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/system_stats', methods=['GET'])
def system_stats():
    return jsonify(get_system_stats())

@app.route('/startup', methods=['POST'])
def startup():
    time.sleep(1)
    return jsonify({'status': 'ready', 'message': 'Systems Online.'})

@app.route('/music_list', methods=['GET'])
def get_music_list():
    try:
        music_dir = os.path.join(STATIC_DIR, "music")
        if not os.path.exists(music_dir): return jsonify([])
        files = [f for f in os.listdir(music_dir) if f.lower().endswith(('.mp3', '.wav'))]
        files.sort()
        return jsonify(files)
    except:
        return jsonify([])

@app.route('/process_text', methods=['POST'])
def process_text():
    try:
        user_text = request.json.get('message')
        response = chat_session.send_message(user_text)
        ai_text = response.text
        # Returning 'text' to match what your script.js expects
        return jsonify({'text': ai_text})
    except Exception as e:
        print(f"[VTM ERROR] {str(e)}")
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    print("\n[VTM-HOST] Access Interface: http://localhost:5001\n")
    app.run(host='0.0.0.0', port=5001, debug=True, use_reloader=False)
