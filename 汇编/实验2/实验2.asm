DATAS SEGMENT
    ;�˴��������ݶδ���  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    mov ax,ffff
    mov ds,ax
    
    mov ax,2200
    mov ss,ax
    
    mov sp,0100
    
    mov ax,[0]
    add ax,[2]
    mov bx,[4]
    add bx,[6]
    
    push ax
    push bx
    pop ax
    pop bx
    
    push [4]
    push [6]
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
