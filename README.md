# SIT315 Task M1 – Complete Interrupt-Driven System (4/4 QP)

## 🔧 Summary

This Arduino project demonstrates a **complete interrupt-driven embedded system** meeting the 4/4 QP requirements for SIT315. It uses:

- **Timer1** to blink an LED at 1Hz (every 1 second)
- **Pin Change Interrupts (PCI)** on D8 and D9 to detect two pushbutton inputs
- Safe interrupt design: no delay(), short ISR, and flag-based handling
- Clear separation between time-based and event-based logic

## 🛠️ Hardware Setup

### Components:
- Arduino Uno
- 2 × Push Buttons
- 1 × LED
- 1 × 220Ω resistor
- Jumper wires & breadboard

### Circuit Connections:

| Component   | Arduino Pin | Notes                |
|-------------|--------------|----------------------|
| Button A    | D8           | Use INPUT_PULLUP     |
| Button B    | D9           | Use INPUT_PULLUP     |
| LED         | D10          | 330Ω resistor to GND |

### Notes:
- Both buttons are wired from pin → button → GND.
- LED is wired from D10 → 330Ω resistor → GND.
- No external resistors needed for buttons.

## 📂 Project Structure
SIT315_TaskM1/
├── TaskM1.cpp # Arduino source code
├── README.md # This file
├── Reflection_Report_SIT315_TaskM1.docx # 300–500 word report
├── screenshot_serial.png # Screenshot of Serial Monitor
├── circuit_diagram.png # Diagram showing hardware layout


## ▶️ How to Use

1. Connect components as per the circuit.
2. Upload `TaskM1.cpp` to Arduino Uno using Arduino IDE.
3. Open **Serial Monitor** at **9600 baud**.
4. Press:
   - **Button A (D8)** → prints: 🔘 Button A Pressed
   - **Button B (D9)** → prints: 🟡 Button B Pressed
5. LED (D10) blinks every second via Timer1.

## 🧠 Features

- Uses **Timer1 CTC mode** for time interrupts
- Uses **PCI on same group (D8 & D9)** for input detection
- ISR-safe logic: **no delay()**, just flag-setting
- All processing in `loop()` for ISR separation

## 🏁 Submission Checklist

- [x] TaskM1.cpp uploaded
- [x] Serial screenshot showing PCI & Timer output
- [x] Reflection Report included
- [x] GitHub link  & TinkerCard shared (inside reflection report)

