#include <bits/stdc++.h>
/*The key observation here is that we need to pick items which have
higher value/weight ratio.

Here is the algorithm:

1.We will calculate the ratio of value/weight for each item.
2.Sort the items in decreasing order based on this ratio.
3.We take the item with the highest ratio first and add them until we can’t
add a whole item. Add the next item as much as we can.

Time Complexity
O(N * log(N)), where ‘N’ is the number of items.
Since we are sorting the array, the time complexity is O(NlogN).

Space Complexity
O(1), i.e. constant space complexity.

*/
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    /*sorting the items based on value/weight ratio*/
    sort(items.begin(), items.end(), [&](pair<int, int> &p1, pair<int, int> &p2)
         {
        int weight1 = p1.first,value1 = p1.second;
        int weight2 = p2.first,value2 = p2.second;
        return double(value1)/weight1 > double(value2)/weight2; });
    int currWeight = 0;
    double maxProfit = 0;
    for (int i = 0; i < n; ++i)
    {
        int weight = items[i].first, profit = items[i].second;
        /*If weight can be fully taken into knapsack then take it*/
        if (currWeight + weight <= w)
        {
            currWeight += weight;
            maxProfit += profit;
        }
        /*Take the fraction value of the reaming weight left in knapsack.
        Here after we cannot take any other weight into knapscak so break from loop*/
        else
        {
            int weightLeft = w - currWeight;
            maxProfit += (double(weightLeft) / weight) * double(profit);
            break;
        }
    }
    return maxProfit;
}