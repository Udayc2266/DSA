#include <bits/stdc++.h>
using namespace std;

void print(int*arr , int n){
    cout<<"[";
    for(int i=0 ; i< n ; i++){
        
        cout<<arr[i]<<",";
        
    }
    cout<<"]";
};

void bubble(int *arr , int n){

    for(int i = 0 ; i < n-1 ; i++){
        bool isSwap = false;
        for(int j =0 ; j< n-i-1 ; j++){
            if(arr[j]>arr[j+1] ){
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }

            if(!isSwap){
                return;
            }
        }   
    }
}



int main(){

    int arr[] = {5,4,1,3,2};
    int n = sizeof(arr)/ sizeof(int);
    
    bubble(arr , n);
    print(arr , n);

    return 0;
}