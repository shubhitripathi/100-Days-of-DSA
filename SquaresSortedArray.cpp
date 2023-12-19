/* LINK : https://leetcode.com/problems/squares-of-a-sorted-array/
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]*/
#include<iostream>
using namespace std;
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    const int n = nums.size();
    vector<int> ans(n);
    int i = n - 1;

    for (int l = 0, r = n - 1; l <= r;)
      if (abs(nums[l]) > abs(nums[r]))
        ans[i--] = nums[l] * nums[l++];
      else
        ans[i--] = nums[r] * nums[r--];

    return ans;
  }
};