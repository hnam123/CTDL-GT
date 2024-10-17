#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

node *makenode(int x){
	node *newnode = new node();
	if(newnode!=NULL){
		newnode->data = x;
		newnode->left = NULL;
		newnode->right=	NULL;
	}
	return newnode;
}

void duyet(node *root){
	if(root!=NULL){
		duyet(root->left);
		cout << root->data << " ";
		duyet(root->right);
	}
}

node* insert(node* root, int data)
{
    if (root == NULL) {
        return makenode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

int search(node *root,int k){
	if(root == NULL){
		return 0;
	}
	else if((root)->data == k){
		return 1;
	}
	else if((root)->data <= k){
		return search(root->right,k);
	}
	else{
		return search(root->left,k);
	}
}
node* minvalue(node*root){
	node *tmp =root;
	while(tmp&&tmp->left !=NULL){
		tmp=tmp->left;
	}
	return tmp;
}
node* deletion(node*root,int data){
	if(root==NULL){
		return root;
	}
	if(search(root,data)==1){
		if (data < root->data) {
        root->left = deletion(root->left, data);
  		  }
  		else if(data > root->data){
  			root->right = deletion(root->right,data);
		  }
		else{
			if(root->left==NULL){
				node*tmp=root->right;
				delete root;
				return tmp;
			}
			else if(root->right==NULL){
				node*tmp = root->left;
				delete root;
				return tmp;
			}
		node* tmp = minvalue(root->right);
		root->data = tmp->data;
		root->right = deletion(root->right, tmp->data);
		}
	}
}
int main(){
	node *root = NULL;
	root=insert(root,50);	
	root=insert(root,30);	
	root=insert(root,20);
	root=insert(root,40);
	root=insert(root,70);
	root=insert(root,60);
	root=insert(root,80);
	duyet(root);
	int number1,number2;
	
	cout<<"Enter number be searched\n";
	cin>>number1;
	
	if(search(root,number1) == 1) cout<<"Found\n";
	else cout<<"Not Found\n";

	cout<<"Enter number be deleted\n";
	cin>>number2;
	root=deletion(root,number2);
	duyet(root);
	return 0;
}
