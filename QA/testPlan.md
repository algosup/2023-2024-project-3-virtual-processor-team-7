# Test Plan

<br>

| Authors | Abderrazaq MAKRAN and Raphael PROUDHON |
|---|---|
|Created|01/22/2024|
|Last Updated| 02/16/2024 |
|Status| Finish|

<br>

## Document History

| Version | Date | Author | Description of Changes|
|---|---|---|---|
|1.0| 01/22/2024 | Abderrazaq MAKRAN and Raphael PROUDHON| Create the template  |
|1.01| 01/23/2024|Abderrazaq MAKRAN and Raphael PROUDHON | Add main titles: Introduction, Test strategy, Execution strategy and Test management and start to fill the different parts |
|1.02| 01/24/2024|Abderrazaq MAKRAN and Raphael PROUDHON | Add table of contents and add images |
|1.03| 01/25/2024|Abderrazaq MAKRAN and Raphael PROUDHON | Remake charts with Lucidchart to match the background color with GitHub and fill more content. |
|1.04| 01/26/2024|Abderrazaq MAKRAN and Raphael PROUDHON | Add document review and commenting in Test management part |
|1.05| 01/27/2024|Abderrazaq MAKRAN | Add scopes and levels of testing and modify test cycles |
|2.0| 02/01/2024|Abderrazaq MAKRAN and Raphael PROUDHON| Small review of all the test plan by the QA's and the project manager, modification of poorly written parts  |
|2.01| 02/07/2024|Abderrazaq MAKRAN and Raphael PROUDHON| Change the indentation, the test plan has some preview problem. In parallel, start writing test cases in a draft file |
|2.02| 02/10/2024|Abderrazaq MAKRAN and Raphael PROUDHON| Not much modification, focus on test cases  |
|2.03| 02/12/2024|Abderrazaq MAKRAN and Raphael PROUDHON| Not much modification, focus on test cases |
|2.04| 02/13/2024|Abderrazaq MAKRAN and Raphael PROUDHON| Add schedule estimation and test deliverables in Test management |
|2.05| 02/14/2024|Abderrazaq MAKRAN and Raphael PROUDHON| Pre-release version, review syntax, grammar, spelling errors   |
|3.0 | 02/16/2024 | Abderrazaq MAKRAN and Raphael PROUDHON| Final version, review syntax, grammar, spelling errors   |
|3.0 | 02/16/2024 | Abderrazaq MAKRAN and Raphael PROUDHON| Final version  |

<br>
<details>

## Table of Contents

- [Test Plan](#test-plan)
  - [Document History](#document-history)
  - [Table of Contents](#table-of-contents)
  - [1. GLOSSARY](#1-glossary)
  - [2. INTRODUCTION](#2-introduction)
    - [2.1 Purpose](#21-purpose)
    - [2.2 Project Overview](#22-project-overview)
    - [2.3 Audience](#23-audience)
  - [3. TEST STRATEGY](#3-test-strategy)
    - [3.1 Test Objectives](#31-test-objectives)
    - [3.2 Test Environment](#32-test-environment)
    - [3.3 Test Principles](#33-test-principles)
  - [3.4 Scope and Levels of Testing](#34-scope-and-levels-of-testing)
    - [3.4.1 Define Scope of Testing](#341-define-scope-of-testing)
      - [In scope](#in-scope)
      - [Out scope](#out-scope)
    - [3.4.2 Identify Testing Type](#342-identify-testing-type)
      - [Functional testing](#functional-testing)
      - [Unit testing](#unit-testing)
      - [Agile testing](#agile-testing)
  - [4. EXECUTION STRATEGY](#4-execution-strategy)
    - [4.1 Criteria](#41-criteria)
      - [4.1.1 Entry Criteria and Exit Criteria](#411-entry-criteria-and-exit-criteria)
      - [4.1.2 Suspension Criteria](#412-suspension-criteria)
    - [4.2 Test Cycles](#42-test-cycles)
    - [Two Functional Testing Cycles:](#two-functional-testing-cycles)
    - [4.3 GitHub Issues](#43-github-issues)
    - [4.4 Test Cases](#44-test-cases)
    - [4.5 Validation and Bug Report Management](#45-validation-and-bug-report-management)
    - [4.7 Bug Tracking \& Reporting](#47-bug-tracking--reporting)
  - [5. TEST MANAGEMENT PROCESS](#5-test-management-process)
    - [5.1 Test Management Tool](#51-test-management-tool)
    - [5.2 Test Design Process](#52-test-design-process)
    - [**Understanding Requirements:**](#understanding-requirements)
    - [**Traceability:**](#traceability)
    - [**Test Cases Preparation:**](#test-cases-preparation)
    - [**Test Cases Review:**](#test-cases-review)
    - [**Rework and Approval(comments):**](#rework-and-approvalcomments)
    - [5.3 Schedule Estimation](#53-schedule-estimation)
    - [5.4 Test Deliverables](#54-test-deliverables)
    - [5.5 Document Review and Commenting](#55-document-review-and-commenting)
    - [Importance of Reviewing Documents](#importance-of-reviewing-documents)
    - [Collaborative Learning](#collaborative-learning)
    - [Error Prevention](#error-prevention)
    - [Continuous Improvement](#continuous-improvement)
    - [Guidelines for Document Review](#guidelines-for-document-review)
    - [Document Review Process](#document-review-process)
  - [CONCLUSION](#conclusion)
  - [Test Plan approval](#test-plan-approval)

</details>

## 1. GLOSSARY

<br>

|Term|Definition|Source|
|---|---|---|
|C |C is a general-purpose computer programming language. It was created in the 1970s by Dennis Ritchie, and remains very widely used and influential. By design, C's features cleanly reflect the capabilities of the targeted CPUs.| [Wikipedia](https://en.wikipedia.org/wiki/C_(programming_language))|
|Virtual Processor | A virtual processor is a representation of a physical processor core to the operating system of a logical partition that uses shared processors.| [IBM](https://www.ibm.com/docs/en/power8/8408-44E?topic=processors-virtual)|
|Assembly language| In computer programming, assembly language, often referred to simply as assembly and commonly abbreviated as ASM or asm, is any low-level programming language with a very strong correspondence between the instructions in the language and the architecture's machine code instructions.| [Wikipedia](https://en.wikipedia.org/wiki/Assembly_language)|
| Operating System | An operating system (OS) is system software that manages computer hardware and software resources, and provides common services for computer programs.| [Wikipedia](https://en.wikipedia.org/wiki/Operating_system)|
|IDE: Integrated Development Environment | An integrated development environment is a software application that provides comprehensive facilities for software development. An IDE normally consists of at least a source-code editor, build automation tools, and a debugger. (Visual Studio Code)| [Wikipedia](https://en.wikipedia.org/wiki/Integrated_development_environment)|
|Compiler GCC|The GNU Compiler Collection is an optimizing compiler produced by the GNU Project supporting various programming languages, hardware architectures and operating systems. The Free Software Foundation distributes GCC as free software under the GNU General Public License.| [Wikipedia](https://en.wikipedia.org/wiki/GNU_Compiler_Collection)|
|Test case|In software engineering, a test case is a specification of the inputs, execution conditions, testing procedure, and expected results that define a single test to be executed to achieve a particular software testing objective, such as to exercise a particular program path or to verify compliance with a specific requirement.|[Wikipedia](https://en.wikipedia.org/wiki/Test_case)| 
| Project Manager | A project manager is a professional in the field of project management. Project managers have the responsibility of the planning, procurement and execution of a project, in any undertaking that has a defined scope, defined start and a defined finish; regardless of industry.| [Wikipedia](https://en.wikipedia.org/wiki/Project_manager)|
| Program Manager | He is a strategic project-management professional whose job is to help oversee and coordinate the various projects, products, and other strategic initiatives across an organization.| [ProductPlan](https://www.productplan.com/glossary/program-manager/#:~:text=Definition%3A%20A%20program%20manager%20is,strategic%20initiatives%20across%20an%20organization.) |
| Technical Lead | He oversees the technical aspects of a software team by making architectural and design decisions, guiding team members in technical matters, and supervising system modifications. |[Ironhack](https://www.ironhack.com/gb/blog/what-is-a-tech-lead#:~:text=A%20technical%20lead%20%E2%80%93%20or%20tech,matters%2C%20and%20supervising%20system%20modifications.)|
|Software Engineer | He applies engineering principles and knowledge of programming languages to build software solutions for end users. Software engineers design and develop computer games, business applications, operating systems, network control systems, and middleware—to name just a few of the many career paths available.| [Michigan Technological University](https://www.mtu.edu/cs/undergraduate/software/what/#:~:text=of%20software%20applications.-,Software%20engineers%20apply%20engineering%20principles%20and%20knowledge%20of%20programming%20languages,the%20many%20career%20paths%20available.)|
| QA (Quality Assurance) |A QA engineer creates tests that identify issues with software before a product launch. These tests entail other tasks such as developing and running new tests and reporting their results to stakeholders, who will collaborate to fix program bugs or problems.| [Workable](https://resources.workable.com/qa-engineer-job-description#:~:text=What%20does%20a%20Quality%20Assurance,fix%20program%20bugs%20or%20problems.)|
| Low-level programming | A low-level programming language is a programming language that provides little or no abstraction from a computer's instruction set architecture—commands or functions in the language map that are structurally similar to the processor's instructions. Generally, this refers to either machine code or assembly language.| [Wikipedia](https://en.wikipedia.org/wiki/Low-level_programming_language) |

<br>

## 2. INTRODUCTION

### 2.1 Purpose

  - The purpose of this test plan is to ensure the functionality, reliability, and correctness of the virtual processor and interpreter. The document introduces:
  
    ### **Test Strategy:**

      This section outlines the goals of this test plan, specifying the testing environment and delineating the scope and levels of testing. Articulates the principles guiding the testing process, and categorizes the types of testing involved.

    ### **Execution Strategy:**

      Describe how the tests will be performed, and the process for identifying and reporting bugs.

    ### **Test Management:**

      This section outlines the process for handling the logistics of the test and addressing all events that arise during execution.

### 2.2 Project Overview

- We have been asked to develop a virtual processor and interpreter for running assembly code. This project is open to students eager to delve into low-level programming. Our approach focuses on simplicity, providing straightforward guides to follow. Our ultimate aim? To cultivate a welcoming environment for anyone interested in exploring assembly language and system programming.

### 2.3 Audience

- The primary audience for this test plan includes members of the project team, each with distinct roles:

  - **Technical Team (Technical Lead and Software Engineers):**

    - Responsible for executing tasks outlined in this document.
    - Contribute insights and recommendations regarding the test plan.

  - **Project Manager:**

    - Plans testing activities within the overall project schedule.
    - Reviews, approves, and holds accountability for the test plan.
    - Tracks the performance of the testing activities.

  - **Program Manager**
    - Review and approve the test plan to ensure alignment with the project's objectives.
    - Ensuring that the testing process adheres to established procedures and standards

  - **QA Team Members:**

    - Ensures the test plan and deliverables are consistent with the project's design.
    - Provides the necessary testing environment.
    - Adheres to procedures related to bug fixes and programming.

## 3. TEST STRATEGY

### 3.1 Test Objectives

- This test plan is dedicated to thoroughly evaluating the virtual processor and interpreter in our project, with a strong emphasis on functionality, reliability, and correctness. Our objectives include validating the precise execution of assembly code, assessing the reliability of the virtual processor across various scenarios, and ensuring accurate results from the interpreter. In addition to technical validation, we prioritize educational value, by aligning our testing framework with the learning goals for students and developers exploring low-level programming concepts. Clear documentation and guides are provided to ensure accessibility for a wide audience. Through this testing approach, we aim not only to validate technical robustness but also to underscore the project's educational significance in the realm of low-level programming.

### 3.2 Test Environment

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
    - 14-inch (1920 x 1080)
    - Processor: Intel(R) Core(TM) i7-1165G7 CPU @ 2.80GHz
    - RAM: 16.0 GB
    - System type: 64-bit operating system, x64-based processor

  - [ThinkPad E14 Gen 5](https://www.lenovo.com/fr/fr/p/laptops/thinkpad/thinkpade/thinkpad-e14-gen-5-(14-inch-intel)/len101t0064)
    - Windows 11 Pro
    - 14-inch (1920 x 1080)
    - Processor: 13th Gen Intel(R) Core(TM) i7-1355U, 1700 Mhz
    - RAM: 16.0 GB
    - System type: 64-bit operating system, x64-based processor

### 3.3 Test Principles

- Testing will be focused on meeting the objectives and ensuring quality
<br>

- The testing processes will be well defined, yet flexible, with the ability to change as needed.
<br>  

- There will be common, consistent procedures for all teams supporting testing activities
<br>

- Testing activities will be built upon previous stages to prevent redundancy or duplication of effort
<br>

- Testing will be divided into distinct phases, each with clearly defined objectives and goals.
<br>

- We will also perform unit tests for each feature released by the development team
<br>

- We will execute the unit test algorithms developed by the development team.

## 3.4 Scope and Levels of Testing

### 3.4.1 Define Scope of Testing

#### In scope

- Comprehensive testing of each component of the software, including individual instructions.
- Functional testing of all features and functionalities.
- Identification and validation of expected system behavior.
- Testing of various scenarios and inputs to ensure system robustness.

#### Out scope

- Security testing for potential vulnerabilities in the system.
- User acceptance testing (UAT) for assessing user satisfaction.

### 3.4.2 Identify Testing Type

#### Functional testing

Functional testing is a type of software testing that evaluates the functionality of a system or application based on specified requirements. The goal is to ensure that the software performs as expected, focusing on user-facing features and behaviors. Functional testing includes various types such as unit testing, integration testing, system testing, and user acceptance testing. The primary emphasis is on verifying that the software's features align with defined requirements.

#### Unit testing

Unit testing is a type of software testing where individual components or units of a program, such as functions or methods, are tested in isolation to ensure they work as intended. It involves automated, fast, and repeatable tests to catch defects early in the development process. Unit testing is fundamental for ensuring the reliability and maintainability of software.

#### Agile testing

Agile testing aligns with Agile development principles, emphasizing continuous feedback, collaboration, iterative testing, test automation, and adaptability to deliver high-quality software in a dynamic and iterative development environment.

## 4. EXECUTION STRATEGY

### 4.1 Criteria

#### 4.1.1 Entry Criteria and Exit Criteria

- Entry criteria define the conditions that must be fulfilled before the testing process can commence. These criteria act as prerequisites and ensure that the testing environment is ready for effective and meaningful testing. Entry criteria typically include aspects such as:
  - **The availability of the test environment**
  - **Completion of necessary documentation**
  - **Readiness of unit test**
  - **The successful completion of any prerequisite testing phases.**

Adhering to entry criteria helps ensure efficient testing and that the results obtained are reliable.

  <p float="left">
  <img src="Images/entryExitCriteria.png" width="700" />

- Exit criteria, on the other hand, establish the conditions that must be met for testing to be considered complete and successful. They determine when testing activities can be concluded and the software can move to the next phase or be released. Exit criteria may include factors such as:

  - **Achieving a certain level of test coverage**

  - **The successful execution of test cases, and the resolution of critical bugs**

  - **The commitment of the whole code on the Github repository**
  
  Meeting exit criteria is crucial for making informed decisions about the readiness of the software for the next phase.

#### 4.1.2 Suspension Criteria

- The purpose of implementing suspension criteria is to avoid unnecessary expenditure of effort and resources. When testing faces impediments such as bugs or other obstacles that hinder effective progress, it is prudent to temporarily halt testing activities until these issues are addressed. This strategic pause optimizes the utilization of testing resources and contributes to maintaining the precision and validity of test results.
      <p float="left">
      <img src="Images/suspensionCriteria.png" width="700" />

### 4.2 Test Cycles

 **Functional Testing Cycles:** These cycles focus on ensuring that the software functions as expected. The first cycle addresses critical issues, and the second cycle aims to refine the system performance and collect additional data.

### Two Functional Testing Cycles:

- **First Cycle:**

  - **Objective:** Identify critical bugs, including any high-priority issues that may block basic functionality
  - **Approach:** Use workarounds if necessary to execute all test cases.
  - **Focus:** Prioritize the discovery of showstopper issues that could impede fundamental functionality
- **Second Cycle:**
  - **Objective:** Address remaining high and medium-priority bugs, eliminate workarounds from the first cycle, refine test cases, and gather performance data.
  - **Approach:** Resolve issues identified in the first cycle, with particular attention to medium-priority bugs.
  - **Focus:** Conduct a comprehensive testing phase, ensuring the resolution of bugs and optimal system performance.

 <br>

### 4.3 GitHub Issues

   GitHub Issues is a built-in issue-tracking tool that allows us to create and manage issues and assign them to team members.

   We define:

- **bugs:** Unexpected problems or code errors.
- **Errors:** Includes all errors that do not originate in the code.
- **Deadlines:** Specific project stage deadlines to ensure timely delivery.
- **Documentation:** Request for documentation on a specific function or group of functions in the code.
- **Task allocation:** Assignment and tracking of specific responsibilities.
  <br>

### 4.4 Test Cases

   To ensure comprehensive testing of all features and thorough identification of potential bugs, test cases will be generated using GitHub Issues as a collaborative tool. This approach facilitates clear visibility for QA's team members, outlining what needs testing and tracking the testing progress.Additionally, it serves as a centralized platform for the entire team to stay informed about pending features or those yet to be implemented
  <br>
  
  A standardized template for creating these tickets has been formulated and is accessible in the file. Inside `.github` folder, providing consistency and structure to the testing process:
  <p float="left">
  <img src="Images/testCase.png" width="700" />

- To enhance clarity, each test case will be meticulously crafted and documented within GitHub Issues, designated with the label "Test Case."
- This ensures that every team member can readily comprehend the testing requirements.
  
- Assignees for these test cases will include both QA team members and software engineers.

  | Severity |Importance|
  |----------|----------|
  |1 (Critical) |Core business processes|
  |2 (High) |Major functionalitie|
  |3 (Medium) |Secondary features|
  |4 (Low) |Minor features with minimal impact|
  
### 4.5 Validation and Bug Report Management

- The bugs will be tracked through tickets on GitHub issues only. Software engineers will gather information on a daily basis from GitHub, and request additional details from the project manager and the QA team. Software Engineers will work on fixes. The title must be clear and explicit so that everyone can understand what bug it is. Each bug report will be created on GitHub issues with the label "bug". The people in charge of resolving the bug will be set as assignees.
  <br>
  
  - A template for those tickets has been created :
  <p float="left">
  <img src="Images/bugReport.png" width="700" />

  - It is the QA team's responsibility to open a bug report, link it to the corresponding test case, assign an initial severity, retest and close the bug.

  - It is the Project Manager and Technical Lead's responsibility to review the severity of the bugs and facilitate with the software engineers team the fix and its implementation, communicate with the QA team when the test can continue or should be halted, request the QA team to retest, and modify status as the bug progresses through the cycle.

  - It is Software Engineers responsibility to review the bug report on a daily basis, ask for details if necessary, fix the bug, communicate to the Project Manager and Technical Lead the fix is done.
  
  - bug found during the testing will be categorized according to the bug reporting template implemented directly on GitHub issues and the categories are:

 | Severity | Impact |
 |---|---|
 |1 (Critical) | - This bug is critical enough to crash the system, cause file corruption, or cause potential data loss. <br> - It causes an abnormal return to the operating system (crash or a system failure message appears). <br> - It causes the application to hang and requires re-booting the system.|
 |2 (High) | -It causes a lack of vital program functionality with workaround.|
 |3 (Medium) |- This bug will degrade the quality of the System. However there is an intelligent workaround for achieving the desired functionality, for example through another screen. <br> - This bug prevents other areas of the product from being tested. However other areas can be independently tested.|
 |4 (Low) | - There is an insufficient or unclear error message, which has minimum impact on product use.|

### 4.7 Bug Tracking & Reporting

  <p float="left">
  <img src="Images/defectTrackingReporting.png" width="900" />

## 5. TEST MANAGEMENT PROCESS

### 5.1 Test Management Tool

- GitHub issues is the tool used for Test Management. All testing artefacts such as Test cases, test results are updated in the GitHub issues.

- A project specific folder structure will be created in GitHub to manage the project's status.

- Each resource in the team will be provided with Read/Write access to add/modify Test cases.

- During the Test Design phase, all test cases are written directly with the template testcase.yml. Any change to the test case will be directly updated in GitHub issues.
<br>

- Each software engineer will directly access their respective assigned test cases and update the status of each executed step in GitHub issues.
<br>

- Any encountered bugs will be reported in GitHub Issues and linked to the respective test case.
<br>

- During bug fix testing, bugs are reassigned to the QA team for verification of the bug fix. The QA verifies the bug fix and updates the status directly in GitHub issues.
<br>

- Various reports can be generated from GitHub Issues to provide status updates on Test execution. For example, Status report of Test cases executed, Passed, Failed, No. of open Bugs, Severity bugs etc.
  
### 5.2 Test Design Process

<p float="left">
  <img src="Images/TestDesignProcess.png" width="1000" />

This section outlines the process of test case preparation and collaboration between each team member. Here's a breakdown of the key points:

<br>

### **Understanding Requirements:**

- Testers thoroughly understand each requirement specified for the project.

### **Traceability:**

- Each test case is mapped to use cases and requirements, creating traceability in GitHub Issues. This traceability helps establish a clear link between tests and the specific requirements they address.

### **Test Cases Preparation:**

- For each requirement, QA's prepare corresponding test cases to ensure comprehensive coverage.

### **Test Cases Review:**

- Test cases undergo a review process facilitated by the Project Manager or Tech lead. During this review, any identified bug is captured and communicated to the QA's.

### **Rework and Approval(comments):**

- QA's address the review bugs, make necessary revisions to the test cases and seek approval and sign-off from the Project Manager or Tech lead. This iterative process ensures that the test cases align with the project's requirements.

This process emphasizes collaboration, review, and iteration to enhance the quality and accuracy of the test cases, ultimately contributing to the effectiveness of the testing phase.

### 5.3 Schedule Estimation

To span the duration of the project, we have estimated the time required to complete each testing task. The project will last eight weeks, so it is crucial to plan the QA tasks carefully to ensure sufficient time for testing the virtual processor and ensuring its quality.

| Task | Subtask | Time estimation |
|------|---------|-------------|
|Analyse requirement specification| - Review functional specifications - Review technical specification| - 8 hours <br> - 8 hours|
| Create the test specification|  - Create the test plan <br> - Create test cases <br> - Review the test cases|- 48 hours <br> - 16 hours <br> - 4 hours|
|Execute the test cases| - Build up the test environment <br> - Execute the test cases <br> - Update test cases status|- 4 hours <br> - 40 hours <br> - 16 hours|
|Report the bug| - Create bug reports| - 24 hours|

By the project's conclusion, based on this estimation, the QA efforts for this project will amount to a total of 168 hours. <br>

### 5.4 Test Deliverables

- **Test Plan/Test Strategy:** This section outlines the approach and methodology for testing, detailing how various tests will be conducted.
  
- **Test Cases:** This section specifies a comprehensive set of tests designed to ensure the proper functioning of the virtual processor as intended.

- **Bug Reports:** This section documents any identified issues encountered during the testing phase.

### 5.5 Document Review and Commenting

### Importance of Reviewing Documents

Document review is a crucial aspect of our project management process at ALGOSUP. It involves carefully examining the documents created by team members, providing constructive feedback, and ensuring the overall quality and accuracy of project deliverables.

### Collaborative Learning

Reviewing the work of peers, especially across different promotions, promotes collaborative learning. It allows team members to share insights, correct potential errors, and offer diverse perspectives that contribute to the overall improvement of project documentation.

### Error Prevention

By conducting thorough document reviews and leaving comments, we aim to prevent errors before they impact the project. Identifying and rectifying issues during the review process helps maintain the integrity of our work and ensures that final deliverables meet the highest standards.

### Continuous Improvement

Document reviews are not just about error correction, they also serve as opportunities for continuous improvement. Team members can suggest enhancements, share alternative approaches, and collectively strive for excellence in project documentation.

### Guidelines for Document Review

1. **Be Thorough:** Carefully review each document to identify grammatical errors, inconsistencies, or inaccuracies.

2. **Provide Constructive Feedback:** When leaving comments, focus on constructive feedback that helps the document author understand the issue and improve their work.

3. **Encourage Collaboration:** Use document reviews as a platform for collaboration. Encourage discussions and foster an environment where team members feel comfortable seeking and providing feedback.

### Document Review Process

1. **Author Submission:** The document author submits their work for review through the designated platform (e.g., GitHub Issues).

2. **Review and Comment:** Peers review the document thoroughly, leaving comments on specific sections that require attention.

3. **Discussion and Clarification:** Engage in discussions to clarify comments and address any questions raised during the review process.

4. **Revision:** The document author revises the document based on the feedback received.

5. **Final Approval:** Once the document meets the required standards, it receives final approval.

## CONCLUSION

In conclusion, this test plan outlines a robust strategy for ensuring the functionality, reliability, and correctness of our virtual processor and interpreter project.

The thorough Test Strategy, detailed Execution Strategy, and meticulous Test Management Process are tailored to ensure the project's success.

The collaborative efforts of the team members have contributed to the development of a thorough testing approach.

The glossary provides a shared understanding of key terms, and the document history attests to the iterative nature of the testing process.

We appreciate the contributions of all team members, teacher Caroline CORDIER, and ALGOSUP for this valuable opportunity.

Together, we look forward to the successful execution of the testing phase and the overall success of the project.

## Test Plan approval

| Role | Name | Signature | Date |
|---|---|---|---|
| Project Manager | Matteo LEFIN |✅| 02/16/2024|
| Program Manager | Gaël MALVAR |✅|02/16/2024 |
| Tech Lead | Robin DEBRY |✅| 02/16/2024|
| Software Developer | Camille GAYAT |✅|02/16/2024 |
| Software Developer | David CUAHONTE |✅| 02/16/2024|
| Quality Assurance | Raphaël PROUDHON |✅|02/16/2024 |
| Quality Assurance | Abderrazaq MAKRAN |✅|02/16/2024|
