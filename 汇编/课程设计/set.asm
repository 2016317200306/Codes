DATAS SEGMENT
	;16���ƶ��ձ�
    info_hex db '0123456789abcdef' 
    
    x dw 0						;x���ڱ�����յ���
    start1 db 0dh,0ah,0dh,0ah,'input 1 to input a dexnumber,input 2 to input a binnnumber,input 3 to input a Octnumber,input 4 to input a Hexnumber: $'
    
    begin db 0dh,0ah,0dh,0ah,'input Dexnumber: $'
    begin1 db 0dh,0ah,0dh,0ah,'input Binnumber: $'
    begin2 db 0dh,0ah,0dh,0ah,'input Octnumber: $'
    begin3 db 0dh,0ah,0dh,0ah,'input Hexnumber: $'
    
    over1 db 0dh,0ah,'the Hexnumber is: $'
    over2 db 0dh,0ah,'the Binnumber is: $'
    over3 db 0dh,0ah,'the Octnumber is: $'
    over4 db 0dh,0ah,'the Dexnumber is: $'
    
DATAS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    mov dx,offset start1		;��ʾ�����һ������
    mov ah,9
    int 21h
    
    mov ah,1		
    int 21h
    
    cmp al,31h					;Ϊ1�����10������ת��
    je input_dex
    
    cmp al,32h					;Ϊ2�����2������ת��
    je input_bin
    
    cmp al,33h					;Ϊ3�����8������ת��
    je input_oct
    
    cmp al,34h					;Ϊ4�����16������ת��
    je input_hex
    
    jne over_program			;����������˳�����
input_dex:
	mov x,0
	mov dx,offset begin			;dx����������ʾ���ַ
	mov ah,9					;����21���жϵ�9�Ź���
	int 21h						;��ʾ������ʾ��
	
	call get					;����get������ȡ���������
	
	call output_mess2			;���ú�������Ӧ��2���������
	call output_mess3			;���ú�������Ӧ��8���������
	call output_mess1			;���ú�������Ӧ��16���������
	
	jmp start					;�����������ѭ������
	
input_bin:
	mov x,0
	mov dx,offset begin1		;dx����������ʾ���ַ
	mov ah,9					;����21���жϵ�9�Ź���
	int 21h						;��ʾ������ʾ��
	
	call get1					;����get������ȡ���������
	
	call output_mess3			;���ú�������Ӧ��8���������
	call output_mess4			;���ú�������Ӧ��10���������
	call output_mess1			;���ú�������Ӧ��16���������
	
	jmp start					;�����������ѭ������
	
input_oct:
	mov x,0
	mov dx,offset begin2		;dx����������ʾ���ַ
	mov ah,9					;����21���жϵ�9�Ź���
	int 21h						;��ʾ������ʾ��
	
	call get2					;����get������ȡ���������
	
	call output_mess2			;���ú�������Ӧ��2���������
	call output_mess4			;���ú�������Ӧ��10���������
	call output_mess1			;���ú�������Ӧ��16���������
	
	jmp start					;�����������ѭ������	

input_hex:
	mov x,0
	mov dx,offset begin3		;dx����������ʾ���ַ
	mov ah,9					;����21���жϵ�9�Ź���
	int 21h						;��ʾ������ʾ��
	
	call get3					;����get������ȡ���������
	
	call output_mess2			;���ú�������Ӧ��2���������
	call output_mess3			;���ú�������Ӧ��8���������
	call output_mess4			;���ú�������Ӧ��10���������
	
	jmp start					;�����������ѭ������	

get:
	mov ah,1					;����21���ж�1�Ź���
	int 21h						;����һ�����֣�һ�δ���һλ������asc2����ʽ������al��
	
	;**����1
	;�������21���жϵ�1�Ź���
	;һ��ֻ�ܶ���һ������
	;��˶���ʮ��������ʱҪѭ��
	;������Ӧʮ�������ִ���x��
	
	cmp al,27					;�ж��Ƿ�Ϊesc��
	je over_program			    ;��escֱ���˳�����
	
	sub al,30h					;�ж��Ƿ�Ϊ���֣�0-9��
	
	;**����2
	;����ֱ�ӱȽ�Ҫ�ֱ��0��9
	;ת���ɶ�Ӧ��asc2��
	;��ȥ30��ֱ�Ӿ������������
	
	cmp al,0					;��������ʱ�Զ��˳�������
	jb get_exit
	cmp al,9
	ja get_exit
	
	mov ah,0					;ֻ����al�е�ֵ
	xchg ax,x					;����x,ax��ֵ
	
	mov cx,10					;��һ��ʱ��axΪ0
	mul cx						;֮�󼸴Σ�ax��Ϊx��ֵ
	add x,ax					;���յ�������ʱ��ԭx�е�ֵ��λ
								;�������ս������x��Ϊ�����ʮ������
	
	jmp get						;���������ʱ��ѭ��������һ����
	
get_exit:
	ret							;�������ʱ������������
	
get1:
	mov ah,1					;����21���ж�1�Ź���
	int 21h						;����һ�����֣�һ�δ���һλ������asc2����ʽ������al��
	
	cmp al,27					;�ж��Ƿ�Ϊesc��
	je over_program			    ;��escֱ���˳�����
	
	sub al,30h					;�ж��Ƿ�Ϊ���֣�0��1��
	
	cmp al,0					;��������ʱ�Զ��˳�������
	jb get1_exit
	cmp al,1
	ja get_exit
	
	mov ah,0					;ֻ����al�е�ֵ
	xchg ax,x					;����x,ax��ֵ
	
	mov cx,2					;��һ��ʱ��axΪ0
	mul cx						;֮�󼸴Σ�ax��Ϊx��ֵ
	add x,ax					;���յ�������ʱ��ԭx�е�ֵ��λ
								;�������ս������x��Ϊ�����ʮ������
	
	jmp get1					;���������ʱ��ѭ��������һ����
	
get1_exit:
	ret							;�������ʱ������������	

get2:
	mov ah,1					;����21���ж�1�Ź���
	int 21h						;����һ�����֣�һ�δ���һλ������asc2����ʽ������al��
	
	cmp al,27					;�ж��Ƿ�Ϊesc��
	je over_program			    ;��escֱ���˳�����
	
	sub al,30h					;�ж��Ƿ�Ϊ���֣�0-8��
	
	cmp al,0					;��������ʱ�Զ��˳�������
	jb get_exit
	cmp al,7
	ja get_exit
	
	mov ah,0					;ֻ����al�е�ֵ
	xchg ax,x					;����x,ax��ֵ
	
	mov cx,8					;��һ��ʱ��axΪ0
	mul cx						;֮�󼸴Σ�ax��Ϊx��ֵ
	add x,ax					;���յ�������ʱ��ԭx�е�ֵ��λ
								;�������ս������x��Ϊ�����ʮ������
	
	jmp get2					;���������ʱ��ѭ��������һ����
	
get2_exit:
	ret							;�������ʱ������������

get3:
	mov ah,1					;����21���ж�1�Ź���
	int 21h						;����һ�����֣�һ�δ���һλ������asc2����ʽ������al��
	
	cmp al,27					;�ж��Ƿ�Ϊesc��
	je over_program			    ;��escֱ���˳�����
	
	
	
	cmp al,30h					;��������ʱ�Զ��˳�������
	jb get3_exit
	cmp al,39h
	ja get3_exit
	
	sub al,30h
re:
	
	mov ah,0					;ֻ����al�е�ֵ
	xchg ax,x					;����x,ax��ֵ
	
	mov cx,16					;��һ��ʱ��axΪ0
	mul cx						;֮�󼸴Σ�ax��Ϊx��ֵ
	add x,ax					;���յ�������ʱ��ԭx�е�ֵ��λ
								;�������ս������x��Ϊ�����ʮ������
	
	jmp get3					;���������ʱ��ѭ��������һ����
	
get3_exit:
	cmp al,61h
	jb real_end
	cmp al,66h
	ja real_end
	sub al,51h
	jmp re
real_end:	
	ret							;�������ʱ������������

output_mess1:					;���ת��Ϊ16�������������Ϣ
	mov dx,offset over1			;����21���жϵ�9�Ź��ܣ���ʾ�����ʾ��
	mov ah,9
	int 21h

trans_hex:						;���ú�����xת����16����
	mov ax,x					;��x��ֵ�����ax��
	mov cx,0					;cx����
	
	;**����3
	;�ڲ���cx����ʱ��ջ���������
	;������Ԫ�ص��������׵����
	
divide_16:						;���õ�16������
	mov bl,16					
	div bl						;��16�õ�����
	
	;��bl������bx��
	;��ֹ����16λ������������
	
	mov dl,al					;������
	mov al,ah					;ֻ������
	mov ah,0
	push ax						;������ջ
	inc cx						;ջ�����ּ�һ
	mov al,dl					;�ָ���
	cmp ax,0					;�ж�ax���Ƿ�Ϊ0
	jne divide_16				;���������ܼ�����
	
	;push ax
	;inc cx
	;**����4
	;���������ѹջ��
	;��Ϊ�Ѿ��������
	;��ѹջ��������������
	
output_result_hex:
	
	mov ax,datas
	mov ds,ax
	
	pop bx						;ջ�����ֵ�����bx
	mov dl,ds:[bx]				;21���жϵ�2�Ź��ܰ�dl�е�ֵ���
	
	mov ah,2					;����2�Ź���
	int 21h
	loop output_result_hex			;ѭ������������
	
	;����ջ������������
	;�������16������
	
	ret							;ת������������������
	

output_mess2:					;���ת��Ϊ2�������������Ϣ
	mov dx,offset over2			;����21���жϵ�9�Ź��ܣ���ʾ�����ʾ��
	mov ah,9
	int 21h
trans_bin:						;���ú�����xת����16����
	mov ax,x					;��x��ֵ�����ax��
	mov cx,0					;cx����
	
	
divide_2:						;���õ�16������
	mov bl,2					
	div bl						;��16�õ�����
	
	mov dl,al					;������
	mov al,ah					;ֻ������
	mov ah,0
	push ax						;������ջ
	inc cx						;ջ�����ּ�һ
	mov al,dl					;�ָ���
	cmp ax,0					;�ж�ax���Ƿ�Ϊ0
	jne divide_2				;���������ܼ�����
	
output_result_bin:
	
	mov ax,datas
	mov ds,ax
	
	pop bx						;ջ�����ֵ�����bx
	add bx,30h
	
	;**����5
	;����bx��Ϊ����'0'��'1'
	;����dl�����ʱҪת������Ӧ��asc2��
		
	mov dl,bl				    ;21���жϵ�2�Ź��ܰ�dl�е�ֵ���
	
	mov ah,2					;����2�Ź���
	int 21h
	loop output_result_bin		;ѭ������������
	
	;����ջ������������
	;�������2������
	
	ret							;ת������������������

output_mess3:					;���ת��Ϊ8�������������Ϣ
	mov dx,offset over3			;����21���жϵ�9�Ź��ܣ���ʾ�����ʾ��
	mov ah,9
	int 21h

trans_oct:						;���ú�����xת����8����
	mov ax,x					;��x��ֵ�����ax��
	mov cx,0					;cx����
	
	;**����3
	;�ڲ���cx����ʱ��ջ���������
	;������Ԫ�ص��������׵����
	
divide_8:						;���õ�8������
	mov bl,8					
	div bl						;��8�õ�����
	
	;��bl������bx��
	;��ֹ����8λ������������
	
	mov dl,al					;������
	mov al,ah					;ֻ������
	mov ah,0
	push ax						;������ջ
	inc cx						;ջ�����ּ�һ
	mov al,dl					;�ָ���
	cmp ax,0					;�ж�ax���Ƿ�Ϊ0
	jne divide_8				;���������ܼ�����
	
	;push ax
	;inc cx
	;**����4
	;���������ѹջ��
	;��Ϊ�Ѿ��������
	;��ѹջ��������������
	
output_result_oct:
	mov ax,datas
	mov ds,ax
	
	pop bx						;ջ�����ֵ�����bx
	add bx,30h
	mov dl,bl				    ;21���жϵ�2�Ź��ܰ�dl�е�ֵ���
	
	mov ah,2					;����2�Ź���
	int 21h
	loop output_result_oct		;ѭ������������
	
	;����ջ������������
	;�������16������
	
	ret							;ת������������������
	
output_mess4:					;���ת��Ϊ10�������������Ϣ
	mov dx,offset over4			;����21���жϵ�9�Ź��ܣ���ʾ�����ʾ��
	mov ah,9
	int 21h

trans_dex:					;���ú�����xת����10����
	mov ax,x					;��x��ֵ�����ax��
	mov cx,0					;cx����
	
divide_10:						;���õ�10������
	mov bl,10					
	div bl						;��10�õ�����
	
	;��bl������bx��
	;��ֹ����8λ������������
	
	mov dl,al					;������
	mov al,ah					;ֻ������
	mov ah,0
	push ax						;������ջ
	inc cx						;ջ�����ּ�һ
	mov al,dl					;�ָ���
	cmp ax,0					;�ж�ax���Ƿ�Ϊ0
	jne divide_10				;���������ܼ�����
	
output_result_dex:
	mov ax,datas
	mov ds,ax
	
	pop bx						;ջ�����ֵ�����bx
	add bx,30h
	mov dl,bl				    ;21���жϵ�2�Ź��ܰ�dl�е�ֵ���
	
	mov ah,2					;����2�Ź���
	int 21h
	loop output_result_dex	    ;ѭ������������
	
	;����ջ������������
	;�������10������
	
	ret							;ת������������������

over_program:
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START


