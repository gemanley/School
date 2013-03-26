.data
str1: .asciiz " Please enter a number >= 1 : "
str2: .asciiz "\n\n The result is:"
.text
.globl main
main:
li $v0, 4 # Load 4 into v0
la $a0, str1 # Load str1 into a0
syscall # Display str1 on the console
li $v0, 5 # Load 5 into v0 (Replacing 4)
syscall # Display the console, putting the user input into v0
move $t1, $v0 # Put v0 into t1
addi $t3, $zero, 1 # Put 1 into t3
slti $t2, $t1, 1 # t2 = t1 < 1 i.e. Is the user input less than 1?
beq $t3, $t2, do_nothing # If the user input is invalid, be done
addi $t0, $t0, 0 # Put 0 into t0
loop:
sge $t2, $t1, $t3 # t2 = (t1 >= t3)
beq $t2, $zero, end # Goto end if t3 > t1
add $t0, $t0 , $t1 # Increments t0 by t1
addi $t1, $t1 , -1 # Decrements t1 by 1
j loop # Loop until break
end:
li $v0, 4 # Puts 4 into v0
la $a0, str2 # Puts str2 into a0
syscall # Shows str2 in the console
li $v0, 1 # Puts 1 into v0
move $a0, $t0 # Moves contents of t0 (Result) into a0
syscall # Show the result
do_nothing:
li $v0, 10 # Puts 10 into v0
syscall # Show the result
