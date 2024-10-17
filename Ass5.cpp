class Tree {
    // Ch?a m?t Node g?c
    Node* root;

    // C�c h�m ph? tr? cho c�c h�m ch�nh
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
    // Ki?m tra di?u ki?n BST: node->data ph?i n?m trong kho?ng min v� max
    if (node->getData() <= min || node->getData() >= max) return false;
    // Ch? c� hai con: firstChild l� con b�n tr�i, v� nextSibling l� con b�n ph?i
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
    // C�c h�m kh?i t?o kh�c n?u c?n thi?t
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

    // H�m th�m m?t Node v�o c�y
    // H�m tr? v? false n?u Node cha kh�ng t?n t?i tr�n c�y
    // ho?c Node father d� c� con l� data
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

    // H�m x�a m?t Node tr�n c�y
    // N?u kh�ng ph?i Node l� x�a Node d� v� to�n b? c�c Node con c?a n�
    // H�m tr? v? s? lu?ng Node d� x�a
    // N?u Node data kh�ng t?n t?i tr? v? 0 (zero)
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
                    // X�a t?t c? c�c Node con c?a n�
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
        return 0; // Kh�ng t�m th?y Node d? x�a
    }

    // H�m in ra c�c Node theo th? t? preorder
    void preorder()
    {
        preorderHelper(root);
        cout << endl;
    }


    // H�m in ra c�c Node theo th? t? postorder
    void postorder()
    {
        postorderHelper(root);
        cout << endl;
    }

    // H�m ki?m tra c�y nh? ph�n
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

    // H�m ki?m tra c�y t�m ki?m nh? ph�n
    bool isBinarySearchTree()
    {
        return isBinarySearchTreeHelper(root, INT_MIN, INT_MAX);
    }

    // H�m ki?m tra c�y max-heap
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

    // H�m in ra c�c Node theo th? t? inorder n?u l� c�y nh? ph�n
    void inorder()
    {
        inorderHelper(root);
        cout << endl;
    }

    // H�m tr? v? d? cao c?a c�y
    int height()
    {
        return heightHelper(root);
    }

    // H�m tr? v? d? s�u c?a m?t Node
    int depth(int data)
    {
        if (root == nullptr) return -1; // Node kh�ng t?n t?i

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
    return -1; // Node kh�ng t?n t?i
    }

    // H�m d?m s? lu?ng l�
    int numOfLeaves()
    {
        return numOfLeavesHelper(root);
    }

    // H�m tr? v? Node c� gi� tr? l?n nh?t
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

    // H�m tr? v? Node c� nhi?u con nh?t
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
