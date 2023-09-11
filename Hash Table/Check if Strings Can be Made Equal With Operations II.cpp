/*You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.

You can apply the following operation on any of the two strings any number of times:

Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.

Return true if you can make the strings s1 and s2 equal, and false otherwise.

 

Example 1:

Input: s1 = "abcdba", s2 = "cabdab"
Output: true
Explanation: We can apply the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
- Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
- Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.

Example 2:

Input: s1 = "abe", s2 = "bea"
Output: false
Explanation: It is not possible to make the two strings equal.
*/
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        
       if(s1.length() != s2.length())
       {
           return false;
       }
        
        unordered_map<char, int> map;
        
        for(int i = 0; i < s1.length(); i++)
        {
            if(i % 2 == 0)
            {
                map[s1[i]]++;
            }
            
            else
            {
                map[s2[i]]++;
            }
        }
        
        for(int j = 0; j < s1.length(); j++)
        {
            if(j % 2 == 0)
            {
                if(map[s2[j]] > 0)
                {
                    map[s2[j]]--;
                }
                
                else
                {
                    return false;
                }
            }
            
            else
            {
                if(map[s1[j]] > 0)
                {
                    map[s1[j]]--;
                }
                
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
