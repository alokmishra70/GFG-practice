//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends


long long recursiveFun(int m , int n){
    if(m == 0 and n == 0) return 1;
    if(m < 0 || n < 0) return 0;
    
    long long  down = recursiveFun(m-1 , n);
    long long right = recursiveFun(m,n-1);
    
    return down + right; 
}

long long  numberOfPaths(int m, int n)
{
    return recursiveFun(m-1,n-1);
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