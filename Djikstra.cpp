#include<bits/stdc++.h>
using namespace std;
/* do thi vo huong */

const int INF = 1e9;
int n,m;
vector<pair<int,int>>ke[10001];

void input(){
	cin>>n>>m;
	for(int i=0 ;i < m;i++){
		int x,y,w;cin>>x>>y>>w;
		ke[x].push_back({y,w});
		ke[y].push_back({x,w});
	}
}

void Djikstra(int s){
	//Mang luu khoang cach duong di
	vector<long long> d(n+1,INF);
	d[s]=0;
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > Q;
	//{Khoang cach, dinh}
	Q.push({0,s});
	
	while(!Q.empty()){
		//Chon ra dinh co khoang cach s nho nhat
		pair<int,int> top = Q.top();
		Q.pop();
		
		int u = top.second;
		int kc = top.first;
		
		if(kc > d[u]) continue;// d[u] da dc cap nhat -> tiep tuc vong lap
		
		// cap nhat khoang cach tu dinh s den moi dinh ke voi no
		for(auto it:ke[u]){
			int v =it.first;
			int w = it.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				Q.push({d[v],v});
			}
		}
	}
	for(int i = 1;i<=n;i++){
		cout <<d[i]<<" ";
	}
}
int main(){
	input();
	int s;cin>>s;
	Djikstra(s);
	return 0;
}
