#include<bits/stdc++.h>
using namespace std;

int mcmRec(vector<int> arr , int i , int j){
    if(i == j){
        return 0;
    }
    int ans = INT_MAX;
    for(int k=i; k<j ; k++ ){
        //(i  ,  k)
        int cost1 = mcmRec(arr , i , k);
        //(K+1  , j)
        int  cost2 = mcmRec(arr , k+1 , j);

        int currCost = cost1 + cost2 + (arr[i-1]* arr[k]  * arr[j]);
        ans = min(ans, currCost);
    }
    return ans; 
}

int mcmRecMem(vector<int> arr , int i , int j ,vector<vector<int>> &dp){
    if(i == j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k=i; k<j ; k++ ){
        //(i  ,  k)
        int cost1 = mcmRecMem(arr , i , k, dp);
        //(K+1  , j)
        int  cost2 = mcmRecMem(arr , k+1 , j,dp);

        int currCost = cost1 + cost2 + (arr[i-1]* arr[k]  * arr[j]);
        ans = min(ans, currCost);
        
    }
    return dp[i][j]  = ans; 
    
}

int mcmTab(vector<int> arr , int i , int j ){
    if(i == j){
        return 0;
    }
    int n = arr.size();
    vector<vector<int>> dp(n , vector<int> (n, 0));
    for(int i =1 ;  i<n; i++){
        dp[i][i]=0;
    }
    int ans = INT_MAX;
    for(int len = 2; len <=n ; len++){
        for(int i =1 ; i<=n-len ; i++){
            int j = i+len-1;
            dp[i][j]= INT_MAX;
            for(int k = i ; k<j ;  k++){
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                int currCost = cost1 + cost2 + (arr[i-1]* arr[k]  * arr[j]);
                dp[i][j] = min(dp[i][j],currCost);
            }

        }
    }
    return dp[i][j] ; 
    
}

int main(){
    
    vector<int> arr = {1,2,3,4,3};  // 1-> n-1
    int n = arr.size();
    cout<<mcmRec(arr, 1 , n-1);

    vector<vector<int>> dp(n , vector<int> (n, -1));

    cout<<mcmRecMem(arr, 1 , n-1 , dp);

    cout<<mcmTab(arr, 1 , n-1);
    return 0;
}