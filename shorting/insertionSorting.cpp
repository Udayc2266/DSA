#include <bits/stdc++.h>
using namespace std;

void print(int*arr , int n){
    cout<<"[";
    for(int i=0 ; i< n ; i++){
        
        cout<<arr[i]<<",";
        
    }
    cout<<"]";
};

void insertion(int *arr , int n){

    for (int i=1 ; i<n ; i++){
        int curr = arr [i];
        int pre = i-1;
        while(pre >= 0 && arr[pre] < curr){
            swap(arr[pre] , arr[pre+1]);
            pre--; 
        }
        arr[pre+1] = curr;
    }    

}

int main(){

    int arr[] = {5,4,1,3,2};
    int n = sizeof(arr)/ sizeof(int);
    
    insertion(arr , n);
    print(arr , n);

    return 0;
}