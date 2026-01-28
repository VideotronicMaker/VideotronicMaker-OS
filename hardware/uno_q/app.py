# =========================================================================
# VTM OS™ COMMUNITY EDITION - UNO Q (SBC)
# Based on VTM OS Platform Proprietary Source
# Copyright (C) 2025 Tishin Padilla. VTM OS All Rights Reserved.
# =========================================================================

import os
import time
import threading
import subprocess
import random
import serial
import serial.tools.list_ports
from flask import Flask, render_template, request, jsonify
import google.generativeai as genai
import psutil
import sys

# Set a conservative recursion limit to prevent stack exhaustion

sys.setrecursionlimit(1000)

# --- CONFIGURATION ---
genai.configure(api_key=os.environ.get("GEMINI_API_KEY"))

app = Flask(__name__)

# --- PATH SETUP ---
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

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

# --- LAB DATA GLOBALS ---
last_lab_data = {"lux": 0, "rssi": 0, "snr": 0, "raw": "Searching..."}

# --- CONSOLIDATED SERIAL LISTENER (VTM-BioLink™) ---
def serial_listener():
    """Background thread to catch data from the Uno Q Internal Bridge."""
    global last_lab_data
    # Internal bridge for Uno Q Linux <-> STM32
    port = "/dev/ttyHS1"
    
    while True:
        try:
            ser = serial.Serial(port, 115200, timeout=1)
            print(f"[VTM-BIOLINK] Connected on {port}")
            while True:
                if ser.in_waiting > 0:
                    line = ser.readline().decode('utf-8', errors='ignore').strip()
                    # Keep your original LoRa data parsing logic
                    if line.startswith("+RCV"):
                        parts = line.split(',')
                        if len(parts) >= 5:
                            last_lab_data = {
                                "lux": int(parts[2]),
                                "rssi": int(parts[3]),
                                "snr": int(parts[4]),
                                "raw": line
                            }
                            print(f"[VTM-LAB DATA] {line}")
                    else:
                        last_lab_data["raw"] = line
        except Exception as e:
            print(f"[VTM-BIOLINK] Bridge Error: {e}. Retrying in 5s...")
            time.sleep(5)

# Start the hardware listener
threading.Thread(target=serial_listener, daemon=True).start()

# --- SYSTEM TELEMETRY ---
def get_system_stats():
    try:
        cpu = psutil.cpu_percent(interval=None)
        ram = psutil.virtual_memory().percent
        temp = random.randint(98, 115) 
        return {"cpu": cpu, "ram": ram, "temp": temp}
    except:
        return {"cpu": 0, "ram": 0, "temp": 0}

@app.route('/lab_telemetry')
def lab_telemetry():
    return jsonify(last_lab_data)

# --- ROUTES ---

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/system_stats', methods=['GET'])
def system_stats():
    return jsonify(get_system_stats())

@app.route('/startup', methods=['POST'])
def startup():
    # Community Edition: Ready signal without audio file generation
    return jsonify({'status': 'ready', 'audio_url': None})

@app.route('/process_text', methods=['POST'])
def process_text():
    try:
        user_text = request.json.get('message')
        response = chat_session.send_message(user_text)
        ai_text = response.text
        # Community Edition returns null for audio_url to skip playback
        return jsonify({'text': ai_text, 'audio_url': None})
    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    # --- VTM COMMUNITY BOOT SEQUENCE ---
    print("\n" * 2)
    print(" █▒▒▒▒▒▒▒▒▒ 10%  [LOADING COMMUNITY KERNEL]")
    time.sleep(0.2)
    print(" ████▒▒▒▒▒▒ 40%  [MOUNTING BIOLINK BRIDGE]")
    time.sleep(0.2)
    print(" ███████▒▒▒ 70%  [SECURING PERSONALITY CORE]")
    time.sleep(0.2)
    print(" ██████████ 100% [SYSTEM READY]")
    print("\n")
    print(" =========================================================")
    print("  V T M   O S   C O M M U N I T Y   |   U N O   Q   S B C")
    print(" =========================================================")
    print("  (C) 2026 VideotronicMaker. Community Edition.")
    print("  Bio-Mimetic Architecture: ACTIVE")
    print(" =========================================================\n")
    
    # use_reloader=False is safer for serial-connected hardware.
    app.run(host='0.0.0.0', port=5000, debug=False, use_reloader=False)
