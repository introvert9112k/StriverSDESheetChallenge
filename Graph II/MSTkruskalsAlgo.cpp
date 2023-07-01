#include <bits/stdc++.h>
class UnionFind
{
private:
    vector<int> parent, rank;

public:
    UnionFind(int n)
    {
        for (int i = 0; i <= n; ++i)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void makeUinon(int node1, int node2)
    {
        int up1 = findParent(node1);
        int up2 = findParent(node2);
        if (up1 != up2)
        {
            if (rank[up1] > rank[up2])
                parent[up2] = up1;
            else if (rank[up2] > rank[up1])
                parent[up1] = up2;
            else
            {
                parent[up2] = up1;
                rank[up1]++;
            }
        }
    }
    bool belongsToSameComponent(int node1, int node2)
    {
        return findParent(node1) == findParent(node2);
    }
};
int kruskalMST(int n, int m, vector<vector<int>> &graph)
{
    vector<vector<int>> edges;
    for (int i = 0; i < m; ++i)
    {
        int node1 = graph[i][0], node2 = graph[i][1], weight = graph[i][2];
        edges.push_back({weight, node1, node2});
    }
    sort(edges.begin(), edges.end());
    int MinimumSum = 0;
    UnionFind dsu(n);
    for (int i = 0; i < m; ++i)
    {
        int weight = edges[i][0], node1 = edges[i][1], node2 = edges[i][2];
        if (dsu.belongsToSameComponent(node1, node2) == false)
        {
            dsu.makeUinon(node1, node2);
            MinimumSum += weight;
        }
    }
    return MinimumSum;
} 