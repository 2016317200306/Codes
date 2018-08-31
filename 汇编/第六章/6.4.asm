DATAS SEGMENT
    dw 0123h,0456h,0789h,0abch,0defh,0fedh,0cbah,0987h
DATAS ENDS

STACKS SEGMENT
    dw 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,stacks
    MOV ss,AX
    mov sp,20h
    
    mov ax,datas
    mov ds,ax
    
    mov bx,0
    
    mov cx,8
  s:push [bx]
    add bx,2
    loop s
    
    mov bx,0
    
 s0:pop[bx]
    add bx,2
    loop s0
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
