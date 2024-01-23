; Sample Assembly File

; Initialize registers
MOV_IMM 42, R1
MOV_IMM 0, R2
MOV_IMM 0, R3

; Move the value from R1 to R2
MOV_REG R1, R2  ; R2 = R1

; Move the value from R2 to R3
MOV_REG R2, R3  ; R3 = R2

; Halt the program
HLT
