#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>>
calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{

    vector<pair<int, int>> adjList[n + 1];
    for (int i = 0; i < m; ++i)
    {
        int node1 = g[i].first.first;
        int node2 = g[i].first.second;
        int wt = g[i].second;
        adjList[node1].push_back({node2, wt});
        adjList[node2].push_back({node1, wt});
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    /*Priority Queue stores 3 values
    1.Wt - Weight of the current Edge
    2.node -- currNode
    3 Parent -- Parent of the currNode.
    Basically it is storing edge [parent - node] and its weight.
    */

    /*Intially starting from the node 1,We can start from the any node.
    Intially there is no edge,so edge weight is taken as 0 and parent is taken as -1*/
    pq.push({0, 1, -1});
    /*visited is to keep track of the nodes which are in MST*/
    vector<bool> visited(n + 1, false);
    /*To store the edges in MST with its corresponding weight*/
    vector<pair<pair<int, int>, int>> MST;

    /*Iterate until the pq is not empty*/
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int edgeWeight = it[0];
        int currNode = it[1];
        int parentNode = it[2];

        /*If currNode is already visited,i.e it is in MST
        We already know that parent is in MST,and if currNode is also in MST
        that mean by adding the edge [parent-currNode] we are forming the cycle,
        so if current node is already in MST so don't take that edge and
        continue.*/
        if (visited[currNode])
            continue;
        /*Adding the currNode into MST*/
        visited[currNode] = 1;
        /*If parentNode is -1,i.e it is the first Node,no edge is found yet
        so don't add the edge into ans.*/
        if (parentNode != -1)
            MST.push_back({{parentNode, currNode}, edgeWeight});
        /*Iterating over the adjacent nodes of the currNode which are not in MST
        and adding it to the priority queue*/
        for (auto it : adjList[currNode])
        {
            int adjNode = it.first;
            int weight = it.second;
            if (visited[adjNode] == false)
                pq.push({weight, adjNode, currNode});
        }
    }
    return MST;
} 