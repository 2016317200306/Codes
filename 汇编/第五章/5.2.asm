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
    mov cx,236
  s:add ax,123
    loop s
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
