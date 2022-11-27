//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string addBinary(string A, string B)
	{
	    if(A.length() > B.length()){
	        return addBinary(B , A) ;
	    }
	    int diff = B.length() - A.length() ;
	    
	    string padding;
	    for(int i=0 ; i<diff ; i++){
	        padding.push_back('0');
	    }
	    
	    A = padding + A ;
	    
	    string res ;
	    char carry = '0';
	    
	    for(int i = A.length() - 1 ; i>=0 ; i--){
	        if(A[i] == '1' and B[i] == '1'){
	            if(carry == '1'){
	                res.push_back('1') , carry = '1';
	            }
	            else {
	                res.push_back('0') , carry = '1';
	            }
	        }
	        else if(A[i] == '0' and B[i] == '0'){
	            if(carry == '1'){
	                res.push_back('1') ,carry = '0';
	            }
	            else {
	                res.push_back('0') , carry = '0';
	            }
	        }
	        else if(A[i] != B[i]){
	            if(carry == '1'){
	                res.push_back('0') , carry = '1';
	            }
	            else{
	                res.push_back('1') , carry ='0';
	            }
	        }
	        
	    }
	    
	    if(carry == '1') {
	       res.push_back(carry);
	    }
	       
	       
	    reverse(res.begin() , res.end());
	    
	    
	    int index = 0 ;
	    while(index+1 < res.length() and res[index] == '0')
	        index++;
	    
	    
	    return (res.substr(index));
	    // your code here
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends