#include<bits/stdc++.h>
using namespace std;

void Q5(int arr[],int i ,int n ,int m){
    if(i== m){
        
        return;
    }   
    if( arr[i] == n){
        cout<<"index : "<<i<<" "<<endl;
        
    }
    
    Q5(arr,i+1 ,n , m);
}

int main(){
    int arr[] = {3, 2, 4, 5, 6, 2, 7, 2, 2};
    int n = sizeof(arr)/sizeof(int);

    Q5(arr,0, 2 , n);
    

    return 0;
}