DATAS SEGMENT
    ;�˴��������ݶδ���  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    mov ax,0123H
    mov bx,0456H
    add ax,bx
    add ax,bx
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
