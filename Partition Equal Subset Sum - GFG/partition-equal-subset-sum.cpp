//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int memoFun(int arr[] , int target , int indx , vector<vector<int>>&dp){
        if(target == 0) return 1;
        if(indx == 0) return (arr[0] == target);
        if(dp[indx][target] != -1) return dp[indx][target];
        
        int notTake = memoFun(arr , target , indx-1 , dp);
        int take = 0;
        if(target >= arr[indx]) take = memoFun(arr , target-arr[indx], indx-1 , dp);
        
        return dp[indx][target] = take or notTake;
    }
    int equalPartition(int n, int arr[])
    {
        int sum =0 ;
        for(int i=0 ; i<n; i++){
            sum += arr[i];
        }
        int s = sum/2;
        vector<vector<int>>dp(n, vector<int>(s+1 , -1));
        
        
        if(sum&1) return false;
        else{
            return memoFun(arr , s , n-1  , dp);
        }
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends