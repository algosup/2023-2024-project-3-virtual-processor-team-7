# Functional Specifications | Virtual Processor Team 7

---

<details>
<summary> 📖 Table of content 📖 </summary>

- [Functional Specifications | Virtual Processor Team 7](#functional-specifications--virtual-processor-team-7)
  - [A. Document Control](#a-document-control)
    - [1. Document Information](#1-document-information)
    - [2. Document Approval](#2-document-approval)
  - [B. Introduction](#b-introduction)
    - [1. Glossary](#1-glossary)
    - [2. Project Overview](#2-project-overview)
    - [3. Project Definition](#3-project-definition)
      - [➭ Vision](#-vision)
      - [➭ Objectives](#-objectives)
      - [➭ Scope](#-scope)
      - [➭ Deliverables](#-deliverables)
    - [4. Project Organisation](#4-project-organisation)
      - [➭ Stakeholders](#-stakeholders)
      - [➭ Project Roles](#-project-roles)
      - [➭ Project Reviewers](#-project-reviewers)
    - [5. Project Plan](#5-project-plan)
      - [➭ Retroplanning](#-retroplanning)
      - [➭ Milestones](#-milestones)
      - [➭ Resources/Financial plan](#-resourcesfinancial-plan)
        - [★ Human Resources](#-human-resources)
        - [★ Development Tools](#-development-tools)
        - [★ Associated costs](#-associated-costs)
      - [➭ Assumptions/Constraints](#-assumptionsconstraints)
        - [★ Team member availability](#-team-member-availability)
        - [★ Time constraints](#-time-constraints)
  - [C. Functional Requirements](#c-functional-requirements)
    - [1. System Capabilities](#1-system-capabilities)
      - [➭ 1.1 Data Handling:](#-11-data-handling)
      - [➭ 1.2 Calculations:](#-12-calculations)
      - [➭ 1.3 Branching:](#-13-branching)
      - [➭ 1.4 Platform Independence:](#-14-platform-independence)
      - [➭ 1.5 Error Handling and Detection:](#-15-error-handling-and-detection)
    - [2. Assembly Language](#2-assembly-language)
      - [➭ Instructions](#-instructions)
      - [➭ Example of use](#-example-of-use)
  - [D. Non-Functional Requirements](#d-non-functional-requirements)

</details>

---

## A. Document Control

### 1. Document Information

| Document ID | Document # 01 |
|---|---|
| Document Owner | Gaël MALVAR |
| Issue date | 01/22/2024 |
| Last Issue Date | 01/23/2024 |
| Document Name | Functional Specification|

### 2. Document Approval

| Role | Name | Signature | Date |
|---|---|---|---|
| Project Manager | Mattéo LEFIN| ⌛ | ../../.. |
| Program Manager | Gaël MALVAR | ⌛ | ../../.. |
| Tech Lead | Robin DEBRY | ⌛ | ../../.. |
| Software Engineers | David CUAHONTE CUEVAS | ⌛ | ../../.. |
| Software Engineers | Camille GAYAT  | ⌛ | ../../.. |
| Quality Assurance | Abderrazaq MAKRAN | ⌛ | ../../.. |
| Quality Assurance | Raphaël PROUDHON | ⌛ | ../../.. |

## B. Introduction

### 1. Glossary

| Term used | Definition |
|---|---|
| Virtual Processor | |
| GCC |  |
| Visual Studio Code (VS code) |  |
### 2. Project Overview

The aim of this document is to furnish a thorough functional specification for the Virtual Processor Project of Team 7. This endeavor encompasses the development of a virtual processor tailored to execute assembly code. The processor will be crafted using the C programming language.

### 3. Project Definition

#### ➭ Vision

The fundamental objective of this project is to design and implement a virtual processor capable of executing assembly code. This vision revolves around the creation of a minimalist assembly language specific to the virtual processor, meeting the requirements defined in the call for tenders. The assembly language thus defined will comprise a series of key instructions, including the storage of immediate values in registers, memory manipulation, basic arithmetic and logic operations, and flow control mechanisms.

#### ➭ Objectives

- Design a minimalist assembly language for the virtual processor, respecting the instructions specified in the call for tenders.
- Implement a C language program capable of reading a text file containing programs written in the defined assembly language.
- Validate the syntax of assembly programs to guarantee their semantic validity.
- Set up virtual system calls to display text in a virtual terminal, enabling visualization of assembly code execution.
- Integrate debugging functions, such as display of register contents, to facilitate the development and verification of assembly code.

#### ➭ Scope

| In Scope |
|---|
| Design of a Virtual Processor |
| Minimalist Assembly Language |
| Implementation of an Interpreter |
| Syntax Validation |
| Debugging Features |

| Out of Scope |
|---|
| Compatibility with high-level languages |
| Dive deeper in Assembly |

#### ➭ Deliverables

| Name | Type | Deadline |
|---|---|---|
| Functional Specifications Document | Document (markdown) | 01/30/2024 |
| Technical Specifications Document | Document (markdown) | 02/09/2023 |
| Weekly Reports | Document (markdown) | Every Friday |
| Test Plan | Document (markdown) | 02/16/2024 |

### 4. Project Organisation

#### ➭ Stakeholders

The stakeholders in this project will be: 
- **_Franck JEANNIN_**
- *The 7 members of our team.*

#### ➭ Project Roles

| Role | Description | Name | Image | Link |
|---|---|---|---|---|
| Project Manager | Manages organization, planning, and budgeting while ensuring the team remains motivated. | Mattéo LEFIN|  <img src="https://avatars.githubusercontent.com/u/146164921?v=4" width="75px">      | [Matteo\'s Github Profile](https://github.com/Mattstar64) |
| Program Manager | Ensures the project meets expectations, oversees the design, and takes responsibility for writing the Functional Specifications. | Gaël MALVAR | <img src="https://avatars.githubusercontent.com/u/146000851?v=4 " width="75px"> | [Gaël\'s Github Profile](https://github.com/Gael-MALVAR) |
| Tech Lead | Leads technical decision-making in the project, translates the Functional Specifications into Technical Specifications | Robin DEBRY |<img src="https://avatars.githubusercontent.com/u/91249812?v=4" width="75px"> | [Robin\'s Github Profile](https://github.com/robin-debry) |
| Software Engineers | Codes the software. | David CUAHONTE CUEVAS | <img src="https://avatars.githubusercontent.com/u/91249658?v=4" width="75px"> | [David\'s Github Profile](https://github.com/DavidCC812) |
| Software Engineers | Codes the software. | Camille GAYAT  |<img src="https://avatars.githubusercontent.com/u/145991254?v=4" width="75px"> | [Camille\'s Github Profile](https://github.com/CamilleGayat) |
| Quality Assurance | Conducts comprehensive testing of product functionalities to identify and address bugs and issues. Documents identified bugs and issues, creates the test plan, and verifies the resolution of reported problems after they have been fixed. | Abderrazaq MAKRAN |<img src="https://avatars.githubusercontent.com/u/145991267?v=4" width="75px"> | [Abderrazaq\'s Github Profile](https://github.com/Amakran2003) |
| Quality Assurance | Conducts comprehensive testing of product functionalities to identify and address bugs and issues. Documents identified bugs and issues, creates the test plan, and verifies the resolution of reported problems after they have been fixed. | Raphaël PROUDHON | <img src="https://avatars.githubusercontent.com/u/146000634?v=4" width="75px"> | [Raphaël\'s Github Profile](https://github.com/raproudhon) |


#### ➭ Project Reviewers

The project evaluators, responsible for the in-depth review and approval of important deliverables, will be the two dedicated Quality Assurance (QA) members of the team. Their role will be to:

- Guarantee the quality of the code, the semantic validity of the assembler programs
- Check that the virtual processor's functionalities meet the criteria specified in the [Functional Requirements](#c-functional-requirements).

### 5. Project Plan

#### ➭ Retroplanning

![image retroplanning](retroplanning.png)

#### ➭ Milestones

| Milestone | Deadline|
|---|---|
| Functional Specifications v1 | 01/24/2024 |
| Technical Specifications v1 | ../../2024 |
| Test Plan | ../../2024 |
| Working Prototype | ../../2024 |
| Oral Presentation | 02/29/2024 |

#### ➭ Resources/Financial plan

##### ★ Human Resources

The team is made up of the **7 members** mentioned above in [Project roles](#-project-roles)

The project lasts **8 weeks**:

In this time frame, we have **28 half-days** of project work (**3.5 hours** per half-day).
This means we have **686 manhours**.

##### ★ Development Tools

- Use of the **C language** with the **GCC compiler**.
- Code editing with **Visual Studio Code**.

Two different machines are available:
- **MacBook Air 13″** running on **macOS Venture**.
- **ThinkBook 14 G4 IAP** running on **Windows 11**.

##### ★ Associated costs

No special costs are anticipated, as all materials are provided by the school.

#### ➭ Assumptions/Constraints

##### ★ Team member availability

The team will be available throughout the project to work during assigned hours.

##### ★ Time constraints

Deadlines are in place for the delivery of documents ([Deliverables](#-deliverables)) such as Functional Specifications, Technical Specifications and the Test Plan. 
In addition, deadlines are set for the overall completion of the project. These time constraints must be carefully respected to ensure steady progress and timely delivery of deliverables.

## C. Functional Requirements

### 1. System Capabilities

#### ➭ 1.1 Data Handling:

The assembly language instructions should enable smooth manipulation of data, including:

**<u>Writing data between a register and:</u>**
- An immediate value (a constant).
- Another register.
- The memory (RAM).
- The virtual keyboard/display.


#### ➭ 1.2 Calculations:
**<u>The assembly language needs to provide essential support for mathematical and logical operations, including:**</u>

- The four fundamental mathematical operations: addition, subtraction, multiplication, division.
- The four basic logical operations: NOT, AND, OR, XOR.

#### ➭ 1.3 Branching:

**<u>The programming language should facilitate effective branching by enabling:**</u>

- Comparisons between registers and values.
- Conditional and unconditional jumping.
- Calling and returning from subroutines.

#### ➭ 1.4 Platform Independence:

The interpreter should showcase the ability to be compiled and executed on any real computer architecture. To ensure portability, it should refrain from relying on external libraries beyond standard ones, and any usage of operating system-specific libraries must have viable alternatives.

#### ➭ 1.5 Error Handling and Detection:

The interpreter is required to incorporate robust error-handling mechanisms, capable of detecting syntactical errors such as invalid lines or parameters. In the event of an error, the interpreter should gracefully halt the program and notify the user.

### 2. Assembly Language

#### ➭ Instructions

**<u>1. Storing an immediate value into a register:</u>**

- **Syntax:** **`MOV immediate_value, destination_register`**
- **Example:** **`MOV 42, R1`**
  
**<u>2. Copying the value of a register into another register:</u>**

- **Syntax:** **`MOV source_register, destination_register`**
- **Example:** **`MOV R1, R2`**  
  
**<u>3. Reading the value of the memory at the address contained by a register and storing it into another register:</u>**

- **Syntax:** **`LOAD address_register, destination_register`**
- **Example:** **`LOAD R3, R4`**

**<u>4. Storing the value of a register into memory at the address contained by another register:</u>**

- **Syntax:** **`STOR source_register, address_register`**
- **Example:** **`STOR R2, R5`**

**<u>5. Comparing the content of registers:</u>**

- **Syntax:** **`COMP source_register1, source_register2`**
- **Example:** **`COMP R1, R2`**

**<u>6. Jumping unconditionally to a label:</u>**

- **Syntax:** **`JUMP label`**
- **Example:** **`JUMP start_loop`**

**<u>7. Jumping conditionally to a label:</u>**

- **Syntax:** **`JUMP_IF condition, label`**
- **Example:** **`JUMP_IF NOT_ZERO, end_loop`**

**<u>8. Calling a subroutine:</u>**

- **Syntax:** **`CALL subroutine_label`**
- **Example:** **`CALL my_subroutine`**

**<u>9. Returning from a subroutine:</u>**

- **Syntax:** **`RETURN`**
- **Example:** **`RETURN`**

**<u>10. The 4 basic arithmetic operations: addition, subtraction, multiplication, and division:</u>**

- **Addition:** **`ADD source_register1, source_register2, destination_register`**
- **Subtraction:** **`SUB source_register1, source_register2, destination_register`**
- **Multiplication:** **`MUL source_register1, source_register2, destination_register`**
- **Division:** **`DIV source_register1, source_register2, destination_register`**

**<u>11. The 4 basic logical operations: OR, AND, XOR, and NOT:</u>**

- **OR operation:** **`OR source_register1, source_register2, destination_register`**
- **AND operation:** **`AND source_register1, source_register2, destination_register`**
- **XOR operation:** **`XOR source_register1, source_register2, destination_register`**
- **NOT operation:** **`NOT source_register, destination_register`**

**<u>12. Ending a program:</u>**

- **HLT:** **`HLT`**

**➭ Note**

- **Registers are denoted by **`R`** followed by a number (e.g., **`R1`**, **`R2`**).**
- **Labels are alphanumeric identifiers for program locations (e.g., **`start_loop`**, **`my_subroutine`**).**
- **Conditional jumps can be based on conditions like **`ZERO`**, **`NOT_ZERO`**, **`NEGATIVE`**, **`POSITIVE`**, etc.**
- **The exact syntax and details may vary based on specific design choices and requirements for the processor architecture. This is a simplified example to get you started.**

#### ➭ Example of use

**<u>Assembly program to add two numbers and store the result</u>**

```
; Memory layout
; Memory location 100: First operand
; Memory location 101: Second operand
; Memory location 102: Result

; Start of the program

LOAD R1, 100       ; Load the first operand into register R1
LOAD 101, R2       ; Load the second operand into register R2

ADD R1, R2, R3     ; Add the contents of R1 and R2, store result in R3

STOR R3, 102       ; Store the result in memory location 102

JUMP end_program   ; Jump to the end of the program

end_program:
HLT                ; Halt the program


; Subroutine to perform multiplication

my_subroutine

LOAD R4, 100       ; Load the first operand into register R4
LOAD R5, 101       ; Load the second operand into register R5
MUL R4, R5, R6     ; Multiply the contents of R4 and R5, store result in R6

STOR R6, 102       ; Store the result in memory location 102

RETURN             ; Return from the subroutine
```

## D. Non-Functional Requirements
