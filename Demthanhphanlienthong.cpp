/*Đồ thị vô hướng*/
#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> ke[1001];
bool visited[1001];

void input(){
    cin>>n>>m;
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
    visited[u]=true;
    for(int v :ke[u]){
        if(!visited[v]){
            DFS(v);
        }
    }
}
int main(){
    input();
    int dem = 0;
    for(int i = 1;i<=n;i++){
        if(visited[i]==false){
            //day la thanh phan lien thong moi
            DFS(i); // tham het moi dinh cung thanh phan lien thong voi i
            ++dem;
        }
    }
    cout << dem << endl;
	return 0;
}