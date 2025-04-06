// Recursive Solution to Find All Subsets/ Find Power Set :-
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findSubset(vector<int> arr, int startIndex, vector<int> temp, vector<vector<int>> &ans)
{

    if (startIndex == arr.size())
    {
        ans.push_back(temp);
        return;
    }

    findSubset(arr, startIndex + 1, temp, ans);
    temp.push_back(arr[startIndex]);
    findSubset(arr, startIndex + 1, temp, ans);
}

int main()
{

    vector<int> arr = {1, 3, 44, 5, 78, 0};
    vector<int> temp;
    vector<vector<int>> ans;
    findSubset(arr, 0, temp, ans);
    // Print the 2d ans vector to print all subsets of given arr.
    return 0;
}

// To decrease space complexity, recieve temp as reference too, and do temp.pop_back() after the recursive call in which you include the array elements( doosri wali recursive call).
