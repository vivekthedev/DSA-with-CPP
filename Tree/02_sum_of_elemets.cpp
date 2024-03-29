/*
Coding Problem
Problem Statement: Sum of all nodes
Problem Level: EASY
Problem Description:
Given a generic tree, find and return the sum of all nodes present in the given tree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output prints the sum of all nodes of the given generic tree.

Constraints:
Time Limit: 1 sec

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1:
190
*/

#include <iostream>
#include "01_treeuse.cpp"
using namespace std;

int node_sum(TreeNode<int> *root)
{
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += node_sum(root->children[i]);
    }
    return ans;
}

int main()
{
    TreeNode<int> *root = takeInputLevel();
    cout << node_sum(root);
}