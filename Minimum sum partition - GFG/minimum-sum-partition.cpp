//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int totalSum = 0 ;
	    for(int i=0 ; i<n; i++) totalSum += arr[i];
	    
	    int target = totalSum ;
	    vector<vector<bool>>dp( n, vector<bool>(target+1 , 0)); 
        
        for(int i=0 ; i<n; i++){
            dp[i][0] = true;
        }
        if(arr[0] <= target )dp[0][arr[0]] = true;
        
        for(int i=1 ; i<n; i++){
            for(int k = 1 ; k<= target ; k++){
                bool notTake = dp[i-1][k];
                bool take = false;
                if(k >= arr[i]) take = dp[i-1][k - arr[i]];
                dp[i][k] = take or notTake;
            }
        }
        
        int mini = 1e9;
        
        for(int s1 = 0 ; s1 <= totalSum/2 ; s1++){
            if(dp[n-1][s1] == true){
                mini = min(mini , abs(totalSum - s1) -s1);
            }
            
        }
        return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends