#include<bits/stdc++.h>
using namespace std;

void bubble (int *arr , int n){
    for(int i=0; i<n-1 ; i++){
        for(int j=0; j<n-1-i ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
    for(int i=0; i<n ; i++){
        cout<<arr[i];
    }
    
}

void insertion(int *arr , int n){
    for(int i=0; i<n ;i++){
        int min = i;
        for(int j=i+1 ; j<n ; j++){
            if(arr[min]>arr[j] ){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
    for(int i=0; i<n ; i++){
        cout<<arr[i];
    }
}

void selection(int *arr , int n){

    for (int i=1 ; i<n ; i++){
        int curr = arr[i];
        int pre = arr[i-1];
        while(pre>=0 && arr[pre] >curr){
            swap(arr[pre],arr[pre+1]);
            pre--;
        }
        arr[pre+1] =curr;
    }    
    for(int i=0; i<n ; i++){
        cout<<arr[i];
    }
}

int main(){

    int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    int n = sizeof(arr)/sizeof(int);

    bubble (arr , n);
    insertion(arr ,  n);
    selection(arr, n);

    return 0;
}