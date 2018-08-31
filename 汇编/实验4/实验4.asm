DATAS SEGMENT
    ;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    mov ax,0
    mov ds,ax
    mov ax,0020h
    mov es,ax
    mov bx,0
    mov cx,3fh
  s:mov al,[bx]
    mov es:[bx],al
    inc bx
    loop s
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
