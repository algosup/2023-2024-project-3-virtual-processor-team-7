<h2><u><strong>Weekly report project 3: "Virtual processor". Week 3 (22nd of january to 26th of january).</strong></u>

--------------------------------------------
<h3>Overview</h3>
During this week, we mainly focused on the functional specifications. The objective was to create a first prototype of it for Wednesday and to then send it to the client.
<br>
<br>
To do this we had to produce a new and functional assembly-like language, we firstly documented  on the notion all the information about our assembly language (to verify if we respected all of the instructions from the client) and then we replaced it in our functional specifications.
<br>
<br>
we also prepared the template for the test plan, that way the QA's will be able to jump right in the testing process.

------
<h3>Achievements</h3>

<h4>Monday</h4>

<h5>Organization plan</h5>

On monday, we firstly did a plan related to the organization of our repository :

![Alt text](/documents/management/image/Screenshot%202024-01-22%20at%2016.15.00.png)
*Repository organization.*

![Alt text](/documents/management/image/Screenshot%202024-01-22%20at%2016.15.24.png)
*The test part of the repository.*

<h5>The Functional specifications</h5>

The Functional Specifications are advancing smoothly, they already have a table of content and a third of the content itself, it's missing the sub-parts.

![Alt text](/documents/management/image/ToC_v1.png)
*First version of the Table of Content.*

![Alt text](/documents/management/image/Functional2.png)
*Introduction of the Functional, it includes the glossary, the project overview and definition (including our vision and objectives on this project) and finally, the scope and out of scope of the project.*

![Alt text](/documents/management/image/Functional3.png)
*Project scope, out of scope and deliverables*

![Alt text](/documents/management/image/Functional4.png)
*the project reviewers*

<h5>Assembly Program</h5>

Our team started coding by defining in C language the different instructions and different registers to initialize the [CPU (Central Processing Unit).](#-glossary)
![Alt text](/documents/management/image/Dev1.png)
*We defined an instruction of assembly using C language.*
![Alt text](/documents/management/image/Dev2.png)
*Intialization of the CPU*

<h5>Technical Specifications</h5>

The Technical Specifications include the folder organization but also the development environment and a detailed explanation of the structure of the program.

![Alt text](/documents/management/image/technical2.png)
*A part of the development environment*

![Alt text](/documents/management/image/technical3.png)
*A part of the data structure*

<h5>Test Plan</h5>

We decided to create a template for Bug reports and Test cases.

![Alt text](/documents/management/image/TP1.png)
*Test case template*

![Alt text](/documents/management/image/TP2.png)
*Bug Report template*

<h4>Tuesday</h4>

<h5>The functional</h5>
The functional has been greatly advanced. We were able to give a list of all our assembly instructions and we continued the missing parts of our functional.

![Alt text](/documents/management/image/Functional6.png)
*A part of the functional requirements*

![Alt text](/documents/management/image/Functional7.png)
*A part of the list of our assembly instruction*


<h5>Program</h5>

Our team managed to produce a function that can detect the size and read the contents of the files, they have also done the first instruction: MOV_IMM.

![Alt text](/documents/management/image/Dev4.png)
*A part of the reading program which only include the program getting the size of the assembly file and read the file.*

![Alt text](/documents/management/image/Dev3.png)
*Functional instruction MOV_IMM*

![Alt text](/documents/management/image/Dev5.png)
*Example we used to test out the instruction, there's three registers R1,R2 and R3 and they have 42, 0 and 0 in it*

<h5>Test Plan</h5>

![Alt text](/documents/management/image/TP3.png)
*part of the updates of the test Plan*

<h4>Wednesday & Thursday</h4>

<h5>Functional Specification</h5>

We added  System Capabilities to write data, calculations and more.

![Alt text](/documents/management/image/Functional8.png)
*A part of the System Capabilities*

<h5>Test Plan</h5>
The test plan has been continued, adding graphs like the Entry and Exit Criteria graph.

![Alt text](/documents/management/image/TP4.png)
*Entry and Exit Criteria*

<h5>Programming</h5>

We progressed in the instructions and we also coded a functional reader.

![Alt text](/documents/management/image/Dev7.png)
*Some Assembly instructions that we have*

![Alt text](/documents/management/image/Dev6.png)
*A part of the reader program*

<h5>Meeting with the Client</h5>

To keep advancing on the project, we needed crucial information, that is why we had a meeting with the client were we clarified some questions we had like: Do we need to interpret with C the text files containing the assembly-like instructions or do we need to transform this text files into machine code and then interpret it after?

It turned out that it was the second case and that it doesn't mean we have to start all over again, it just means that we have more work to do.

<h4>Friday</h4>

<h5>Functional Specification</h5>
The functional is almost finished, we added some definitions of the original libraries of the C language and added some definitions to the glossary.

![Alt text](/documents/management/image/Functional9.png)
*Some of the C language original libraries*

![Alt text](/documents/management/image/Functional10.png)
*A part of the updated glossary*

<h5>Program</h5>

The assembly-like part of the project should be finished soon and now we are focusing more on the C language.

-------------------------------
<h3>Project Planning and management</h3>


<h5>KPI'S management </h5>

| KPI's   | Progress |
| -------- | ------- |
| Functional specification  | 92%   |
| Technical specification | 15%   |
| Test Plan| 35%   |
| Assembly-like developpment | 100%   |
| C language developpment | 30%  |
| Weekly report  | 45%   |

<h5>Project Charter</h5>

A project charter has been created to explain who we are and the purpose of the project.

![Alt text](/documents/management/image/PC.png)
*A part of the Project Charter*

<h5>RACI MATRIX</h5>

A RACI Matrix has been created for having a quick vision of which members of the team, clients  and stakeholders roles and responsabilities.

![Alt text](/documents/management/image/RACI.png)
*A part of the RACI Matrix*

<h5>Communication Plan</h5>

A communication plan has been created  even if we only have one stakeholder.

-------
<h3>Glossary</h3>

|Words  | Definition |
| -------- | ------- |
| CPU  | The Central Process Unit is the part of a computer that controls all the other parts   |