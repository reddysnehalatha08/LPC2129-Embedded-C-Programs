
# LPC2129 Embedded C Programs

This repository contains Embedded C programs developed using the **LPC2129 ARM7 microcontroller**. The programs cover GPIO, LED, Switch, and UART concepts commonly used in embedded systems.

## 📁 Project Structure

### 🔹 LED_Switch

Programs based on **LED, Switch, GPIO, counters, and basic number logic**.

| No. | Program                                 |
| --- | --------------------------------------- |
| 01  | LED Blink 10 Times                      |
| 02  | Switch Controlled LED Pattern           |
| 03  | Switch Press Count – Binary LED Display |
| 04  | Switch Press Count with 500ms Delay     |
| 05  | One Second Up and Down Counter          |
| 06  | Even/Odd Number LED Display             |
| 07  | Paired LED Pattern – 5 Times            |
| 08  | Prime Numbers LED Display               |
| 09  | Odd Digits LED Display                  |
| 10  | Sum of Digits LED Display               |
| 11  | Product of Digits LED Display           |
| 12  | Powers of 2 LED Display                 |
| 13  | Up/Down Counter                         |
| 14  | Second Highest Digit LED Display        |

**Supporting files:**

* `delay.c`
* `delay.h`

### 🔹 UART

Programs based on **UART serial communication** using **9600 baud rate**.

| No. | Program                                                     |
| --- | ----------------------------------------------------------- |
| 01  | UART Transmit String at 9600 Baud Rate                      |
| 02  | UART Receive Character and Display in Binary using LEDs     |
| 03  | UART Character – ASCII, Decimal and Hexadecimal Display     |
| 04  | UART Transmit A-Z using Switch                              |
| 05  | UART Character – Decimal, Hexadecimal and 7-Segment Display |
| 06  | UART Password Validation                                    |

**Supporting files:**

* `uart.c`
* `uart.h`
* `types.h`

## Hardware & Software

* **Microcontroller:** LPC2129 ARM7
* **Programming Language:** Embedded C
* **IDE:** Keil µVision
* **Communication:** UART
* **Baud Rate:** 9600
* **Hardware:** LEDs, Switches, 7-Segment Display, USB-UART Converter

##  Purpose

The purpose of this repository is to practice and demonstrate fundamental **Embedded C programming, GPIO interfacing, switch handling, LED control, number-based logic, and UART communication** using the LPC2129 microcontroller.
