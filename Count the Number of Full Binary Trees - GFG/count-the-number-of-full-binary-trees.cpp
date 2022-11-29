//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod = 1000000007;
public:
    
    long long int numoffbt(long long int arr[], int n){
        // Your code goes here
    long long int maxvalue = INT_MIN, minvalue = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        maxvalue = max(maxvalue, arr[i]);
        minvalue = min(minvalue, arr[i]);
    }
 
    int mark[maxvalue + 2];
    int value[maxvalue + 2];
    memset(mark, 0, sizeof(mark));
    memset(value, 0, sizeof(value));
 
    
    for (int i = 0; i < n; i++)
    {
        mark[arr[i]] = 1;
        value[arr[i]] = 1;
    }
 
    
    long long int ans = 0;
    for (int i = minvalue; i <= maxvalue; i++)
    {
        
        if (mark[i])
        {
            
            
            for (int j = i + i;
                 j <= maxvalue && j/i <= i; j += i)
            {
                
                
                if (!mark[j])
                    continue;
 
                
                value[j] = value[j] + (value[i] * value[j/i]);
 
                
                if (i != j/i)
                    value[j] = value[j] + (value[i] * value[j/i]);
            }
        }
 
        ans += value[i];
    }
 
    return ans%mod;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends