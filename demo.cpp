#include <iostream>
#include <queue>  // �? d�ng h�ng d?i cho vi?c duy?t c�y
using namespace std;

// M?t Node trong c�y
class Node {
public:
    int data;
    Node* fatherNode;
    Node* firstChild;
    Node* nextSibling;

    Node(int data) {
    	this->data = data;
    	this->fatherNode=NULL;
    	this->firstChild=NULL;
    	this->nextSibling=NULL;
    }
    
    // H�m th�m con v�o danh s�ch con c?a Node
    bool addChild(Node* child) {
        if (!this->firstChild) {
            this->firstChild = child;
        } else {
            Node* temp = this->firstChild;
            while (temp->nextSibling) {
                if (temp->data == child->data) return false;  // Node d� t?n t?i
                temp = temp->nextSibling;
            }
            temp->nextSibling = child;
        }
        child->fatherNode = this;
        return true;
    }
};

// L?p C�y
class Tree {
    Node* root;

public:
    Tree() {
        root = NULL;
    }

    bool insert(int father, int data) {
        if (!root) {
            if (father == -1) {  // Kh�ng c� cha th� d�y l� Node g?c
                root = new Node(data);
                return true;
            } else {
                return false;  // Kh�ng c� Node cha
            }
        }
        Node* fatherNode = search(root, father);
        if (!fatherNode) return false;  // Node cha kh�ng t?n t?i

        Node* newNode = new Node(data);
        return fatherNode->addChild(newNode);
    }
    // H�m t�m Node trong c�y
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

    // H�m duy?t preorder (NLR)
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        Node* child = node->firstChild;
        while (child) {
            preorder(child);
            child = child->nextSibling;
        }
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    // H�m duy?t postorder (LRN)
    void postorder(Node* node) {
        if (!node) return;
        Node* child = node->firstChild;
        while (child) {
            postorder(child);
            child = child->nextSibling;
        }
        cout << node->data << " ";
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

    // H�m ki?m tra c�y nh? ph�n
    bool isBinaryTree(Node* node) {
        if (!node) return true;
        Node* child = node->firstChild;
        int count = 0;
        while (child) {
            count++;
            if (count > 2) return false;  // Nhi?u hon 2 con th� kh�ng ph?i c�y nh? ph�n
            if (!isBinaryTree(child)) return false;
            child = child->nextSibling;
        }
        return true;
    }

    bool isBinaryTree() {
        return isBinaryTree(root);
    }

    // H�m ki?m tra c�y t�m ki?m nh? ph�n
    bool isBinarySearchTree(Node* node, int min, int max) {
        if (!node) return true;
        if (node->data < min || node->data > max) return false;
        Node* left = node->firstChild;
        Node* right = left ? left->nextSibling : NULL;
        return isBinarySearchTree(left, min, node->data - 1) && isBinarySearchTree(right, node->data + 1, max);
    }

    bool isBinarySearchTree() {
        return isBinarySearchTree(root, INT_MIN, INT_MAX);
    }

    // H�m t�nh chi?u cao c?a c�y
    int height(Node* node) {
        if (!node) return 0;
        int maxHeight = 0;
        Node* child = node->firstChild;
        while (child) {
            maxHeight = max(maxHeight, height(child));
            child = child->nextSibling;
        }
        return 1 + maxHeight;
    }

    int height() {
        return height(root);
    }

    // H�m tr? v? s? lu?ng l�
    int numOfLeaves(Node* node) {
        if (!node) return 0;
        if (!node->firstChild) return 1;

        int count = 0;
        Node* child = node->firstChild;
        while (child) {
            count += numOfLeaves(child);
            child = child->nextSibling;
        }
        return count;
    }

    int numOfLeaves() {
        return numOfLeaves(root);
    }
    int findMax(Node *root){
    	if(isBinarySearchTree()==true){
    		Node*tmp=root;
    		while(tmp&&tmp->nextSibling!=NULL){
    			tmp = tmp->nextSibling;
			}
			return tmp->data;
		}
		else{
			if(root->firstChild->data > root->data){
				return root->firstChild->data;
			}
			if(root->nextSibling->data > root->data){
				return root->nextSibling->data;
			}
			return findMax(root->firstChild);
			return findMax(root->nextSibling);
		}
	}
	int findMax(){
		return findMax(root);
	}
};

int main(int argc, char const *argv[]) {
    Tree tree;

    // Ch�n c�c ph?n t? v�o c�y
    tree.insert(-1, 10);  // Node g?c
    tree.insert(10, 5);
    tree.insert(10, 20);
    tree.insert(5, 3);
    tree.insert(5, 7);
    tree.insert(20, 15);
    tree.insert(20, 30);

    cout << "Duy?t c�y theo th? t? Preorder: ";
    tree.preorder();

    cout << "Duy?t c�y theo th? t? Postorder: ";
    tree.postorder();

    cout << "Chi?u cao c?a c�y: " << tree.height() << endl;
    cout << "S? lu?ng l�: " << tree.numOfLeaves() << endl;

    cout << "C�y c� ph?i l� Binary Search Tree? " << (tree.isBinarySearchTree() ? "Yes" : "No") << endl;
	cout << tree.findMax();
    return 0;
}

