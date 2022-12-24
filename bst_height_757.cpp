#include <iostream>

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
    else {
      root->right = add_elem(root->right, a);
    }
    return root;
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
    cout << (*root) << " " << *(root->left) << " " << *(root->right) << "\n";
}