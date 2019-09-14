/* 
 * CS:APP Data Lab 
 * 
 * <Zhihan Zhang 478594>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    //x^y = (~x & y) | (x & ~y)
    //a | b = ~ ~(a | b) = ~ (~a & ~b)
    return ~(~x & ~y) & ~(x & y);
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
    //Set starting point 01010101 so that all even numbered bits are 1.
    //Then shifts over by 8, to obtain 0101010100000000 and uses OR operator to obtain.
    //0101010101010101, then repeats the process with 16.
    int word = 0x55; //85
    word = word | word <<8;
    return word | word <<16;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    //Using shift to bits
    int y = 0;
    n = n << 3; // n == n*3
    m = m << 3; //m == n*3
    y = 0xff & ((x >> n) ^ (x >> m)); // 1111 1111
    x = x ^ (y << n); 
    x = x ^ (y << m);
    return x;
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   between lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
    //Using shift to generate a mask
    return ((2 << highbit) + ~0) >> lowbit << lowbit;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
    //Using XOR to clear any bits, the left of the result should always be 0 other than sign.
    return (x >> n) & (~(((1 << 31) >> n) << 1));
}
// #include "rotateRight.c" /*3 = 13*/
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    //Main point is logical shift
    int mask=0x11 | (0x11 << 8),s;
  	mask= mask | (mask << 16);

	s = x & mask;
  	s += (x >> 1) & mask;
  	s += (x >> 2) & mask;
	s += (x >> 3) & mask;
	s += s >> 16;
  	mask = 0x0f | (0x0f << 8);
	s = (s & mask) + ((s >> 4) & mask);
	return (s + (s >> 8)) & 0x3f;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    //move 32-n by left
    int shift = 33 + ~n;
    //two values will be equal if n bits is enough to cover x.
    return !(x ^ ((x << shift) >> shift));
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
    //Using XOR all bits of bitwise complement of x+y and x
    //Right shift 31 bits and AND with 1
    return (((x ^ y)|(~((x + y) ^ x))) >> 31) & 1;;
}
/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {
    // x*3 = x+x+x, so we add one x each time
    // Check overflow by using (x+x) and (x+x+x) 
    int Min = 1 << 31;
    int Max = ~Min;
    int n = Min;

    int y = x + x;
    int z = x + y;
    
    int a_overflow  = ((~x & (y | z)) & n);
    int a_underflow = ((x & ~(y & z)) & n);
    int a_normal    = !(a_overflow | a_underflow);

    int n_normal    = ~a_normal + 1;
    int n_underflow = a_underflow >> 31;
    int n_overflow  = a_overflow >> 31;

    return (z & n_normal) | (Min & n_underflow) | (Max & n_overflow);
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
    //If a positive integer is power of 2, the leading bit should be 0, such that (x-1) & x == 0
    int sign = !(x >> 31);
    return (!!x) & sign & !((x + ~1 + 1) & x);
}
// #include "howManyBits.c" /*4 = 33*/
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x) {
    //Multiply by 3/4 equal to multiply by 1/2 plus multiply by 1/4
    //For negative number, +1 if it is divisible by 3 in order to round toward 0
    //Calculate integer part and fraction part separately
    int n = 1 << 31;
    int msb = x & n;
    int msb_mask = msb >> 31;
    int frac = (( (x & 1) << 1) + (x & 3));
    int r = (x >> 1) + (x >> 2) + (frac >> 2);

    r = r + ((msb_mask) & !!(frac & 3));
    return r;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    //toAdd may lead to a carry, if this happens, we need to frac >>= 1; exp += 1;
    //However, since we suppress the leading 1 of frac, the carry can be automatically added to exp.
    unsigned s = 0, exp = 31, frac = 0, toAdd = 0;
    if (x == 0x00000000u) return 0x00000000u;
    if (x & 0x80000000u) { s = 0x80000000u; x = -x; }
    while (1) {
      if (x & 0x80000000u) break;
      exp -= 1;
      x <<= 1;
    }
    if ((x & 0x000001ff) == 0x180) toAdd = 1;
        else if ((x & 0xff) > 0x80) toAdd = 1;
        frac = ((x & 0x7fffffffu) >> 8) + toAdd;
  
    return s + ((exp + 127) << 23) + frac;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
    //Divide into infinity/Denormalized/Normailized
    //uf = +-0 case
	if(uf == 0 || uf == 0x80000000) return uf;
	//Infinity case.
	if(((uf >> 23) & 0xff) == 0xff) return uf;
	//Tiny value, but noy equal ot zero
	if(((uf >> 23) & 0xff) == 0x00) {
		return (uf & (1 << 31)) | (uf << 1);
	}
	//Otherwise, Add 1 to exp value
	return uf + (1 << 23);
}
