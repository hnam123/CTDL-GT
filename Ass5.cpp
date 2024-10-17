class Tree {
    // Ch?a m?t Node g?c
    Node* root;

    // Các hàm ph? tr? cho các hàm chính
    void preorderHelper(Node* node) {
        if (node == nullptr) return;
        cout << node->getData() << " ";
        preorderHelper(node->firstChild);
        preorderHelper(node->nextSibling);
    }

    void postorderHelper(Node* node) {
        if (node == nullptr) return;
        postorderHelper(node->firstChild);
        cout << node->getData() << " ";
        postorderHelper(node->nextSibling);
    }
    
	void inorderHelper(Node* node) {
    	if (node == nullptr) return;
   		inorderHelper(node->firstChild);
   		cout << node->getData() << " ";
   		inorderHelper(node->nextSibling);
    }
    int heightHelper(Node* node) {
        if (node == nullptr) return 0;
        int childHeight = heightHelper(node->firstChild);
        int siblingHeight = heightHelper(node->nextSibling);
        return max(childHeight + 1, siblingHeight);
    }

    int numOfLeavesHelper(Node* node) {
        if (node == nullptr) return 0;
        if (node->firstChild == nullptr) return 1;
        return numOfLeavesHelper(node->firstChild) + numOfLeavesHelper(node->nextSibling);
    }

    bool isBinarySearchTreeHelper(Node* node, int min, int max) {
    if (node == nullptr) return true;
    // Ki?m tra di?u ki?n BST: node->data ph?i n?m trong kho?ng min và max
    if (node->getData() <= min || node->getData() >= max) return false;
    // Ch? có hai con: firstChild là con bên trái, và nextSibling là con bên ph?i
    Node* leftChild = root->firstChild;
    Node* rightChild = (leftChild != NULL) ? leftChild->nextSibling : NULL;
    bool leftBST = (leftChild == NULL) ? true : isBinarySearchTreeHelper(leftChild, min, root->data);
    bool rightBST = (rightChild == NULL) ? true : isBinarySearchTreeHelper(rightChild, root->data, max);
    return leftBST && rightBST;
    }


    

public:
    Tree() {
        root = nullptr;
    }
    // Các hàm kh?i t?o khác n?u c?n thi?t
    Node* find(Node* node, int data){
        if(node == nullptr)
            return nullptr;
        if(node->getData() == data)
            return node;

        Node* child = find(node->firstChild, data);
        if(child)
            return child;
        return find(node->nextSibling, data);
    }

    // Hàm thêm m?t Node vào cây
    // Hàm tr? v? false n?u Node cha không t?n t?i trên cây
    // ho?c Node father dã có con là data
    bool insert(int father, int data)
    {
        if (root == NULL) {
            root = new Node(data);
            return true;
        }

        Node* fatherNode = search(root, father);
        if (fatherNode == NULL) {
            cout << "Node cha khong ton tai!\n";
            return false;
        }

        Node* newNode = new Node(data);
        newNode->fatherNode = fatherNode;

        if (fatherNode->firstChild == NULL) {
            fatherNode->firstChild = newNode;
        } else {
            Node* sibling = fatherNode->firstChild;
            while (sibling->nextSibling != NULL) {
                sibling = sibling->nextSibling;
            }
            sibling->nextSibling = newNode;
        }
        return true;
    }

    // Hàm xóa m?t Node trên cây
    // N?u không ph?i Node lá xóa Node dó và toàn b? các Node con c?a nó
    // Hàm tr? v? s? lu?ng Node dã xóa
    // N?u Node data không t?n t?i tr? v? 0 (zero)
    int remove(int data)
    {
        if (root == nullptr) return 0;

        if (root->getData() == data) {
            int count = numOfLeaves();
            delete root;
            root = nullptr;
            return count;
        }

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            Node* child = current->firstChild;
            Node* prev = nullptr;

            while (child != nullptr) {
                if (child->getData() == data) {
                    // Xóa t?t c? các Node con c?a nó
                    int count = numOfLeavesHelper(child);
                    if (prev == nullptr) {
                        current->firstChild = child->nextSibling;
                    } else {
                        prev->nextSibling = child->nextSibling;
                    }
                    delete child;
                    return count;
                }
                prev = child;
                child = child->nextSibling;
            }

            if (current->firstChild) q.push(current->firstChild);
            if (current->nextSibling) q.push(current->nextSibling);
        }
        return 0; // Không tìm th?y Node d? xóa
    }

    // Hàm in ra các Node theo th? t? preorder
    void preorder()
    {
        preorderHelper(root);
        cout << endl;
    }


    // Hàm in ra các Node theo th? t? postorder
    void postorder()
    {
        postorderHelper(root);
        cout << endl;
    }

    // Hàm ki?m tra cây nh? phân
    bool isBinaryTree()
    {
        if (root == nullptr) return true;

        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
        Node* current = q.front();
        q.pop();

        int countChildren = 0;
        Node* child = current->firstChild;
        while (child != nullptr)
        {
            countChildren++;
            if (countChildren > 2) return false;
            child = child->nextSibling;
        }

        if (current->firstChild) q.push(current->firstChild);
        if (current->nextSibling) q.push(current->nextSibling);
        }
    return true;
    }

    // Hàm ki?m tra cây tìm ki?m nh? phân
    bool isBinarySearchTree()
    {
        return isBinarySearchTreeHelper(root, INT_MIN, INT_MAX);
    }

    // Hàm ki?m tra cây max-heap
    bool isMaxHeapTree()
    {
         if (root == nullptr) return true;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            Node* child = current->firstChild;
            while (child != nullptr) {
                if (child->getData() > current->getData()) return false;
                child = child->nextSibling;
            }

            if (current->firstChild) q.push(current->firstChild);
            if (current->nextSibling) q.push(current->nextSibling);
        }
        return true;
    }

    // Hàm in ra các Node theo th? t? inorder n?u là cây nh? phân
    void inorder()
    {
        inorderHelper(root);
        cout << endl;
    }

    // Hàm tr? v? d? cao c?a cây
    int height()
    {
        return heightHelper(root);
    }

    // Hàm tr? v? d? sâu c?a m?t Node
    int depth(int data)
    {
        if (root == nullptr) return -1; // Node không t?n t?i

        queue<Node*> q;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
        int size = q.size();
        for (int i = 0; i < size; i++)
            {
            Node* current = q.front();
            q.pop();
            if (current->getData() == data) return level;
            if (current->firstChild) q.push(current->firstChild);
            if (current->nextSibling) q.push(current->nextSibling);
            }
        level++;
        }
    return -1; // Node không t?n t?i
    }

    // Hàm d?m s? lu?ng lá
    int numOfLeaves()
    {
        return numOfLeavesHelper(root);
    }

    // Hàm tr? v? Node có giá tr? l?n nh?t
    int findMax()
    {
        if (root == NULL) return -1;
        Node* current = root;
        while(current != NULL){
                while (current->nextSibling != NULL){
                    current = current->nextSibling;
                    }
                if(current->firstChild != NULL){
                    current = current->firstChild;
                    }
                else{
				return current->data;
				}
			}
        return -1;
    }

    // Hàm tr? v? Node có nhi?u con nh?t
    int findMaxChild()
    {
        if (root == nullptr) return -1;

        int maxChildren = 0;
        int maxNode = -1;

        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
        Node* current = q.front();
        q.pop();

        int countChildren = 0;
        Node* child = current->firstChild;
        while (child != nullptr)
            {
            countChildren++;
            child = child->nextSibling;
            }

        if (countChildren > maxChildren)
            {
            maxChildren = countChildren;
            maxNode = current->getData();
            }

        if (current->firstChild) q.push(current->firstChild);
        if (current->nextSibling) q.push(current->nextSibling);
        }
    return maxNode;
    }
};
