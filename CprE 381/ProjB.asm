lw $s1, 0($0)
add $s2, $s1, $0 # s2 = s1
addi $s0, $0, 5
beq $s1, $s2, skip # always skip unless error
addi $s1, $s1, 4
skip : addiu $s1, $s1, 4 # s1 += 4
sub $s1, $s1, $s0 # s1 -= 5, i.e. s1 -= 1
bgez $s1, skip # keep looping until less than 0
addu $s2, $s1, $s2 # add original value and current (i.e. negative)
and $s3, $s2, $s1
andi $t0, $s3, 7
addi $t1, $t1, 0
bgezal $t0, skip1
addi $t1, $t1, 1
skip1: bgtz $t0, skip2
addi $t1, $t1, 1
skip2: blez $t0, skip3
addi $t1, $t1, 1
skip3: bltz $t0, skip4
addi $t1, $t1, 1
skip4: bltzal $t0, skip5
addi $t1, $t1, 1
skip5: bne $s1, $s2, nobranch
nobranch: j bleh
bleh: jal link
jalr $t1, $t5
link: lb $t2, 2($0)
lbu $t3, 2($0)
lh $t4, 2($0)
lhu $t5, 2($0)
lui $t1, 4
mul $t1, $s1, $s2
nor $t1, $t1, $s1
or $t1, $t1, $s2
ori $t1, $t1, 255
sb $s1, 0($0)
sh $s2, 4($0)
sll $t1, $t1, 2
sllv $t1, $t1, $t2
slt $t0, $s1, $s2
slti $t0, $t1, 10000
sra $t1, $t1, 2
srav $t1, $t1, $t2
srl $t1, $t1, 2
srlv $t1, $t1, $t2
sltiu $t0, $t1, 40
sltu $t0, $s1, $s0
sub $t0, $0, $t0
subu $t0, $t0, $0
sw $t0, 8($0)
xor $t1, $s1, $s2
xori $t1, $t1, 15
jr $t1
