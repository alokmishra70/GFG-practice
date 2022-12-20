//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        int maxi1 = INT_MIN;
        int maxi2 = INT_MIN;
        int mini1 = INT_MAX;
        int mini2 = INT_MAX;
        for(int i = 0 ; i<n ; i++){
            maxi1 = max(maxi1 , arr[i] + i);
            mini1 = min(mini1 , arr[i] + i );
            maxi2 = max(maxi2 , arr[i] - i );
            mini2 = min(mini2 , arr[i] - i);
        }
        return max(maxi1 - mini1 , maxi2 - mini2) ;
        // Complete the function
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends