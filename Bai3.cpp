#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *next;
	node *prev;
};

node *makenode(int x){
	node *newnode = new node();
	if(newnode != NULL){
		newnode->	data = x;
		newnode->	next = NULL;
		newnode->	prev = NULL;
	}
	return newnode;
}

void insert(node** head, int x){
	node *newnode = makenode(x);
	if(*head == NULL){
		*head = newnode;
		return;
	}
	node *tmp = *head;
	while( tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next=newnode;
	newnode->prev=tmp;
}

int count(node *head){
 	int cnt = 0;
 	while(head->next != NULL){
 		if(head->prev!=NULL && head->prev->data + head->data + head->next->data == 0){
 			++cnt;
		}
		head = head->next;	
	}
    return cnt;
}
int main(){
	node *head = NULL;
	int n,x;cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> x;
		insert(&head,x);
	}
	cout << count(head);
	return 0;
}
