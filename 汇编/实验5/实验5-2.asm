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

datas segment
	dw 0123h,0456h
datas ends

stacks segment
	dw 0,0
stacks ends

END START
