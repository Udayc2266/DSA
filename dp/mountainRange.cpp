#include<bits/stdc++.h>
using namespace std;



int mountainRange(int n ){
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
   
    cout<<mountainRange(n);
    

    
    return 0;
}