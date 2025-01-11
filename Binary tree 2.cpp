#include<bits/stdc++.h>
using namespace std;
class Node{
	struct Node{
		int data;
		Node*left;
		Node *right;
	};
	Node *makeNode(int data){
		Node*newNode=new Node();
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	friend class tree;
};
class tree(){
	Node *root
	tree(){
		root=NULL;
	}
	Node* Insert(int pos,int data){
		
	}
	Node* search(Node*root,int data){
		
	}
};


int main(){
	Node *root = NULL;
	int n;cin>>n;
	for(int i = 1;i<n;i++){
		int x,y;
		cin>>x>>y;
		root=Insert(x,y);
	}
	
	return 0;
}

