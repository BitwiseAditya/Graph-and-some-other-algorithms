/* 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

 

Example 1:


Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
Example 2:


Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numOfCities( unordered_map<int, vector<pair<int, int>>> & graph, int n, int dT, int v){
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<int> distance(n,INT_MAX);
        distance[v] = 0;
        pq.push({0,{v,v}});
        while(!pq.empty()){
            int weight = pq.top().first;
            int from = pq.top().second.first;
            int to = pq.top().second.second;
            pq.pop();
            for(auto & nums : graph[to]){
                    if(distance[nums.first] > distance[to] + nums.second){
                        distance[nums.first] = distance[to] + nums.second;
                        pq.push({nums.second,{to,nums.first}});
                    }
            }
        }
        int count = 0;
        for(auto & it : distance){
            if(it <= dT){
                count += 1;
            }
        }
        return count;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for(auto & edge : edges){
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }
        int ans;
        int minCount = INT_MAX;
        for(int i=0; i<n; i++){
           int temp = numOfCities(graph, n, distanceThreshold, i);
           if(temp <= minCount){
            minCount = temp;
            ans = i;
           }
        }
        return ans;
    }
};



