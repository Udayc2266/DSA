#include<bits/stdc++.h>
using namespace std;


int partition(int arr[] ,int si  ,int ei){
    int pivot = arr[ei];
    int i = si-i;

    for(int j = 0; j <= ei - 1 ; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);

    return i;
   
}

void print(int *arr , int n){

    for(int x=0; x<n ;x++){
        cout<<arr[x]<<" ";


    }

}


void quickSorting (int arr[] , int si , int ei){

    if(si >= ei ){
        return;
    }
    int pivotIdx = partition(arr,si,ei);

    quickSorting(arr, si , pivotIdx-1);
    quickSorting(arr, pivotIdx+1 , ei);
    
}

int main(){

    int arr[] = { 4 , 5, 6, 7, 0, 1, 2 };

    int n = sizeof(arr)/sizeof(int);

    quickSorting(arr, 0 , n-1);

    print(arr , n);

    return 0;
}