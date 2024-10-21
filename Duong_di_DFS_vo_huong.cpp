#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
vector<int>ke[1001];
int trace[100];
bool visited[1001];

void input(){
    cin >>n>>m>>s>>t;
    for(int i = 0;i<m;i++){
        int x,y;
        cin >>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited,false,sizeof(visited));
}

void DFS(int u){
    visited[u]=true;
    for(int v: ke[u] ){
        if(!visited[v]){
            DFS(v);
            trace[v]=u;
            }
    }
}

int main(){
    input();
    DFS(s);
    if(!visited[t]){
        cout << "Path unavailable";
    }
    else{
        vector <int> path;
        while(t!=s){
            path.push_back(t);
            t=trace[t];
        }
        path.push_back(s);
        reverse(path.begin(),path.end());
        for(int x : path){
            cout <<x<<" ";
        }
    }
    return 0;
}