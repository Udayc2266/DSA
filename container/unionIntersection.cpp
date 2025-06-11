#include<bits/stdc++.h>
using namespace std;

int Union(vector<int>arr , vector<int>arr2){

    
    unordered_set<int> s;
    for(int i = 0 ; i<arr.size();i++){
        s.insert(arr[i]); 
    }
    for(int i = 0 ; i<arr2.size();i++){
        s.insert(arr2[i]); 
    }

    for(int el:s){
        cout<<el;
    }
    return s.size();


}
void intersection(vector<int>arr , vector<int>arr2){

    
    unordered_set<int> s;
    for(int i = 0 ; i<arr.size();i++){
        s.insert(arr[i]); 
    }
    for(int i = 0 ; i<arr2.size();i++){
        if(s.count(arr2[i])){
            cout<<arr2[i];
            s.erase(arr2[i]);
        }
    }

    

}

int main(){
    vector<int>arr = {7,3,9} ;
    vector<int>arr2 = {6,3,9,2,9,4};
    intersection(arr , arr2);

    return 0;
}