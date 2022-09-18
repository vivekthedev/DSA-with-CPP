#include <iostream>
#include "BinaryTree.h"
using namespace std;

class BST
{
    BinaryTreeNode<int> *root;
    bool hasData(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        else if (data < root->data)
        {
            return hasData(data, root->left);
        }
        else
        {
            return hasData(data, root->right);
        }
    }

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }
    void insert(int data)
    {
    }
    void deleteData(int data)
    {
    }
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }
};