#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<vector <pair<int, int> > >& adj, int u, int v, int weight){
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}

void printGraph(vector<vector<pair<int, int> > > graph){    
    for(int i = 1; i <= graph.size(); i++){
        cout<<i<<" -> ";
        for(pair<int, int> edge : graph[i]){
            cout<<"("<<edge.second<<")"<<edge.first<<", ";
        }
        cout<<endl;
    }
}

int main(){
    
    vector<vector<pair<int, int> > > graph;
    
    ifstream edges;
    edges.open("./edges.txt");
    
    string input;
    int n = 0, m = 0;
    
    if(edges.is_open()){
        getline(edges, input, ' ');
        n = stoi(input);
        getline(edges, input, '\n');
        m = stoi(input);
        
        graph.resize(n + 1);
        
        while(getline(edges, input, '\n')){
            char *token = strtok(const_cast<char*>(input.c_str()), " ");
            int val[3];
            for(int i = 0; token != nullptr; ++i){
                val[i] = stoi(token);
                token = strtok(nullptr, " ");
            }
            addEdge(graph, val[0], val[1], val[2]);
        }
        edges.close();
    }
    
    
}
