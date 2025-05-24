#include<bits/stdc++.h>
using namespace std;

int solid_rombus (int n){

    for (int i =1 ; i<=n ; i++){
        for(int j= 1; j<=(n-i); j++ ){
            cout<<" ";

        }
        for(int j=1 ; j<=n ; j++){
            cout<<"*";
        }
        cout<<endl;
    }



}


int main(){

    solid_rombus(9);


    return 0;

}