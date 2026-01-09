# ESC Game Engine

ESC Game Engine is an experimental 2D game engine written in C++, focused on engine architecture, systems design, and low-level game development.

The engine is currently functional and can be built and executed, using an older version of SFML.
While usable, the project is still early-stage and under active development.

![ESC Game Engine Demo](assets/demo.gif)

---

## 🎯 Goals (Planned)

The long-term goal of ESC Game Engine is to provide:

* A lightweight 2D game engine
* Simple entity and scene management
* Event-driven input handling
* Rendering and window management via SFML
* A clean, modular codebase suitable for learning and experimentation

These features are **planned**, not yet implemented.

---

## 🛠 Tech Stack

* **Language:** C++
* **Graphics / Windowing:** SFML (version update required)

---

## 📌 Roadmap (Short-Term)

* [ ] Update SFML to 3.0+
* [ ] Create sprite importing features
* [ ] Physics implementation
* [ ] Initial documentation

---

# Build Guide – ESC Game Engine

This document explains how to build and run **ESC Game Engine** on **Windows** using **CMake** and **Visual Studio**.

The engine is currently **functional** and depends on an **older version of SFML**.

---

## 🖥 Requirements

- **Windows 10 / 11**
- **Visual Studio 2022**
  - Workload: *Desktop development with C++*
- **CMake 3.20+**
- **SFML (older supported version)**

> ⚠ The engine will not build with newer SFML versions yet.  
> Updating SFML is tracked in `TODO.md`.

---

## 📁 Project Layout (Simplified)

ESC-Game-Engine/
├── CMakeLists.txt
├── src/
├── include/
├── external/
│ └── SFML/
├── build/ (generated)

---

## 🧱 How to build

Running the engine with releasse target in visual studio
