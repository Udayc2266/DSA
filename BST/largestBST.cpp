//difficute
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


class Info{
    public:
        bool isBST;
        int min;
        int max;
        int sz;

        Info( bool isBST,int min,int max,int sz){
            this->isBST = isBST;
            this->min = min;
            this->max = max;
            this->sz = sz;
        }
};

static int maxSize ;

Info* largestBST(Node* root){     //0(n)
    if(root == NULL){
        return NULL;
    }

    if(root->left ==  NULL && root->right ==  NULL){
        return new Info(true, INT_MAX,INT_MIN,0); 
    }
    Info* left = largestBST( root->left);
    Info* right = largestBST( root->right);

   
    int Currmin = min(root->data,min (left->min,right->min));
    int Currmax = max(root->data,max (left->min,right->min));
    int CurrSize = left->sz + right->sz + 1 ;

    if(left->isBST && right->isBST
        && root->data >left->max 
        && root->data < right->min){
            maxSize = max(maxSize,CurrSize);
            return new Info(true, Currmin,Currmax,CurrSize);
    }
    return new Info(false, Currmin,Currmax,CurrSize);
}

int main(){ 

    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left  = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);
    cout<<largestBST(root)->sz;
    
    return 0;
}