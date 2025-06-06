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


 
Node* insert(Node* root , int val){ //0(n)
    if(root == NULL){
        root = new Node(val);
        return root;
    }   
    if(val < root->data){
        root->left = insert(root->left, val );
    }else{
        root->right = insert(root->right , val);
    }

    return root;
}
Node* buildBST(int arr[], int n){

    Node* root = NULL;

    for(int i =0 ; i<n ; i++ ){
        root = insert(root, arr[i]);
    }
    return root;

}

void inOrder(Node* root){

    if(root == NULL){
        return ;
    }
    inOrder(root->left);
    cout<<root->data <<" ";
    inOrder(root->right);
    


}

bool helpValidateBST(Node*root, Node* min, Node* max ){
    if(root == NULL){
        return;
    }

    if(min != NULL && root < min ){
        return false;
    }
    if(max != NULL && root > max ){
        return false;
    }

    return helpValidateBST(root->left,min, root ) && helpValidateBST(root->right,  root, max );



}

bool validateBST(Node* root){


    return helpValidateBST(root,NULL , NULL);

    
}

int main(){

    int arr[6] = {5,1,3,4,2,7};

    Node* root = buildBST(arr,6);
    inOrder(root);
    

    return 0;
}