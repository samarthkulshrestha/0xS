bits 32
section     .text
    align   4
    dd      0x1BADB002
    dd      0x00
    dd      - (0x1BADB002 + 0x00)

global start
extern kmain        ; located in kernel.c
start:
    cli             ; clears interrupts
    call kmain      ; send processor to continue exec from kmain (c code)
    hlt             ; halt the cpu
