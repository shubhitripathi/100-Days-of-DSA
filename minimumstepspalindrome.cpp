/* LINK: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".*/
#include<iostream>
using namespace std;
class Solution {
 public:
  int minInsertions(string s) {
    return s.length() - longestPalindromeSubseq(s);
  }

 private:
  // Same as 516. Longest Palindromic Subsequence
  int longestPalindromeSubseq(const string& s) {
    const int n = s.length();
    // dp[i][j] := the length of LPS(s[i..j])
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        if (s[i] == s[j])
          dp[i][j] = 2 + dp[i + 1][j - 1];
        else
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }

    return dp[0][n - 1];
  }
};
