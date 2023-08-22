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
