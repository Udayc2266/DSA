#include<bits/stdc++.h>
using namespace std;

int lcsRec(string s1 , string s2){                  //0(2^n+m)
    if(s1.size()==0 || s2.size()==0){
        return 0;
    }
    int n = s1.size();
    int m = s2.size();
    if( s1[n-1] == s2[m-1]){
        return lcsRec(s1.substr(0,n-1) , s2.substr(0,m-1)) + 1;
    }else{

        int ans1 = lcsRec(s1.substr(0,n-1) , s2);
        int ans2 = lcsRec(s1 , s2.substr(0,m-1));
        return max (ans1 , ans2);
    }
}

int lcsRecMem(string s1 , string s2 , vector<vector<int>>dp){                  //0(n*m)
    if(s1.size()==0 || s2.size()==0){
        return 0;
    }
    int n = s1.size();
    int m = s2.size();
    if(dp[n][m]!= -1){
        return dp[n][m];
    }
    if( s1[n-1] == s2[m-1]){
        dp[n][m]  = lcsRecMem(s1.substr(0,n-1) , s2.substr(0,m-1),dp) + 1;
        return dp[n][m];
    }else{

        int ans1 = lcsRecMem(s1.substr(0,n-1) , s2 ,dp);
        int ans2 = lcsRecMem(s1 , s2.substr(0,m-1),dp);
        dp[n][m] = max (ans1 , ans2);
        return dp[n][m];
    }
}

int lcsRecTeb(string s1 , string s2){                  //0(n*m)
   
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1 , vector<int> (m+1, 0));
    for(int i = 1 ; i<n+1; i++ ){
        for(int j = 1 ; j<m+1 ; j++){
            if( s1[i-1] == s2[j-1]){
                dp[i][j]= dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    
    string s1 = "abcdge";
    string s2 = "abedg";
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1 , -1));
    cout<<lcsRecTeb(s1,s2);
    cout<<lcsRecMem(s1,s2,dp);
    cout<<lcsRec(s1,s2);
    
    return 0;
}