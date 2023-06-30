/*
Intuition :
Time Complexity : O(V + E)
Space Complexity : O(V)
*/
void DFsTraversal(int currNode, vector<int> adjList[], vector<bool> &visited,
                  vector<int> &temp)
{
    temp.push_back(currNode);
    visited[currNode] = true;
    for (auto adjNode : adjList[currNode])
        if (visited[adjNode] == false)
            DFsTraversal(adjNode, adjList, visited, temp);
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> adjList[V];
    for (auto edge : edges)
    {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }
    vector<vector<int>> ans;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i)
    {
        if (visited[i] == false)
        {
            vector<int> temp;
            DFsTraversal(i, adjList, visited, temp);
            ans.push_back(temp);
        }
    }
    return ans;
} 