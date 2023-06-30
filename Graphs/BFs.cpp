#include <bits/stdc++.h> 
/*
Time Complexity  : O(V + E)
Space Complexity : O(V)
*/
vector<int> usingAdjacencyList(int vertex, vector<pair<int, int>> edges)
{
    vector<int> ans;
    vector<int> adjList[vertex];
    for(auto edge : edges)
    {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }
    vector<bool> visited(vertex,false);
    for(int i = 0; i<vertex; ++i)
    {
        if(visited[i] == false)
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty())
            {
                int currNode = q.front();
                q.pop();
                ans.push_back(currNode);
                for(auto adjNode : adjList[currNode])
                {
                    if(visited[adjNode] == false)
                    {
                        visited[adjNode] = true;
                        q.push(adjNode);
                    }
                }
            }
        }
    }
    return ans;
}


/* 
	Time complexity: O(V + E). 
	Space complexity: O(V^2). 

	Where V is the number of vertices in the input graph and 
    E is the number of edges in the input graph.
*/ 
vector<int> usingAdjacenyMatrix(int vertex, vector<pair<int, int>> edges)
{
    vector<vector<int>> adjacencyMatrix(vertex,vector<int>(vertex,0));
	for (int i = 0; i < edges.size(); i++)
	{
		adjacencyMatrix[edges[i].first][edges[i].second] = 1;
		adjacencyMatrix[edges[i].second][edges[i].first] = 1;
	}
	vector<bool> visited(vertex,false);
	vector<int> result;
    for (int i = 0; i < vertex; i++) {
        if (!visited[i])
        {
            queue<int> q;
            visited[i] = true;
            q.push(i);
            while (!q.empty()) 
            {
                int currNode = q.front();
                q.pop();
                result.push_back(currNode);
                for (int adjNode = 0; adjNode < vertex; ++adjNode)
                {
                    if (adjacencyMatrix[currNode][adjNode] == 1 && !visited[adjNode])
                    {
                        visited[adjNode] = true;
                        q.push(adjNode);
                    }
                }
            }
        }
    }
    return result;
} 

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    return usingAdjacenyMatrix(vertex, edges);
}  