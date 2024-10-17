#include<iostream>
using namespace std;
void Convert(int n){
	if(n>0){
		int sd=n%2;
		n=n/2;
		Convert(n);
		cout << sd;
	}
}
int main(){
	int a;cin>>a;
	Convert(a);
	return 0;
}
