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
    
    mov ax,0020h
    mov es,ax
    
    mov bx,0
    
    mov cx,12
    
  s:mov dl,[bx]
    mov es:[bx],dl
    inc bx
    loop s
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
