#include<bits/stdc++.h>
using namespace std;

int catal(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    int ans = 0;
    for(int i = 0 ; i<n ; i++){
        ans += catal(i) * catal(n-i-1); 

    }

    return ans;
}

int catalMem(int n , vector<int> &dp){
    if(n == 0 || n == 1){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = 0;
    for(int i = 0 ; i<n ; i++){
        ans += catalMem(i,dp) * catalMem(n-i-1,dp);
    }

    return dp[n] = ans;
}

int catalTab(int n ){
    vector<int> dp(n+1,-1);
    dp[0] = 1;
    dp[1] = 1;
    if(dp[n] != -1){
        return dp[n];
    }
    
    for(int i = 2 ; i<=n ; i++){
        int ans = 0;
        for(int j = 0 ; j<i ; j++){
            ans += dp[j] * dp[i-1-j]; 
        }
        dp[i] = ans;
    }
    

    return dp[n];
}


int main(){
    int n = 15;
    vector<int> dp(n+1,-1);
    cout<<catalMem(n,dp)<<endl;
    cout<<catal(n)<<endl;
    cout<<catalTab(n);
    

    
    return 0;
}