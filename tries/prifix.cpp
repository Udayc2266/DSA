#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
        unordered_map<char , Node*> children;
        bool endOfWord;
        int freq;
        Node(){
            endOfWord = false;
        }

};

class Trie{

    Node* root;


    public:
        Trie(){
            root = new Node();
            root->freq = -1;
        }

        void insert(string data){      //)(L)
            Node* temp = root;
            for(int i =0 ; i< data.size() ; i++){
                if(temp->children.count(data[i]) == 0){
                    temp->children[data[i]]=new Node();
                    temp->children[data[i]]->freq = 1;
                }else{

                    temp->children[data[i]]->freq++;

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

        string getPrifix(string key){

            Node* temp = root;
            string prefix ="";

            for(int i =0 ; i<key.size();i++){       //0(L)
                prefix += key[i];
                if (temp->children[key[i]]->freq == 1){
                    return prefix;
                }

                temp->children[key[i]];
            }
            return prefix;

        }

};


void prifix(vector<string> dis ){       //0(n*L)

    Trie trie;
    for(int i =0 ; i < dis.size();i++){

        trie.insert(dis[i]);

    }
    for(int i =0 ; i<dis.size() ; i++){
        cout<<trie.getPrifix(dis[i])<<endl;
    }

}

int main(){


    vector<string> dis =  {"i","like","sam","samsung","mobile","ice"};
    Trie trie;
    prifix(dis);
    


    return 0;
}