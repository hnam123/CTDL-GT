#include<bits/stdc++.h>
using namespace std;

int main(){
	int a=10,*p;
	p = &a;
	cout << "Gia tri cua a ban dau la: "<< a << endl;
	*p = *p+1;
	
	cout <<"Dia chi cua a: "<< &a <<endl;
	cout << "gia tri cua con tro "<< p << endl;
	cout << "Gia tri p dang tro toi "<< *p <<endl;
	cout <<"Gia tri cua a luc sau la: "<< a <<endl;
	return 0;
}
