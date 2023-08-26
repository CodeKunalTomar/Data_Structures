/*Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
Example 2:

Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated 
into ascending order.
*/

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int count[3] = {0, 0, 0};
        
        for(int i = 0; i < n; i++)
        {
            count[a[i]]++;
        }
        
        int index = 0;
        for(int i = 0; i < 3; i++)
        {
            while(count[i] > 0)
            {
                a[index] = i;
                index++;
                count[i]--;
            }
        }
    }
    
};