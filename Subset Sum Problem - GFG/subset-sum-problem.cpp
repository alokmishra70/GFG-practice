//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool memoFun(vector<int>& arr , int indx , int target , vector<vector<int>>&dp){
        if(target == 0) return true;
        if(indx == 0) return (arr[0] == target);
        
        if(dp[indx][target] != -1) return dp[indx][target];
        
        bool notTake = memoFun(arr, indx-1 , target , dp);
        bool take = false;
        if(target >= arr[indx]) take = memoFun(arr,indx-1 , target - arr[indx] , dp);
        
        return  dp[indx][target] = take or notTake;
    }
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<vector<int>>dp( n, vector<int>(target+1 , -1)); 
        
        return memoFun(arr, n-1 , target , dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends