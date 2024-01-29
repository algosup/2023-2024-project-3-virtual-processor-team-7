<h2><u><strong>Weekly report project 3: "Virtual processor". Week 3 (22nd of january to 26th of january).</strong></u>

--------------------------------------------
<h3>Overview</h3>
During this week, we principaly focused on the functional specification to create a first prototype of it for wednesday and send it to the client so we can correct or modify it for the final deadline.
<br>
<br>
For this we had to produce a new and functional assembly language, we firstly documented it on the notion all the information about our assembly language (and if we respected all the instruction from the client) and then we replaced it in our functional specification.
<br>
<br>
we also prepared the template for the test plan so the QA's would just have to jump right in the test.

------
<h3>Achievements</h3>

<h4>Monday</h4>

<h5>organisation plan</h5>

On monday, we firstly done a plan of how we organize our represitory :

![Alt text](/documents/management/image/Screenshot%202024-01-22%20at%2016.15.00.png)
*Represitory organisation.*

![Alt text](/documents/management/image/Screenshot%202024-01-22%20at%2016.15.24.png)
*The test part of the represitory.*

<h5>The functional</h5>

The functional already have the big lines in the table of content and and a third of the content itself, it just miss sub parts.

![Alt text](/documents/management/image/ToC_v1.png)
*First version of the Table of Content.*

![Alt text](/documents/management/image/Functional2.png)
*Introduction of the Functional, it include the Glossary, the project overview and definition (including our vision and objectives on this project) and finally, the scope and out of scope of the project.*

![Alt text](/documents/management/image/Functional3.png)
*Project scope, out of scope and deliverables*

![Alt text](/documents/management/image/Functional4.png)
*the project reviewvers*

<h5>Assembly Program</h5>

Our team started coding by defining in C language the different instructions and different register and initialize the [CPU (Central Processing Unit).](#-glossary)
![Alt text](/documents/management/image/Dev1.png)
*we defined the instruction of assembly using C language.*
![Alt text](/documents/management/image/Dev2.png)
*intialization of the CPU*

<h5>Technical Specification</h5>

The Technical sepecification include the folder organisation but also developement environment and an explaination of the program structure in details.

![Alt text](/documents/management/image/technical2.png)
*A part of the development environment*

![Alt text](/documents/management/image/technical3.png)
*A part of the data structure*

<h5>Test Plan</h5>

we decided to create a template for Bug reports and Test cases.

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
*A part of the list of assembly instruction*


<h5>Assembly</h5>

Our team managed to produce a functional readable instruction .

![Alt text](/documents/management/image/Dev4.png)
*A part of the reading program which only include the program getting the size of the assembly file and read the file.*


![Alt text](/documents/management/image/Dev3.png)
*Functional instruction MOV_IMM*

![Alt text](/documents/management/image/Dev5.png)
*Exemple we used to test out the instruction, there's three registers R1,R2 and R3 and they have 42, 0 and 0 in it*

<h5>Test Plan</h5>

![Alt text](/documents/management/image/TP3.png)
*part of the updates of the test Plan*

<h4>Wednesday & Thursday</h4>

<h5>Functional Specification</h5>

We added  System Capabilities for writing data, calculations and more.

![Alt text](/documents/management/image/Functional8.png)
*A part of the System Capabilities*

<h5>Test Plan</h5>
The test plan has been continued, adding graphs like the Entry and Exit Criteria graph.

![Alt text](/documents/management/image/TP4.png)
*Entry and Exit Criteria*

<h5>Programming</h5>

We progressed a lot and done a lot of assembly instructions and we also coded a functional reader.

![Alt text](/documents/management/image/Dev6.png)
*A part of the reader program*

![Alt text](/documents/management/image/Dev7.png)
*Some Assembly instructions that has been finished*



<h5>Meeting with the Client</h5>

For the next parts of the project, we needed crucial information like, do we have to just interpret with C the text files containing the assembly instruction or do we need to transform this text files into machine code and so Interpret it after ? 
It turned that it was the case 2 and that it doesn't mean we have to star all over again, it just had a bit more work.


<h4>Friday</h4>

<h5>Functional Specification</h5>
The functional is almost finished, we added some definition of the original libraries of the C language and added some definitions to the glossary.

![Alt text](/documents/management/image/Functional9.png)
*Some the C language original libraries*

![Alt text](/documents/management/image/Functional10.png)
*A part of the updated glossary*

<h5>Program</h5>

The assembly part of the project has been finished and now we are focusing more on the C language

-------------------------------
<h3>Project Planning and management</h3>


<h5>KPI'S management </h5>

| KPI's   | Progress |
| -------- | ------- |
| Functional specification  | 92%   |
| Technical specification | 15%   |
| Test Plan| 35%   |
| Assembly developpment | 100%   |
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