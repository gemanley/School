.data
str1: .asciiz "The result is:"
.text
.globl main
main:
li $t1, 1
li $t2, 99
li $t3, 25
addi $t4, $zero, 0
addi $s0, $zero, 0
loop:
slti $t0, $t3, 1
bne $t0, $zero, end
add $t0, $t1, $t2
add $s0, $s0, $t0
addi $t3, $t3, -1
addi $t2, $t2, -2
addi $t1, $t1, 2
j loop
end:
li $v0, 4 # Puts 4 into v0
la $a0, str1 # Puts str1 into a0
syscall # Shows str2 in the console
li $v0, 1 # Puts 1 into v0
move $a0, $s0 # Moves contents of t0 (Result) into a0
syscall # Show the result