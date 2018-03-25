/*
 * CS:APP Data Lab
 *
 * <jdang>
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
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
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
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  // this is an 8-bit number
  int mask = 0x55;

  // make a 32-bit version of mask
  mask = mask | mask << 8;
  mask = mask | mask << 16;

  return mask;
}
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // the target is to make 'a' equaled to the value of Tmin by adding
  // 1 to x
  int a = x + 1;

  // if a is 0 then mask is equaled to 1
  // if a is != 0 then mask is equaled to 0
  int mask = !a;

  // the target is to make x be -1
  x += a;

  // if x is not Tmax, this expression will be set to 0
  return !(~x | mask);
}

/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {

  // inverting x then AND to y
  int left = ~x & y;

  // inverting y then AND to x
  int right = x & ~y;

  // C | D = ~(~C & ~D)
  return ~(~left & ~right);
}

/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {

  // if x = 0 -> mask = 0
  // if x != 0 -> mask = 1
  int mask = !!x;

  // used to determine whether to output y or z
  // the possible values are 0000 0000 and 1111 1111
  int mask2 = ~mask + 1;

  // depending on the value of mask2 it will either copy the value
  // into the variable or set the value to 0
  int a = mask2 & y;
  int b = ~mask2 & z;

  // only one of the variable is a non-zero
  return a + b;

}

/*
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4
 */
int greatestBitPos(int x) {

  // used to check if x is a negative value
  int isNeg = 1 << 31;

  // basically this maintains the position of the most significant 1 bit
  // and set the next n number of bits to 1
  x = x | (x >> 1);
  x = x | (x >> 2);
  x = x | (x >> 4);
  x = x | (x >> 8);
  x = x | (x >> 16);

  // if x was a negative value this expression will set the first bit
  // to 1 and when using '&' it will pretty much ignore the value of x
  // if x was a positive it will change the sign bit back to 0 and place
  // the most significant 1 bit at the correct position
  // * I am taking advantage of the fact that the bits preceding after the
  // first occurance of the 1 bit are all '1'
  return (isNeg ^ ((~x) >> 1)) & x;

}

/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {

  // basically this sets mask to the value of 2^n
  // taking advantage of the property for multiples of 2
  int mask = (1 << n) + ~0;

  // tests to see if x is a negative value or not
  // if x was positive, this expression would be set to 0
  int isNeg = (x >> 31) & mask;

  // through many trial and errors I realized that by
  // shifting the most significant 1 position to the left by n
  // then adding it to x then shifting it back to the right by n
  // resolves the negative case issue, while also working for x being
  // positive
  int result = (x + isNeg) >> n;

  return result;
}

/*
 * isNonNegative - return 1 if x >= 0, return 0 otherwise
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {

  // moves the sign bit value to the least significant bit
  int mask = x >> 31;

  // depending on the sign bit value this will return either 1 or 0
  return !mask;
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
  // initalizing Tmin to have the value of tmin
  int Tmin = 1 << 31;

  // (+) = 0000 ... 0000
  // (-) = 1111 ... 1111
  int sign = x >> 31;

  // multiplying x by 2
  int twice = x + x;

  // multiply x by 3
  int triple = twice + x;

  // basically this sees if there was a sign change
  // if there was a sign change this variable would be -1
  // if no sign change this variable would be 0
  int signDelta = ((x ^ twice) | (x ^ triple)) >> 31;

  // if there was a sign change then this value would be set to 0
  // if there wasn't a sign change this would be equaled to x * 3
  int mask = ~signDelta & triple;

  // this basically determines if if it will saturate to either Tmin or Tmax
  int decider = Tmin + (~sign);

  // in the case where there was an overflow, depending on the value of
  // the decider it would set mask2 to that value
  // if there wasn't a sign change then signDelta would set mask2 to zero
  // basically this would be ignored
  int mask2 = signDelta & decider;

  return mask + mask2;
}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  // finding the sign of x and y
  int signX = x >> 31;
  int signY = y >> 31;

  // if x and y have the same sign
  // if x > y then (~y + x) >> 31 = 0;
  // if x < y then (~y + x) >> 31 = 1;
  // also in the case of signX and signY having different signs
  // it will set this expression to 0
  int same = (!(signX ^ signY)) & ((~y + x) >> 31);

  // if x is less, then different will be -1
  int different = signX & !signY;

  // basically this corrects the return value
  return !(same | different);
}

/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {

  // setting sign to the value of tmin (-128)
  int sign = 1 << 31;

  // sets the upper limit to be equaled to 0x39
  int setUpperLimit = 0x39;

  // sets the lower limit to the negative value of 0x30
  // if x was 0x30, by adding x to this variable should be equaled to 0
  // if x > 0x30, by adding x to this variable, result should be a positive value
  // if x < 0x30, by adding x to this variable, result  should be a negative value
  int setLowerLimit = ~0x30 + 1;

  // if x was 0x39, by adding -x to setUpperLimit, result should be equaled to 0
  // if x > 0x39, by adding -x to setUpperLimit, result should be a negative value
  // if x < 0x39, by adding -x to setUpperLimit, result should be a positive value
  // using the expression to the left of '&' depending on that value would either set
  // this variable to 1 (if not in range) or 0 (if within range)
  int upperLimit = sign & (setUpperLimit + (~x + 1)) >> 31;

  // if x was 0x30, by adding x to setLowerLimit, result  should be equaled to 0
  // if x > 0x30, by adding x to setLowerLimit, result should be a positive value
  // if x < 0x30, by adding x to setLowerLimit, result  should be a negative value
  // using the expression to the right of '&' depending on that value would either set
  // this variable to 1 (if not in range) or 0 (if within range)
  int lowerLimit = sign & (setLowerLimit + x) >> 31;

  // the target is that hopefully both the variables are 0 so that by taking the bang of the expression, which
  // should be equaled to 0, it would yield a 1
  // in the case where 1 of the variables indicated x not being in range, by taking the bang of the expression,
  // which should be equaled to 1, it would yield a 0
  return !(upperLimit | lowerLimit);
}

/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x) {

  //int orig = x;
  // sign will be used to determine the sign bit of x
  // if x was a negative value sign = 1
  // if x was a positive value sign = 0
  int sign = x >> 31;

  // this holds the bits of the 3 least significant bits of the original x
  // not the one being edited
  int origCutOff = x & 7;

  // this is like the origCutOff, but this is one is used to be edited
  int cutOff = origCutOff;

  // multiplying the cutOff values by 5 and then dividing by 8
  cutOff = (cutOff << 2) + cutOff;
  cutOff = (cutOff >> 3);

  // dividing x by 8 and then multiplying it by 5
  x = (x >> 3);
  x = (x << 2) + x;

  // adding the cutOff value to x and setting x equaled to the sum
  x += cutOff;

  // this checks to see if the 3 least significant bits was all 0 or has a 1 within in them
  // I am checking for the sake of deciding if I need to add a 1 or not
  // I would add a 1 if there will be a remainder and if it the value of x was a negative
  // if there is a remainder when dividing x by 8 and x is a negative (1), the value would come out to x += 1
  // if no remainder when dividing x by 8 and x is negative (1), the value would come out to x += 0
  // if there is a remainder when dividing x by 8 and x is a positive (0), the value would come out to x += 0
  x += (!!(origCutOff)) & sign;

  return x;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {

  // this is in charge of counting the number of bits left to the most significant
  // 1 bit
  int counter = 0;

  // this checks to see if there is a 1 bit within the leftmost 16 bits
  // if there is then set the variable to be equaled to 16
  counter += ((!!(x >> 16)) << 4);

  // in the case of the previous mask being 0, split the right most 16 bits
  // in half and check the leftmost 8 bits of that halved rightmost 16 bit to
  // see if it contains a 1
  // in the case of the previous maske not being 0, it means there was a 1 within
  // the left most 16 bits of x, so I will do the similar, but this being done
  // upon the leftmost 16 bits of x. Also 8 will be added to x, which would be 16
  counter += ((!!(x >> (counter + 8))) << 3);

  // this works the same way as the previous line of code
  counter +=  ((!!(x >> (counter + 4))) << 2);

  // this works the same way as the previous line of code and the one before that
  counter +=  ((!!(x >> (counter + 2))) << 1);

  // this works the same way as the previous lines of code
  counter += (!!(x >> (counter + 1)));

  return counter;
}

/*
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {

  // this checks to see if the exponent bit is all 1
  int isExpoAllOne = (((uf << 1) >> 24) == 0xFF);

  // this checks to see if the fraction is all 0
  int isFracNotAllOne = !!((uf << 9) | 0);

  // this is designed to avoid working upon a value that is not a number
  // if uf is, then simply just return it
  if (isExpoAllOne && isFracNotAllOne) {
    return uf;
  }

  // if it passes the test, then proceed to return -f
  // which basically flips the sign bit
  return (1 << 31) ^ uf;
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

  int E = 0;   // this is the exponent of the floating point
  int lastBits; // this basically is used to determine the type of rounding
  int mantissa; // this is the fractional part of the floating point
  int sign;  // this determines the sign value of x

  // used to count the number of bits to the left of the msb 1 bit
  int numOfBits = 1;

  // if x is 0 then simply just return a 0 back
  if (x == 0) {
    return 0;
  }

  // because Tmin cannot be supported in floating point it
  // would return the lowest value that can be supported
  if (x == 0x80000000) {
    return 0xCF000000;
  }

  // used to determine if x is negative or positive
  // if (-)x ==> sign = 1
  // if (+)x ==> sign = 0
  sign = ((x >> 31) & 1);

  // if x is a negative value convert x to -x
  if (sign) {
    x = -x;
  }

  /*
  /////////////////////////////////////////////////////////////
  Focusing on the expo bits
  /////////////////////////////////////////////////////////////
  */

  // count the number of bits after the first occurance of the 1 bit
  // this excludes the sign bit
  // the main purpose of this is to determine the number of times
  // I would need to divide by 2 in order to get to 1
  while ((x >> numOfBits) != 0) {
    numOfBits++;
  }

  // need to subtract by 1 because I started the numOfBits count to 1
  numOfBits--;

  // E = expo + 127
  // E is the actual exponent value in the float
  E = numOfBits + 127;

  /*
  //////////////////////////////////////////////////////////////
  Focusing on the mantissa bits
  //////////////////////////////////////////////////////////////
  */

  // I need to first normalize the mantissa bits in order to
  // get a 1 bit as the leftmost bit
  // this multiplies x by 2^(number of bits to the left of MSB 1 bit)
  // in order to get the 1 bit to the leftmost bit
  x = x << (31 - numOfBits);

  // now divide x by 256 in order to determine the mantissa
  // 0x7FFFFF would grab the rightmost 23 bits of x (the mantissa)
  // dividing by 256 to fit the value of x back into a value that would be supported
  mantissa = (x >> 8) & 0x7FFFFF;

  // testing to see if any need to do any roundings
  if (numOfBits > 23) {
    lastBits = x & 0xFF; // the bits that will determine the round off

    // if the bits that are potentially truncated are greater than 1/2 or
    // if the mantissa is exactly 1/2 with the bit before the truncated is 1
    // round up
    if ((lastBits > 128) || ((lastBits == 128) && (mantissa & 1))) {
      mantissa += 1;

      // needing to consider the exponent as well in terms of rounding
      if ((mantissa >> 23)) {
        E += 1;
        mantissa = 0;
      }

    }

  }

  return (sign << 31) | (E << 23) | mantissa;
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

  // if uf is an infinity value both (+) or (-) or not a number
  if (((uf >> 23) & 0xFF) == 0xFF) {
    return uf;
  }

  // handling the +0 and -0 case
  if ((uf == 0) || (uf == 0x80000000)) {
    return uf;
  }

  // handling a very small value that is not 0
  if (((uf >> 23) & 0xFF) == 0) {
    // if uf (-) ==> set it to Tmin and multiply it by 2
    // if uf (+) ==> set to 0 and multiply it by 2
    return ((uf & (1 << 31)) | (uf << 1));
  }

  // if it isn't a special case, simply multiply uf by 2
  return (uf + (1 << 23));
}
