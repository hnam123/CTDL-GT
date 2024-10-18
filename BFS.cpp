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

void BFS(int u){
    //b1 : tao 1 hang doi rong
    queue<int> q;
    q.push(u);
    visited[u]=true;
    // b2 ; lap
    while(!q.empty()){
        int v = q.front();// dinh o dau hang doi
        q.pop();//xoa dinh o dau hang doi
        cout << v <<" ";
        for(int x:ke[v]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
            }
        }
    }
}
int main(){
    input();
    BFS(s);
	return 0;
}