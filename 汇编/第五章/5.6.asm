DATAS SEGMENT
    ;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    mov ax,0ffffh
    mov ds,ax
    mov bx,0
    
    mov dx,0
    
    mov cx,12
    
  s:mov al,[bx]
    mov ah,0
    add dx,ax
    inc bx
    loop s
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
