//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    long long int countDp(int coins[] , int n , int sum , vector<vector<long long int>> &dp){
        
        if(n==0){
            return (sum%coins[0] == 0);
        }
        if(dp[n][sum] != -1) return dp[n][sum];
        long long int nottake = countDp(coins,n-1,sum,dp);
        long long int take =  0;
        if(coins[n] <= sum ) take = countDp(coins , n , sum-coins[n] ,dp );
        
        return dp[n][sum] = take + nottake;
    }
    
  public:
  
    long long int count(int coins[], int n, int sum) {
        
        vector<vector<long long int>>dp(n,vector<long long int>(sum+1 , -1));
        
        return countDp(coins,n-1,sum,dp);
        
        


    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends