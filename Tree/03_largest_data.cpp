/*
Coding Problem
Problem Statement: Node with largest data
Problem Level: MEDIUM
Problem Description:
Given a generic tree, find and return the node with maximum data. You need to return the node which is having maximum data.
Return null if tree is empty.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.

Output Format :
The first and only line of output contains the data of the node with largest data in the given tree.

Constraints:
Time Limit: 1 sec

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0

Sample Output 1:
50

*/

#include <iostream>
#include "01_treeuse.cpp"
using namespace std;

int largest_num(TreeNode<int> *root)
{
    int largest = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        // if (largest < )
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevel();
}