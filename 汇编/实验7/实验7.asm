DATAS SEGMENT
    db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
    db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
    db '1993','1994','1995'
    ;21 years
    
    dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
    dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000
    ;21 earn
    
    dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
    dw 11542,14430,15257,17800
    ;21 mates
DATAS ENDS

table segment
	db 21 dup ('year summ ne ?? ')
table ends

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS
START:
    mov ax,datas
    mov ds,ax
    
    mov ax,table
    mov es,ax
    
    mov di,0
    mov si,0
    mov cx,21
    
    
    ;input year
 s1:mov bx,ds:[si]
    mov es:[di+0],bx
    mov bx,ds:[si+2]
    mov es:[di+2],bx
    
    add di,16
    add si,4
    
    loop s1
    
    ;input salary
    mov di,0
    mov si,0054h
    mov cx,21
    
 s2:mov bx,ds:[si]
    mov es:[di+5],bx
    mov bx,ds:[si+2]
    mov es:[di+7],bx
    
    add di,16
    add si,4
    
    loop s2
    
    ;input mates
    mov di,0
    mov si,168
    mov cx,21
    
 s3:mov bx,ds:[si]
    mov es:[di+10],bx
    mov bx,ds:[si+1]
    mov es:[di+11],bx
    
    add di,16
    add si,2
    
    loop s3
    
    calculate
  s4:mov 
  
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START




