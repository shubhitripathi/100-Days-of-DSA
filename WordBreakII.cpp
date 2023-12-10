/* LINK: https://leetcode.com/problems/word-break-ii/
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]*/
#include<iostream>
using namespace std;
class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet{wordDict.begin(), wordDict.end()};
    unordered_map<string, vector<string>> memo;
    return wordBreak(s, wordSet, memo);
  }

 private:
  vector<string> wordBreak(const string& s,
                           const unordered_set<string>& wordSet,
                           unordered_map<string, vector<string>>& memo) {
    if (const auto it = memo.find(s); it != memo.cend())
      return it->second;

    vector<string> ans;

    // 1 <= prefix.length() < s.length()
    for (int i = 1; i < s.length(); ++i) {
      const string& prefix = s.substr(0, i);
      const string& suffix = s.substr(i);
      if (wordSet.count(prefix))
        for (const string& word : wordBreak(suffix, wordSet, memo))
          ans.push_back(prefix + " " + word);
    }

    // `wordSet` contains the whole string s, so don't add any space.
    if (wordSet.count(s))
      ans.push_back(s);

    return memo[s] = ans;
  }
};