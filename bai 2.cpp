#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
node* makenode(int data){
	node* newnode = new node();
	newnode->data = data;
	newnode->next = NULL;
}
void insert(node** head,int data){
	node* tmp = makenode(data);
	tmp->next = *head; 
	*head = tmp;
}
void pop(node **head){
	if(*head != NULL){
		node *tmp = *head;
		*head=tmp->next;
		delete tmp;
	}
}
int Top(node*head){
	if(head!=NULL){
		return (head)->data;
	}
}

int main(){
	node *head = NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,4);
	insert(&head,6);
	insert(&head,9);
	insert(&head,5);
	cout << Top(head)<<endl;
	pop(&head);
	cout << Top(head);	
		pop(&head);
			cout << Top(head);
	return 0;
}
