The transform in a happy number transformation is done by separating a number into its decimal digits, then summing of the squares of the digits. This shall be called transforming the number.

Note since each digit is squared, the result for -num is the same as num, so it shall be assumed that num is positive or has been made positive by negating it. 

0 is not happy as the transform of 0 is 0.

When a number is transformed the new value is generally smaller than the old value. This is because the largest the new value can be is ndig*81 where ndig is the number of decimal digits in the old value. ndig is a value on the order of the base 10 log (log10) of the old number. For a given value of num, the value of ndig is 1+ceil(log10(num).

So, for any number where 81*(1+ceil(log10(num))) is greater than num, the result of the transform may be greater than num. This is also equivalent to 81 + 81*ceil(log10(num)).

We must posit that in order to form a loop, there must be a value in the loop which produces a transformed value which is larger than itself. As this is a loop, this value (like all others in the loop) must also be produced by a transformation.

There is some number which is the largest which can be produced by a transformation of a number which also can be produced by a transformation. This shalle be called largestlooper Any numbers larger than this number cannot be in a loop. Each number 0..largestlooper maps through the transformation onto another number 0..largestlooper. There are largestlooper+1 of these mappings.

The set of numbers which can be in a loop shall be called loopers. The set of loopers can have at most largestlooper+1 members, being the set 0..largestlooper.

The following is a process for determinging the largest number which can be in a loop.

As n is a positive integer we do not have to consider any value less than 1.

The transform of 1 is 1.

The ceil of log10 of numbers greater than 1 and less than 10 is 1, as the logarithms of all these numbers are fractional values less than 1 but greater than 0. For these values of num the largest value the transform can be is 81, which is greater than all the values of num in this range.

The transform of 10 is 1.

The ceil of log10 of numbers greater than 10 and less than 100 is 2, as the logarithms of all these numbers are values less than 2 but greater than 1. For these values of num the largest value the transform can be is 162, which is greater than all the values of num in this range.

The transform of 100 is 1.

The ceil of log10 of numbers greater than 100 and less than 243 is 3, as the logarithms of all these numbers are values less than 3 but greater than 2. For these values of num the largest value the transform can be is 243, which is greater than all the values of num in this range.

The transform of 243 is 27. The transformed value is less than the old value.

For every value above this, as (1+ceil(log10(num))) is less than num/81, the transformed value is less than the old value.

Note that the section between 100 and 243 can be refined.

For a value of num greater than or equal to 200 and less than 243, the transform of num is the same as the transform of 200 plus the transform of num-200. The transform of 200 is 4, so the transform of num is 4 plus the transform of num-200. Given this and that the transforms of all numbers less than 100 are no greater than 162 the transforms of all numbers greater than or equal to 200 and less than 242 are no greater than 166.

So no transformed value of num greater than or equal to 200 is greater than num.

For a value of num greater than or equal to 100 and less than 200, the transform of num is the same as the transform of 100 plus the transform of num-100. The transform of 100 is 1, so the transform of num is 1 plus the transform of num-100. Given this and that the transforms of all numbers less than 100 are no greater than 162 the transforms of all numbers greater than or equal to 163 and less than 200 are no greater than 163.

Therefore the largest number for which its transformed value is greater than itself and can itself be produced by a transformation is less than 163. Therefore the largest value which can be in a loop is 162.

By automated checking, the largest number for which the transformed value is greater than itself is 99 and it produces the value 162.

Every number greater than or equal to 0 and less than 163 maps onto another number greater than or equal to 0 and less than 163. This means the largest loop starting below 162 can be at most 163 mappings long.

However, there is another loop that doens't lead to the final state of 1, that is 0. So there are at most 162 links in a traversal to 1.

Also, for every number XY where there is another number YX which is not the same, XY and YX lead to the same node. It is not possible to traverse both of these links in a route which ends up at 1 because the 2nd traversal would be an indication that this is a loop. So that means the traversals strating at half of the numbers 00-99 except for 00-99 cannot be traversed. That removes 45 traversals, leaving us with 107 traversals.

If, after producing a number less than 163 we traverse 107 more times and have not yet reached 0 or 1, then we will never reach either of them.
