//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int recursive(int arr[], int n , vector<int>& dp){
        if(n == 0) return arr[n];
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        
        int pick = arr[n] + recursive(arr,n-2 , dp);
        int notPick = 0 + recursive(arr,n-1 , dp);
        
        return dp[n] = max(pick,notPick);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        
        vector<int>dp(n , -1);
        dp[0] = arr[0];
        
        for(int i=1 ; i<n; i++){
            int pick = arr[i];
            if(i>1){
                pick += dp[i-2];
            }
            int notPick = dp[i-1];
            
            dp[i] = max(pick , notPick);
            
        }
        
        return dp[n-1];
        // Your code here
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends