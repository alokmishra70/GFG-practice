//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int>dp(n,1);
        
        for(int i=0 ; i<n; i++){
            for(int pre = 0 ; pre < i ; pre++){
                if(a[pre] < a[i]  and 1+dp[pre] > dp[i]){
                    dp[i] = 1+dp[i];
                }
            }
        }
        
        
        return *max_element(dp.begin(),dp.end());
       // your code here
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends