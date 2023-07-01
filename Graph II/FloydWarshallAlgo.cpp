void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            /*If matrix[i][j] is -1 then there is no edge betwen i and j.
             so make it to 1e9 so that it is not get updated in the algo*/
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 1e9;
            }
            /*shortest distance from node-node is zero.
              so make matrix[i][j] = 0*/
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    /*Applying the floyd warshall algorthim.*/
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                /*if any of shortestPath[i][k] == 1e9 ||
         shortestPath[k][j] == 1e9.
            That mean there is no path from i to k or k to j.
            We should consider only paths which are valid paths.
            Suppose there is path shorestPath[i][k] < 0 and no
             path between k-->j i.e shortestPath[k][j] == 1e9,
             if we take both the sum
            (shortestPath[i][k] + shorestPath[k][j]) <
                                     shortestPath[i][j]
            Which is not valid.
            This happens because of the negative edges present
            in the graph.
            Conisder only those paths which are valid.
            */
                if (shortestPath[i][k] == 1e9 || shortestPath[k][j] == 1e9)
                    continue;
                else
                    shortestPath[i][j] = min(shortestPath[i][j],
                                             shortestPath[i][k] + shortestPath[k][j]);
            }
        }
    }
    /*making back the 1e9 to -1*/
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
            {
                matrix[i][j] = -1;
            }
        }
    }
}
 