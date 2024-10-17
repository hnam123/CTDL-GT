#include <iostream>
using namespace std;

// M?t Node trong cây
class Node {
    // Ch?a thông tin c?a Node dó
    int data;
    // Con tr? d?n Node cha
    Node* fatherNode;

    // Con tr? d?n các Node con
    // Ðây là m?t danh sách liên k?t (con tr? d?n con d?u tiên)
    // Th? t? uu tiên t? nh? d?n l?n (con nh? du?c duy?t tru?c)
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
    // Các hàm kh?i t?o khác n?u c?n thi?t

    friend class Tree;
};

// L?p Cây
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
    // Các hàm kh?i t?o khác n?u c?n thi?t

    // Hàm thêm m?t Node vào cây
    // Hàm tr? v? false n?u Node cha không t?n t?i trên cây
    // ho?c Node father dã có con là data
    bool insert(int father, int data);

    // Hàm xóa m?t Node trên cây
    // N?u không ph?i Node lá xóa Node dó và toàn b? các Node con c?a nó
    // Hàm tr? v? s? lu?ng Node dã xóa
    // N?u Node data không t?n t?i tr? v? 0 (zero)
    int remove(int data);

    // Hàm in ra các Node theo th? t? preorder
    void preorder();

    // Hàm in ra các Node theo th? t? postorder
    void postorder();

    // Hàm ki?m tra cây nh? phân
    bool isBinaryTree();

    // Hàm ki?m tra cây tìm ki?m nh? phân
    bool isBinarySearchTree();

    // Hàm ki?m tra cây max-heap
    bool isMaxHeapTree();

    // Hàm in ra các Node theo th? t? inorder n?u là cây nh? phân
    void inorder();

    // Hàm tr? v? d? cao c?a cây
    int height();

    // Hàm tr? v? d? sâu c?a m?t Node
    int depth(int data);

    // Hàm d?m s? lu?ng lá
    int numOfLeaves();

    // Hàm tr? v? Node có giá tr? l?n nh?t
    int findMax();

    // Hàm tr? v? Node có nhi?u con nh?t
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
    // T?o ra m?t cây ng?u nhiên có t?i thi?u 30 Node
    // Test th? các hàm c?a l?p cây

    // T?o ra m?t cây th?a mãn tính ch?t là Binary Search Tree và test l?i
    
    // T?o ra m?t cây th?a mãn tính ch?t là Max Heap Tree và test l?i
    
    return 0;
}
