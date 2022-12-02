//{ Driver Code Starts
// C++ program to Print root to leaf path WITHOUT
// using recursion
#include <bits/stdc++.h>
using namespace std;

bool isBinary(string str);

// Driver program to test above functions
int main()
{
    string str;
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
       cin >> str;
       cout << isBinary(str) << endl;
    }
    return 0;
}

// } Driver Code Ends


// Return true if str is binary, else false
bool isBinary(string str)
{
    if(str == "1" || str == "0") return true;
    else if(count(str.begin() , str.end() , '1') > 0 && count(str.begin(),str.end(),'0') > 0){
        return true;
    }
    else {
        return false;
    }
   // Your code here
}