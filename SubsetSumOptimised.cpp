#include <bits/stdc++.h>
using namespace std;
void findSubset(vector<int> &arr, int &n, int &k, vector<vector<int>> &ans, vector<int> &temp, int sum, int startIndex)
{
  if (sum == k)
  {
    ans.push_back(temp);
    return;
  }

  for (int i = startIndex; i < n; i++)
  {
    if (sum + arr[i] > k) // Stop if adding the current element exceeds the target
      break;
    if (i > startIndex && arr[i] == arr[i - 1]) // Skip duplicates
      continue;

    temp.push_back(arr[i]);
    findSubset(arr, n, k, ans, temp, sum + arr[i], i + 1);
    temp.pop_back();
  }
}

vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
{
  sort(arr.begin(), arr.end());
  vector<vector<int>> ans;
  vector<int> temp;
  findSubset(arr, n, k, ans, temp, 0, 0);
  return ans;
}
// Optimised Code To Solve The Subset Sum , also called the combination sum, Problem. Works on GFG.
