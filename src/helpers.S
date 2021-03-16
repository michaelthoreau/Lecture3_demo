.syntax unified
.global is_0


is_0:
    cmp r0, #0 // is a == 0
    ite eq
    moveq r0, #1
    movne r0, #0
    bx lr
