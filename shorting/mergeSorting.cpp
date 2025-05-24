#include<bits/stdc++.h>
using namespace std;


void merge(int *arr ,int si ,int mid ,int ei){

    vector<int> temp;
    int i = si;
    int j=mid+1;
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);

        }else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){

        temp.push_back(arr[i++]);

    }

    while(j<=ei){

        temp.push_back(arr[j++]);

    }

    for(int idx = si , x=0 ; idx<=ei ; idx++ ){
        arr[idx] = temp[x++];
    }

}

void print(int *arr , int n){

    for(int x=0; x<n ;x++){
        cout<<arr[x]<<" ";


    }

}


void mergeShorting (int *arr , int si , int ei){

    if(si>=ei){
        return;
    }

    int mid = si-(ei-si)/2;


    mergeShorting (arr , si , mid);
    mergeShorting (arr , mid+1, ei);

    merge(arr , si , mid , ei);
}

int main(){

    int arr[] = { 2,3,-2,4 };

    int n = sizeof(arr)/sizeof(int);

    mergeShorting(arr, 0 , n-1);

    print(arr , n);

    return 0;
}