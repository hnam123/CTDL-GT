#include<bits/stdc++.h>
using namespace std;
int n = 0;
int a[100000],Maxn=100000;

void enqueue(int x){
	if(n==Maxn) return;
	a[n]=x;
	++n;
}
void dequeue(){
	if(n==0) return;
	for(int i=0; i<=n-1;i++){
		a[i]=a[i+1];
	}
	--n;
}
int front(){
	return a[0];
}

int main(){
	int l,x; cin>>l;
	int cnt = 0 ,lc;
	while(cnt < l){
		cout << "Nhap lua chon"<<endl;
		cout << "1.endequeue" << endl;
		cout << "2.dequeue " <<endl;
		cin >> lc;
		if(lc==1){
			cout<<"enqueue: ";
			cin >> x;
			enqueue(x);
		}
		else{
			dequeue();
		}
		cnt++;
	}

	for(int i = n-1 ; i>=0 ;i--){
		cout << front() << " ";
		dequeue();
	}
	return 0;
}
