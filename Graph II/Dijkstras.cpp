#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    vector<pair<int, int>> adjList[vertices];
    for (auto edge : vec)
    {
        adjList[edge[0]].push_back({edge[1], edge[2]});
        adjList[edge[1]].push_back({edge[0], edge[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        int currNode = pq.top().second;
        int sourceToCurrNodeDistance = pq.top().first;
        pq.pop();
        for (auto it : adjList[currNode])
        {
            int adjNode = it.first;
            int edgeDistance = it.second;
            int newDistance = sourceToCurrNodeDistance + edgeDistance;
            if (newDistance < distance[adjNode])
            {
                distance[adjNode] = newDistance;
                pq.push({newDistance, adjNode});
            }
        }
    }
    return distance;
}  