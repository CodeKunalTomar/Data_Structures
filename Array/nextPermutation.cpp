/*You have been given a
permutation of ‘N’
integers. A sequence of ‘N’
integers is called a
permutation if it contains
all integers from 1 to ‘N’
exactly once. Your task is
to rearrange the numbers
and generate the
lexicographically next
greater permutation.
To determine which of the
two permutations is
lexicographically smaller,
we compare their first
elements of both
permutations. If they are
equal — compare the
second, and so on. If we
have two permutations X
and Y, then X is
lexicographically smaller if
X[i] < Y[i], where ‘i’ is the
first index in which the
permutations X and Y
differ.

Sample Input 1:
2
3
1 2 3
5
2 3 1 4 5

Sample Output 1:
1 3 2
2 3 1 5 4

Explanation Of Sample Input 1:
In the first test case, the lexicographically next greater permutation is [1, 3, 2].

In the second test case, the lexicographically next greater permutation is [2, 3, 1, 4, 5].

Sample Input 2:
2
2
1 2
3
3 1 2

Sample Output 2:
2 1
3 2 1
Explanation For Sample Input 2:
In the first test case, the lexicographically next greater permutation is [2, 1].

In the second test case, the lexicographically next greater permutation is [3, 2, 1].
*/

#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int i = n - 2;

    while(i >= 0 && permutation[i] >= permutation[i + 1])
    {
        i--;
    }

    if(i >= 0)
    {
        int j = n - 1;

        while(j > i && permutation[j] <= permutation[i])
        {
            j--;
        }

        swap(permutation[i], permutation[j]);
    }

    reverse(permutation.begin() + i + 1, permutation.end());
    return permutation;

    
}