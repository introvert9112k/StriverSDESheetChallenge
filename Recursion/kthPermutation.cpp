string findKthPermutation(int ind, int n, int &k, string &s, vector<int> &visited,
                          string &currPermutation)
{
    if (ind == n)
    {
        --k;
        if (k == 0)
            return currPermutation;
        else
            return "";
    }
    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            currPermutation += s[i];
            if (findKthPermutation(ind + 1, n, k, s, visited, currPermutation) != "")
                return currPermutation;
            currPermutation.pop_back();
            visited[i] = 0;
        }
    }
    return "";
}
/*
Intuition :
1.Take the sorted version of numbers in string format,so the permutations
generated would be lexographical order.
2.Generate all the permuations until the kth permutation is found,then return
the kth permutation.

TC : O(n!)
SC : O(n)
recursion stack space.
*/
string approach1(int n, int k)
{
    string s = "";
    for (int i = 1; i <= n; ++i)
        s.push_back(char(i + '0'));
    string currPermutation = "";
    vector<int> visited(n, 0);
    return findKthPermutation(0, n, k, s, visited, currPermutation);
}
/*
This method doesn't give the lexogrphical order permutations even if the
input is sorted.
*/
string findKthPermutation2(int ind, int n, int &k, string &s)
{
    if (ind == n)
    {
        --k;
        cout << s << endl;
        if (k == 0)
            return s;
        else
            return "";
    }
    for (int i = ind; i < n; ++i)
    {
        swap(s[ind], s[i]);
        if (findKthPermutation2(ind + 1, n, k, s) != "")
            return s;
        swap(s[ind], s[i]);
    }
    return "";
}
string approach2(int n, int k)
{
    string s = "";
    for (int i = 1; i <= n; ++i)
        s.push_back(char(i + '0'));
    return findKthPermutation2(0, n, k, s);
}
/*
Intution :
1.Basically using the mathematics we are building the kth permutation sequence.
See the TUF article for better understanding.

Time Complexity: O(N) * O(N) = O(N^2)

Reason: We are placing N numbers in N positions.
This will take O(N) time. For every number,
we are reducing the search space by removing the element already
placed in the previous step. This takes another O(N) time.

Space Complexity: O(N)
Reason: We are storing  the numbers in a data structure(here vector)
*/
string optimal(int n, int k)
{
    int fact = 1;
    vector<int> numbers;
    for (int i = 1; i < n; ++i)
    {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    k -= 1;
    string ans = "";
    while (true)
    {
        ans += to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0)
            break;
        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}
string kthPermutation(int n, int k)
{
    return optimal(n, k);
} 