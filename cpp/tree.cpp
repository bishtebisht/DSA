#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// //inorder -> left->root->right
// void inorder(Node* root) {
//     if (root == nullptr) {
//         return;
//     }
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }

// int main() {
//     Node* root = createNode(1);
//     root->left = createNode(2);
//     root->right = createNode(3);
//     root->left->left = createNode(4);
//     root->left->right = createNode(5);
    
//     cout << "Inorder Traversal: ";
//     inorder(root);
    
//     return 0;
// }

//Sum of root to leaf binary numbers

int sumRootToLeaf(Node* root, int currentSum) {
    if (root == nullptr) {
        return 0;
    }
    
    //building binary number by shifting left and adding current node's data
    currentSum = currentSum * 2 + root->data;
    
    // If it's a leaf node, return the current sum
    if (root->left == nullptr && root->right == nullptr) {
        return currentSum;
    }
    
    // Recur for left and right subtrees
    return sumRootToLeaf(root->left, currentSum) + sumRootToLeaf(root->right, currentSum);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(0);
    root->right = createNode(1);
    root->left->left = createNode(0);
    root->left->right = createNode(1);
    
    int result = sumRootToLeaf(root, 0);
    cout << "Sum of Root to Leaf Binary Numbers: " << result << endl;
    
    return 0;
}
