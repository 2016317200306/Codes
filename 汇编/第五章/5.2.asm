DATAS SEGMENT
    ;�˴��������ݶδ���  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    mov ax,0
    mov cx,236
  s:add ax,123
    loop s
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
