/* Circle of strings

Given an array arr of lowercase strings, determine if the strings can be chained together to form a circle.
A string X can be chained together with another string Y if the last character of X is the same as the first
character of Y. If every string of the array can be chained with exactly two strings of the array(one with the
first character and the second with the last character of the string), it will form a circle.

For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings
can be chained as "for", "rig", "geek" and "kaf"

Examples

Input: arr[] = ["abc", "bcd", "cdf"]
Output: 0
Explaination: These strings can't form a circle because no string has 'd'at the starting index.
Input: arr[] = ["ab" , "bc", "cd", "da"]
Output: 1
Explaination: These strings can form a circle of strings.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints: 
1 ≤ length of strings ≤ 20 */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int node, unordered_map<int, vector<int>> & graph, vector<bool> & visited ){
        visited[node] = true;
        if(graph.find(node) != graph.end()){
            for(int i=0; i<graph[node].size(); i++){
                if(!visited[graph[node][i]])
                dfs(graph[node][i], graph, visited);
            }
        }
    }
    int isCircle(vector<string> &arr) {
        // code here
        unordered_map<int, vector<int>> graph;
        vector<int> inorder(26,0);
        vector<int> outorder(26,0);
        int n = arr.size();
        for(int i=0; i<n; i++){
            string temp = arr[i];
            int a = temp[0]-'a';
            int b = temp[temp.size() - 1]-'a';
            graph[a].push_back(b);
            outorder[a] += 1;
            inorder[b] += 1;
        }
        for(int i=0; i<26; i++){
            if(inorder[i] != outorder[i]){
                return 0;
            }
        }
        vector<bool> visited(26,false);
        dfs(arr[0][0]-'a', graph, visited);
        for(int i=0; i<26; i++){
            if(inorder[i] && outorder[i] && !(visited[i])){
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends
