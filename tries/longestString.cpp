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

        string helpper(Node* root,string &ans , string temp){
            for(pair<char, Node*> child:root->children){
                if(child.second->endOfWord){

                        temp+= child.first;
                    if((temp.size() == ans.size()&& temp<ans)||(temp.size() > ans.size())){
                        ans = temp;
                    }
                    helpper(child.second,ans,temp);
                    temp = temp.substr(0,temp.size()-1);

                }
                return temp;
                
            }
        }
        string stringWithEOW(){
            string ans ="";
            return helpper(root, ans ,"");
        }

};

string logestString(vector<string> word){
    Trie trie;
    for(int i =0 ; i<word.size() ;i++ ){
        trie.insert(word[i]);
    }
    return trie.stringWithEOW();
}

int main(){


    vector<string> word =  {"a","banana","app","appl","ap","apply", "apple"};
    cout<<logestString(word);
    

    return 0;
}