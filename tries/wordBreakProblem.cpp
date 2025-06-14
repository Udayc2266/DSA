#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
        unordered_map<char , Node*> children;
        bool endOfWord;
        Node(){
            endOfWord = false;
        }

};

class Trie{

    Node* root;


    public:
        Trie(){
            root = new Node();
        }

        void insert(string data){      //)(L)
            Node* temp = root;
            for(int i =0 ; i< data.size() ; i++){
                if(temp->children.count(data[i]) == 0){
                    temp->children[data[i]]=new Node();
                }
                temp = temp->children[data[i]];
            }
            temp->endOfWord = true;
        }

        bool search(string key){      //0(L)
            Node* temp = root;
            for(int i =0 ; i<key.size();i++){
                if(temp->children.count(key[i])){
                    temp = temp->children[key[i]]; 
                }else{
                    return false;
                }
            }

            return temp->endOfWord;
        }

        

};

bool helper(Trie &trie ,string key){
    if(key.size()==0){
        return true;
    }

     for(int i =0 ; i < key.size();i++){
        string first = key.substr(0,i+1);

        string second = key.substr(i+1);
        if(trie.search(first) && helper(trie,second)) {
            return true;
        }
     }
     return false;
}
bool wordBreakProblem(vector<string> dis ,string key){

    Trie trie;
    for(int i =0 ; i < dis.size();i++){

        trie.insert(dis[i]);

    }
    return helper(trie,key);

}

int main(){


    vector<string> dis =  {"i","like","sam","samsung","mobile","ice"};
    Trie trie;
    cout<<wordBreakProblem(dis,"ilikesumsung");
    


    return 0;
}