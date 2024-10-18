/*Đồ thị vô hướng*/
#include<bits/stdc++.h>
using namespace std;

int n,m,s;
vector<int> ke[1001];
bool visited[1001];

void input(){
    cin>>n>>m;
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
    cout <<u<<" ";
    visited[u]=true;
    for(int v :ke[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}
int main(){
    input();
    for(int i = 1;i<=n;i++){
        memset(visited,false,sizeof(visited));
        DFS(i);
        cout << endl;
        for(int j =1;j<=n;j++){
            if(!visited){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
	return 0;
}