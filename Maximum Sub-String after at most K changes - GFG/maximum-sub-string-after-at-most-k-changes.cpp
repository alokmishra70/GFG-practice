//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int findLen(string& A, int n, int k, char ch)
    {
    int maxlen = 1;
    int cnt = 0;
    int l = 0, r = 0;
     
   
    while (r < n) {
     
        
        if (A[r] != ch)
            ++cnt;
 
        
        while (cnt > k) {
            if (A[l] != ch)
                --cnt;
            ++l;
        }
 
        maxlen = max(maxlen, r - l + 1);
        ++r;
    }
    return maxlen;
}
 
int answer(string& A, int n, int k)
{
    int maxlen = 1;
    for (int i = 0; i < 26; ++i) {
        maxlen = max(maxlen, findLen(A, n, k, i+'A'));
        maxlen = max(maxlen, findLen(A, n, k, i+'a'));
    }
    return maxlen;
}
	
	
		int characterReplacement(string s, int k){
		   return answer(s,s.size(),k);
		   
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends