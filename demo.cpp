#include <iostream>
#include <queue>  // Ð? dùng hàng d?i cho vi?c duy?t cây
using namespace std;

// M?t Node trong cây
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
    
    // Hàm thêm con vào danh sách con c?a Node
    bool addChild(Node* child) {
        if (!this->firstChild) {
            this->firstChild = child;
        } else {
            Node* temp = this->firstChild;
            while (temp->nextSibling) {
                if (temp->data == child->data) return false;  // Node dã t?n t?i
                temp = temp->nextSibling;
            }
            temp->nextSibling = child;
        }
        child->fatherNode = this;
        return true;
    }
};

// L?p Cây
class Tree {
    Node* root;

public:
    Tree() {
        root = NULL;
    }

    bool insert(int father, int data) {
        if (!root) {
            if (father == -1) {  // Không có cha thì dây là Node g?c
                root = new Node(data);
                return true;
            } else {
                return false;  // Không có Node cha
            }
        }
        Node* fatherNode = search(root, father);
        if (!fatherNode) return false;  // Node cha không t?n t?i

        Node* newNode = new Node(data);
        return fatherNode->addChild(newNode);
    }
    // Hàm tìm Node trong cây
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

    // Hàm duy?t preorder (NLR)
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

    // Hàm duy?t postorder (LRN)
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

    // Hàm ki?m tra cây nh? phân
    bool isBinaryTree(Node* node) {
        if (!node) return true;
        Node* child = node->firstChild;
        int count = 0;
        while (child) {
            count++;
            if (count > 2) return false;  // Nhi?u hon 2 con thì không ph?i cây nh? phân
            if (!isBinaryTree(child)) return false;
            child = child->nextSibling;
        }
        return true;
    }

    bool isBinaryTree() {
        return isBinaryTree(root);
    }

    // Hàm ki?m tra cây tìm ki?m nh? phân
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

    // Hàm tính chi?u cao c?a cây
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

    // Hàm tr? v? s? lu?ng lá
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

    // Chèn các ph?n t? vào cây
    tree.insert(-1, 10);  // Node g?c
    tree.insert(10, 5);
    tree.insert(10, 20);
    tree.insert(5, 3);
    tree.insert(5, 7);
    tree.insert(20, 15);
    tree.insert(20, 30);

    cout << "Duy?t cây theo th? t? Preorder: ";
    tree.preorder();

    cout << "Duy?t cây theo th? t? Postorder: ";
    tree.postorder();

    cout << "Chi?u cao c?a cây: " << tree.height() << endl;
    cout << "S? lu?ng lá: " << tree.numOfLeaves() << endl;

    cout << "Cây có ph?i là Binary Search Tree? " << (tree.isBinarySearchTree() ? "Yes" : "No") << endl;
	cout << tree.findMax();
    return 0;
}

