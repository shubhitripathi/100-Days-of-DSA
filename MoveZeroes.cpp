/* LINK: https://leetcode.com/problems/move-zeroes/
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]*/

#include<iostream>
using namespace std;
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int i = 0;
    for (const int num : nums)
      if (num != 0)
        nums[i++] = num;

    while (i < nums.size())
      nums[i++] = 0;
  }
};


usi
