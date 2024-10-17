#include <bits/stdc++.h>
#include <vector>
using namespace std;

// H�m t�nh chi?u cao c?a c�y
int height(int node, const vector<vector<int>> &adj) {
    if (adj[node].empty()) return 1; // N?u l� n�t l�, tr? v? 1
    int maxHeight = 0;
    for (int child : adj[node]) {
        maxHeight = max(maxHeight, height(child, adj));
    }
    return maxHeight + 1;
}

// H�m duy?t theo Preorder
void preorder(int node, const vector<vector<int>> &adj) {
    cout << node << " ";
    for (int child : adj[node]) {
        preorder(child, adj);
    }
}

// H�m duy?t theo Postorder
void postorder(int node, const vector<vector<int>> &adj) {
    for (int child : adj[node]) {
        postorder(child, adj);
    }
    cout << node << " ";
}

// H�m ki?m tra xem c�y c� ph?i l� c�y nh? ph�n kh�ng
bool isBinaryTree(int node, const vector<vector<int>> &adj) {
    if (adj[node].size() > 2) return false;
    for (int child : adj[node]) {
        if (!isBinaryTree(child, adj)) return false;
    }
    return true;
}

// H�m duy?t theo Inorder (�p d?ng cho c�y nh? ph�n)
void inorder(int node, const vector<vector<int>> &adj) {
    if (adj[node].size() > 0) inorder(adj[node][0], adj); // Duy?t n�t tr�i
    cout << node << " "; // In n�t g?c
    if (adj[node].size() > 1) inorder(adj[node][1], adj); // Duy?t n�t ph?i
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1); // Danh s�ch k? d? luu c�c c?nh
    vector<bool> hasParent(N + 1, false); // ��nh d?u n�t n�o c� cha

    // Nh?p c�c c?nh c?a c�y
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        hasParent[v] = true;
    }

    // T�m n�t g?c (n�t kh�ng c� cha)
    int root = -1;
    for (int i = 1; i <= N; i++) {
        if (!hasParent[i]) {
            root = i;
            break;
        }
    }

    // T�nh chi?u cao c?a c�y
    cout << height(root, adj) << endl;

    // Duy?t c�y theo Preorder
    preorder(root, adj);
    cout << endl;

    // Duy?t c�y theo Postorder
    postorder(root, adj);
    cout << endl;

    // Ki?m tra v� duy?t theo Inorder n?u l� c�y nh? ph�n
    if (isBinaryTree(root, adj)) {
        inorder(root, adj);
    } else {
        cout << "NOT BINARY TREE";
    }
    cout << endl;

    return 0;
}
