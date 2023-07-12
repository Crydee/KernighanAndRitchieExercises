/* In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of
 * n equal to -(2^(wordsize - 1)).  Explain why not.  Modify it to print that value correctly, regardless of the machine on which it runs. */

/*  The problem is that we make n positive if it's negative, but a two's complement representation can represent, for a given wordsize, a negative
 *  value with magnitude one larger than the largest positive value. The value of the largest +ve value that can be represented is
 *  2^(wordsize - 1) - 1*/
