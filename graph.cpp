#include<bits/stdc++.h>
using namespace std;

vector<int> ke[10001];
int main(){
	
	int n,m,i,j;
	cin>>n>>m;
	for(i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		ke[x].push_back(y);
	}
	for(i=1;i<=n;i++){
		sort(ke[i].begin(),ke[i].end());
		cout<<i<<":";
		for(int x : ke[i]){
			cout<<x<<" ";
		}
	}
	return 0;
}
