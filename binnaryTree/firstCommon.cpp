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
static int idx = -1;
Node* binaryTree(vector<int> nodes){

    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode-> left = binaryTree(nodes);
    currNode-> right = binaryTree(nodes);
    return currNode;


}

bool rootToNode(Node* root, int n , vector<int> &path){
    if(root == NULL){
        return false;
    }
    path.push_back(root->data);
    if(root-> data == n){
        return true;
    }
    int isLeft = rootToNode(root->left,  n ,path );
    int isRight = rootToNode(root->right,  n ,path );

    if(isLeft || isRight){
        return true;
    }
    path.pop_back();
    return false;
}



int lastCommon(Node*root , int n1, int n2){ //0(n) , 0(n)
    vector<int> path1;
    vector<int> path2;

    if(! rootToNode(root, n1,path1)||!rootToNode(root, n2,path2)){
        return false;
    }


    int lca = -1;
    for(int i =0  ; i<path1.size() && i<path2.size() ; i++){
        if(path1[i] != path2[i]){
            break;

        }
        lca = path1[i];
    }
    return lca;

}

Node* lastCommon2(Node*root , int n1, int n2){ //0(n) , 0(1)
    if(root == NULL){
        return NULL;
    }

    if(root-> data == n1 || root->data == n2 ){
        return root;
    }
    Node* leftLCA = lastCommon2(root->left,n1,n2);
    Node* rightLCA = lastCommon2(root->right,n1,n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }
    return leftLCA == NULL ? rightLCA : leftLCA;
    
}

int dist(Node*root , int n){
    if(root == NULL){
        return -1;
    }
    if(root->data == n){
        return 0;
    }

    int LD = dist(root->left, n);
    int RD = dist(root->right, n);

    if(LD != -1){
        return LD+1;
    }
    if(RD != -1){
        return RD+1;
    }
    return -1;
}

int sortDistance(Node*root , int n1, int n2){ //0(n)

    Node* LCA = lastCommon2(root , n1 , n2);

    int dist1 = dist(LCA , n1); 
    int dist2 = dist(LCA , n2); 

    return dist1 + dist2;

}


int KthAncestor(Node*root , int node, int k){
    if(root == NULL){
        return -1;
    }
    if(root->data == node){
        return 0;
    }
    int LS = KthAncestor(root -> left,  node,  k);
    int RS = KthAncestor(root -> right,  node,  k);
    if(LS == -1 && RS ==-1 ){
        return -1;
    }
    int valid = LS == -1 ? RS : LS;
    if(valid+1 == k){
        cout<<root->data;
    }

    return valid+1; 

}


int tansform(Node* root){ //0(n)

    if(root == NULL){
        return 0;
    }

    int leftOld = tansform(root->left);
    int rightOld = tansform(root->right);

    int curr = root->data;

    root->data = leftOld + rightOld ;
    if(root->left!=NULL){
        root->data+= root->left->data ;
    }
    if(root->right!=NULL){
         root->data+=root->right->data;
    }

    return curr;


}



int main(){

    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node*root = binaryTree(nodes);
    cout<<KthAncestor(root,6,1);

    return 0;
}