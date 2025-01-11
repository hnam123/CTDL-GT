#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
vector<int>ke[1001];
bool visited[1001];
int trace[1001];
void input(){
	cin>>n>>m>>s>>t;
	for(int i=0 ;i <m;i++){
		int x,y;cin>>x>>y;
		ke[x].push_back(y);
	}
	memset(visited,false,sizeof(visited));
}

void BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u]=true;
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(int x : ke[v]){
			if(!visited[x]){
				trace[x]=v;
				q.push(x);
				visited[x]=true;
			}
		}
	}
}

int main(){
	input();
	BFS(s);
	if(!visited[t]){
		cout << "No path";
	}
	else{
		int cnt = 0;
		while(t!=s){
			t=trace[t];
			cnt ++;
		}
		cout << cnt;
	}
	return 0;
}
