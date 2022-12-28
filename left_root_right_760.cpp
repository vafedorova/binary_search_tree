#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

ostream &operator<<(ostream &out, const Node &a) {
    out << a.data;
    return out;
}

Node *add_elem(Node *root, int a) {
    if (root == nullptr) {
        root = new Node(a);
        return root;
    }
    if (a < root->data) {
        root->left = add_elem(root->left, a);
    }
    else if (a > root->data) {
        root->right = add_elem(root->right, a);
    }
    return root;
}

// обход левый-корень-правый
void left_root_right(const Node *root) {
    if (root == nullptr) {
        return;
    }
    left_root_right(root->left);
    cout << root->data << "\n";
    left_root_right(root->right);
}

int main() {
    Node *root = nullptr;
    int a;
    cin >> a;
    while (a != 0)
    {
        root = add_elem(root, a);
        cin >> a;
    }
    left_root_right(root);
}