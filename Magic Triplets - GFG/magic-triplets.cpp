//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = 10^9 + 7;
	public:
	int countTriplets(vector<int>nums){
	    // Code here.
	    int cnt = 0;
	    int n = nums.size();
	    for( int  i=1 ; i<n-1; i++){
	        int less = 0  , more = 0;
	        
	        for(int j = i-1 ; j>= 0 ; j--){
	            if(nums[j]<nums[i]) less++;
	        }
	        
	        for(int j = i+1 ; j<n  ; j++){
	            if(nums[j]>nums[i]) more++;
	        }
	        
	        cnt += more*less;
	        
	    }
	    return cnt;
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends