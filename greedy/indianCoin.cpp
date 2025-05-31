#include<bits/stdc++.h>
using namespace std;

bool compare (pair<int, int> pairs1 ,pair<int, int> pairs2){
    return pairs1.second < pairs2.second;
}

int indianCoin(vector<int> coins , int v){
    int ans =0;
    int n = coins.size();
    for(int i = n ; v>0 && i>=0 ;i--){
        if( v>= coins[i]){
           ans += (v / coins[i]);
           v = v%coins[i];
        }
    }
    cout<<ans;
    return ans;
}

int main(){
    vector<int> coins = {1,2,5,10,20,50,100,200,500,2000};
    int v= 590;
    indianCoin(coins , v);
    return 0;
}