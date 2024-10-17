#include <iostream>

using namespace std;

class Node {
    int data;
    Node* fatherNode;
    Node* firstChild;
    Node* nextSibling;

public:
    Node(int data) {
    	this->data = data;
    	this->fatherNode=NULL;
    	this->firstChild=NULL;
    	this->nextSibling=NULL;
    }
    bool AddChild(Node* Child){
    	if (this->firstChild == NULL) {
            this->firstChild = Child;
        } 
		else {
            Node* temp = this->firstChild;
            while (temp->nextSibling != NULL) {
                if (temp->data == Child->data) return false;  
                temp = temp->nextSibling;
            }
            temp->nextSibling = Child;
        }
        Child->fatherNode = this;
        return true;
	}
    friend class Tree;
};

class Tree {
    Node* root;
public:
    Tree() {
        root = NULL;
    }

    bool insert(int father, int data){
    	// cay chua co node nao
    	if(root==NULL){
    		root = new Node(data);
    		return true;
    	}
		// cay da co node
			Node* fatherNode = search(root, father);
			if(fatherNode==NULL){	//Node cha khong ton tai trong cay
				return false;
			}
			if(fatherNode->data==data){
				return false;				// Node cha da co con la data
			}	
			Node* newNode = new Node(data);	// Tao mot node moi
			newNode->fatherNode = fatherNode;
			if(fatherNode->firstChild==NULL){ // node father chua co con firstChild
				fatherNode->firstChild=newNode;
			}
			else{								//node father co con firstChild
				Node *tmp= fatherNode->firstChild;
				while(tmp->nextSibling != NULL){
					tmp=tmp->nextSibling;
				}
				tmp->nextSibling=newNode;
				return true;
			}
	}
	Node* search(Node *node,int value){
		if(node == NULL){
			return NULL;
		}
		if(node->data == value){
			return node;
		}
		Node *tmp= node->firstChild;
		while(tmp!=NULL){
			Node *ans = search(tmp,value);
			if(ans!=NULL){
				return ans;
			}
			tmp=tmp->nextSibling;
		}
		return NULL;
}
//    int remove(int data){
//    	
//	}

    void preorder(Node* node) {
        if (!node) return;
		cout << node->data << " ";
        inorder(node->firstChild);
		inorder(node->nextSibling);
        }
    void preorder(){
    	preorder(root);
    	cout<<endl;
	}
	
	void postorder(Node* node) {
        if (!node) return;
        inorder(node->firstChild);
		inorder(node->nextSibling);
		cout << node->data << " ";
		
    }
    void postorder(){
    	postorder(root);
    	cout<<endl;
	}
	
    bool isBinaryTree(){
    	return CheckBinaryTree(root);
	}
	bool CheckBinaryTree(Node*root){
		if(root==NULL) return true;
		Node *tmp=root->firstChild;
		int cnt = 0;
		while(tmp!=NULL){
			cnt++;
			if(cnt > 2) return false; // qua 2 con -> false
			if(CheckBinaryTree(tmp)) return true;
			tmp=tmp->nextSibling;
		}
		return true;
	}
	
    bool isBinarySearchTree(Node* root){
    	return check(root,INT_MIN,INT_MAX);
	}
	bool check(Node*root, int Min, int Max){
		if(root==NULL) return true;
        if(root->data <= Min || root->data >= Max){
            return false;
        }
        Node*left = root->firstChild;
        Node*right;
        if(left!=NULL){
        	right = left->nextSibling;
		}
		else{
			right = NULL;
		}
		return check(left, Min, root->data) && check(right, root->data, Max);
	}
	bool isBinarySearchTree(){
    	return isBinarySearchTree(root);
	}
	
//    bool isMaxHeapTree();

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->firstChild);
		cout << node->data << " ";
		inorder(node->nextSibling);
    }
	void inorder(){
		inorder(root);
		cout<<endl;
	}
    int height(Node* node) {
        if (!node) return 0;
        int maxHeight = 0;
        Node* tmp = node->firstChild;
        while ( tmp!=NULL ) {
            maxHeight = max(maxHeight, height(tmp));
            tmp = tmp->nextSibling;
        }
        return 1 + maxHeight;
    }
	int height() {
        return height(root);
    }
//    int depth(int data);

    int numOfLeaves(Node *root){
    	if(root == NULL) return 0;
    	if( root->firstChild == NULL && root->nextSibling ==NULL){
    		return 1;
		}
		return numOfLeaves(root->firstChild) + numOfLeaves(root->nextSibling);
	}
	int numOfLeaves(){
		return numOfLeaves(root);
	}
	
    int findMax(Node *root){	
			Node*tmp=root;
			while(tmp != NULL){
                while (tmp->nextSibling != NULL){
                    tmp = tmp->nextSibling;
                    }
                if(tmp->firstChild != NULL){
                    tmp = tmp->firstChild;
                    }
                else{
				return tmp->data;
				}
			}
	}
	int findMax(){
		return findMax(root);
	}

//    int findMaxChild();
};

int main(int argc, char const *argv[]) {
    Tree tree;
    tree.insert(-1, 8);  
    tree.insert(8, 4);
    tree.insert(8, 16);
    tree.insert(4, 2);
    tree.insert(4, 5);
    tree.insert(16, 9);
    tree.insert(16, 17);

    cout << "In cay theo Preorder: ";
    tree.preorder();

    cout << "In cay theo Postorder: ";
    tree.postorder();
	cout << "In cay theo Inorder: ";
	tree.inorder();
    cout << "Chieu cao cua cay " << tree.height() << endl;
		
    cout << "So luong node la: " << tree.numOfLeaves() << endl;
	cout << "Cay co phai  la Binary Tree? " << (tree.isBinaryTree() ? "Yes" : "No") << endl;
    cout << "Cay co phai  la Binary Search Tree? " << (tree.isBinarySearchTree() ? "Yes" : "No") << endl;
    
    cout << "Node lon nhat trong cay la : "<<tree.findMax()<<endl;

    return 0;
}
