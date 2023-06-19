/*
Intuition:
1.Sort the intervals based on the arrival time becomes,the train which
arrives first will occupy the platform first.

2.If arrival time is same then take the train with early departure.

3.Intially 1 platform would be alloted for the train which comes first.

4.If the second train has arrival time > departure time of first then
second would go into the platform else it other platform.

5.let's second train need other platform, now we have two platforms and two
trains in platform,if the third train comes, if departure time of any of the
two trains is less than the arrival time of third train,then it goes
into that platform else it need new platform.

6.So intution is keep track of the departure times of all the train that are
not left yet, pick up the train which has minimum departure time among them.
If the coming train arrival < departure then this train goes to that
platform, so platforms are not increased and this platform has departure
time equal to current train departure time.
else it requires another platform and it also waits in its platform,so
add the current trian departure to the list.

TC : O(n + nlogn + nlogn)
n -- for creating the array vector
nlogn -- for sorting the vector based on arrival times.
nlogn -- for calculating the platforms required
SC : O(n + n)
Space for the array and priority Queue
*/
int approach1(int at[], int dt[], int n)
{
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i)
        arr[i] = {at[i], dt[i]};
    sort(arr.begin(), arr.end(), [&](pair<int, int> &p1, pair<int, int> &p2)
         {
        if(p1.first < p2.first) return true;
        else if(p1.first == p2.first) return p1.second < p2.second;
        else return false; });
    /*This stores the departure times of all the waiting trains in platforms*/
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(arr[0].second);
    int platforms = 1;
    for (int i = 1; i < n; ++i)
    {
        /*If any of the waiting train departure time is less than
        the current train arrival time,then it goes to that platform,
        as previous train left remove its departure time for pq.*/
        if (pq.top() < arr[i].first)
            pq.pop();
        /*New platform is required for the coming train*/
        else
            ++platforms;
        /*As current train arrived,add its departure time to the
        waiting trains list*/
        pq.push(arr[i].second);
    }
    return platforms;
}
/*
Intuition :
1.sort the arrival and departure arrays.
2.maintain two pointers i,and j to traverse the arrays.
3.if at[i] <= dt[j],dt[j] points to train which has minimum departure time.
4.So if any of the train has arrival time less than the minimum departure
time then it requires a platform.
5.at[i] > dt[j],that mean the train has left so the curr train can come into
the left platform so decrease the platform.

TC : O(2nlogn + 2n)
SC : O(1)
see the TUF article for the explanation.
*/
int optimal1(int at[], int dt[], int n)
{
    sort(at, at + n);
    sort(dt, dt + n);
    int currPlatforms = 0, maxPlatforms = 0;
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (at[i] <= dt[j])
            ++currPlatforms, ++i;
        else
            --currPlatforms, ++j;
        maxPlatforms = max(maxPlatforms, currPlatforms);
    }
    return maxPlatforms;
}
int calculateMinPatforms(int at[], int dt[], int n)
{
    // return approach1(at,dt,n);
    return optimal1(at, dt, n);
}