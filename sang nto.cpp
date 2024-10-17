#include<bits/stdc++.h>
using namespace std;
const int n =1000000;
bool a[n+1];
void sangnt(){
	for(int i = 0;i<=n;i++){
		a[i]=true;
	}
	a[0]=a[1]=false;
	for(int i = 2;i<=sqrt(n);i++){
		if(a[i]){
			for(int j = i*i ;j<=n;j+=i ){
				a[j]=false;
			}
		}
	}
}
int main(){
	sangnt();
	for(int i = 0;i< 100;i++){
		if(a[i]){
			cout<< i <<" ";
		}
	}
	return 0;
}
