#include <bits/stdc++.h>
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n)
{
    vector<bool> isCelebrity(n, true);
    for (int i = 0; i < n; ++i)
    {
        if (isCelebrity[i] == true)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j != i)
                {
                    if (knows(i, j))
                        isCelebrity[i] = false;
                    else
                        isCelebrity[j] = false;
                    if (knows(j, i))
                        isCelebrity[j] = false;
                    else
                        isCelebrity[i] = false;
                }
            }
        }
    }
    int celebrity = -1;
    for (int i = 0; i < n; ++i)
    {
        if (isCelebrity[i])
        {
            if (celebrity == -1)
                celebrity = i;
            else
                return -1;
        }
    }
    return celebrity;
} 