#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Hàm tính chi?u cao c?a cây
int height(int node, const vector<vector<int>> &adj) {
    if (adj[node].empty()) return 1; // N?u là nút lá, tr? v? 1
    int maxHeight = 0;
    for (int child : adj[node]) {
        maxHeight = max(maxHeight, height(child, adj));
    }
    return maxHeight + 1;
}

// Hàm duy?t theo Preorder
void preorder(int node, const vector<vector<int>> &adj) {
    cout << node << " ";
    for (int child : adj[node]) {
        preorder(child, adj);
    }
}

// Hàm duy?t theo Postorder
void postorder(int node, const vector<vector<int>> &adj) {
    for (int child : adj[node]) {
        postorder(child, adj);
    }
    cout << node << " ";
}

// Hàm ki?m tra xem cây có ph?i là cây nh? phân không
bool isBinaryTree(int node, const vector<vector<int>> &adj) {
    if (adj[node].size() > 2) return false;
    for (int child : adj[node]) {
        if (!isBinaryTree(child, adj)) return false;
    }
    return true;
}

// Hàm duy?t theo Inorder (áp d?ng cho cây nh? phân)
void inorder(int node, const vector<vector<int>> &adj) {
    if (adj[node].size() > 0) inorder(adj[node][0], adj); // Duy?t nút trái
    cout << node << " "; // In nút g?c
    if (adj[node].size() > 1) inorder(adj[node][1], adj); // Duy?t nút ph?i
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1); // Danh sách k? d? luu các c?nh
    vector<bool> hasParent(N + 1, false); // Ðánh d?u nút nào có cha

    // Nh?p các c?nh c?a cây
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        hasParent[v] = true;
    }

    // Tìm nút g?c (nút không có cha)
    int root = -1;
    for (int i = 1; i <= N; i++) {
        if (!hasParent[i]) {
            root = i;
            break;
        }
    }

    // Tính chi?u cao c?a cây
    cout << height(root, adj) << endl;

    // Duy?t cây theo Preorder
    preorder(root, adj);
    cout << endl;

    // Duy?t cây theo Postorder
    postorder(root, adj);
    cout << endl;

    // Ki?m tra và duy?t theo Inorder n?u là cây nh? phân
    if (isBinaryTree(root, adj)) {
        inorder(root, adj);
    } else {
        cout << "NOT BINARY TREE";
    }
    cout << endl;

    return 0;
}
