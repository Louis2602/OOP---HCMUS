.data
inputA: .asciiz "Input A: "
inputB: .asciiz "Input B: "
plusOutput: .asciiz "Output +: "
subOutput: .asciiz "Output -: "
mulOutput: .asciiz "Output *: "
divOutput: .asciiz "Output /: "
modOutput: .asciiz "Output %: "
endl: .asciiz "\n"

.text
main:
	# Input A
	li $v0, 4
	la $a0, inputA
	syscall
	
	li $v0, 5
	syscall
	move $s0, $v0
	# Input B
	InputB:
		li $v0, 4
		la $a0, inputB
		syscall
	
		li $v0, 5
		syscall
		move $s1, $v0
	beq $s1, $zero, InputB
	
	# Add
	addi $a1, $s0, 0
	addi $a2, $s1, 0
	add $v1, $a1, $a2

	li $v0, 4
	la $a0, plusOutput
	syscall
	jal Output
	
	# Sub
	subi $a1, $s0, 0
	subi $a2, $s1, 0
	sub $v1, $a1, $a2
	
	li $v0, 4
	la $a0, subOutput
	syscall
	jal Output
	
	# Multiplication
	mul $a1, $s0, 1
	mul $a2, $s1, 1
	mul $v1, $a1, $a2
	
	li $v0, 4
	la $a0, mulOutput
	syscall
	jal Output
	
	# Division
	div $a1, $s0, 1
	div $a2, $s1, 1
	div $a1, $a2
	
	# Div
	mflo $v1
	li $v0, 4
	la $a0, divOutput
	syscall
	jal Output
	
	# Mod
	mfhi $v1
	li $v0, 4
	la $a0, modOutput
	syscall
	jal Output
	
# End program
li $v0, 10
syscall
	
# Output
Output:
	li $v0, 1
	move $a0, $v1
	syscall	
	li $v0, 4
	la $a0, endl
	syscall	
	jr $ra