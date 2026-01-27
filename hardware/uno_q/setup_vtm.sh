#!/bin/bash
echo "--- VTM OS™ COMMUNITY EDITION SETUP ---"
echo "Initializing Uno Q environment..."

# 1. Update and install system dependencies
sudo apt update && sudo apt install -y python3-pip python3-venv

# 2. Setup Virtual Environment
python3 -m venv venv
source venv/bin/activate

# 3. Install Python requirements
pip install -r requirements.txt

echo "---------------------------------------"
echo "SETUP COMPLETE."
echo "To launch: export GEMINI_API_KEY='your_key' && python3 app.py"
echo "---------------------------------------"
