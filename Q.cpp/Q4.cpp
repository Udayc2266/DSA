#include<bits/stdc++.h>
using namespace std;

void tranverse (int arr[][3], int n ,int m , int x){

    int arrnew[n]={0};
    for(int  i =0 ; i<n ; i++){
        for(int j = 0 ; j<m ;j++){

            arrnew[arr[i][j]]    ++  ;
            if( x == arr[i][j]  ){
                cout<<arrnew[arr[i][j]]<<"\n";
            }else{
                cout<<"not exsit\n";
            }

        }

        
    }
    

    

}

int main(){

    int arr[2][3] ={{1,2,3} ,{4,5,6}};
    tranverse(arr, 2 , 3 , 6);
    
    return 0;
}