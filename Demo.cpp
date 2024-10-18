
#include<bits/stdc++.h>
using namespace std;

int n,m,s;
vector<int> ke[1001];
bool visited[1001];

void input(){
    cin>>n>>m>>s;
    for(int i = 0;i<m;i++){
        int x,y;
        cin>>x>>y;
        ke[x].push_back(y);
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
            DFS(v);
        }
    }
}
int main(){
    input();
    
	return 0;
}