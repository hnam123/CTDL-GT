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
void enqueue(node** head,int data){
	node* newnode = makenode(data);
	if(*head==NULL){
		*head = newnode;
		return;
	}
	node *tmp = *head;
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	tmp->next = newnode; 
}
void dequeue(node **head){
	if(*head == NULL){
		return;
	}
	node *tmp =*head;
	*head=(*head)->next;
	delete tmp;
}
int front(node *head){
	return head->data;
}
int main(){
	node *head = NULL;
	enqueue(&head,1);
	enqueue(&head,2);
	enqueue(&head,3);
	enqueue(&head,4);
	enqueue(&head,5);
	cout << front(head)<<endl;
	dequeue(&head);
	cout << front(head);
	return 0;
}
