/*Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"
*/
//Approach - 1
//Time and Space Complexity will be O(log columnNumber)

/*#include <iostream>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber > 0)
        {
            //string concatenation
            ans = char('A' + (columnNumber - 1) % 26) + ans;
            //arithmetic calculation
            columnNumber = (columnNumber - 1)/26;
        }

        return ans;
  }
};

int main()
{
    Solution s1;

    string ans = s1.convertToTitle(701);
    cout << ans;
}*/


//Approach - 2
//Time and Space Complexity is O(log n)
/*#include <iostream>
using namespace std;
string convertToTitle(int n)
{
    if(n <= 0)
    {
        return "";
    }

    string ans = "";
    if(n > 0)
    {
        n--;
        ans = convertToTitle(n / 26) + char('A' + (n % 26));
    }

    return ans;
}

int main()
{
    string ans = convertToTitle(701);

    cout << ans;
}*/


//Approach - 3
//Time and Space Complexity will be O(log columnNumber) but due to push_back function we are directly storing characters in a string so it become more efficient

#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        ans.reserve(8);
        while(columnNumber > 0)
        {
            char lastChar = char('A' + (columnNumber - 1) % 26);
            ans.push_back(lastChar);
            //arithmetic calculation
            columnNumber = (columnNumber - 1)/26;
        }
        reverse(ans.begin(), ans.end());

        return ans;
  }
};

int main()
{
    Solution s1;

    string ans = s1.convertToTitle(701);
    cout << ans;
}
