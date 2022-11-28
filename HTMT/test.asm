.data
odd: .asciiz "Odd"
even: .asciiz "even"

.text
main:
	li $s0, 2
	
	jal checkOdd
	move $s1, $v0
		
	beq $s1, 1, printOdd
	j printEven
	
checkOdd:
	and $v0, $s0, 1
	jr $ra
printOdd:
	li $v0, 4
	la $a0, odd
	syscall
	move $a0, $s0
	li $v0, 1
	syscall
	j exit
printEven:
	li $v0, 4
	la $a0, even
	syscall	
	j exit
	
exit:
	li $v0, 10
