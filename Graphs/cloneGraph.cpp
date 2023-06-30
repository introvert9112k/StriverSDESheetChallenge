/*
   TC : O(V + 2E)
   Normal BFs time complexity
   SC : O(V + V)
   Space for the queue and the map
*/
graphNode *cloneGraph(graphNode *node)
{
    /*Create a new Node in graph corresponding to the given node of old graph*/
    graphNode *startNode = new graphNode(node->data);
    /*We use BFs to traverse the graph and create of deep copy of it*/
    queue<graphNode *> q;
    /*Push the original graph Node into queue*/
    q.push(node);
    /*We would take a map
    key -- The node value.
    value -- Corresponding node in the new graph*/
    unordered_map<int, graphNode *> map;
    /*Inserting the new node into the map.
    This only works when the nodes are unique,else we should map the old node with it's corresponding
    new node.*/
    map[node->data] = startNode;
    while (!q.empty())
    {
        auto currNode = q.front();
        q.pop();
        /*Iterate over all the neighbours of the currNode*/
        for (auto adjNode : currNode->neighbours)
        {
            /*If neighbour node is not present in the map,that mean it is not visited yet.
            Create a new node corresponding to the neighbour node and insert in map and insert
            the neighbour node in the queue*/
            if (map.find(adjNode->data) == map.end())
            {
                /*Creating the corresponding node for the neigbhour node*/
                graphNode *newGraphAdjNode = new graphNode(adjNode->data);
                /*Inserting in map*/
                map[adjNode->data] = newGraphAdjNode;
                /*Pushing the neigbhour node into its corresponding parent node*/
                map[currNode->data]->neighbours.push_back(newGraphAdjNode);
                /*Pushing the original neighbour node into queue,for further traversal*/
                q.push(adjNode);
            }
            /*If neighbour node is already visited,that mean the corresponding copy graph nodes
            of the currNode and neighbour nodes are already created,so just push the corresponding
            nodes*/
            else
            {
                map[currNode->data]->neighbours.push_back(map[adjNode->data]);
            }
        }
    }
    return startNode;
} 