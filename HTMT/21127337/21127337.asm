.data
	arr        : .space 396 # max 99 integers
	mess       : .asciiz "Enter number of elements in the array (0-100): "
	sum		   : .asciiz "\nSum of odd numbers in the array: "
	input      : .asciiz "Input element "
	outputText : .asciiz "Output Array: "
	newline   : .asciiz  "\n"
	space      : .asciiz " "
	colon	   : .asciiz ": "
.text	
main:
	# print input no. elements
	Num:
		li $v0, 4
    	la $a0, mess
    	syscall
    	# read no. elements
    	li $v0, 5
    	syscall
		move $s0, $v0
	ble $s0, $zero, Num
	bge $s0, 100, Num
	
	addi $t0, $zero, 0
	addi $s1, $zero, 0
Input:
	# take input
	bge $t0, $s0, outputArr

	li $v0, 4
	la $a0, input
	syscall
	
	move $a0, $t0
	li $v0, 1
	syscall
	
	li $v0, 4
	la $a0, colon
	syscall
	
	li $v0, 5
    syscall
    
    sw $v0, arr($s1)
    addi $s1, $s1, 4
    addi $t0, $t0, 1
    j Input
    
outputArr:
	li $v0, 4
	la $a0, outputText
	syscall
	addi $t0, $zero, 0
	addi $s1, $zero, 0

	loop1:
		bge $t0, $s0, Sum
		lw $t6, arr($s1)
		# print element
		move $a0, $t6
		li $v0, 1
		syscall
		
		li $v0, 4
		la $a0, space
		syscall
		
		# increase count
		addi $s1, $s1, 4
    	addi $t0, $t0, 1
    	
    	j loop1
Sum:
	li $v0, 4
	la $a0, newline
	syscall
	addi $t0, $zero, 0
	addi $s1, $zero, 0
	addi $s3, $zero, 0
	
	loop2:
		bge $t0, $s0, outputSum
		lw $t6, arr($s1)
		
		move $t3, $t6
		
		jal checkOdd
		move $a0, $v0
		# increase count
		addi $s1, $s1, 4
   		addi $t0, $t0, 1
   		
		beq $a0, 1, plus
		bne $a0, 1, loop2
		plus:
			li $v0, 4
			la $a0, space
			syscall
			move $a0, $t3
			li $v0, 1
			syscall
			add $s3, $s3, $t3
		
   		j loop2

checkOdd:
	and $v0, $t6, 1
	jr $ra
	
outputSum: 
	li $v0, 4
	la $a0, sum
	syscall
	li $v0, 1
	move $a0, $s3
	syscall
    
exit:
	li $v0, 10
