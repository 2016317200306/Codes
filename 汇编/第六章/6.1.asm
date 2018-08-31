DATAS SEGMENT
    ;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    dw 0123h,0456h,0789h,0abch,0defh,0fedh,0cbah,0987h
    
    mov bx,0
    mov ax,0
    
    mov cx,8
  s:add ax,cs:[bx]
    add bx,2
    loop s
    
    MOV AH,4CH
    INT 21H
CODES ENDS

end

