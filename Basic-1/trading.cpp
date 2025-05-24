#include<bits/stdc++.h>
using namespace std;

int trading(int *arr , int n){
    int bestBuy[100000];
    bestBuy[0] = INT_MAX;
    for(int i = 1 ; i < n ; i++){
        bestBuy[i] = min(bestBuy[i-1] , arr[i-1] );
    }
    int maxProfit = 0;
    for(int i = 0 ; i < n ; i++){
        int currProfit = arr[i] - bestBuy[i];
        maxProfit = max(maxProfit , currProfit );
    }

    cout<<"Best Profit : "<<maxProfit;
}


int main (){

    int arr[] = {457,11,526,63,613,40,355,467,986,23,0,456,975};
    int n = sizeof(arr)/sizeof(int);
    trading(arr , n);
    return 0;
}