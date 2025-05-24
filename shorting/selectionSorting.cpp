#include <bits/stdc++.h>
using namespace std;

void print(int*arr , int n){
    cout<<"[";
    for(int i=0 ; i< n ; i++){
        
        cout<<arr[i]<<",";
        
    }
    cout<<"]";
};

void selection(int *arr , int n){

    for (int i=0 ; i<n-1 ; i++){
        int min = i ;
        for(int j=1+i ; j<n ; j++){
            if(arr[j] > arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);

    }    

}

int main(){

    int arr[] = {5,4,1,3,2};
    int n = sizeof(arr)/ sizeof(int);
    
    selection(arr , n);
    print(arr , n);

    return 0;
}