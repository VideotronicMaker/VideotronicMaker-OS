/* ==========================================================================
 * VTM OS - Community Edition (MIT License)
 * Optimized for: Chat, Nexus, and Music Player
 * ========================================================================== */

// ==========================================
// 1. INITIALIZATION & DOM ELEMENTS
// ==========================================
const splashScreen = document.getElementById('splash-screen');
const splashStatus = document.getElementById('splash-status');
const sendBtn = document.getElementById('send-button');
const userInput = document.getElementById('user-input');
const chatLog = document.getElementById('chat-log');

// ==========================================
// 2. VTM PROPRIETARY BOOT SEQUENCE
// ==========================================
window.onload = function() {
    console.log("[VTM-HOST] System Core: Initializing...");
    playTelemetrySound(800, 0.2, 'sine'); 
    
    setTimeout(() => { if(splashStatus) splashStatus.innerText = "Initializing VTM Community Core..."; }, 800);
    setTimeout(() => { if(splashStatus) splashStatus.innerText = "System Online. Learn with me as I learn."; }, 1600);

    setTimeout(() => {
        // Startup signals readiness to the backend
        fetch('/startup', { method: 'POST' });
        
        if(splashScreen) {
            splashScreen.style.opacity = '0';
            setTimeout(() => { splashScreen.style.display = 'none'; }, 1000);
        }
    }, 2000);
    
    fetchMusicList();
};

function playTelemetrySound(freq, duration, type) {
    const AudioContext = window.AudioContext || window.webkitAudioContext;
    if (!AudioContext) return;
    const ctx = new AudioContext();
    const osc = ctx.createOscillator();
    const gain = ctx.createGain();
    osc.connect(gain);
    gain.connect(ctx.destination);
    osc.type = type; 
    osc.frequency.setValueAtTime(freq, ctx.currentTime);
    gain.gain.setValueAtTime(0.1, ctx.currentTime);
    gain.gain.exponentialRampToValueAtTime(0.001, ctx.currentTime + duration);
    osc.start();
    osc.stop(ctx.currentTime + duration);
}

// ==========================================
// 3. SYSTEM STATS (Header Telemetry)
// ==========================================
function updateSystemStats() {
    fetch('/system_stats')
        .then(res => res.json())
        .then(data => {
            const cpuBar = document.getElementById('cpu-bar');
            const ramBar = document.getElementById('ram-bar');
            const cpuText = document.getElementById('cpu-text');
            const ramText = document.getElementById('ram-text');
            const tempText = document.getElementById('temp-text');
            
            if(cpuBar) cpuBar.style.width = data.cpu + '%';
            if(ramBar) ramBar.style.width = data.ram + '%';
            if(cpuText) cpuText.innerText = Math.round(data.cpu) + '%';
            if(ramText) ramText.innerText = Math.round(data.ram) + '%';
            if(tempText) tempText.innerText = Math.round(data.temp) + '°F';
        })
        .catch(err => console.error("[VTM-HOST] Telemetry Error:", err));
}
setInterval(updateSystemStats, 1000);

// ==========================================
// 4. VIEW SWITCHER
// ==========================================
window.switchView = function(viewName) {
    // Hide all sections and deactivate buttons
    document.querySelectorAll('.view-section').forEach(el => el.classList.remove('active'));
    document.querySelectorAll('.control-button').forEach(el => el.classList.remove('active'));
    
    const targetView = document.getElementById('view-' + viewName);
    if (targetView) targetView.classList.add('active');
    
    // Activate current footer button
    const buttons = document.querySelectorAll('.control-button');
    buttons.forEach(btn => {
        if (btn.getAttribute('onclick').includes(`'${viewName}'`)) {
            btn.classList.add('active');
        }
    });
};

// ==========================================
// 5. CHAT LOGIC (Text Only)
// ==========================================
if (userInput) {
    userInput.addEventListener("keypress", function(event) {
        if (event.key === "Enter" && !event.shiftKey) {
            event.preventDefault();
            sendText();
        }
    });
}

if (sendBtn) sendBtn.addEventListener('click', sendText);

async function sendText() {
    const text = userInput.value.trim();
    if (!text) return;

    addMessage(text, "user-msg");
    userInput.value = '';

    try {
        const response = await fetch('/process_text', { 
            method: 'POST', 
            headers: {'Content-Type': 'application/json'},
            body: JSON.stringify({ message: text })
        });
        
        const data = await response.json();
        
        if (data.text) {
            addMessage(data.text, "bot-msg");
        } else if (data.error) {
            addMessage("Error: " + data.error, "bot-msg");
        }
    } catch (e) {
        console.error("Chat Error:", e);
        addMessage("System connection lost.", "bot-msg");
    }
}

function addMessage(text, type) {
    if (!text) return; 
    
    const msgWrapper = document.createElement('div');
    msgWrapper.classList.add('flex', type === 'user-msg' ? 'justify-end' : 'justify-start');
    
    const msgBubble = document.createElement('div');
    msgBubble.className = type === 'user-msg' 
        ? 'bg-orange-600 p-4 rounded-xl text-white max-w-[80%]' 
        : 'bg-gray-700 p-4 rounded-xl text-gray-100 max-w-[80%]';
    
    msgBubble.innerText = text;
    msgWrapper.appendChild(msgBubble);
    chatLog.appendChild(msgWrapper);
    chatLog.scrollTop = chatLog.scrollHeight;
}

// ==========================================
// 6. MUSIC PLAYER
// ==========================================
let playlist = [];
let currentTrackIndex = 0;
let isMusicPlaying = false;
let musicPlayer = new Audio();

function fetchMusicList() {
    fetch('/music_list').then(res => res.json()).then(files => {
        if (files && files.length > 0) { 
            playlist = files; 
            loadTrack(0); 
            document.getElementById('track-status').innerText = "Library Online";
        }
    });
}

function loadTrack(index) {
    if (playlist.length === 0) return;
    if (index >= playlist.length) index = 0;
    if (index < 0) index = playlist.length - 1;
    
    currentTrackIndex = index;
    const trackName = playlist[currentTrackIndex];
    musicPlayer.src = `/static/music/${encodeURIComponent(trackName)}`;
    document.getElementById('track-name').innerText = trackName.split('.')[0];
}

window.togglePlay = function() {
    const playIcon = document.getElementById('play-icon');
    const visualizer = document.getElementById('music-visualizer');
    
    if (isMusicPlaying) {
        musicPlayer.pause();
        isMusicPlaying = false;
        if(playIcon) playIcon.innerHTML = '<path d="M8 5v14l11-7z"/>';
        if(visualizer) visualizer.classList.remove('viz-active');
    } else {
        musicPlayer.play().catch(e => console.error("Play failed:", e));
        isMusicPlaying = true;
        if(playIcon) playIcon.innerHTML = '<path d="M6 19h4V5H6v14zm8-14v14h4V5h-4z"/>';
        if(visualizer) visualizer.classList.add('viz-active');
    }
};

window.nextTrack = function() { 
    loadTrack(currentTrackIndex + 1); 
    if(isMusicPlaying) musicPlayer.play(); 
};

window.prevTrack = function() { 
    loadTrack(currentTrackIndex - 1); 
    if(isMusicPlaying) musicPlayer.play(); 
};
