#include <iostream>
#include <queue>
#include "BinaryTree.h"
using namespace std;

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    if (root->left)
    {
        cout << "L " << root->left->data;
    }
    if (root->right)
    {
        cout << "R " << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *left = takeInput();
    BinaryTreeNode<int> *right = takeInput();

    root->left = left;
    root->right = right;
    return root;
}

BinaryTreeNode<int> *takeInputLevel()
{
    int rootData;
    cout << "enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

int numNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 1;
    return 1 + numNodes(root->left) + numNodes(root->right);
}

void inorderTraversal(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int getMax(int a, int b)
{
    return a > b ? a : b;
}

int height(BinaryTreeNode<int> *root)
{
    int l = 0, r = 0;
    if (root->left)
    {
        l = height(root->left);
    }

    if (root->right)
    {
        r = height(root->right);
    }
    return 1 + getMax(l, r);
}

bool is_node_exists(BinaryTreeNode<int> *root, int data)
{
    if (root->data == data)
    {
        return true;
    }
    bool l = false, r = false;
    if (root->left)
    {
        l = is_node_exists(root->left, data);
    }
    if (root->right)
    {
        r = is_node_exists(root->right, data);
    }
    return l || r;
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int> *root = takeInputLevel();
    // printTree(root);
    // cout << height(root);
    // cout << is_node_exists(root, 81);
    // cout << numNodes(root);
    // inorderTraversal(root);
}