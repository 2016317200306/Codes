DATAS SEGMENT
    ;此处输入数据段代码  
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    mov ax,0ffffh
    mov ds,ax
    
    mov ax,0
    
    mov al,ds:[0]
    mov ah,0
    add dx,ax
    
    mov al,ds:[1]
    mov ah,0
    add dx,ax
    
    mov al,ds:[2]
    mov ah,0
    add dx,ax
    
    mov al,ds:[3]
    mov ah,0
    add dx,ax
    
    mov al,ds:[4]
    mov ah,0
    add dx,ax
    
    mov al,ds:[5]
    mov ah,0
    add dx,ax
    
    mov al,ds:[6]
    mov ah,0
    add dx,ax
    
    mov al,ds:[7]
    mov ah,0
    add dx,ax
    
    mov al,ds:[8]
    mov ah,0
    add dx,ax
    
    mov al,ds:[9]
    mov ah,0
    add dx,ax
    
    mov al,ds:[0ah]
    mov ah,0
    add dx,ax
    
    mov al,ds:[0bh]
    mov ah,0
    add dx,ax
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
