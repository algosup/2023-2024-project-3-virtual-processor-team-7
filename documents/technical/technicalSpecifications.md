# Technical Specifications

| Role | Name | Signature | Date |
|---|---|---|---|
| Project Manager | Mattéo LEFIN|  |  |
| Program Manager | Gaël MALVAR |  |  |
| Tech Lead | Robin DEBRY |  |  |
| Software Developer | David CUAHONTE CUEVAS |  |  |
| Software Developer | Camille GAYAT  |  |  |
| Quality Assurance | Abderrazaq MAKRAN |  |  |
| Quality Assurance | Raphaël PROUDHON |  | |

<details>

<summary>

## Table of Content

</summary>

- [Technical Specifications](#technical-specifications)
  - [Table of Content](#table-of-content)
  - [1. Introduction](#1-introduction)
    - [Document Purpose \& Definition](#document-purpose--definition)
    - [Glossary](#glossary)
    - [Project Overview](#project-overview)
      - [Project Brief](#project-brief)
    - [Setting up the development environment](#setting-up-the-development-environment)
      - [Hardware requirement](#hardware-requirement)
      - [Software requirement](#software-requirement)
      - [Coding methodology](#coding-methodology)
        - [➭ Workflow](#-workflow)
        - [➭ Coding conventions](#-coding-conventions)
        - [➭ Commenting conventions](#-commenting-conventions)
        - [➭ Documents conventions](#-documents-conventions)
        - [➭ Folders conventions](#-folders-conventions)
        - [Test-Driven Development](#test-driven-development)
      - [Assumptions and constraints](#assumptions-and-constraints)
  - [2.Technical Specifications](#2technical-specifications)
    - [Folder Structure](#folder-structure)
    - [Data Structures](#data-structures)
      - [Registers](#registers)
      - [CPU](#cpu)
      - [Instructions](#instructions)

</details>

## 1. Introduction

### Document Purpose & Definition

The goal of the Technical Specifications is to take the Functional Requirements which defines the features, scope and goals of the project, to dissect each requirement and turn it into instructions, as clear as possible, to guide the development team as well as the quality assurance team in the successful completion of their mission.

We therefore encourage thorough reading of the [Functional Specifications](../functional/functionalSpecifications.md) before further reading.

The goal of the Technical Requirements is to clarify as much as possible to avoid the engineers making decisions

With that being said, we will try to cover as many functional and non-functional aspects of the project while making technological and architectural decisions, evaluating those decisions, measuring their associated risks and impact and compare those to other potential solutions.

The document should also benefit other stakeholders and project owners by giving insight into our methodology and may serve as a future reference for maintenance.

### Glossary

| Term | Definition |
|---|---|

### Project Overview

#### Project Brief

As stated in the Functional Requirements, the goal of the project is to create a virtual processor and an interpreter for running assembly code on that processor.

We have been given eight weeks to complete this project.

### Setting up the development environment

We will set up our development environment following the requirements as follow :

#### Hardware requirement

- Computer, the OS used is not important as long as it can run the required software.

#### Software requirement

- Any text editor but [Visual Studio Code](https://code.visualstudio.com/) is recommended.
- [Github](https://github.com/) or any control version system. Our team will use Github for this project especially [Github Desktop](https://desktop.github.com) it will be easier for all team members.
- We use the version 18 of C language called C18 also known as C17 because it is one of the most recent version of C language.
- We use [GCC](https://gcc.gnu.org/) as our compiler.

#### Coding methodology

##### ➭ Workflow

The development team started to work on the basic features of the project such as the basic logical operation, the basic arithmetic operation using these instructions

- ADD to make an addition.
- SUB to make a substraction.
- MUL to make a multiplication.
- DIV to make a division.

Once the Functional Specifications are dissected in the Technical Specifications, the functions and features of the project will be assigned to team members and priotised by either the project manager or the tech lead depending on the task.

For each functions and features the QA's team members will create Github Issues, those issues will be assigned to the team member in charge of the task.
We prefer to use the term of ticket more than issues as it is more representative of the work to be done.

Each ticket represents a chunk of work, a bug found, a feature request, an update. This abstraction allows to keep track of many types of tasks, break them down even more and allows to move forward swiftly.

##### ➭ Coding conventions

- All the code will be written in C language and we will use the C18 standard.
- Each functions name will be written in snake_case.
- Variable names will be written in camelCase.
- All variable will be written at the same place.
- All #define will be written in SNAKE_CASE and in uppercase.
- All #define will be written at the same place.

##### ➭ Commenting conventions

Comment all the functions to explain what they do.

##### ➭ Documents conventions

All the documents will be written in Markdown.
All their name will be written in camelCase.

##### ➭ Folders conventions

All the folders will be written in snake_case.

##### Test-Driven Development

We will use the Test-Driven Development methodology to develop our project.
For that we will create Assembly code files that will be used to test our project.
Each assembly code will test a specific part of the project for instance one assembly code will test the basic logical operation, another one will test the basic arithmetic operation and so on.

#### Assumptions and constraints

| Assumption | Constraints |
|---|---|
|The project assumes the use of the C programming language, utilizing the gcc compiler.|The project aims for portability across different platforms. However, specific platform-dependent features may limit absolute portability.|

## 2.Technical Specifications

### Folder Structure

In each headers file we will write the prototype of the functions you used.

**`/interpreter`** Contains all the files related to the interpreter.

`main.c` Core of the project, contains the main function.

**`interpreter/headers`** Contains all the header files such as :

`cpu.h` Header file for the functions related to the Central Processing Unit(CPU).

`storeImm.h` Header file for the functions related to store an immediate value in a register.

`copy.h` Header file for the functions related to copy a register value to another register.

`load.h` Header file for the functions related to load a value from memory into a register.

`storeAddr.h` Header file for the functions related to store the value of a register into memory address.

`compare.h` Header file for the functions related to compare two values.

`jump.h` Header file for the functions related to jump with or without condition.

`subroutine.h` Header file for the functions related to call a subroutine and return from a subroutine.

`arithm.h` Header file for the functions related to arithmetic operations.

`logic.h` Header file for the functions related to logical operations.

**`/documents`** Contains all the documents related to the project in subfolders such as :

**`documents/Functional`** Contains all the documents related to the functional specifications such as :

`functionalSpecifications.md` Contains the functional specifications.

**`documents/functional/images`** Contains all the images for the functional specifications.

**`documents/technical`** Contains all the documents related to the technical specifications such as :

`technicalSpecifications.md` Contains the technical specifications.

**`documents/technical/images`** Contains all the images for the technical specifications.

**`Documents/Management`** Contains all the documents related to the management of the project such as :

`notion.md` Contains all the information about the project such as the KPI's, the gantt chart, the task list and the weekly reports.

**`documents/management/images`**Contains all the images for the management documents.

**`documents/management/WeeklyReport`** Contains all the weekly reports such as :

`weeklyReport1.md` Contains the weekly report 1.

`weeklyReport2.md` Contains the weekly report 2.

`weeklyReport3.md` Contains the weekly report 3.

`weeklyReport4.md` Contains the weekly report 4.

`weeklyReport5.md` Contains the weekly report 5.

`weeklyReport6.md` Contains the weekly report 6.

`weeklyReport7.md` Contains the weekly report 7.

`weeklyReport8.md` Contains the weekly report 8.

**`/qa`** Contains all the files related to the quality assurance which contains:

`testPlan.md` Contains the test plan.

**`/qa/template`**  Contains all the files related to the quality assurance template which contains:

`testCases.yml` Contains the template to create a test case.

`bugReport.yml` Contains the template to create a bug report.

**`/test`** Contains all the files related to the test which contains all the assembly code files like :

`testMain.asm` Contains a complex assembly with multiple function to ensure that is working as intended.

`testCpu.asm` Contains the assembly code to test the CPU.

`testStoreImm.asm` Contains the assembly code to test the store immediate value in a register.

`testCopy.asm` Contains the assembly code to test the copy of a register value to another register.

`testLoad.asm` Contains the assembly code to test the load of a value from memory into a register.

`testStoreAddr.asm` Contains the assembly code to test the store of the value of a register into memory address.

`testCompare.asm` Contains the assembly code to test the compare of two values.

`testJump.asm` Contains the assembly code to test the jump without condition.

`testJumpCond.asm` Contains the assembly code to test the jump with condition.

`testCall.asm` Contains the assembly code to test the call of a subroutine.

`testReturn.asm` Contains the assembly code to test the return from a subroutine.

`testArithm.asm` Contains the assembly code to test the arithmetic operations.

`testLogic.asm` Contains the assembly code to test the logical operations.

``` folder

|-- 2023-2024-project-3-virtual-processor-team-7 (root)
|   |-- interpreter
|   |   |-- headers
|   |   |-- main.c
|   |-- documents
|   |   |-- functional
|   |   |   |-- images
|   |   |   |   |-- functional1.png
|   |   |   |-- functionalSpecifications.md
|   |   |-- management
|   |   |   |-- images
|   |   |   |   |-- notion1.png
|   |   |   |-- notion.md
|   |   |   |-- weeklyReport
|   |   |   |   |-- weeklyReport1.md
|   |   |   |   |-- weeklyReport2.md
|   |   |   |   |-- weeklyReport3.md
|   |   |   |   |-- weeklyReport4.md
|   |   |   |   |-- weeklyReport5.md
|   |   |   |   |-- weeklyReport6.md
|   |   |   |   |-- weeklyReport7.md
|   |   |   |   |-- weeklyReport8.md
|   |   |-- technical
|   |   |   |-- images
|   |   |   |   |-- technical1.png
|   |   |   |-- technicalSpecifications.md
|   |-- qa
|   |   |-- template
|   |   |   |-- bugReport.yml
|   |   |   |-- testCases.yml
|   |   |-- testPlan.md
|   |-- test
|   |-- .gitignore
|   |-- README.md
|   |-- LICENSE
```

### Data Structures

#### Registers

We will use 3 registers to store the data :

- R1
- R2
- R3

To implement them we will use a typedef enum.

``` c
typedef enum {
    R1,
    R2,
    R3,
    R4,
    R5,
    R6
} Register;
```

it will be easier to use them in the functions.

#### CPU

We will use a struct to implement the CPU.
The CPU will have 6 registers, a memory of 100 bytes, a program counter, a stack and a stack pointer.

``` c

typedef struct {
    int registers[6]; 
    char memory[MEMORY_SIZE][100]; 
    int program_counter;
    int stack[MEMORY_SIZE];
    int stack_pointer;
} CPU;

```

#### Instructions

According to the [Functional Specifications](../functional/functionalSpecifications.md) we will use 17 instructions to implement them we will use a typedef enum with their name but only the first 4 characters and only in uppercase.

[⬆️ Back to top](#table-of-content)
