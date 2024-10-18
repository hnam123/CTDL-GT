/*Đồ thị vô hướng*/
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
        ke[y].push_back(x); // có hướng thì chỉ cần bỏ dòng này đi là xong
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
    DFS(s);
    cout <<endl;
    for(int i = 1;i<=n;i++){        // kiem tra xem do thi co lien thong hay khong 
        if(!visited[i]){
            cout << "No";
            return 0;
        }
    } 
    cout <<"Yes";
	return 0;
}