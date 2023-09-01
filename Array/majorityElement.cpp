/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than n / 2 times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

#include <algorithm>
class Solution {
public:

//Time Complexity for the below approach will be O(n square) and space complexity will be O(1)

    /*int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element = 0, maxCount = 0;

        for(int i = 0; i < n; i++)
        {
            if(element == nums[i])
            {
                continue;
            }

            int count_Element = count(nums.begin(), nums.end(), nums[i]);

            if(count_Element > maxCount)
            {
                maxCount = count_Element;
                element = nums[i];
            }
        }
        return element;
    }*/

//The time and space complexity of the below approach will be O(n)

    /*int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int> map;

        for(int i = 0; i < n; i++)
        {
            if(++map[nums[i]] > n/2)
            {
                return nums[i];
            }
        }
        return -1;
    }
    */

//The Boyer-Moore Majority Vote algorithm is an efficient algorithm for finding the majority element in an array, which is an element that appears more than n/2 times in an array of //length n.

//The time complexity of the below approach will be O(n) and space complexity will be O(1)

    int majorityElement(vector<int>& nums)
    {
        int n = nums.size();
        int count = 0, candidate = 0;

        for(int i = 0; i < n; i++)
        {
            if(count == 0)
            {
                candidate = nums[i];
                count = 1;
            }

            else if(nums[i] == candidate)
            {
                count++;
            }

            else
            {
                count--;
            }
        }
        return candidate;
    }
};