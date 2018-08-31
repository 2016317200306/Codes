DATAS SEGMENT
	;16进制对照表
    info_hex db '0123456789abcdef' 
    
    x dw 0						;x用于保存接收的数
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
    
    mov dx,offset start1		;提示输入第一个数字
    mov ah,9
    int 21h
    
    mov ah,1		
    int 21h
    
    cmp al,31h					;为1则进行10进制数转换
    je input_dex
    
    cmp al,32h					;为2则进行2进制数转换
    je input_bin
    
    cmp al,33h					;为3则进行8进制数转换
    je input_oct
    
    cmp al,34h					;为4则进行16进制数转换
    je input_hex
    
    jne over_program			;其他情况则退出程序
input_dex:
	mov x,0
	mov dx,offset begin			;dx保存输入提示语地址
	mov ah,9					;调用21号中断的9号功能
	int 21h						;显示输入提示语
	
	call get					;调用get函数获取输入的数字
	
	call output_mess2			;调用函数把相应的2进制数输出
	call output_mess3			;调用函数把相应的8进制数输出
	call output_mess1			;调用函数把相应的16进制数输出
	
	jmp start					;无特殊情况，循环输入
	
input_bin:
	mov x,0
	mov dx,offset begin1		;dx保存输入提示语地址
	mov ah,9					;调用21号中断的9号功能
	int 21h						;显示输入提示语
	
	call get1					;调用get函数获取输入的数字
	
	call output_mess3			;调用函数把相应的8进制数输出
	call output_mess4			;调用函数把相应的10进制数输出
	call output_mess1			;调用函数把相应的16进制数输出
	
	jmp start					;无特殊情况，循环输入
	
input_oct:
	mov x,0
	mov dx,offset begin2		;dx保存输入提示语地址
	mov ah,9					;调用21号中断的9号功能
	int 21h						;显示输入提示语
	
	call get2					;调用get函数获取输入的数字
	
	call output_mess2			;调用函数把相应的2进制数输出
	call output_mess4			;调用函数把相应的10进制数输出
	call output_mess1			;调用函数把相应的16进制数输出
	
	jmp start					;无特殊情况，循环输入	

input_hex:
	mov x,0
	mov dx,offset begin3		;dx保存输入提示语地址
	mov ah,9					;调用21号中断的9号功能
	int 21h						;显示输入提示语
	
	call get3					;调用get函数获取输入的数字
	
	call output_mess2			;调用函数把相应的2进制数输出
	call output_mess3			;调用函数把相应的8进制数输出
	call output_mess4			;调用函数把相应的10进制数输出
	
	jmp start					;无特殊情况，循环输入	

get:
	mov ah,1					;调用21号中断1号功能
	int 21h						;输入一个数字（一次处理一位），以asc2码形式保存在al中
	
	;**问题1
	;这里调用21号中断的1号功能
	;一次只能读入一个数字
	;因此读入十进制数字时要循环
	;并将对应十进制数字存入x中
	
	cmp al,27					;判断是否为esc键
	je over_program			    ;是esc直接退出程序
	
	sub al,30h					;判断是否为数字（0-9）
	
	;**问题2
	;这里直接比较要分别把0和9
	;转换成对应的asc2码
	;减去30后直接就是输入的数字
	
	cmp al,0					;不是数字时自动退出本函数
	jb get_exit
	cmp al,9
	ja get_exit
	
	mov ah,0					;只保留al中的值
	xchg ax,x					;交换x,ax的值
	
	mov cx,10					;第一次时，ax为0
	mul cx						;之后几次，ax中为x的值
	add x,ax					;接收到新数字时，原x中的值进位
								;这样最终接收完后，x中为输入的十进制数
	
	jmp get						;无特殊情况时，循环处理下一个数
	
get_exit:
	ret							;接收完成时，返回主程序
	
get1:
	mov ah,1					;调用21号中断1号功能
	int 21h						;输入一个数字（一次处理一位），以asc2码形式保存在al中
	
	cmp al,27					;判断是否为esc键
	je over_program			    ;是esc直接退出程序
	
	sub al,30h					;判断是否为数字（0、1）
	
	cmp al,0					;不是数字时自动退出本函数
	jb get1_exit
	cmp al,1
	ja get_exit
	
	mov ah,0					;只保留al中的值
	xchg ax,x					;交换x,ax的值
	
	mov cx,2					;第一次时，ax为0
	mul cx						;之后几次，ax中为x的值
	add x,ax					;接收到新数字时，原x中的值进位
								;这样最终接收完后，x中为输入的十进制数
	
	jmp get1					;无特殊情况时，循环处理下一个数
	
get1_exit:
	ret							;接收完成时，返回主程序	

get2:
	mov ah,1					;调用21号中断1号功能
	int 21h						;输入一个数字（一次处理一位），以asc2码形式保存在al中
	
	cmp al,27					;判断是否为esc键
	je over_program			    ;是esc直接退出程序
	
	sub al,30h					;判断是否为数字（0-8）
	
	cmp al,0					;不是数字时自动退出本函数
	jb get_exit
	cmp al,7
	ja get_exit
	
	mov ah,0					;只保留al中的值
	xchg ax,x					;交换x,ax的值
	
	mov cx,8					;第一次时，ax为0
	mul cx						;之后几次，ax中为x的值
	add x,ax					;接收到新数字时，原x中的值进位
								;这样最终接收完后，x中为输入的十进制数
	
	jmp get2					;无特殊情况时，循环处理下一个数
	
get2_exit:
	ret							;接收完成时，返回主程序

get3:
	mov ah,1					;调用21号中断1号功能
	int 21h						;输入一个数字（一次处理一位），以asc2码形式保存在al中
	
	cmp al,27					;判断是否为esc键
	je over_program			    ;是esc直接退出程序
	
	
	
	cmp al,30h					;不是数字时自动退出本函数
	jb get3_exit
	cmp al,39h
	ja get3_exit
	
	sub al,30h
re:
	
	mov ah,0					;只保留al中的值
	xchg ax,x					;交换x,ax的值
	
	mov cx,16					;第一次时，ax为0
	mul cx						;之后几次，ax中为x的值
	add x,ax					;接收到新数字时，原x中的值进位
								;这样最终接收完后，x中为输入的十进制数
	
	jmp get3					;无特殊情况时，循环处理下一个数
	
get3_exit:
	cmp al,61h
	jb real_end
	cmp al,66h
	ja real_end
	sub al,51h
	jmp re
real_end:	
	ret							;接收完成时，返回主程序

output_mess1:					;输出转换为16进制数的相关信息
	mov dx,offset over1			;调用21号中断的9号功能，显示输出提示语
	mov ah,9
	int 21h

trans_hex:						;利用函数把x转换成16进制
	mov ax,x					;把x的值存放在ax中
	mov cx,0					;cx计数
	
	;**问题3
	;在不用cx计数时，栈内情况不明
	;容易有元素弹出不彻底的情况
	
divide_16:						;除得到16进制数
	mov bl,16					
	div bl						;除16得到余数
	
	;用bl而不用bx，
	;防止进行16位除法产生错误
	
	mov dl,al					;保存商
	mov al,ah					;只留余数
	mov ah,0
	push ax						;余数入栈
	inc cx						;栈内数字加一
	mov al,dl					;恢复商
	cmp ax,0					;判断ax中是否为0
	jne divide_16				;不是零则还能继续除
	
	;push ax
	;inc cx
	;**问题4
	;在最后不用再压栈了
	;因为已经运算完成
	;再压栈会造成输出有问题
	
output_result_hex:
	
	mov ax,datas
	mov ds,ax
	
	pop bx						;栈内数字弹出到bx
	mov dl,ds:[bx]				;21号中断的2号功能把dl中的值输出
	
	mov ah,2					;调用2号功能
	int 21h
	loop output_result_hex			;循环调用输出结果
	
	;利用栈先入后出的特性
	;逆序输出16进制数
	
	ret							;转换结束，返回主程序
	

output_mess2:					;输出转换为2进制数的相关信息
	mov dx,offset over2			;调用21号中断的9号功能，显示输出提示语
	mov ah,9
	int 21h
trans_bin:						;利用函数把x转换成16进制
	mov ax,x					;把x的值存放在ax中
	mov cx,0					;cx计数
	
	
divide_2:						;除得到16进制数
	mov bl,2					
	div bl						;除16得到余数
	
	mov dl,al					;保存商
	mov al,ah					;只留余数
	mov ah,0
	push ax						;余数入栈
	inc cx						;栈内数字加一
	mov al,dl					;恢复商
	cmp ax,0					;判断ax中是否为0
	jne divide_2				;不是零则还能继续除
	
output_result_bin:
	
	mov ax,datas
	mov ds,ax
	
	pop bx						;栈内数字弹出到bx
	add bx,30h
	
	;**问题5
	;这里bx中为数字'0'或'1'
	;放入dl中输出时要转换成相应的asc2码
		
	mov dl,bl				    ;21号中断的2号功能把dl中的值输出
	
	mov ah,2					;调用2号功能
	int 21h
	loop output_result_bin		;循环调用输出结果
	
	;利用栈先入后出的特性
	;逆序输出2进制数
	
	ret							;转换结束，返回主程序

output_mess3:					;输出转换为8进制数的相关信息
	mov dx,offset over3			;调用21号中断的9号功能，显示输出提示语
	mov ah,9
	int 21h

trans_oct:						;利用函数把x转换成8进制
	mov ax,x					;把x的值存放在ax中
	mov cx,0					;cx计数
	
	;**问题3
	;在不用cx计数时，栈内情况不明
	;容易有元素弹出不彻底的情况
	
divide_8:						;除得到8进制数
	mov bl,8					
	div bl						;除8得到余数
	
	;用bl而不用bx，
	;防止进行8位除法产生错误
	
	mov dl,al					;保存商
	mov al,ah					;只留余数
	mov ah,0
	push ax						;余数入栈
	inc cx						;栈内数字加一
	mov al,dl					;恢复商
	cmp ax,0					;判断ax中是否为0
	jne divide_8				;不是零则还能继续除
	
	;push ax
	;inc cx
	;**问题4
	;在最后不用再压栈了
	;因为已经运算完成
	;再压栈会造成输出有问题
	
output_result_oct:
	mov ax,datas
	mov ds,ax
	
	pop bx						;栈内数字弹出到bx
	add bx,30h
	mov dl,bl				    ;21号中断的2号功能把dl中的值输出
	
	mov ah,2					;调用2号功能
	int 21h
	loop output_result_oct		;循环调用输出结果
	
	;利用栈先入后出的特性
	;逆序输出16进制数
	
	ret							;转换结束，返回主程序
	
output_mess4:					;输出转换为10进制数的相关信息
	mov dx,offset over4			;调用21号中断的9号功能，显示输出提示语
	mov ah,9
	int 21h

trans_dex:					;利用函数把x转换成10进制
	mov ax,x					;把x的值存放在ax中
	mov cx,0					;cx计数
	
divide_10:						;除得到10进制数
	mov bl,10					
	div bl						;除10得到余数
	
	;用bl而不用bx，
	;防止进行8位除法产生错误
	
	mov dl,al					;保存商
	mov al,ah					;只留余数
	mov ah,0
	push ax						;余数入栈
	inc cx						;栈内数字加一
	mov al,dl					;恢复商
	cmp ax,0					;判断ax中是否为0
	jne divide_10				;不是零则还能继续除
	
output_result_dex:
	mov ax,datas
	mov ds,ax
	
	pop bx						;栈内数字弹出到bx
	add bx,30h
	mov dl,bl				    ;21号中断的2号功能把dl中的值输出
	
	mov ah,2					;调用2号功能
	int 21h
	loop output_result_dex	    ;循环调用输出结果
	
	;利用栈先入后出的特性
	;逆序输出10进制数
	
	ret							;转换结束，返回主程序

over_program:
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START


