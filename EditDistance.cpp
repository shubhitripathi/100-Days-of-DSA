/*LINK: https://leetcode.com/problems/edit-distance/
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')*/
#include<iostream>
using namespace std;
class Solution {
 public:
  int minDistance(string word1, string word2) {
    const int m = word1.length();
    const int n = word2.length();
    // dp[i][j] := the minimum number of operations to convert word1[0..i) to
    // word2[0..j)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i)
      dp[i][0] = i;

    for (int j = 1; j <= n; ++j)
      dp[0][j] = j;

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (word1[i - 1] == word2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;

    return dp[m][n];
  }
};
