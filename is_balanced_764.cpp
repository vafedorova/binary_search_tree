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

// высота дерева
int calc_height(const Node *root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(calc_height(root->left), calc_height(root->right));
}

// проверка сбалансированности
bool is_balanced(const Node *root) {
    if (root == nullptr) {
        return true;
    }
    if (abs(calc_height(root->left) - calc_height(root->right)) > 1) {
        return false;
    }
    return is_balanced(root->left) && is_balanced(root->right);
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
    cout << (is_balanced(root) ? "YES" : "NO") << "\n";
}