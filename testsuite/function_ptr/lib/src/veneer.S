    .arch armv7-m
    .eabi_attribute 20, 1
    .eabi_attribute 21, 1
    .eabi_attribute 23, 3
    .eabi_attribute 24, 1
    .eabi_attribute 25, 1
    .eabi_attribute 26, 1
    .eabi_attribute 30, 1
    .eabi_attribute 34, 1
    .eabi_attribute 18, 4
    .text

/* if your function has no stack parameter then use this macro to generate veneer
    param name: name of the veneer to generate.
*/
.macro NO_STACK_VENEER name, prefix=IMPL
    .align  1
    .global \name
    .syntax unified
    .thumb
    .thumb_func
    .fpu softvfp
    .type   \name, %function
\name:
    push    {r9, r10, r11, lr}
    ldr     r9,  =\prefix\()_data
    ldr     r10, =\prefix\()_rodata
    bl      \prefix\()_\name
    pop     {r9, r10, r11, pc}
    .size   \name, .-\name
.endm

.macro COPY_WITH_LDRD_STRD size offset
    ldrd    r9, r10, [sp, #16 + \size + \offset]
    strd    r9, r10, [sp, #\offset]
    .if \offset
    COPY_WITH_LDRD_STRD \size \offset - 8
    .endif
.endm

/* if your function has stack parameters then use this macro to generate veneer
   param name: name of the veneer to generate.
   stack_bytes: additionnal stack to hold stack parameters. Value must be a
                multiple of 8 and not 0.
*/
/* stack_bytes must be multiple of 8 and not null */
.macro STACK_VENEER name stack_bytes, prefix=IMPL
    .align  1
    .global \name
    .syntax unified
    .thumb
    .thumb_func
    .fpu softvfp
    .type   \name, %function
\name:
    push    {r9, r10, r11, lr}
    sub     sp, sp, #\stack_bytes
    COPY_WITH_LDRD_STRD \stack_bytes \stack_bytes-8
    ldr     r9,  =\prefix\()_data
    ldr     r10, =\prefix\()_rodata
    bl      \prefix\()_\name
    add     sp, sp, #\stack_bytes
    pop     {r9, r10, r11, pc}
    .size   \name, .-\name
.endm

/* lib veneer */
NO_STACK_VENEER get_key_fct
