DATAS SEGMENT
    ;�˴��������ݶδ���  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    mov bx,0
    mov cx,12
    
  s:mov ax,0ffffh
    mov ds,ax
    mov dl,[bx]
    
    mov ax,0020h
    mov ds,ax
    mov [bx],dl
    
    inc bx
    loop s
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
