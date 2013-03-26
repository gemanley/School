.data
str1: .asciiz "\nPlease enter a number >= 1 : "
str2: .asciiz "\n The result is:"
.text
.globl main
main:
li $v0, 4 # Load 4 into v0
la $a0, str1 # Load str1 into a0
syscall # Display str1 on the console
li $v0, 5 # Load 5 into v0 (Replacing 4)
syscall # Display the console, putting the user input into v0
move $s0, $v0

li $v0, 4 # Load 4 into v0
la $a0, str1 # Load str1 into a0
syscall # Display str1 on the console
li $v0, 5 # Load 5 into v0 (Replacing 4)
syscall # Display the console, putting the user input into v0
move $s1, $v0

addi $s2, $zero, 0

loop:
slti $t0, $s0, 1
beq $t0, 1, exit
add $s2, $s2, $s1
addi $s0, $s0, -1
j loop
exit:
li $v0, 4 # Puts 4 into v0
la $a0, str2 # Puts str2 into a0
syscall # Shows str2 in the console
li $v0, 1 # Puts 1 into v0
move $a0, $s2 # Moves contents of t0 (Result) into a0
syscall # Show the result