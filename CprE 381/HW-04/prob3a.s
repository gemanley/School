sll $a2, $a2, 2 # Multiply a2 by 4 (12000)
sll $a3, $a3, 2 # Multiply a3 by 4 (12000)
add $v0, $zero, $zero # Initialize $v0 to 0
add $t0, $zero, $zero # Initialize $t0 to 0
outer: add $t4, $a0, $t0 # $t4 = &A1[$t0]
lw $t4, 0($t4) # $t4 = A1[$t0]
add $t1, $zero, $zero # Reset $t1 to 0
inner: add $t3, $a1, $t1 # $t3 = &A2[$t1]
lw $t3, 0($t3) # $t3 = A2[$t1]
bne $t3, $t4, skip # if(A2[$t1] == A1[$t0]) {
addi $v0, $v0, 1 # Increment $v0 by 1 }
skip: addi $t1, $t1, 4 # Increment $t1 by 4
bne $t1, $a3, inner # if($t1 == 12000) {
addi $t0, $t0, 4 # Increment $t0 by 4 }
bne $t0, $a2, outer # if($t0 != 12000) goto outer