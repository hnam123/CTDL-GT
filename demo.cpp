#include<bits/stdc++.h>

using namespace std;

struct Node{
	int value;
	Node* next;
};
typedef struct Node* node;

node newnode(int x){
	node tmp = new Node();
	tmp -> value = x;
	tmp -> next = NULL;
	return tmp;
}

void chenDau (node &head, int x){
	node tmp = newnode (x);
	if (head == NULL){
		head = tmp;
	}
	else{
		tmp -> next = head;
		head = tmp;
	}
}

void chenCuoi (node &head, int x){
	node tmp = newnode (x);
	if (head == NULL){
		head = tmp;
	}
	else{
		node p = head;
		while (p -> next != NULL){
			p = p -> next;
		}
		p -> next = tmp;
	}
}

int sizenode(node head){
	int cnt = 0;
	while(head!=NULL){
		++cnt;
		head=head->next;
	}
}

void chen (node &head, int p, int x){
	node tmp2 = head;
	int n = sizenode(head);
	if (p < 0 || p > n ){
		cout << "Error";
		return;
	} 
	if (p == 0) {
		chenDau (head, x);
		return;
	}
	else if (p == n+1){
		chenCuoi (head, x);
		return;
	}
	for (int i = 1; i < p - 1; i++){
		tmp2 = tmp2 -> next;
	}
	node tmp1 = newnode(x);
	tmp1 -> next =  tmp2 -> next;
	tmp2 -> next = tmp1;
}

void in (node head){
	node tmp = head;
	while ( tmp != NULL){
		cout << tmp -> value << " ";
		tmp = tmp -> next;
	}
	cout << endl;
}

int main(){
	node head = NULL;
	int n; cin  >>  n;
	for (int i = 0; i < n; i++){
		cout << "Choose:" << endl << "1.Insert" << endl << "2.Delete" << endl;
		int lc;
		cin >> lc;
		if ( lc == 1) {
			int p, x;
			cout << "Nhap vi tri va gia tri muon chen:" << endl;
			cin >> p >> x;
			chen (head, p, x);
		}
		//if ( lc == 2) cin << z;
		
	}
	in ( head );
	cout << sizenode (head) << endl;
	return 0;
}
