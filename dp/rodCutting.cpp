#include<bits/stdc++.h>
using namespace std;

int unboundedKnapsec(vector<int> prise , vector<int> lenght , int rod , int n){

    vector<vector<int>> dp(n+1, vector<int>(rod+1 , 0));
     for(int i=1 ; i<=n+1 ; i++){

        for(int j =1 ; j<= rod+1 ; j++){
            int itemVal = prise[i-1];
            int itemWt = lenght[i-1];
            if(itemWt<=j){

                dp[i][j] = max(itemVal+dp[i][j-itemWt] , dp[i-1][j]);

            }else{

                dp[i][j] =  dp[i-1][j];

            }
        }

        return dp[n][rod];

    }

}

int main(){
    
    vector<int> prise = {15, 14 , 10 , 45, 30};
    vector<int> lenght = {2, 5, 1, 3, 4};
    int rod = 7;
    int n = 5;
    cout<<unboundedKnapsec(prise,lenght,rod,n);
    
    return 0;
}