#include<bits/stdc++.h>
using namespace std;
 

int main(){

   int  arr[] ={1,5,699999,2,48,96,9990};
   int n = sizeof(arr)/sizeof(int);
   int max = arr[0];

   for(int i =1 ; i<n ; i++){
   

    if(arr[i]> max){

        max = arr[i];

        

    }

    


   }
   cout<<"max is :"<<max; 

   return 0;
}