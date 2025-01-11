#include<bits/stdc++.h>
using namespace std;
struct Node{
	int voteID;
	int k;
	int time;
	int status;
	Node *next;
};
Node *makeNode(int voteID, int k, int time, int status){
	Node*newNode= new Node();
	newNode->voteID = voteID;
	newNode->k = k;
	newNode->time = time;
	newNode->status = status;
	newNode->next = NULL;
	return newNode;
}
int main(){
	
	return 0;
}
