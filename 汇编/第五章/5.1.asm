DATAS SEGMENT
    ;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
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
