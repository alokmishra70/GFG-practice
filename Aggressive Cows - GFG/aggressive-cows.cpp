//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool canPlace(int n, int k, vector<int> &s , int dis){
        int cowCount = 1;
        int lastPos = s[0];
        
        for(int i = 0 ; i<n ; i++){
            if(s[i]-lastPos >= dis ){
                cowCount++;
                if(cowCount == k){
                    return true;
                }
                lastPos = s[i];
            }
        }
        return false;
    }


    int solve(int n, int k, vector<int> &s) {
    sort(s.begin() , s.end());
    int low = 0 , high = s[n-1] ;
    int res = -1;
    int mid = low + (high-low)/2;
    while(low <= high ){
        // int mid = (low+high)/ 2;
        if(canPlace(n,k,s,mid)){
            res = mid;
            low = mid + 1;
            
        }
        else{
            high = mid - 1 ;
        }
        mid = low + (high-low)/2;
    }
    return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends