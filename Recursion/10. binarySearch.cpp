/*

Chapter Assignment
Problem Statement: Binary Search (Recursive)
Problem Level: EASY
Problem Description:
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :
Line 1 : Array size
Line 2 : Array elements (separated by space)
Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5

Sample Output:
3

*/

#include <iostream>
using namespace std;
int binarySearch(int nums[], int num, int start, int end)
{
    int mid = start + end / 2;
    if (nums[mid] == num)
    {
        return mid;
    }
    if (nums[mid] > num)
    {
        binarySearch(nums, num, start, mid - 1);
    }
    if (nums[mid] < num)
    {
        binarySearch(nums, num, mid + 1, end);
    }
}
int main()
{
    int size, num, nums[200] = {2, 56, 78, 123, 8589, 43222};
    cin >> size;
    // string data;
    // getline(cin, data);
    cin >> num;
    cout << binarySearch(nums, num, 0, size - 1);
    return 0;
}