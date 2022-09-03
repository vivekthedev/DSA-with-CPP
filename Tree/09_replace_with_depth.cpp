/*
Problem Statement: Replace with depth
Problem Level: MEDIUM
Problem Description:
You are given a generic tree. You have to replace each node with its depth value.
You just have to update the data of each node, there is no need to return or print anything.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output format:
The updated tree is printed level wise. Each level is printed in a new line. Please refer to sample output 1 for more details.

Constraints:
Time Limit: 1 sec

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1:
0
1 1 1
2 2
*/
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

void replace_with_depths(TreeNode<int> *root, int lev = 0)
{
    root->data = lev;
    for (int i = 0; i < root->children.size(); i++)
    {
        replace_with_depths(root->children[i], lev + 1);
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevel();
    replace_with_depths(root);
}