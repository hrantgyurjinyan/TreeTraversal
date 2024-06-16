#include <iostream>

class Node 
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


class BinaryTree 
{
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    void inOrderTraversal(Node* node) 
    {
        if (node == nullptr) 
            return;
        
        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    void preOrderTraversal(Node* node) 
    {
        if (node == nullptr) 
            return;
        
        std::cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    void postOrderTraversal(Node* node) 
    {
        if (node == nullptr) 
            return;
        
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        std::cout << node->data << " ";
    }

    void inOrder() 
    {
        inOrderTraversal(root);
        std::cout << std::endl;
    }

    void preOrder() 
    {
        preOrderTraversal(root);
        std::cout << std::endl;
    }

    void postOrder() 
    {
        postOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree tree;


    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);

    std::cout << "In-Order Traversal: ";
    tree.inOrder();

    std::cout << "Pre-Order Traversal: ";
    tree.preOrder();

    std::cout << "Post-Order Traversal: ";
    tree.postOrder();


    delete tree.root->left->left;
    delete tree.root->left->right;
    delete tree.root->left;
    delete tree.root->right;
    delete tree.root;

    return 0;
}

