
#include <iostream>
#include <queue>
#include "TreeNode.h"
#include <algorithm>

using namespace std;

void printTree(TreeNode<int> *root)
{
    cout << root->data << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
void printTreeNew(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ", ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTreeNew(root->children[i]);
    }
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter children of : " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int> *takeInputLevel()

{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << " th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int height(TreeNode<int> *root)
{
    int h = 1;
    vector<int> heights;
    heights.push_back(h);
    for (int i = 0; i < root->children.size(); i++)
    {
        h = 1;
        h = h + height(root->children[i]);
        heights.push_back(h);
    }
    return *max_element(heights.begin(), heights.end());
}

int num_nodes(TreeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += num_nodes(root->children[1]);
    }
    return ans;
}

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

int countLeafNode(TreeNode<int> *root)
{
    if (root->children.size() > 0)
    {
        return 1;
    }
    else
    {
        int ans = 0;
        for (int i = 0; i < root->children.size(); i++)
        {
            ans = ans + countLeafNode(root->children[i]);
        }
    }
}

void preorderTraversal(TreeNode<int> *root)
{
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorderTraversal(root->children[i]);
    }
}
void postorderTraversal(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        postorderTraversal(root->children[i]);
    }
    cout << root->data << " ";
}

void deleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

int main()
{
    //     // TreeNode<int> *root = new TreeNode<int>(1);
    //     // TreeNode<int> *node1 = new TreeNode<int>(2);
    //     // TreeNode<int> *node2 = new TreeNode<int>(3);

    //     // root->children.push_back(node1);
    //     // root->children.push_back(node2);
    TreeNode<int> *root = takeInputLevel();
    // cout << height(root);
    // postorderTraversal(root);
    //     printTreeNew(root);
}