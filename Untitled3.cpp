#include <iostream>
using namespace std;

// M?t Node trong c�y
class Node {
    // Ch?a th�ng tin c?a Node d�
    int data;
    // Con tr? d?n Node cha
    Node* fatherNode;

    // Con tr? d?n c�c Node con
    // ��y l� m?t danh s�ch li�n k?t (con tr? d?n con d?u ti�n)
    // Th? t? uu ti�n t? nh? d?n l?n (con nh? du?c duy?t tru?c)
    Node* firstChild;

    // Con tr? d?n Node sibling
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
    // C�c h�m kh?i t?o kh�c n?u c?n thi?t

    friend class Tree;
};

// L?p C�y
class Tree {
    // Ch?a m?t Node g?c
    Node* root;
public:
    Tree() {
        root=NULL;
    }
    Node* search(Node *node,int value){
		if(node->firstChild == NULL){
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
    // C�c h�m kh?i t?o kh�c n?u c?n thi?t

    // H�m th�m m?t Node v�o c�y
    // H�m tr? v? false n?u Node cha kh�ng t?n t?i tr�n c�y
    // ho?c Node father d� c� con l� data
    bool insert(int father, int data);

    // H�m x�a m?t Node tr�n c�y
    // N?u kh�ng ph?i Node l� x�a Node d� v� to�n b? c�c Node con c?a n�
    // H�m tr? v? s? lu?ng Node d� x�a
    // N?u Node data kh�ng t?n t?i tr? v? 0 (zero)
    int remove(int data);

    // H�m in ra c�c Node theo th? t? preorder
    void preorder();

    // H�m in ra c�c Node theo th? t? postorder
    void postorder();

    // H�m ki?m tra c�y nh? ph�n
    bool isBinaryTree();

    // H�m ki?m tra c�y t�m ki?m nh? ph�n
    bool isBinarySearchTree();

    // H�m ki?m tra c�y max-heap
    bool isMaxHeapTree();

    // H�m in ra c�c Node theo th? t? inorder n?u l� c�y nh? ph�n
    void inorder();

    // H�m tr? v? d? cao c?a c�y
    int height();

    // H�m tr? v? d? s�u c?a m?t Node
    int depth(int data);

    // H�m d?m s? lu?ng l�
    int numOfLeaves();

    // H�m tr? v? Node c� gi� tr? l?n nh?t
    int findMax();

    // H�m tr? v? Node c� nhi?u con nh?t
    int findMaxChild();
};

bool Tree::insert(int father,int data){
	if(Tree::search(node,father)==NULL){
    		return false;
		}
		else{
			if(Tree::search(node,father)->data==data){
				return false;
			}
		}
	}
int Tree::remove(int data){
	
}
void Tree::preorder(){
	
}
void Tree::postorder(){
	
}
bool Tree::isBinaryTree(){
	
}
bool Tree::isBinarySearchTree(){
	
}
bool Tree::isMaxHeapTree(){
	
}
void Tree::inorder(){
	
}

int Tree::height(){
	
}

int Tree::depth(int data){
	
}

int Tree::numOfLeaves(){
	
}

int Tree::findMax(){
	
}

int Tree::findMaxChild(){
	
}
int main(int argc, char const *argv[]) {
    // T?o ra m?t c�y ng?u nhi�n c� t?i thi?u 30 Node
    // Test th? c�c h�m c?a l?p c�y

    // T?o ra m?t c�y th?a m�n t�nh ch?t l� Binary Search Tree v� test l?i
    
    // T?o ra m?t c�y th?a m�n t�nh ch?t l� Max Heap Tree v� test l?i
    
    return 0;
}
