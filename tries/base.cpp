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

int main(){


    vector<string> word =  {"the","a","there","their","any","thee"};
    Trie trie;
    for(int i =0 ; i<word.size() ;i++ ){
        trie.insert(word[i]);
    }


    return 0;
}