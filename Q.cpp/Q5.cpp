#include<bits/stdc++.h>
using namespace std;

void Q5(int arr[],int i ,int n){
    if(i==n){
        cout<<"not found"<<endl;
        return;
    }   
    if( arr[i] == n){
        cout<<"index : "<<i<<endl;
        return ;
    }
    
    Q5(arr,i+1 ,n);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(int);

    Q5(arr,0, 9);
    

    return 0;
}