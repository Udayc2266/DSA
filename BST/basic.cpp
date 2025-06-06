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

bool search(Node*root , int key){ //0(Height) avg : 0(logN)
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }

   

}

Node* ISgetInorderSuccessor(Node* root){

    while(root->left != NULL){

        root=root->left;

    }
    return root;

}

Node* delNode(Node*root , int val){
    if(root == NULL){
        return NULL;
    }
    if(val < root->data){
        root->left = delNode(root->left , val);
    }  else if(val > root->data){
        root->right = delNode(root->right, val);
    }else{

        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL; 
        }

        if(root->left == NULL || root->right == NULL){
            delete root;
            return root->left == NULL ? root->right : root->left; 
        }

        Node* IS = ISgetInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right , IS->data );

    }

    return root;
}
int main(){

    int arr[6] = {5,1,3,4,2,7};

    Node* root = buildBST(arr,6);
    inOrder(root);
    cout<<endl;
    delNode(root,5);
    inOrder(root);

    return 0;
}