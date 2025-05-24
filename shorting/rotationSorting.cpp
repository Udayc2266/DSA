#include<bits/stdc++.h>
using namespace std;



int rotationSorting (int arr[] , int si , int ei , int tar){
    int mid = si -(ei-si)/2;
    if(si>ei){
        return -1;
    }
    if(arr[mid] == tar){
        return mid;
    }
    if(arr[si]<= arr[mid]){
        if(arr[si]<= tar && arr[mid]>= tar){
            return rotationSorting(arr, si , mid-1 ,tar);
        }else{
            return rotationSorting(arr,  mid+1 , ei ,tar);
        }
    }else{
        if(arr[mid]<= tar && arr[ei] >= tar){

            return rotationSorting(arr,  mid+1 , ei ,tar);

        }else{
            return rotationSorting(arr, si , mid-1 ,tar);
        }
    }
    
    
}

int main(){

    int arr[] = { 4 , 5, 6, 7, 0, 1, 2 };

    int n = sizeof(arr)/sizeof(int);

    cout<<"index : "<<rotationSorting(arr, 0 , n-1 , 50)<<endl;

   

    return 0;
}