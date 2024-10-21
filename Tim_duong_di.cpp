#include<bits/stdc++.h>
using namespace std;

int n,m,s,t;
vector<int> ke[1001];
bool visited[1001];
int trace[1001];
void input(){
    cin>>n>>m>>s>>t;
    for(int i = 0;i<m;i++){
        int x,y;
        cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1;i<=n;i++){
        sort(ke[i].begin(),ke[i].end());
    }
    memset(visited,false,sizeof(visited));
}

void DFS(int u){
    visited[u]=true;
    for(int v :ke[u]){
        if(!visited[v]){
            trace[v] = u;
            DFS(v);
        }
    }
}
int main(){
    input();
    DFS(s);
    if(!visited[t]){
        cout << "-1";
    }
    else{
        vector<int> path;
        while(t!=s){
            path.push_back(t);
            t = trace[t];
        }
        path.push_back(s);
        reverse(path.begin(),path.end());
        for(int x:path){
            cout << x << " ";
        }
    }

	return 0;
}