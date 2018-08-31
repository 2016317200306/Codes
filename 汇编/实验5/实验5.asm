DATAS SEGMENT
    dw 0123h,0456h,0789h,0abch,0defh,0fedh,0cbah,0987h
DATAS ENDS

STACKS SEGMENT
    dw 0,0,0,0,0,0,0,0
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    mov ax,stacks
    mov ss,ax
    mov sp,16
    
    mov ax,datas
    mov ds,ax
    
    push ds:[0]
    push ds:[2]
    pop ds:[2]
    pop ds:[0]
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
