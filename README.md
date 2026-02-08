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

VTM OS™ is a modular prototyping platform designed to take you from the terminal to a customizable UI. Together with the VTM P³ frame, it provides a foundational framework for experimenting with bio-mimetic AI. While inspired by and optimized for the Arduino Uno Q as the preferred board, the system is flexible and can be utilized on a Mac, PC, or any other SBC.

### 🎥 Featured: The Music Video Guide
<div align="center">
  <a href="https://www.youtube.com/watch?v=tJTPic1ApBQ" target="_blank" rel="noopener noreferrer">
    <img src="https://img.youtube.com/vi/tJTPic1ApBQ/maxresdefault.jpg" width="100%" alt="Video Guide">
  </a>
</div>

## 🤖 Official Hardware: VTM P³
**Code needs a body.** The **VTM P³ (Physical Prototyping Platform)** is the official reference hardware for VTM OS. It is a modular 'Vertical Workbench' built using standard physical computing parts.

<div align="center">
  <a href="https://videotronicmaker.com/arduino-uno-q-prototyping-platform-p3/">
    <img src="https://videotronicmaker.com/wp-content/uploads/2026/01/p-3-sketch-scaled.webp" alt="VTM P3 Reference Design" width="100%">
  </a>
  <p><i>*Prices listed below are as of Jan 30, 2026 and subject to change. As an Amazon Associate I earn from qualifying purchases. This means I may make a small commission if you buy through these links at no extra cost to you.*</i></p>
</div>

### 🏗️ VTM P³ Hardware Bill of Materials (BOM)
To build the VTM P³ frame, these are the suggested V-Slot components.

#### 1. The Skeleton (Aluminum)
| Component | Spec | Qty Needed | Price (Approx) | Purchase Link | Build Notes |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Main Towers (Y-Axis)** | 2040 V-Slot (500mm) | 4 Rails | **$26.99** | [**Amazon Link**](https://amzn.to/4ksoaRP) | **⚠️ Important:** Link is for a 2-Pack. **Order Qty: 2** to get the 4 rails needed. |
| **Z-Axis Feet** | 4040 V-Slot (400mm) | 2 Rails | **$46.02** | [**Amazon Link**](https://amzn.to/3NG4dKW) | The heavy base. Provides the "desk footprint" stability. |
| **Base Crossbar** | 4040 V-Slot (300mm) | 1 Rail | **$35.82** | [**Amazon Link**](https://amzn.to/4qPQz6F) | Link is for a 2-Pack. You will have 1 spare rail for future upgrades. |
| **Drawer Supports** | 2040 V-Slot (400mm) | 1 Rail | **$18.99** | [**Amazon Link**](https://amzn.to/3LXaHEI) | Link is for a 2-Pack. You will have 1 spare rail (good for testing). |
| **Top Rail (X-Axis)** | 2020 V-Slot (300mm) | 1 Rail | **$16.99** | [**Amazon Link**](https://amzn.to/4k9y7Dd) | Link is for a 4-Pack. You get 3 spare rails for mounting lights/cameras. |

#### 2. The Joints (Fasteners & Brackets)
| Component | Spec | Quantity | Price | Purchase Link | Notes |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **The "Everything" Kit** | M5 T-Nuts & Screws | 240 Pcs | **$12.99** | [**Amazon Link**](https://amzn.to/3NMlLFc) | **Essential.** Includes 8mm, 10mm, 12mm, and 14mm screws. |
| **Corner Brackets** | 2020 L-Brackets | 30 Sets | **$12.99** | [**Amazon Link**](https://amzn.to/4k5ZWMM) | The 90-degree joints for the frame. Comes with matching screws. |
| **Monitor Mount** | VESA 75/100 Plate | 1 Unit | **~$19.99** | [**Amazon Search**](https://amzn.to/3vH7Q7w) | *Search for "Sim Rig VESA Mount".* Bolts directly to the 2020 Top Rail. |

#### 3. The Muscles (Motion)
*The robotic kinematics. This kit provides the arm structure and high-torque servos in a single package. Two arms are required for full bi-manual operation.*

| Component | Spec | Quantity | Price | Purchase Link | Notes |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **6DOF LeArm Kit** | Full Metal + 6x Digital Servos | 2 Kits | **$139.99** | [**Amazon Link**](https://amzn.to/4amAcbE) | **⚠️ Important:** Features anti-stall digital servos. |
| **Hiwonder xArm1S** | 6DOF Full Metal + Wireless/App | 2 Kits | **$199.99** | [**Amazon Link**](https://amzn.to/4kkAB1K) | Premium kit. Supports PC, App, and Mouse control. |
| **Arduino Braccio** | 6DOF Shield-compatible Arm | 2 Kits | **$275.00** | [**Arduino Store**](https://store-usa.arduino.cc/products/tinkerkit-braccio-robot) | **⚠️ Note:** Currently Sold Out. Includes official Braccio Shield. |
| **diymore ROT3U Arm** | 6DOF Aluminium Structure | 2 Kits | **$38.99** | [**Amazon Link**](https://amzn.to/4arJwds) | **⚠️ Note:** Unassembled parts. Does **NOT** include servos. |
| **MG996R Servos (6pk)** | Brass Gear / High Torque | 2 Packs | **$34.99** | [**Amazon Link**](https://amzn.to/4qlYFmk) | Necessary for diymore ROT3U or custom frame builds. |

---

### 💰 Platform Build Estimate
*The VTM P³ is an Open Source Reference Design. The costs below represent the specific "Laboratory Standard" configuration used in the documentation, but feel free to swap or scavenge parts.*

| Subsystem | Components | Cost to Replicate |
| :--- | :--- | :--- |
| **1. The Skeleton** | Industrial Aluminum Extrusion Frame | **~$172.00** |
| **2. The Joints** | Fasteners, Brackets & VESA Mount | **~$46.00** |
| **3. The Muscles** | 2x 6DOF Metal Arm Kits (Digital Servos) | **~$280.00** |
| **TOTAL ESTIMATE** | **Full Prototyping Platform** | **~$498.00** |

**🎓 The Open Source Advantage:** Build at Your Own Pace: The VTM P³ is modular, allowing you to build it part by part as your budget and time allow.

### 🎥 Watch the Demos
<div align="center">

[![Building an AI Desk Bot with Arduino Uno Q](https://ytcards.demolab.com/?id=WiXRPLrF5m0&title=Building+an+AI+Desk+Bot+with+Arduino+Uno+Q&lang=en&background_color=%230d1117&title_color=%23ffffff&stats_color=%23dedede&max_title_lines=1&width=250&border_radius=5)](https://www.youtube.com/watch?v=WiXRPLrF5m0)
[![Arduino UNO Q Robot Project: Dual-Brain Sync](https://ytcards.demolab.com/?id=xDm-rMR-oBs&title=Arduino+UNO+Q+Robot+Project%3A+Dual-Brain+Sync&lang=en&background_color=%230d1117&title_color=%23ffffff&stats_color=%23dedede&max_title_lines=1&width=250&border_radius=5)](https://www.youtube.com/watch?v=xDm-rMR-oBs)
[![LoRa Field Research Station with Arduino Uno Q](https://ytcards.demolab.com/?id=Xr02o3HJoto&title=LoRa+Field+Research+Station+with+Arduino+Uno+Q&lang=en&background_color=%230d1117&title_color=%23ffffff&stats_color=%23dedede&max_title_lines=1&width=250&border_radius=5)](https://www.youtube.com/watch?v=Xr02o3HJoto)

</div>

---

## 📖 Documentation & The Growth Guide
The VTM OS is more than just a repository; it's an evolving prototyping ecosystem. To understand the "Mind-Body-Link" architecture and start your own evolutionary build, visit the official documentation:

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

### Watch the Videos
<div align="center">

[![Arduino Uno Q Project: VTM OS Installation Guide for macOS](https://ytcards.demolab.com/?id=81OwakGelIU&title=Arduino+Uno+Q+Project%3A+VTM+OS+Installation+Guide+for+macOS&lang=en&background_color=%230d1117&title_color=%23ffffff&stats_color=%23dedede&max_title_lines=1&width=250&border_radius=5)](https://www.youtube.com/watch?v=81OwakGelIU) [![VTM OS: Arduino Uno Q Installation Guide](https://ytcards.demolab.com/?id=imKBDTqGAus&title=VTM+OS%3A+Arduino+Uno+Q+Installation+Guide&lang=en&background_color=%230d1117&title_color=%23ffffff&stats_color=%23dedede&max_title_lines=1&width=250&border_radius=5)](https://www.youtube.com/watch?v=imKBDTqGAus)

</div>

### 1. Download and Navigate
Clone the repository and move into the directory. This ensures the environment is built inside the project folder, not your home directory.

```bash
git clone "https://github.com/VideotronicMaker/VideotronicMaker-OS.git"(https://github.com/VideotronicMaker/VideotronicMaker-OS.git)
cd VideotronicMaker-OS
```

### 2. Environment Setup (macOS/Linux)
Create an isolated virtual environment to prevent library conflicts.

```bash
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
```
#### 3. Launch the Mind
Ensure your service_account.json is in the project root. Activate the environment and start the system:
```bash
source venv/bin/activate
python3 app.py
```

### 🚀 Uno Q SBC - Community Edition Quick Start
Running VTM OS™ directly on the Arduino Uno Q (SBC/MPU) allows for a fully integrated AI-to-Hardware experience. This version is optimized for the internal VTM-BioLink™ bridge.

### 1. Download and Navigate
Clone the repository and move into the directory. This ensures the environment is built inside the project folder, not your home directory.

```bash
git clone https://github.com/VideotronicMaker/VideotronicMaker-OS.git
cd VideotronicMaker-OS
```

### 2. Manual Terminal Setup (Uno Q)
Open a terminal on the Uno Q and run these commands to prepare the environment:

```bash
sudo apt update && sudo apt install -y python3-pip python3-venv
python3 -m venv venv
source venv/bin/activate
pip install flask pyserial "google-generativeai>=0.8.3" psutil
```

#### 3. Launch the Mind
Ensure your service_account.json is in the project root. Activate the environment and start the system:
```bash
source venv/bin/activate
python3 app.py
```

#### 5. Access the Nexus Dashboard
Open your browser on your host machine to: **http://localhost:5002**

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
