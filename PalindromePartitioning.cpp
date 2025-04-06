/*
131. Palindrome Partitioning

Given a string s, partition s such that every
substring
 of the partition is a
palindrome
. Return all possible palindrome partitioning of s.



Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]


Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
        backtrack(s, ans, temp, 0);
        return ans;
    }
    void backtrack(string &s, vector<vector<string>> &ans, vector<string> &temp, int start)
    {
        if (start == s.length())
        {
            ans.push_back(temp);
            return;
        }

        for (int end = start; end < s.length(); end++)
        {
            if (isPalindrome(s, start, end))
            {
                temp.push_back(s.substr(start, end - start + 1));
                backtrack(s, ans, temp, end + 1);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end)
    {
        for (int i = start, j = end; i <= j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};
