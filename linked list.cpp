#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next=NULL;
};
node *makenode(int x){
	node *newnode = new node();
	if(newnode != NULL){
		newnode->	data = x;
		newnode->	next = NULL;
	}
	return newnode;
}
int size(node *head){
	int cnt = 0;
	while(head != NULL){
		++cnt;
		head=head->next;
	}
	return cnt;
}
void duyet(node *head){
	while(head!=NULL){
		cout << head->data << " ";
		head=head->next;
	}
	cout << endl;
}
void insert(node **head,int p, int k){
	node *tmp = *head;
	int n = size(*head);
	if(p < 0 || p > n+1) return;
	if(p == 0){
		node *newnode = makenode(k);
		newnode->next = *head; 
		*head = newnode;
		return;
	}
	for(int i = 0 ;i <= p - 2;i++){
		tmp=tmp->next;
	}
	node *newnode = makenode(k);
	newnode->next = tmp->next;
	tmp->next = newnode;
}

void erase( node **head ,int p){
	node *tmp = *head;
	int n = size(*head);
	if(p<0||p>n) return;
	if(p==0){
		if(*head==NULL) return;
		*head = (*head)->next;
		delete tmp;
	}
	else{
		for(int i = 0 ; i<= p - 2;i++){
			tmp=tmp->next;	
		}
		node *kth = tmp -> next;
		tmp->next = kth->next;
		delete kth;
		}	
	}
int main(){
	node *head=NULL;
	int l,x,y,z; cin>>l;
	int cnt = 0 ,lc;
	while(cnt < l){
		cout << "Nhap lua chon"<<endl;
		cout << "1.insert" << endl;
		cout << "2.delete " <<endl;
		cin >> lc;
		if(lc==1){
			cout<<"insert: ";
			cin >> x >> y;
			insert( &head , x , y);
		}
		else{
			cout<<"delete: ";
			cin >> z;
			erase(&head,z);
		}
		cnt++;
	}
	duyet(head);
	return 0;
}
