// Program to find all possible permutations of an array/string.The Array/string must have unique non-repeated elements.
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> myAns;
    void countPermutes(vector<int> &myVec, unordered_map<int, int> &myMap, vector<int> &nums, int i)
    {
        if (myMap.size() >= nums.size())
        {
            myAns.push_back(myVec);
            myMap.erase(nums[i]);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (myMap.find(nums[i]) == myMap.end())
            {
                myVec.push_back(nums[i]);
                myMap[nums[i]] += 1;
                countPermutes(myVec, myMap, nums, i);
                myMap.erase(nums[i]);
                myVec.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> myVec;
        unordered_map<int, int> myMap;
        int i;
        countPermutes(myVec, myMap, nums, i);
        return myAns;
    }
};