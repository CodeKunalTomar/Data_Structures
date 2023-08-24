/*Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
*/

class Solution {
public:
    string reorganizeString(string s) {
        string str = "";
        unordered_map<char, int> map;
        priority_queue<pair<int, char>> pq;

        for(auto i : s)
        {
            map[i] += 1;
        }

        for(auto i : map)
        {
            pq.push(make_pair(i.second, i.first));
        }

        while(pq.size() > 1)
        {
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();

            str += top1.second;
            str += top2.second;

            top1.first -= 1;
            top2.first -= 1;

            if(top1.first > 0)
            {
                pq.push(top1);
            }

            if(top2.first > 0)
            {
                pq.push(top2);
            }
        }

        if(!pq.empty())
        {
            if(pq.top().first > 1)
            {
                return "";
            }

            else
            {
                str += pq.top().second;
            }
        }
        return str;
    }
};