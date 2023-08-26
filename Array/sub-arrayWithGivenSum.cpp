/*Given an unsorted array A of size N that contains only positive integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.

Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.
Example 2:

Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements 
from 1st position to 5th position
is 15.
*/

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        int left = 0;
        int right = 0;
        long currentSum = 0;
        
        vector<int> result = {-1};
        int i = 0;
        while(right < arr.size())
        {
            currentSum = currentSum + arr[right];
            
            while(currentSum > s)
            {
                currentSum = currentSum - arr[left];
                left++;
            }
            
            if(currentSum == s)
            {
                right = right + 1;
                left = left + 1;
                result = {left, right};
                break;
            }
            right++;
        }
        
        if(s == 0)
        {
            return {-1};
        }
        
        return result;
    }
};