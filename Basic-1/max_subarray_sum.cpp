#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int*arr ,int n){
    int sum = 0;
    int maxsum =INT_MIN;
    for(int start = 0 ; start < n ; start++){
        for(int end = start ; end < n ; end++){
            
            
            for(int i = start ; i <= end ; i++){
                sum = sum + arr[i];    
            }
            
            maxsum = max(maxsum , sum) ;
            
        }
       cout<<"max sum is :" <<maxsum;
        
    }
    
    
}

int main(){

    int arr[] = {2 , -3 , 6 , -5 , 4 , 2};
    int n = sizeof(arr)/sizeof(int);
    maxSubarraySum(arr , n);

    
    return 0;

}