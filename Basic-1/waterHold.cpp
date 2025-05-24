#include<bits/stdc++.h>
using namespace std;

int trading(int *arr , int n){
    int leftMax[100000];
    leftMax[0] = arr[0];
    for(int i = 1 ; i < n ; i++){
        leftMax[i] = max(leftMax[i-1] , arr[i-1] );
    }
    int rightMax[100000];
    rightMax[n-1] = arr[n-1];
    for(int i = n-2  ; i >=0 ; i--){
        rightMax[i] = max(rightMax[i+1] , arr[i+1] );
    }
    int waterTrap = 0;
    
    for(int i = 0 ; i < n ; i++){
        int currWater = min(leftMax[i] , rightMax[i] ) - arr[i];
        if(currWater > 0){
            waterTrap += currWater;
        }
    }
    cout<<"water trapped : "<< waterTrap;

}


int main (){

    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(int);
    trading(arr , n);
    return 0;
}