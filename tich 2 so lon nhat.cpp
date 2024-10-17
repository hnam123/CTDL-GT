#include<iostream>
using namespace std;
//void arr_in(long long a[100],int n){
//	int i;
//	do{
//		for(int i = 0;i<n;i++){
//		cin >> a[i];
//		}
//	}while(a[i]>10^5&&a[i]<0);
//}
long long maxpro(long long a[100],int n){
	long long maxpro = 0; 
	for(int i=0 ;i<n;i++){
		for(int j = i+1 ;j<n;j++){
			if(a[i]*a[j]>maxpro){
				maxpro=a[i]*a[j];
			}
		}
	}
	return maxpro;
}
int main(){
//	int n;
//	do{
//		cin >> n;
//	}while(n<1&&n>2*10^5);
//	long long a[n];
//	arr_in(a,n);
	long long a[5]={ 9 , 7 ,5 ,4,10};
	cout << maxpro(a,5);
	return 0;
}
