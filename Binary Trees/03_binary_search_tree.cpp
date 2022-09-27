#include <iostream>
#include <queue>
#include "BinaryTree.h"
#include <list>
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
bool binary_search(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    bool ans = root->data > data ? binary_search(root->right, data) : binary_search(root->right, data);
    return ans;
}

void printRange(BinaryTreeNode<int> *root, int l, int u)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data >= l && root->data <= u)
    {
        cout << root->data << " ";
    }
    printRange(root->left, l, u);
    printRange(root->right, l, u);
}

bool check_bst(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left)
    {
        if (root->data < root->left->data)
        {
            return false;
        }
    }

    if (root->right)
    {
        if (root->data > root->right->data)
        {
            return false;
        }
    }
    bool ans_l = check_bst(root->left);
    bool ans_r = check_bst(root->right);
    return ans_l && ans_r;
}

BinaryTreeNode<int> *construct_bst(int arr[], int l, int u)
{
    if (l >= u)
    {
        int num = arr[l];
        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(num);
        return root;
    }
    int m = (l + u) / 2;
    int num = arr[m];
    cout << num << endl;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(num);
    root->left = construct_bst(arr, l, m - 1);
    root->right = construct_bst(arr, m + 1, u);
    return root;
}

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

pair<Node *, Node *> bst_to_LL(BinaryTreeNode<int> *root)
{
    /* Incomplete */
    if (root == NULL)
    {
        pair<Node *, Node *> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    Node *head = new Node(root->data);
    cout << "created head for " << head->data << endl;

    pair<Node *, Node *> left = bst_to_LL(root->left);

    pair<Node *, Node *> right = bst_to_LL(root->right);

    if (right.first != NULL)
    {
        // cout << "Attaching " << right.first->data << " to the next of " << head->data << endl;
        head->next = right.first;
    }
    if (left.second != NULL)
    {
        // cout << "Attaching " << head->data << " to the next of " << left.second->data << endl;
        left.second->next = head;
        left.second = right.second;
        // cout << "Now my left pair is (" << left.first->data << ", " << left.second->data << ")" << endl;
    }
    if (left.first == NULL && left.second == NULL)
    {
        left.first = head;
        left.second = head;
        // cout << "Now my left pair is (" << left.first->data << ", " << left.second->data << ")" << endl;
    }

    return left;
}

vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftOutput = getRootToNodePath(root->left, data);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    return NULL;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevel();
    // cout << binary_search(root, 17);
    // printRange(root, 3, 8);
    // cout << check_bst(root);
    // int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // BinaryTreeNode<int> *root = construct_bst(arr, 0, 6);
    // printTree(root);
    // pair<Node *, Node *> p = bst_to_LL(root);
}