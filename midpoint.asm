;; Midpoint algorithm module. 
;;
;; Compiler used: NASM version 2.13
;; Made for: 64-bit Linux with C caling convention
;;
;; @file pso.asm
;; @author Marek Sedlacek (xsedla1b)
;; @date February 2020
;; @email xsedla1b@fit.vutbr.cz 
;;        mr.mareksedlacek@gmail.com
;;

;; Exported functions
global midpoint         ;; Function for rastering circle using midpoint algorithm

;; Macros

;; Constants

;; Global uninitialized variables
section .bss
align 64

;; Global variables
section .data

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

    xor rax, rax                                ;; Loop counter
    

    pop rbp
    ret
; end of midpoint 
