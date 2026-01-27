#include <bits/stdc++.h>
using namespace std;

/*
 Problem:
 Find the minimum cost to travel from node 0 to node n-1.
 Each edge [u, v, w] represents:
  - u -> v with cost w
  - v -> u with cost 2*w

 Approach:
 - Build an adjacency list with directed weighted edges.
 - Apply Dijkstra's algorithm from node 0.
 - Stop early when node (n-1) is reached.

 Time Complexity:
 O((n + m) log n), where m = number of edges

 Space Complexity:
 O(n + m)
*/

class Solution
{
public:
    int minCost(int n, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, long long>>> adj(n);

        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2LL * w});
        }

        vector<long long> dist(n, LLONG_MAX);
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<>>
            pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            long long cost = top.first;
            int node = top.second;

            if (cost > dist[node])
                continue;
            if (node == n - 1)
                return (int)cost;

            for (auto &edge : adj[node])
            {
                int next = edge.first;
                long long w = edge.second;

                if (dist[next] > cost + w)
                {
                    dist[next] = cost + w;
                    pq.push({dist[next], next});
                }
            }
        }

        return -1;
    }
};
