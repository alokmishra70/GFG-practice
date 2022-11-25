//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    vector<int> dp1(n,1);
	    
	    for(int i=0 ; i<n ; i++){
	        for(int pre = 0 ; pre < i ; pre++){
	            
	            if(nums[pre] < nums[i] and 1+dp1[pre] > dp1[i]){
	                dp1[i] = 1 + dp1[pre];
	            }
	        }
	    }
	    
	    vector<int> dp2(n,1);
	    
	    for(int i=n-1 ; i>=0 ; i--){
	        for(int pre = n-1 ; pre > i ; pre--){
	            
	            if(nums[pre] < nums[i] and 1+dp2[pre] > dp2[i]){
	                dp2[i] = 1 + dp2[pre];
	            }
	        }
	    }
	    
	    int maxi = INT_MIN;
	    
	    for(int i=0 ; i<n ; i++){
	        maxi = max(maxi , dp1[i]+dp2[i]-1);
	    }
	    return maxi;
	    
	    // code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends