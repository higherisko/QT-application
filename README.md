# Qt PLC Communication Tool

A personal C++/Qt project exploring how a desktop application can communicate with PLCs over industrial network protocols. I am building it alongside my hands-on experience in industrial maintenance and PLC programming, with the goal of growing it into a practical monitoring and IoT integration tool.

> **Status: work in progress.** The repository contains an early desktop UI and separate Modbus/TCP-related components. The user interface and communication path are not yet fully integrated, so this is a development project rather than a ready-to-use industrial product.

## Current project direction

- Desktop application built with Qt 6 Widgets and C++17.
- UI scaffolding for connection settings, IP/port selection, and application information.
- Modbus frame/parser and client components under development.
- PLC data and memory/tag abstractions under development.
- TCP client components under development.

## Planned development

- Connect the UI to a working Modbus TCP client.
- Show PLC connection state and selected tag/register values.
- Add logging and a simple history view.
- Explore database storage and a Python-based data/API layer.
- Later, connect a microcontroller or other IoT device and display its data alongside PLC values.

## Technology

- C++17
- Qt 6 (Widgets, Network)
- CMake
- Industrial communication concepts: Modbus/TCP, PLC tags and registers

## Build

Requirements: a C++17 compiler, CMake 3.16 or newer, and Qt 6 with the Widgets and Network components.

```powershell
cmake -S . -B build
cmake --build build
```

Run the executable generated in the `build` directory for your platform and build configuration.

## About the developer

I work in industrial maintenance and have around three years of PLC experience, including Mitsubishi PLC training/certification and practical work with Profinet devices, sensors, and PLC-to-PLC communication. I am expanding into desktop software, databases, and embedded/IoT development. This project documents that learning path through a real industrial automation use case.

## Note

This project is for learning and portfolio purposes. Do not connect it to production equipment or rely on it for safety-related control.
