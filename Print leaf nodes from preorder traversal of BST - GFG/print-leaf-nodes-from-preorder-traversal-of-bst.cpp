//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
    
    vector<int> solve(int preorder[], int n)
{
    vector<int>v;
    stack<int> s;
    for (int i = 0, j = 1; j < n; i++, j++)
    {
        bool found = false;
 
        if (preorder[i] > preorder[j])
            s.push(preorder[i]);
 
        else
        {
            while (!s.empty())
            {
                if (preorder[j] > s.top())
                {
                    s.pop();
                    found = true;
                }
                else
                    break;
            }
        }
 
        if (found)
            v.push_back(preorder[i]);
    }
 
    // Since rightmost element is always leaf node.
    v.push_back(preorder[n - 1]);
    
    return v;
}
  public:
    vector<int> leafNodes(int arr[],int N) {
        // code here
        return solve(arr,N);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends