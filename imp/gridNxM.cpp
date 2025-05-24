#include<bits/stdc++.h>
using namespace std;

int grid(int r , int c , int n , int m){
    if(r == n-1 && c == m-1){
        return 1;
    }
    if(r >= n || c>=m){
        return 0;
    }

    int val1 = grid(r , c+1 , n , m);

    int val2 = grid(r+1 , c , n , m);

    return val1 + val2;
}

int main(){
    int n=10;
    int m=10;
    cout<<grid(0,0 ,n,m);

    return 0;
}