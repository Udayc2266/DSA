#include<bits/stdc++.h>
using namespace std;


int longestComSubstring(string s1 , string s2){                  //0(n*m)
   
    int n = s1.size();
    int m = s2.size();
    int ans = 0;

    vector<vector<int>> dp(n+1 , vector<int> (m+1, 0));
    for(int i = 1 ; i<n+1; i++ ){
        for(int j = 1 ; j<m+1 ; j++){
            if( s1[i-1] == s2[j-1]){
                dp[i][j]= dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int main(){
    
    string s1 = "abcdge";
    string s2 = "abedg";
    cout<<longestComSubstring(s1,s2);

    return 0;
}