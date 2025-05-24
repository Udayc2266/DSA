#include<bits/stdc++.h>
using namespace std;

vector <int>  pairSum(vector<int> arr, int target){
    int st = 0 , ls = arr.size()-1 ;
    int currSum = 0;
    vector <int> ans;
    while(st<ls){

        currSum = arr[st] + arr[ls];
        if(currSum == target){

            ans.push_back(st);
            ans.push_back(ls);
            return ans;
        }else if(currSum > target){
            ls--;
        }else{
            st++;
        }

    }
    return ans;
}

int main(){
    vector <int> vec ={2,7,11,14};
    int target = 13;
    vector<int> ans = pairSum (vec , target);

    cout<<"ans : "<<ans[0]<<","<<ans[1];


    return 0;
}