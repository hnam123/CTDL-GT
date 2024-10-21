#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> ke[1001];
bool visited[1001];
vector<int>tplt;
void input(){
    cin>>n>>m;
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
    tplt.push_back(u);
    visited[u]=true;
    for(int v :ke[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}
int main(){
    input();
    cout <<endl;
    for(int i = 1;i<=n;i++){  // kiem tra xem do thi co lien thong hay khong 
        if(!visited[i]){
            DFS(i);
            sort(begin(tplt),end(tplt));
            for(int x: tplt){
                cout << x << " " ;
            }
            cout << endl;
            tplt.clear();
        }
    } 
	return 0;
}