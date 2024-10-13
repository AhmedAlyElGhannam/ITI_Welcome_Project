# Introduction
On Orientation Day in ITI (13th of October 2024), a **Welcome Project** was assigned to me with a deadline of 1.5 weeks even before starting off my journey in ITI's Embedded Systems Track. *bruh!*

# Project Description
Make a robot that has the following features:
1. Mode A: Mobile control through Bluetooth.
2. Mode B: Avoid obstacles via Ultrasonic/IR/LiDAR. **boom vine sound effect**
3. Mode C: Line follower (via IR).
4. Mode D: Find the shortest path in a maze.

# Initial Design Ideas
1. Modes will be implemented as a state machine that follows the UML diagram present in this repository.
2. Use ESP32 because it has Bluetooth built-in.
3. Use Blynk as application platform for mobile control. (Mode A)
4. For obstacle avoidance ultrasonic + servo motor for obstacle avoidance. (Mode B)
5. For line follower, use 2-IR or 4-IR configuration. (Mode C)
6. Consider using FreeRTOS for ESP platform. (will be badass)
7. Use Arduino framework + PlatformIO extension in VSCode.
8. For finding the "shortest path in a maze", consider using A* search...?! (Mode D --- depends on whether the maze is static with multiple paths \[use Dijkstra or sth\] OR variable with one true path \[use A* search\])

## Issues/Questions
1. Is the maze required to be solved 2D (black lines on the ground) or 3D (with walls)?
