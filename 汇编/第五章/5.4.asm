DATAS SEGMENT
    ;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    mov ax,2000h
    mov ds,ax
    mov al,[0]
    mov bl,[1]
    mov cl,[2]
    mov dl,[3]
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
