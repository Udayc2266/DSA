#include<bits/stdc++.h>
using namespace std;



void question (int *arr , int n){
    bool a = false;
    for(int i = 0 ; i< n ; i++){
        for(int j = i+1 ; j <n ; j++){
            if(arr[i]==arr[j]){
                a = true;
            }
        }
    }
    cout<<a;
};

int main(){

    int arr[] = {1,4,32,42};
    int n = sizeof(arr)/sizeof(int);

    question(arr , n);

    return 0;
}