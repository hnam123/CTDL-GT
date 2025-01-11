#include<bits/stdc++.h>
using namespace std;
int f[1001];

int Fibo(int n){
	if(n<=1) return 1;
	if(f[n]!=-1) return f[n];
	f[n]=Fibo(n-1) + Fibo(n-2);
	return f[n];	
}

int main(){
	memset(f,-1,sizeof f);
	int t;cin>>t;
	int a[t];
	
	for(int i=0;i<t;i++){
		cin>>a[i];
	}
	for(int i=0;i<t;i++){
		cout << Fibo(a[i])<<endl;
	}
	return 0;
}
