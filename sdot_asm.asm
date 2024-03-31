;Jeanne Eugenie Arguelles    XX22
;John Kirsten Espiritu       XX22

section .text
    bits 64
    default rel

global sdot_asm

sdot_asm:
    mulsd xmm0, xmm1 ; a = a*b
    movsd xmm2, [r8] ; xmm2 = (result*)
    addsd xmm2, xmm0 ; xmm2 += a
    movsd [r8], xmm2 ; (result*) = xmm2
    ret
