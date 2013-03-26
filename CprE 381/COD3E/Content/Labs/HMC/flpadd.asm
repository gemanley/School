# Lab 7: Floating Point Addition
# Created 2/12/99 by Travis Furrer & David Harris
# E114, Harris
#--------------------------------
# <Please put your name here>
#--------------------------------


# The numbers below are loaded into memory (the Data Segment)
# before your program runs.  You can use a lw instruction to
# load these numbers into a register for use by your code.

        .data
atest:  .word 0x40000000 # you can change this to anything you want
btest:  .word 0x40000000 # you can change this to anything you want
smask:  .word 0x007FFFFF
emask:  .word 0x7F800000
ibit:   .word 0x00800000
obit:   .word 0x01000000
        .text

# The main program computes e using the infinite series, and
# calls your flpadd function (below).
#
# PLEASE DO NOT CHANGE THIS PART OF THE CODE
#
# The code uses the registers as follows:
#    $s0 - 1 (constant integer)
#    $s1 - i (loop index variable)
#    $s2 - temp
#    $f0 - 1 (constant single precision float)
#    $f1 - e (result accumulator)
#    $f2 - 1/i!
#    $f3 - i!
#    $f4 - temp
        
main:   li $s0,1                # load constant 1
        mtc1 $s0,$f0            # copy 1 into $f0
        cvt.s.w $f0,$f0         # convert 1 to float
        mtc1 $0,$f1             # zero out result accumulator
        li $s1,0                # initialize loop index
tloop:  addi $s2,$s1,-11        # Have we summed the first 11 terms?
        beq $s2,$0,end          # If so, terminate loop
        bnez $s1,fact           # If this is not the first time, skip init
        mov.s $f3,$f0           # Initialize 0! = 1
        j dfact                 # bypass fact
fact:   mtc1 $s1,$f4            # copy i into $f4
        cvt.s.w $f4,$f4         # convert i to float
        mul.s $f3,$f3,$f4       # update running fact
dfact:  div.s $f2,$f0,$f3       # compute 1/i!
        #add.s $f1,$f1,$f2      # we use your flpadd function instead!
        mfc1 $a0,$f1            #\  These lines should do the same thing
        mfc1 $a1,$f2            # \ as the commented out line above.
        jal flpadd              # / This is where we call your function.
        mtc1 $v0,$f1            #/
        addi $s1,$s1,1          # increment i
        j tloop                 #
end:    j end                   #



# If you have trouble getting the right values from the program
# above, you can comment it out and do some simpler tests using
# the following program instead.  It allows you to add two numbers
# (specified as atest and btest, above), leaving the result in $v0.

#main:   lw $a0,atest
#        lw $a1,btest
#        jal flpadd
#end:    j end



# Here is the function that performs floating point addition of
# single-precision numbers.  It accepts its arguments from
# registers $a0 and $a1, and leaves the sum in register $v0
# before returning.
#
# Make sure not to use any of the registers $s0-$s7, or any
# floating point registers, because these registers are used
# by the main program.  All of the registers $t0-$t9, however,
# are okay to use.
#
# YOU SHOULD NOT USE ANY OF THE MIPS BUILT-IN FLOATING POINT
# INSTRUCTIONS.  Also, don't forget to add comments to each line
# of code that you write.
#
# Remember the single precision format (see page 276):
#          bit 31 = sign (1 bit)
#      bits 30-23 = exponent (8 bits)
#       bits 22-0 = significand (23 bits)
#
#
#
#	Explain your registers here
#

Enter your code here