#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int>* l;
    bool isUndir;
public:
    Graph(int v  , bool isUndir = true){

        this->v = v;
        l = new list<int> [v];
        this->isUndir = isUndir;


    }

    // weghtedGraph : list<pair<int,int>>[v]

    void addEdge(int u , int v){

        l[u].push_back(v);
        if(isUndir){

            l[v].push_back(u);

        }
        

    }

    void print(){
        for(int u =0 ; u<v; u++){
            list<int> neighbors = l[u];
            cout<<u<<"->";
            for(int v: neighbors){

                cout<<v<<",";

            }
            cout<<endl;
        }
    }

    void topologicalHelpper(int src,vector<bool>&vis,stack<int> &s){    //0(V + E)
        vis[src] = true;

        list<int> neighbours = l[src];
        for(int i : neighbours){
            if(!vis[v]){
                topologicalHelpper(v,vis,s);
            }
        }

        s.push(src);
    }

    void topologicalSort(){             //dfs
        vector<bool> vis(v,false);
        stack<int> s;
        for(int i =0 ; i<v ; i++){
            if(!vis[i]){
                topologicalHelpper(i,vis,s);
            }
        }

        while(s.size()>0){
            cout<<s.top();
            s.pop();
        }
    }

    void calcInDegree(vector<int> inDeg){

        for(int i =0 ; i<v;i++){
            list<int> neighbors = l[i];
            for(int v : neighbors){
                inDeg[v]++;
            }
        }

    }

    void topologicalSort2(){         //kahn's algo    0(E + V)
        vector<int> inDeg(v,0);
        calcInDegree(inDeg);
        queue<int> q;

        for(int i =0 ; i<v ; i++){
            if(inDeg[i] == 0 ){
                q.push(i);
            }
        }

        while(q.size()>0){
            int curr = q.front();
            q.pop();
            cout<<curr;

            list<int> neighbors = l[curr];
            for(int v:neighbors){
                inDeg[v]--;
                if(inDeg[v] == 0){
                    q.push(v);
                }
            }
        }
    }
};

int main(){

    Graph g(5 , false);
    g.addEdge(0, 1);
    
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    g.addEdge(1,2);
    g.addEdge(3, 4);
    g.topologicalSort2();

  
   

     
    
    return 0;
}