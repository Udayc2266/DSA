#include<bits/stdc++.h>
using namespace std;


int main(){
    
    vector<int> a = {4,1,8,7};
    vector<int> b = {2,3,6,5};

    sort (a.begin() , a.end());

    sort (b.begin() , b.end());
    int absDiff = 0;

    for(int i = 0 ; i<a.size() ; i++){
        absDiff += abs(a[i] - b[i]);
    }

    cout<<absDiff; 
    return 0;
}