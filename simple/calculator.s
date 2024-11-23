section .data
    menu db "Simple Calculator", 0
    options db "1. Add", 0
    db "2. Subtract", 0
    db "3. Multiply", 0
    db "4. Divide", 0
    db "5. Exit", 0
    prompt_choice db "Enter your choice: ", 0
    prompt_num1 db "Enter the first number: ", 0
    prompt_num2 db "Enter the second number: ", 0
    result_msg db "Result: ", 0
    error_msg db "Error: Division by zero.", 0

section .bss
    num1 resd 1
    num2 resd 1
    choice resb 1

section .text
    global _start

_start:
    ; Display menu
    ; Implement logic to read input, perform calculations, and display output
