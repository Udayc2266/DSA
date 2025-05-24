#include <bits/stdc++.h>
using namespace std;

void print(int*arr , int n){
    cout<<"[";
    for(int i=0 ; i< n ; i++){
        
        cout<<arr[i]<<",";
        
    }
    cout<<"]";
};

void countSorting(int *arr , int n){
    int freq[100000] = {0} ;
    int minVal = INT_MAX , maxVal= INT_MIN;
    
    for(int i=0 ; i<n; i++){
        freq[arr[i]]++;
        minVal = min(minVal , arr[i]);
        maxVal = max(maxVal , arr[i]);
    };
    for(int i = minVal , j=0 ; i <= maxVal ; i++){
        while(freq[i] > 0){
            arr[j++] = i;
            freq[i]--;
        }
    }

}

int main(){

    int arr[] = {5,1,2,6,4,3,4,1,3,2};
    int n = sizeof(arr)/ sizeof(int);
    
    countSorting(arr , n);
    print(arr , n);

    return 0;
}