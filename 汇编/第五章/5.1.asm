DATAS SEGMENT
    ;�˴��������ݶδ���  
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
     mov ax,2
     
     mov cx,11
s:	 add ax,ax
	 loop s
	 
	 mov ax,4c00h
	 int 21h
CODES ENDS
    END START
