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
        - [Workflow](#workflow)
        - [Coding conventions](#coding-conventions)
        - [Commenting conventions](#commenting-conventions)
        - [Documents conventions](#documents-conventions)
        - [Test-Driven Development](#test-driven-development)
      - [Assumptions and constraints](#assumptions-and-constraints)

</details>

## 1. Introduction

### Document Purpose & Definition

The goal of the Technical Specifications is to take the Functional Requirements which defines the features, scope and goals of the project, to dissect each requirement and turn it into instructions, as clear as possible, to guide the development team as well as the quality assurance team in the successful completion of their mission.

We therefore encourage thorough reading of the [Functional Specifications](../functional/functionalSpecifications.md) before further reading.

The goal of the Technical Requirements is to clarify as many dark areas as possible to avoid the engineers making decisions
In a sense, while the Functional Requirements represent the "What/Why" aspect of the project, the Technical Requirements are supposed to represent the "How" of the project.

With that being said, we will try to cover as many functional and non-functional aspects of the project while making technological and architectural decisions, evaluating those decisions, measuring their associated risks and impact (providing mitigation) and compare those to other potential solutions.

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

##### Workflow

The development team started to work on the basic features of the project such as the basic logical operation, the basic arithmetic operation using these instructions

- ADD to make an addition.
- SUB to make a substraction.
- MUL to make a multiplication.
- DIV to make a division.

Once the Functional Specifications are dissected in the Technical Specifications, the functions and features of the project will be assigned to team members and priotised by either the project manager or the tech lead depending on the task.

With each functions and features we will create Github Issues, those issues will be assigned to the team member in charge of the task and will be tracked using the Github Project Board.
We prefer to use the term of ticket more than issues as it is more representative of the work to be done.

Each ticket represents a chunk of work, a bug found, a feature request, an update. This abstraction allows to keep track of many types of tasks, break them down even more and allows to move forward swiftly.

##### Coding conventions

All the code will be written in C language and we will use the C18 standard.
Each functions name will be written in snake_case.
Variable names will be written in camelCase.
All variable will be written at the same place.
All #define will be written in SNAKE_CASE and in uppercase.
All #define will be written at the same place.

##### Commenting conventions

Comment all the functions to explain what they do.

##### Documents conventions

All the documents will be written in Markdown.
All their name will be written in camelCase.

##### Test-Driven Development

We will use the Test-Driven Development methodology to develop our project.
For that we will create Assembly code files that will be used to test our project.
Each assembly code will test a specific part of the project for instance one assembly code will test the basic logical operation, another one will test the basic arithmetic operation and so on.

#### Assumptions and constraints

| Assumption | Constraints |
|---|---|
|The project assumes the use of the C programming language, utilizing the gcc compiler. Visual Studio Code is recommended as the integrated development environment (IDE).|The project aims for portability across different platforms. However, specific platform-dependent features may limit absolute portability.|
