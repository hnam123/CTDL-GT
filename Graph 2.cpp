#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<pair<int,int> > canh;
	int a[n][n];
	for(int i = 1;i<=n;i++){
	    for(int j=1;j<=n;j++){
	        cin>>a[i][j];
	    }
	}
	for(int i = 1;i<=n;i++){
	    for(int j=1;j<=n;j++){
	        if(a[i][j]==1&&i<j){
	            canh.push_back({j,i});
	        }
	    }
	}
	sort(begin(canh),end(canh));
	for(auto it : canh){
	    cout<<it.first<<" "<<it.second<<endl;
	}
	cout << endl;
	
	vector<int>ke[1001];
	for(int i = 1;i<=n;i++){
	    for(int j=1;j<=n;j++){
	        if(a[i][j]==1){
	            ke[i].push_back(j);
	        }
	    }
	}
	for(int i=1;i<=n;i++){
	    sort(ke[i].begin(),ke[i].end());
	    cout<<i<<" : ";
	    for(int y : ke[i]){
	        cout<<y<<" ";
	    }
	    cout << endl;
	}
	return 0;
}
