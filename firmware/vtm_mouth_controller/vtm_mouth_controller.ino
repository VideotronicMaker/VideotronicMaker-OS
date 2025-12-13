/*
 * VTM-OS: The Body - LED Matrix Mouth Controller
 * =============================================================================
 * PROJECT:      VideotronicMaker OS (VTM-OS) - The Body
 * FILE:         vtm_mouth_controller.ino
 * AUTHOR:       Tishin Padilla (VideotronicMaker)
 * DATE:         2025-12-09
 * VERSION:      1.0.0
 * DESCRIPTION:  This sketch controls the 13x8 LED Matrix mouth animation on the 
 * STM32 Microcontroller (MCU) of the Arduino Uno Q. It functions 
 * as the 'Body' in the Dual-Brain architecture, receiving commands 
 * from the Linux MPU (the 'Brain') via the Arduino Router Bridge 
 * (RPC). This code is inspired by foundational Arduino examples 
 * and built using core Arduino libraries.
 *
 * ASSISTANT:    Code logic and structure assisted by Google Gemini.
 *
 * LICENSES & CREDITS:
 *
 * This software is licensed under the MIT License.
 *
 * Copyright (c) 2025 Tishin Padilla (VideotronicMaker)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * The included libraries (ArduinoGraphics, Arduino_LED_Matrix, Arduino_RouterBridge)
 * are copyrighted by their respective creators and used under their applicable
 * licenses (typically LGPL or MIT).
 * =============================================================================
 */

// =======================
// 1. LIBRARY INCLUDES
// =======================

// Necessary for drawing shapes and managing the 12x8 display surface.
#include <ArduinoGraphics.h>
// Required for accessing and initializing the built-in 12x8 LED matrix hardware.
#include <Arduino_LED_Matrix.h>
// CRITICAL: Enables Remote Procedure Calls (RPC) over the internal serial link
// between the Linux MPU (the 'Brain') and the STM32 MCU (the 'Body').
#include <Arduino_RouterBridge.h>

// Instantiate the LED Matrix object to interact with the hardware.
ArduinoLEDMatrix matrix;

// =======================
// 2. CONSTANTS & STATE
// =======================

// Define the ON and OFF colors for the LED matrix (White and Black).
// 0xFFFFFFFF is white (maximum R, G, B, A values).
const uint32_t ON_COLOR = 0xFFFFFFFF;
// 0x00000000 is black (all zeros, effectively 'off').
const uint32_t OFF_COLOR = 0x00000000;

// Global State Variable: Controls the animation loop in loop().
// 'volatile' keyword is essential here. It tells the compiler that this
// variable can be changed unexpectedly by an external event (specifically,
// the Bridge interrupt when an RPC command is received).
volatile int talkState = 0; // 0 = Mouth Closed (Idle), 1 = Talking (Animating)

// =======================
// 3. DRAWING FUNCTIONS
// =======================

// FUNCTION: drawMouthClosed
// Purpose: Renders the idle state: a simple, horizontal closed mouth line.
void drawMouthClosed() {
  // Start the drawing operation buffer.
  matrix.beginDraw();
  // Clear all pixels from the previous frame.
  matrix.clear();
  
  // Set the color for drawing lines and shapes to ON_COLOR (White).
  matrix.stroke(ON_COLOR);
  matrix.fill(ON_COLOR);
  
  // SHAPE 1: Waiting/Closed Mouth. Draws a rectangle centered on the 12x8 grid.
  // Args: (x, y, width, height)
  matrix.rect(1, 3, 10, 2);
  
  // Send the drawing buffer content to the physical LED matrix.
  matrix.endDraw();
}

// FUNCTION: drawRandomMouth
// Purpose: Selects a random mouth shape (from 3 options) and renders it
// to simulate the act of speaking with simple animation.
void drawRandomMouth() {
  matrix.beginDraw();
  matrix.clear();
  
  matrix.stroke(ON_COLOR);
  matrix.fill(ON_COLOR);
  
  // Randomly select one of the 3 open shapes (0, 1, or 2).
  // The 'random()' function with two arguments returns a value up to (but not including) the second.
  int shapeIndex = random(0, 3);

  if (shapeIndex == 0) {
    // SHAPE 2: Fully Open (Simulates a wide 'A' or 'E' vowel sound)
    matrix.rect(0, 0, 12, 2);
    matrix.rect(0, 2, 2, 1);
    matrix.rect(11, 2, 1, 1);
    matrix.rect(1, 3, 2, 1);
    matrix.rect(10, 3, 2, 1);
    matrix.rect(1, 4, 2, 1);
    matrix.rect(9, 4, 2, 1);
    matrix.rect(2, 5, 2, 1);
    matrix.rect(8, 5, 2, 1);
    matrix.rect(3, 6, 2, 1);
    matrix.rect(7, 6, 2, 1);
    matrix.rect(3, 7, 6, 1);
  }
  else if (shapeIndex == 1) {
    // SHAPE 3: Half Open (Simulates a common resting or 'M' sound position)
    matrix.rect(1, 1, 10, 2);
    matrix.rect(1, 3, 2, 2);
    matrix.rect(10, 3, 1, 2);
    matrix.rect(9, 4, 1, 1);
    matrix.rect(2, 5, 8, 1);
  }
  else {
    // SHAPE 4: Narrow Open (Simulates an 'O' or 'U' vowel/tense sound)
    matrix.rect(2, 1, 8, 1);
    matrix.rect(3, 2, 6, 1);
    matrix.rect(3, 3, 1, 3);
    matrix.rect(8, 3, 1, 3);
    matrix.rect(4, 6, 4, 1);
  }
  
  matrix.endDraw();
}

// =======================
// 4. BRIDGE FUNCTIONS (RPC)
// =======================

// RPC FUNCTION: set_mouth
// This function is the communication endpoint. It is called *remotely*
// by the Python script running on the Linux MPU (e.g., in a Flask server).
// The MPU passes an integer 'state' to update the animation logic.
int set_mouth(int state) {
  // Update the global state. This change is read immediately in the loop() function.
  talkState = state;
  // Standard RPC practice is to return the result, confirming the command receipt.
  return state;
}

// =======================
// 5. ARDUINO SETUP
// =======================

void setup() {
  // Initialize the LED Matrix hardware and its control registers.
  matrix.begin();
  
  // Initialize the Router Bridge (The communication backbone to the Linux MPU).
  // This must be called early in setup().
  Bridge.begin(); 
  
  // Register the function 'set_mouth' so the Linux MPU can call it remotely
  // by its string name "set_mouth". This is the 'Remote Procedure Call' setup.
  Bridge.provide("set_mouth", set_mouth);
  
  // Set the initial visual state before the main loop begins.
  drawMouthClosed();
}

// =======================
// 6. MAIN LOOP
// =======================

void loop() {
  // 1. Handle Animation (Real-Time Control)
  if (talkState == 1) {
    // If the MPU command is 'Talking', continuously redraw a random mouth shape.
    drawRandomMouth();
    
    // CRITICAL: Always service the Bridge communication during animation.
    // This allows it to listen for and process the next RPC command (e.g., stop talking).
    Bridge.update();
    
    // Frame rate control: 80ms delay gives approx. 12.5 frames per second (FPS),
    // which is suitable for smooth, low-resource animation.
    delay(80);
  } else {
    // 2. Handle Idle State (Optimization)
    // We use a 'static' variable to track the last state drawn.
    // This ensures 'drawMouthClosed()' is only called *once* when the state changes to 'Idle',
    // preventing unnecessary redrawing that would consume power and CPU cycles.
    static int lastState = -1; // Initialize to an impossible state to force first draw.
    if (lastState != 0) {
      drawMouthClosed();
      lastState = 0; // Mark the closed mouth as drawn.
    }
    
    // CRITICAL: Always service the Bridge, even when idle, to listen for new commands
    // from the Linux MPU. Without this, the MCU cannot receive the 'talkState = 1' command.
    Bridge.update();
  }
}
