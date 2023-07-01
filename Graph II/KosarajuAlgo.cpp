#include <bits/stdc++.h>
/*finding the topological order*/
void findTopologicalOrder(int currNode, vector<int> adjList[], vector<int> &visited,
                          stack<int> &st)
{
    visited[currNode] = 1;
    for (auto adjNode : adjList[currNode])
        if (visited[adjNode] == 0)
            findTopologicalOrder(adjNode, adjList, visited, st);
    st.push(currNode);
}

/*DFs on the reversed graph for finding the scc*/
void DFs(int currNode, vector<int> adjList[], vector<int> &visited,
         vector<int> &scc)
{
    visited[currNode] = 1;
    scc.push_back(currNode);
    for (auto adjNode : adjList[currNode])
        if (visited[adjNode] == 0)
            DFs(adjNode, adjList, visited, scc);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    /*adjacency lists for before and after receving the edes*/
    vector<int> adjList[n], reverseadjList[n];
    /*building the adjacency list*/
    for (auto edge : edges)
        adjList[edge[0]].push_back(edge[1]);
    /*Visited array for the DFs calls*/
    vector<int> visited(n, 0);
    /*stack to store the topological ordering*/
    stack<int> st;
    /*Finding the topological ordering across all components*/
    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == false)
            findTopologicalOrder(i, adjList, visited, st);
    }
    /*Reverseing the edges*/
    for (auto edge : edges)
        reverseadjList[edge[1]].push_back(edge[0]);
    /*reusing the visited array for scc calculation*/
    for (int i = 0; i < n; ++i)
        visited[i] = 0;
    /*Ans for storing the sccs*/
    vector<vector<int>> sccs;
    /*Finding the Scc*/
    while (!st.empty())
    {
        if (visited[st.top()] == 0)
        {
            vector<int> scc;
            DFs(st.top(), reverseadjList, visited, scc);
            sccs.push_back(scc);
        }
        st.pop();
    }
    return sccs;
} 