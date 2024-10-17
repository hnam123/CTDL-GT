#include<iostream>
using namespace std;
void arr_in(long long a[100],int n){
	int i;
	do{
		for(int i = 0;i<n;i++){
		cin >> a[i];
		}
	}while(a[i]>10^5&&a[i]<0);
}
long long sum(long long a[100],int n){
	long long sum = 0; 
	for(int i = 0;i<n;i++){
		sum += a[i];
		}
	return sum;
}
int main(){
	int n;
	do{
		cin >> n;
	}while(n<1&&n>2*10^5);
	long long a[n];
	arr_in(a,n);
	cout << sum(a,n);
	return 0;
}
