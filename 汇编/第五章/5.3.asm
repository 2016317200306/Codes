DATAS SEGMENT
    ;�˴��������ݶδ���  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    mov ax,0ffffh
    mov ds,ax
    mov bx,6
    
    mov al,[bx]
    mov ah,0
    
    mov dx,0
    
    mov cx,3
  s:add dx,ax
    loop s
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
