
#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;

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

int just_larger_number(TreeNode<int> *root, int number)
{
    if (root->data > number)
    {
        number = root->data - number;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevel();
}