#include<bits/stdc++.h>
using namespace std;



int maxSubarraySum(int*arr ,int n){
    int sum = 0;
  
    for(int start = 0 ; start < n ; start++){
        int maxi = 0;
        for(int end = start ; end < n ; end++){
            maxi += arr[end];
            maxi = max(maxi , sum) ;
            
        }
       cout<<"max sum is :" <<maxi;
        
    }
    
    
}

int main(){

    int arr[] = {2 , -3 , 6 , -5 , 4 , 2};
    int n = sizeof(arr)/sizeof(int);

    
    return 0;

}