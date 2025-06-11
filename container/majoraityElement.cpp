#include<bits/stdc++.h>
using namespace std;

void majorityElement(vector<int> nums){

    unordered_map<int,int> m;
    for(int i =0 ; i<nums.size(); i++){
        if(m.count(nums[i])){
            m[nums[i]]++;
        }else{
            m[nums[i]] = 1;
        }
    }

    for(pair<int,int> p : m){
        if(p.second > nums.size()/3){
            cout<<p.first;
        }
    }


}

int main(){
    vector<int> nums = {1,3,2,5,1,3,1,5,1};
    vector<int> nums2 ={1,2};
    majorityElement(nums2);
    return 0;
}