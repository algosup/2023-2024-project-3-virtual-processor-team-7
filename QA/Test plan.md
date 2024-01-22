# Test Plan
<br>



| Authors | Abderrazaq MAKRAN and Raphael PROUDHON |
|---|---|
|Created|01/22/2024|
|Last Updated| |
|Status| Draft|


<br>

# Revision and Sign off

## Document History
| Version | Date | Author | Description of Changes|
|---|---|---|---|
|1| 01/22/2024 | Abderrazaq MAKRAN and Raphael PROUDHON| Draft |

## Approval List
|Name|Role|Approver/Reviewer|Approval/ Review Date|
|---|---|---|---|

<br>

# Table of Contents
- [1. GLOSSARY](#1-glossary)
- [2. INTRODUCTION](#1-introduction)
  - [2.1 Purpose](#21-purpose)
  - [2.2 Project Overview](#22-project-overview)
  - [2.3 Audience](#23-audience)
- [3. TEST STRATEGY](#3-test-strategy)
  - [3.1 Test Objectives](#31-test-objectives)
  - [3.2 Testing Environment](#32-testing-environment)
  - [3.3 Test Principles](#33-test-principles)

## 1. GLOSSARY
<br>

|Term|Definition|Source|
|---|---|---|
C |C is a general-purpose computer programming language. It was created in the 1970s by Dennis Ritchie, and remains very widely used and influential. By design, C's features cleanly reflect the capabilities of the targeted CPUs.| [Wikipedia](https://en.wikipedia.org/wiki/C_(programming_language))
Virtual Processor | A virtual processor is a representation of a physical processor core to the operating system of a logical partition that uses shared processors.| [IBM](https://www.ibm.com/docs/en/power8/8408-44E?topic=processors-virtual)
Assembly language| In computer programming, assembly language, often referred to simply as assembly and commonly abbreviated as ASM or asm, is any low-level programming language with a very strong correspondence between the instructions in the language and the architecture's machine code instructions.| [Wikipedia](https://en.wikipedia.org/wiki/Assembly_language)
IDE: Integrated Development Environment | An integrated development environment is a software application that provides comprehensive facilities for software development. An IDE normally consists of at least a source-code editor, build automation tools, and a debugger.| [Wikipedia](https://en.wikipedia.org/wiki/Integrated_development_environment)

<br>

## 2. INTRODUCTION

- ### 2.1 Purpose

  - The purpose of this test plan is to ensure the functionality, reliability, and correctness of the virtual processor and interpreter. The document introduces:
  
    -  **Test Strategy:**
    -  **Execution Strategy:**
    -  **Test Management:**

- ### 2.2 Project Overview

  - Algosup asked us to build a virtual processor and interpreter for running assembly code. It's an open project for students, developers, and hobbyists to learn low-level programming. We're keeping things clear with easy-to-follow guides. Our goal? Create a friendly space for anyone curious about assembly language and system programming.

- ### 2.3 Audience

  - The primary audience for this test plan includes project team members, each with distinct roles:

      - **Project Team Members:**

        - Responsible for executing tasks outlined in this document.
        - Contribute insights and recommendations regarding the test plan.

      - **Project Manager:**

        - Plans testing activities within the overall project schedule.
        - Reviews, approves, and holds accountability for the test plan.
        - Tracks the performance of the testing activities.

      - **Technical Team:**

          - Ensures the test plan and deliverables are consistent with the project's design.
          - Provides the necessary testing environment.
          - Adheres to procedures related to defect fixes.programming.

This collaborative approach ensures that the test plan not only meets technical requirements but also aligns with overall project goals.

## 3. TEST STRATEGY
- ### 3.1 Test Objectives
  - This test plan is focused on rigorously assessing the virtual processor and interpreter in our project, emphasizing functionality, reliability, and correctness. We aim to validate precise execution of assembly code, assess the reliability of the virtual processor under diverse scenarios, and ensure accurate results from the interpreter. Additionally, we prioritize educational value, providing a testing framework aligned with learning goals for students and developers exploring low-level programming concepts. Clear documentation and guides ensure accessibility for a broad audience. This testing approach aims not only to validate technical robustness but also to highlight the project's educational merits in the realm of low-level programming.

- ### 3.2 Testing Environment
  - **Operating System:** Windows and MacOS
  - **Compiler:** GCC 13.2
  - **IDE:** Visual Studio Code 1.85
  - **Hardware:** <br>
    - [MacBook Air 2020](https://www.apple.com/fr/macbook-air-m1/)
      - 13.3 inch (2560 x 1600)
      - macOS Sonoma 14.2
      - Apple M1 Chip

    - [Lenovo Thinkbook 14](https://pcsupport.lenovo.com/us/en/products/laptops-and-netbooks/thinkbook-series/thinkbook-14-iil/20sl)
      - Windows 11 Pro
      - 14 inch (1920 x 1080)
      - Processor: Intel(R) Core(TM) i7-1165G7 CPU @ 2.80GHz
      - RAM: 16.0 GB
      - System type: 64-bit operating system, x64-based processor

    - [ThinkPad E14 Gen 5](https://www.lenovo.com/fr/fr/p/laptops/thinkpad/thinkpade/thinkpad-e14-gen-5-(14-inch-intel)/len101t0064)
      - Windows 11 Pro
      - 14 inch (1920 x 1080)
      - Processor: 13th Gen Intel(R) Core(TM) i7-1355U, 1700 Mhz
      - RAM: 16.0 GB
      - System type: 64-bit operating system, x64-based processor

- ## 3.3 Test Principles 
  
    - Tests will be focused on meeting the objectives and quality 
    
    - Testing processes will be well defined, yet flexible, with the ability to change as needed. 
    
    - There will be common, consistent procedures for all teams supporting testing activities

    - Testing activities will build upon previous stages to avoid redundancy or duplication of effort

    - Testing will be divided into distinct phases, each with clearly defined objectives and goals.

- ## 3.4 Scope and Levels of Testing
    - ### 3.4.1 Define Scope of Testing
    - ### 3.4.2 Identify Testing Type
    - ### 3.4.3 Document Risk & Issues
    - ### 3.4.4 Create Test Logistics
    -  
## 4. EXECUTION STRATEGY
  - ### 4.1 Entry and Exit Criteria
  - ### 4.2 Test Cycles
  - ### 4.3 Validation and Defect Management
  - ### 4.4 Test Metrics
  - ### 4.5 Defect tracking & Reporting
  - 
## 5. TEST MANAGEMENT PROCESS

## Test Plan approval

| Role | Name | Signature | Date |
|---|---|---|---|
| Project Manager | Matteo LEFIN |  | |
| Program Manager | Gael MALVAR |  | |
| Tech Lead | Robin DEBRY |  | |
| Software Developer | Camille GAYAT |  | |
| Software Developer | David CUAHONTE |  | |
| Quality Assurance | Raphaël PROUDHON |  | |
| Quality Assurance | Abderrazaq MAKRAN |   | |