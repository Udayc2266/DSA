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
void printInRange(Node* root , int start , int end){
    if(root==NULL){
        return;
    }

    if(start<= root->data && end >= root->data){
        cout<<root->data;
        printInRange( root->left ,  start ,  end);
        printInRange( root->right ,  start ,  end);

    }else if (start> root->data){

        printInRange( root->right ,  start ,  end);

    }else{

        printInRange( root->left ,  start ,  end); 

    }
   
    

}

void pathPrint(vector<int> path){

    for(int i = 0 ; i< path.size();i++){
        cout<<path[i];
    }
    cout<<endl;
}

void helpPath(Node* root,vector<int> path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        pathPrint(path);
        path.pop_back();
        return;
    }

    helpPath(root->left, path);
    helpPath(root->right, path);

    path.pop_back();
    return;


}

void rootToLeaf(Node* root){
    vector<int>path;
    helpPath(root,path);
}

void validateBST(Node* root){
    
}

int main(){

    int arr[6] = {5,1,3,4,2,7};

    Node* root = buildBST(arr,6);
    inOrder(root);
    

    return 0;
}