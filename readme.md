# Traffic Navigation and Signal Management System

#B.Tech 3rd Semester DSA Project  
Developed by: Youvraj Singh , kavyansh loshali , jatin sharma, sumit lohani
Language Used: C  
Tools Used: GCC Compiler, VS Code / Code::Blocks  
Date: October 2025  

# Project Overview

This project simulates a Traffic Navigation and Signal Management System using fundamental Data Structures such as Queues, Stacks, and Linked Lists.  
It aims to model real-world traffic flow and optimize signal operations to reduce congestion and prioritize emergency vehicles.

The system adjusts green light duration dynamically based on traffic density and manages vehicles efficiently using queue operations. Emergency vehicles are given immediate priority to ensure smooth passage.

---
 Features

- Vehicle Queue Simulation — vehicles are queued at traffic signals.  
- Emergency Vehicle Priority — emergency vehicles bypass the queue immediately.  
- Adaptive Signal Timing — green light duration changes based on traffic size.  
-  Route Tracking with Stack — maintains history of vehicles that have passed.  
- Dynamic Memory Allocation — for real-time addition and removal of vehicles.  


# Data Structures Used

| Data Structure | Purpose |
| Queue (Linked List) | Stores vehicles waiting at a signal. |
| Stack (Array) | Keeps track of vehicles that have crossed the signal. |
| Linked List Nodes | Dynamically manage incoming vehicles. |



#  Code Summary

The program uses:
- enqueue() – to add vehicles (emergency or normal).  
- dequeue()– to remove vehicles when the signal turns green.  
- simulateSignal() – to simulate adaptive green light behavior.  
- push() – to log vehicles that have passed.  

