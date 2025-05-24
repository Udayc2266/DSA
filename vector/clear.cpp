#include<bits/stdc++.h>
using namespace std;

void clear(int n , int i , int j){

    while(i<=j){
        n = n &(~(1<<i));
        i++;
    }

    cout<<n;

}

int main(){

    clear(15 , 1 , 3);
    


    return 0;
}