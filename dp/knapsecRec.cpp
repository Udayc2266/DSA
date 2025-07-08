#include<bits/stdc++.h>
using namespace std;

int knapsecRec(vector<int> val , vector<int> wt , int w, int n){        //0(2^n)

    if(n == 0 || w == 0){
        return 0;
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= w){
        int ans1 = knapsecRec(val, wt,w-itemWt,n-1) + itemVal;
        int ans2 = knapsecRec(val,wt,w,n-1);
        return max(ans1, ans2);
    }else{

        return knapsecRec(val,wt,w,n-1);

    }
}

int knapsecRecMem(vector<int> val , vector<int> wt , int w, int n , vector<vector<int>> &dp){        //0(n*w)

    if(n == 0 || w == 0){
        return 0;
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(dp[n][w] != -1){
        return dp[n][w];
    }

    if(itemWt <= w){
        int ans1 = knapsecRecMem(val, wt,w-itemWt,n-1,dp) + itemVal;
        int ans2 = knapsecRecMem(val,wt,w,n-1,dp);
        dp[n][w]= max(ans1, ans2);
        return dp[n][w];
    }else{

        dp[n][w] = knapsecRecMem(val,wt,w,n-1,dp);
        return dp[n][w];

    }
}

int knapsecRecTab(vector<int> val , vector<int> wt , int w, int n){ // 0(n*w)

    vector<vector<int>> dp(n+1, vector<int> (w+1,0)) ;  
    for(int i =1 ; i<n+1 ; i++){
        for(int j = 1 ; j<w+1 ; j++){
            int itemWt = wt[i-1];
            int itemVal = val[i-1];
            if( itemWt <= j ){
                dp[i][j] = max(itemVal + dp[i-1][j-itemWt],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w]; 

}

int main(){
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int w = 7;
    int n = 5;

    vector<vector<int>> dp(n+1, vector<int> (w+1,-1)) ;  // dp -> row then vector col
    cout<<knapsecRecMem(val,wt,w,n,dp);

    cout<<knapsecRec(val,wt,w,n);

    cout<<knapsecRecTab(val,wt,w,n); 

    
    return 0;
}