//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends


long long recursiveFun(int m , int n , vector<vector<int>>&dp){
    if(m == 0 and n == 0) return 1;
    if(m < 0 || n < 0) return 0;
    if(dp[m][n] != -1) return dp[m][n];
    
    long long  down = recursiveFun(m-1 , n , dp);
    long long right = recursiveFun(m,n-1 , dp);
    
    return dp[m][n] = down + right; 
}

long long  numberOfPaths(int m, int n)
{
    vector<vector<int>>dp(m , vector<int>( n , -1));
    return recursiveFun(m-1,n-1 , dp);
    // Code Here
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends