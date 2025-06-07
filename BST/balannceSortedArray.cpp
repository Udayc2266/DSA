#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){

            this->data = data;
            left = right = NULL;

        }
};

Node* buildBSTSortedVec(vector<int>arr , int st, int end){
    if(st>end){
        return NULL;
    }
    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);
    curr->left = buildBSTSortedVec(arr,st , mid-1);
    curr->right = buildBSTSortedVec(arr, mid+1 , end);
    return curr;

}

void getInOrder(Node*root,vector<int> &arr ){
    if(root==NULL){
        return;
    }
    getInOrder(root->left,arr);
    arr.push_back(root->data);
    getInOrder(root->right, arr);
    

}


Node* convertBSTtoBalance(Node* root){
    vector<int> arr;
    getInOrder(root, arr);
    return buildBSTSortedVec(arr,0,arr.size()-1);
}

Node* buildBSTfromSorted(int arr[7] , int st, int end){
    if(st>end){
        return NULL;
    }
    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);
    curr->left = buildBSTfromSorted(arr,st , mid-1);
    curr->right = buildBSTfromSorted(arr, mid+1 , end);
    return curr;

}

void prePrint(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    prePrint(root->left);
    
    prePrint(root->right);
    return;
}

int main(){ 

    int arr[7] = {3,4,5,6,7,8,9};


    Node* root =buildBSTfromSorted(arr,0,6);

    prePrint(root);
    return 0;
}