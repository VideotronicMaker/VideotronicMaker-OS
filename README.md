<div align="center">
  <img src="vtm_avatar.webp" alt="VTM OS Logo" width="200" height="auto" />
  <h1>VTM OS™: Community Edition</h1>
  <p><b>Open-Core Bio-Mimetic AI Architecture for Arduino Uno Q</b></p>
  <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" alt="License" />
  <img src="https://img.shields.io/badge/Model-Open_Core-blue?style=for-the-badge" alt="Model" />
  <img src="https://img.shields.io/badge/Hardware-Arduino_Uno_Q-teal?style=for-the-badge" alt="Platform" />

  <br /><br />

  <p><i>"Learn with me as I learn."</i></p>
</div>

---

# VTM OS™ Platform

The **VTM OS™** is an open-core platform designed to bridge the gap between high-level cognitive processing and real-time physical control. This repository hosts the **Community Edition**, providing a foundational framework for makers and developers to implement bio-mimetic AI on microcontrollers like the **Arduino Uno Q**.

### 🎥 Watch the Demos
<div align="center">

[![Building an AI Desk Bot with Arduino Uno Q](https://ytcards.demolab.com/?id=WiXRPLrF5m0&title=Building+an+AI+Desk+Bot+with+Arduino+Uno+Q&lang=en&background_color=%230d1117&title_color=%23ffffff&stats_color=%23dedede&max_title_lines=1&width=250&border_radius=5)](https://www.youtube.com/watch?v=WiXRPLrF5m0)
[![Arduino UNO Q Robot Project: Dual-Brain Sync](https://ytcards.demolab.com/?id=xDm-rMR-oBs&title=Arduino+UNO+Q+Robot+Project%3A+Dual-Brain+Sync&lang=en&background_color=%230d1117&title_color=%23ffffff&stats_color=%23dedede&max_title_lines=1&width=250&border_radius=5)](https://www.youtube.com/watch?v=xDm-rMR-oBs)
[![LoRa Field Research Station with Arduino Uno Q](https://ytcards.demolab.com/?id=Xr02o3HJoto&title=LoRa+Field+Research+Station+with+Arduino+Uno+Q&lang=en&background_color=%230d1117&title_color=%23ffffff&stats_color=%23dedede&max_title_lines=1&width=250&border_radius=5)](https://www.youtube.com/watch?v=Xr02o3HJoto)

</div>

---

## 📖 Documentation & The Growth Guide
The VTM OS is more than just a repository; it's an evolving prototyping ecosystem. To understand the "Mind-Body-Link" architecture and start your own evolutionary build, visit our official documentation:

👉 **[Enter the VTM OS Wiki](https://github.com/VideotronicMaker/VideotronicMaker-OS/wiki)**

* **[Evolutionary Growth Guide](https://github.com/VideotronicMaker/VideotronicMaker-OS/wiki/Growth-Guide):** The 5-stage roadmap from a box of parts to an AI Hub.
* **[Technical Specs](https://github.com/VideotronicMaker/VideotronicMaker-OS/wiki/Technical-Specs):** Deep dive into the VTM-BioLink™ Protocol.
* **[Troubleshooting](https://github.com/VideotronicMaker/VideotronicMaker-OS/wiki/Troubleshooting):** Solving common connection and environment issues.

---

## 🧠 System Architecture: VTM Bio-Mimetic™

The architecture mimics a biological nervous system by decoupling high-level reasoning from real-time execution. 



### 1. The Host Platform ("The Mind")
* **VTM Personality Core™ (Community):** Basic local host management and LLM API bridging.
* **Function:** Handles cognition and "Thought Processing" to determine intent.

### 2. The BioLink Interface ("The Body")
* **VTM-BioLink Protocol™ (Community):** The open telemetry standard for translating AI intent into fluid, organic motion.
* **Target Hardware:** Optimized for the high-speed execution of the **Arduino Uno Q**.

---

## 🛠 Open-Core Licensing Model

VTM OS™ operates on an **Open-Core** model to support the maker community while maintaining professional-grade standards for industrial applications.

* **Community Edition (This Repo):** Licensed under **MIT**. This includes the core communication protocols and basic architecture for non-commercial use and community experimentation.
* **Professional/Industrial:** Advanced personality modules, secured telemetry, and **Proprietary Hardware Reference Designs** (including the **VTM Reference Chassis** with integrated modular storage systems) are available under a **Proprietary License**.



---

## 🚀 Getting Started

### 1. Environment Setup (macOS/Linux)
To ensure a clean installation, it is highly recommended to use a virtual environment.

```bash
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
```

### Windows (Command Prompt)
```cmd
python -m venv venv
venv\Scripts\activate
pip install -r requirements.txt
set GEMINI_API_KEY=your_actual_api_key_here
```

### Windows (PowerShell)
```powershell
python -m venv venv
.\venv\Scripts\Activate.ps1
pip install -r requirements.txt
$env:GEMINI_API_KEY="your_actual_api_key_here"
```

## 2. Configuration
Ensure your `service_account.json` is located in the root directory. This provides the necessary Application Default Credentials (ADC) for the Gemini API to function correctly.

### ⚙️ Google Cloud & API Configuration
The **VTM OS™** requires a Google Cloud Service Account to access the Gemini 2.0 Flash API.

#### 1. Create a Project & Enable API
1. Go to the **Google Cloud Console**.
2. Create a **New Project** (e.g., "VTM-OS-Project").
3. Search for "Generative Language API" and click **Enable**.

#### 2. Create Service Account Credentials
1. Navigate to **APIs & Services > Credentials**.
2. Click **+ Create Credentials** and select **Service Account**.
3. Name the account `vtm-os-user` and click **Create and Continue**.
4. For the role, select **Project > Viewer** and click **Done**.

#### 3. Generate and Place the JSON Key
1. Click on the newly created service account email address.
2. Click the **Keys** tab > **Add Key** > **Create New Key**.
3. Select **JSON** and click **Create**.
4. A file will download to your computer. Rename this file to exactly `service_account.json`.
5. Move the file into the **root directory** of the `vtm-os-community-edition` folder.

> **Note:** The `app.py` script looks specifically for `service_account.json` in the root folder to authenticate your AI requests.

## 3. Community Radio Setup
The built-in music player automatically scans the `static/music` directory.

* Drop your `.mp3` or `.wav` files into `./static/music/`.
* The system will detect new tracks and populate the playlist upon the next browser refresh.

## 4. Hardware Integration
* **Arduino Sketch:** Upload `vtm_mouth_controller.ino` to your Arduino Uno Q.
* **Architecture:** Review the VTM Wiki for detailed mapping of the "Mind-to-Body" bridge.

## 🤝 Contribution & Support
* **Contribute:** Submit issues or pull requests to improve the Community Edition core.
* **Stay Updated:** Follow the Official LinkedIn for development logs.

*Learn with me as I learn.*

© 2026 VideotronicMaker. All Rights Reserved. Trademarks of Tishin Padilla.
