//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
	public:
		int NthTerm(int n){
		    long long int ans = 1 ;
		    long long int mod = 1000000007;
		  //  dp[1] = 2;
		  //  int ans = 0;
		    
		    for(int i=1 ; i<=n; i++){
		        ans = (ans*i) %mod + 1 ;
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends