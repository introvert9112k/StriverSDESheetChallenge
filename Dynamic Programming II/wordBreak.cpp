/*
    Time Complexity  : O(N ^ 2)
    Space Complexity : O(N)

    Where N is the length of target string.
*/

#include <unordered_set>

#include <queue>

bool wordBreak(vector<string> &arr, int n, string &target)
{
    // Declare a hash map.
    unordered_set<string> hashMap;

    // Insert all strings of a into hashmap.
    for (string s : arr)
    {
        hashMap.insert(s);
    }

    // Declare an empty queue.
    queue<int> q;

    // Declare an empty hash map to keep track of visited nodes.
    unordered_set<int> visited;

    // Push 0 to queue.
    q.push(0);

    // Run a loop until q is not empty.
    while (q.size() > 0)
    {
        // Pop front element of queue.
        int frontElement = q.front();
        q.pop();

        // Check if front element is already visited or  not.
        if (visited.find(frontElement) == visited.end())
        {
            // Mark front element as visited.
            visited.insert(frontElement);

            // Run a loop from front element to size of target string.
            for (int j = frontElement; j < target.size(); j++)
            {
                /*
                    If substring starting from j does not exist in
                    hash map then push it to queue.
                */
                if (hashMap.find(target.substr(frontElement, j - frontElement + 1)) != hashMap.end())
                {
                    q.push(j + 1);

                    /*
                        If we have reached at the end of target
                        String then return true.
                    */
                    if (j + 1 == target.size())
                        return true;
                }
            }
        }
    }

    return false;
} 