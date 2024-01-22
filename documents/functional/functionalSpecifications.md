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
      - [➭ Assumptions/Constraints](#-assumptionsconstraints)
  - [C. Functional Requirements](#c-functional-requirements)
    - [1. Assembly Language](#1-assembly-language)
      - [➭ Instructions](#-instructions)
      - [➭ Operations](#-operations)
  - [D. Non-Functional Requirements](#d-non-functional-requirements)

</details>

---

## A. Document Control

### 1. Document Information

| Document ID | Document # 01 |
|---|---|
| Document Owner | Gaël MALVAR |
| Issue date | 01/22/2024 |
| Last Issue Date | 01/22/2024 |
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
| | |

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
|  |
|  |

#### ➭ Deliverables

| Name | Type | Deadline |
|---|---|---|
| Functional Specifications Document | Document (markdown) | 01/30/2024 |
| Technical Specifications Document | Document (markdown) | 02/09/2023 |
| Weekly Reports | Document (markdown) | Every Friday |
| Test Plan | Document (markdown) | 02/16/2024 |

### 4. Project Organisation

#### ➭ Stakeholders

The stakeholders in this project will be the 7 members of our team.

#### ➭ Project Roles

| Role | Name |
|---|---|
| Project Manager | Mattéo LEFIN|
| Program Manager | Gaël MALVAR |
| Tech Lead | Robin DEBRY |
| Software Engineers | David CUAHONTE CUEVAS |
| Software Engineers | Camille GAYAT  |
| Quality Assurance | Abderrazaq MAKRAN |
| Quality Assurance | Raphaël PROUDHON |


#### ➭ Project Reviewers

The project evaluators, responsible for the in-depth review and approval of important deliverables, will be the two dedicated Quality Assurance (QA) members of the team. Their role will be to:

- Guarantee the quality of the code, the semantic validity of the assembler programs
- Check that the virtual processor's functionalities meet the criteria specified in the [Functional Requirements](#c-functional-requirements).

### 5. Project Plan

#### ➭ Retroplanning

#### ➭ Milestones

#### ➭ Resources/Financial plan

#### ➭ Assumptions/Constraints

## C. Functional Requirements

### 1. Assembly Language

#### ➭ Instructions

#### ➭ Operations

## D. Non-Functional Requirements
