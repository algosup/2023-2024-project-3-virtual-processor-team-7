### Test Case 1: Storing Immediate Value

- **Severity:** Critical
- **Action to Realize:** Execute the assembly code `MOV 42, R1`
- **Expected Result:** Register R1 should contain the value 42.
- **Status:** Not Run

### Test Case 2: Copying Register Values

- **Severity:** Critical
- **Action to Realize:** Execute the assembly code `MOV 10, R2; MOV R2, R3`
- **Expected Result:** Registers R2 and R3 should both contain the value 10.
- **Status:** Not Run

### Test Case 3: Reading and Storing in Memory

- **Severity:** High
- **Action to Realize:** Execute the assembly code `MOV 100, R4; STR R3, R4; LOAD R4, R5`
- **Expected Result:** Register R5 should contain the value stored at memory address 100, which is the value previously stored in R3.
- **Status:** Not Run

### Test Case 4: Comparing Register Equality

- **Severity:** Medium
- **Action to Realize:** Execute the assembly code `MOV 5, R5; MOV 5,R6; CMP R5, R6`
- **Expected Result:** The comparison result should indicate equality.
- **Status:** Not Run

### Test Case 5: Comparing Register Inequality

- **Severity:** Medium
- **Action to Realize:** Execute the assembly code `MOV 4, R5; MOV 5,R6; CMP R5, R6`
- **Expected Result:** The comparison result should indicate inequality.
- **Status:** Not Run

### Test Case 6: Unconditional Jump

- **Severity:** Medium
- **Action to Realize:** Execute the assembly code `JMP start_loop`
- **Expected Result:** The program execution should jump to the "start_loop" label.
- **Status:** Not Run

### Test Case 7: Conditional Jump

- **Severity:** Medium
- **Action to Realize:** Execute the assembly code `JMPT TRUE, end_loop`
- **Expected Result:** If the condition is true, the program execution should jump to the "end_loop" label.
- **Status:** Not Run

### Test Case 8: Subroutine Call and Return

- **Severity:** Medium
- **Action to Realize:** Execute the assembly code `CALL my_subroutine; RET`
- **Expected Result:** The program should successfully call and return from the "my_subroutine" subroutine.
- **Status:** Not Run

### Test Case 9: Addition Operation

- **Severity:** Critical
- **Action to Realize:** Execute the assembly code `MOV 8, R7; MOV 4, R8; ADD R7, R8, R9`
- **Expected Result:** Register R9 should contain the sum of values in R7 and R8 (12).
- **Status:** Not Run

### Test Case 10: Subtraction Operation

- **Severity:** Critical
- **Action to Realize:** Execute the assembly code `MOV 10, R4; MOV 3, R5; SUB R4, R5, R6`
- **Expected Result:** Register R6 should contain the result of subtracting the value in R5 from the value in R4 (7).
- **Status:** Not Run

### Test Case 11: Multiplication Operation

- **Severity:** Critical
- **Action to Realize:** Execute the assembly code `MOV 4, R7; MOV 6, R8; MUL R7, R8, R9`
- **Expected Result:** Register R9 should contain the product of values in R7 and R8 (24).
- **Status:** Not Run

### Test Case 12: Division Operation

- **Severity:** Critical
- **Action to Realize:** Execute the assembly code `MOV 15, R10; MOV 3, R11; DIV R10, R11, R12`
- **Expected Result:** Register R12 should contain the result of dividing the value in R10 by the value in R11 (5).
- **Status:** Not Run

### Test Case 13: Logical OR Operation

- **Severity:** Critical
- **Action to Realize:** Execute the assembly code `MOV 1, R13; MOV 0, R14; OR R13, R14, R15`
- **Expected Result:** Register R15 should contain the result of the logical OR operation between values in R13 and R14 (1).
- **Status:** Not Run

### Test Case 14: Logical AND Operation

- **Severity:** Critical
- **Action to Realize:** Execute the assembly code `MOV 1, R16; MOV 0, R17; AND R16, R17, R18`
- **Expected Result:** Register R18 should contain the result of the logical AND operation between values in R16 and R17 (0).
- **Status:** Not Run

### Test Case 15: Logical XOR Operation

- **Severity:** Critical
- **Action to Realize:** Execute the assembly code `MOV 1, R19; MOV 0, R20; XOR R19, R20, R21`
- **Expected Result:** Register R21 should contain the result of the logical XOR operation between values in R19 and R20 (1).
- **Status:** Not Run

### Test Case 16: Logical NOT Operation

- **Severity:** Critical
- **Action to Realize:** Execute the assembly code `MOV 0, R22; NOT R22, R23`
- **Expected Result:** Register R23 should contain the result of the logical NOT operation on the value in R22 (1).
- **Status:** Not Run

### Test Case 17: Display Text in Virtual Terminal

- **Severity:** High
- **Action to Realize:** Execute the assembly code `PRT "Hello, Virtual World!"`
- **Expected Result:** The text "Hello, Virtual World!" should be displayed in the virtual terminal.
- **Status:** Not Run

### Test Case 18: Syntactical Error Detection

- **Severity:** High
- **Action to Realize:** Attempt to execute the assembly code with an invalid instruction: `INVALID_INSTRUCTION R1, R2`
- **Expected Result:** The interpreter should detect the syntactical error and provide an error message.
- **Status:** Not Run

### Test Case 19: Semantic Validity Check

- **Severity:** High
- **Action to Realize:** Attempt to execute the assembly code with a semantic error: `CMP R13, R14; JMPT INVALID_CONDITION, error_label`
- **Expected Result:** The interpreter should detect the semantic error and provide an error message.
- **Status:** Not Run

### Test Case 20: Debugger Functionality

- **Severity:** Low
- **Action to Realize:** Execute the assembly code `MOV 20, R15; PRT "Before Debug: "; PRT R15`
- **Expected Result:** The debugger should display the content of register R15 after the "Before Debug: " message.
- **Status:** Not Run

### Test Case 21: Memory Overflow

- **Severity:** High
- **Action to Realize:** Execute the assembly code that attempts to write to a memory address beyond the allocated memory space.
- **Expected Result:** The system should detect the memory overflow and handle it appropriately, preventing any unintended behavior or crashes.
- **Status:** Not Run

### Test Case 22: Memory Underflow

- **Severity:** High
- **Action to Realize:** Execute the assembly code that attempts to read from a memory address before the start of the allocated memory space.
- **Expected Result:** The system should detect the memory underflow and handle it appropriately, preventing any unintended behavior or crashes.
- **Status:** Not Run

### Test Case 23: Zero Division Error

- **Severity:** Critical
- **Action to Realize:** Execute the assembly code that attempts to divide by zero.
- **Expected Result:** The system should detect the zero division error and handle it appropriately, preventing crashes and providing an error message.
- **Status:** Not Run

### Test Case 24: Overflow in Arithmetic Operations

- **Severity:** Critical
- **Action to Realize:** Execute the assembly code that results in an overflow during an arithmetic operation (e.g., addition or multiplication).
- **Expected Result:** The system should handle overflow situations gracefully, providing the correct result or signaling an overflow error.
- **Status:** Not Run

### Test Case 25: Display Special Characters

- **Severity:** Low
- **Action to Realize:** Execute the assembly code `PRT "Special Characters: $%^&*"`
- **Expected Result:** The virtual terminal should display the specified special characters correctly.
- **Status:** Not Run

### Test Case 26: Conditional Jump with False Condition

- **Severity:** Medium
- **Action to Realize:** Execute the assembly code `JMPT FALSE, jump_label`
- **Expected Result:** If the condition is false, the program execution should continue to the next instruction without jumping.
- **Status:** Not Run

### Test Case 27: Subroutine Nesting

- **Severity:** High
- **Action to Realize:** Execute the assembly code with nested subroutine calls and returns.
- **Expected Result:** The system should handle nested subroutine calls and returns without issues, maintaining the correct program flow.
- **Status:** Not Run

### Test Case 28: Multiple Logical Operations

- **Severity:** Medium
- **Action to Realize:** Execute the assembly code with a sequence of logical operations (e.g., AND, OR, XOR) on different registers.
- **Expected Result:** The logical operations should be performed correctly, and the result should be as expected.
- **Status:** Not Run

### Test Case 29: Mixed Arithmetic and Logical Operations

- **Severity:** Medium
- **Action to Realize:** Execute the assembly code with a sequence of both arithmetic and logical operations.
- **Expected Result:** The combination of arithmetic and logical operations should produce the correct results, and the program should execute as intended.
- **Status:** Not Run

### Test Case 30: Random Test

- **Severity:** Low
- **Action to Realize:** Create a random assembly code program and execute it.
- **Expected Result:** The system should handle the random program gracefully without crashing, demonstrating robustness.
- **Status:** Not Run
