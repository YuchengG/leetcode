// Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

//Example:
//Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

//Hint:

//A direct way is to use the backtracking approach.
//Backtracking should contains three states which are (the current number,
//number of steps to get that number and a bitmask which represent which number
//is marked as visited so far in the current number). Start with state (0,0,0)
//and count all valid number till we reach number of steps equals to 10n.This problem can also be solved using a dynamic programming approach and some knowledge of combinatorics.
//Let f(k) = count of numbers with unique digits with length equals k.
//f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].

// Q: Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10^n

// A: Here I choose a math solution based on permutation:

//     P(n, r) = n * (n - 1) * (n - 2) * ... * (n - r + 1)

// Just take a try

//     When n = 0, 0 ≤ x < 1 with unique digits is 0, A(0) = 1

//     When n = 1, 0 ≤ x < 10 can be divided into

//         0 ≤ x < 1 (calculated in 1): A(0) = 1

//         1 ≤ x < 10 (all numbers with ONLY 1 digit):

//     As they are all unique: A(1) = P(10,1) - 1

//     When n = 2, 0 ≤ x < 100 with unique digits can be divided into

//         0 ≤ x < 1 (calculated in 1): A(0) = 1

//         1 ≤ x < 10 (all numbers with ONLY 1 digit): A(1) = P(10,1) - 1

//         10 ≤ x < 100 (all numbers with ONLY 2 digits):

//     As the numbers have ONLY 2 digits, if they are with unique digits:

//     We need to choose 2 different digits from {1,2,3,4,5,6,7,8,9,0}: P(10,2)

//     And we must filter out the permutations started by 0: P(9,1)

//     A(2) = P(10,2) - P(9,1)

// Think about A(n)

//     When n > 10, 10^(n-1) ≤ x < 10^n MUST have MORE THAN 10 digits.

// As the Pigeonhole principle says, there MUST be AT LEAST N - 9 repeating numbers.

// All numbers should be ignored, which means A(n) = 0 (n > 10).

//     When n ≤ 10, 10^(n-1) ≤ x < 10^n (all numbers with ONLY n digits) have unique digits :

//     Choose n different digits from {1,2,3,4,5,6,7,8,9,0}: P(10,n)

//     Filter out the permutations started by 0: P(9,n-1)

//     Get A(n) = P(10,n) - P(9,n-1) = 9 * P(9,n-1)

// Combine all Intervals

//     As

//         A(n) = 1 (n = 0)

//         A(n) = 9 * P(9,n-1) (0 < n ≤ 10)

//         A(n) = 0 (n > 10)

//     Since we need to count all x (0 ≤ x < 10^n) with unique digits , we can just combine all Intervals:
//         S(n) = A(0) + A(1) + A(2) + .....+ A(n)

//     S(n) is the final answer.

using namespace std;

// Author: Songpeng Zu
// Time: July 26, 2016

// Solver 1
// From Discussion

class Solution {
public:
    int permutation(int n, int r)
    {
        if(r == 0)
        {
            return 1;
        }else{
            return n * permutation(n - 1, r - 1);
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        int sum = 1;
        if(n > 0)
        {
           int end = (n > 10)? 10 : n;
           for(int i = 0; i < end; i++)
           {
               sum += 9 * permutation(9, i);
           }
        }
        return sum;
    }
};
