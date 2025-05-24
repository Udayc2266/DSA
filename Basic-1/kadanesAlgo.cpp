#include<bits/stdc++.h>
using namespace std;



int maxSubarraySum(int*arr ,int n){
    int  cursum = 0;
    int maxsum =0;
  
    for(int start = 0 ; start < n ; start++){
    cursum += arr[start];
    maxsum = max(maxsum , cursum);
    if (cursum < 0){
        cursum = 0;
    }
    }
    cout<<"max : "<<maxsum;
}
int main(){

    int arr[] = {2 , -3 , 6 , -5 , 4 , 2};
    int n = sizeof(arr)/sizeof(int);

    
    return 0;

}