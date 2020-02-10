;; Midpoint algorithm module. 
;;
;; Compiler used: NASM version 2.13
;; Made for: 64-bit Linux with C caling convention
;;
;; @file midpoint.asm
;; @author Marek Sedlacek (xsedla1b)
;; @date February 2020
;; @email xsedla1b@fit.vutbr.cz 
;;        mr.mareksedlacek@gmail.com
;;

;; Exported functions
global midpoint         ;; Function for rastering circle using midpoint algorithm
extern put8lines

;; Macros

;; Global variables
section .data
align 64
__CONST_1       times 32 db 1

;; Code
section .text


;; MIDPOINT 
;; Circle rendering into a 2D array of bytes using midpoint algorithm 
;;
;; @param
;;      TData **midpoint    - RDI - Array of bytes
;;      long s1             - RSI - X coordinate of the circle's center
;;      long s2             - RDX - Y coordinate of the circle's center
;;      long r              - RCX - Circle's radius
midpoint:
        push rbp
        mov rbp, rsp
        push rbx
        push r12
        push r13
        push r14

        xor rax, rax                            ;; x = 0; rcx = y
        mov r8, 1
        mov r10, rcx
        mov r9, 3                               ;; x2 = 3
        sub r8, rcx                             ;; p = 1 - r
        shl r10, 1                              ;; r * 2
        sub r10, 2                              ;; y2 = r * 2 - 2
        vmovaps ymm0, [__CONST_1]               ;; Load all ones to ymm reg

.while:
        cmp rax, rcx
        jg .end                                 ;; Do while x <= y
        ;; Rasterizing 8 lines
        mov r12, rdx
        add r12, rcx                            ;; r12 = s2 + y
        mov rbx, rdx                            ;; Loop counter
        sub rbx, rcx                            ;; rbx = s2 - y
        mov r13, rsi
        mov r14, rsi
        add r13, rax                            ;; s1 + x
        sub r14, rax                            ;; s1 - x
        mov r13, [rdi + r13]                    ;; Load midpoint[s1 + x]
        mov r14, [rdi + r14]                    ;; Load midpoint[s1 - x]
.for_y:
        ;; TODO: add serial approach for width<32 
        cmp rbx, r12
        jge .end_for_y                          ;; rbx >= s2 + y
        vmovups [r13 + rbx], ymm0

        add rbx, 32
        jmp short .for_y

.end_for_y:
.for_x:

        cmp r8, 0
        jl .p_neg                               ;; if p >= 0
        sub r8, r10                             ;; p -= y2
        sub r10, 2                              ;; y2 -= 2
        dec rcx                                 ;; y -= 1
.p_neg:
        add r8, r9                              ;; p += x2
        add r9, 2                               ;; x2 += 2
        inc rax                                 ;; x += 1
        jmp short .while

.end:
        pop r14
        pop r13
        pop r12
        pop rbx
        pop rbp
        ret
; end of midpoint 
