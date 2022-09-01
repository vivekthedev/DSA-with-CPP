
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

bool same_structure(TreeNode<int> *root, TreeNode<int> *root2)
{
    bool ans;
    if (root->children.size() == root2->children.size())
    {

        ans = root->data == root2->data ? true : false;

        for (int i = 0; i < root->children.size(); i++)
        {
            ans = ans && same_structure(root->children[i], root2->children[i]);
        }
        return ans;
    }
    return false;
}

int main()
{
    TreeNode<int> *root = takeInputLevel();
    TreeNode<int> *root2 = takeInputLevel();

    cout << same_structure(root, root2);
}
