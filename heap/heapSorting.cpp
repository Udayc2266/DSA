#include<bits/stdc++.h>
using namespace std;

void heapify(int i , vector<int>&arr , int n){
    int left = 2*i +1;
    int right = 2*i +2;
    int maxI = i;
    if(left < n  && arr[left] > arr[maxI]){

        maxI = left;

    }
    if(left < n  && arr[right] > arr[maxI]){

        maxI = right;

    }

    if(maxI != i){
        swap(arr[maxI], arr[i]);
        heapify(maxI, arr,n);
    }
}

void heapSort(vector<int>&arr){ //0(nlogn)
    int n= sizeof(arr);
    //bulid the maxHeap
    for (int i =n/2 - 1 ; i>= 0; i--){ //0(nlogn)
        heapify(i , arr , n);
    }
    //take els to connect pos
    for(int i = n-1 ; i >= 0 ; i--){ //0(nlogn)
        swap(arr[i], arr[0]);
        heapify(0 , arr, i);
    }
}

int main(){


    return 0;
}