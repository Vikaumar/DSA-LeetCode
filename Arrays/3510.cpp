#include <bits/stdc++.h>
using namespace std;

/*
 LeetCode 3510 - Minimum Pair Removal to Sort Array II

 Problem:
 Given an integer array nums, you may repeatedly merge any adjacent
 pair by replacing them with their sum.
 Return the minimum number of operations required to make the array
 non-decreasing.

 Approach:
 - Treat the array as a doubly linked list using index arrays.
 - Maintain a set of all adjacent pair sums, ordered by minimum sum.
 - Track the number of inversions (arr[i] > arr[i+1]).
 - While inversions exist:
     • Merge the adjacent pair with the smallest sum.
     • Update links, sums, and inversion count locally.
 - Stop when no inversions remain.

 This approach ensures correctness by:
 - Always choosing the globally optimal merge
 - Updating only affected neighbors
 - Avoiding incorrect local greedy decisions

 Time Complexity:
 O(n log n)
 - Each merge involves set insert/erase operations

 Space Complexity:
 O(n)
*/

class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;

        vector<long long> arr(nums.begin(), nums.end());
        vector<int> nxt(n), prv(n);

        for (int i = 0; i < n; i++)
        {
            nxt[i] = i + 1;
            prv[i] = i - 1;
        }

        // Custom comparator for pair sums
        auto cmp = [&](const pair<long long, int> &a,
                       const pair<long long, int> &b)
        {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        };

        set<pair<long long, int>, decltype(cmp)> st(cmp);
        int inversions = 0;

        // Initialize adjacent sums and inversion count
        for (int i = 0; i + 1 < n; i++)
        {
            st.insert({arr[i] + arr[i + 1], i});
            if (arr[i] > arr[i + 1])
                inversions++;
        }

        int operations = 0;

        while (inversions > 0)
        {
            auto it = st.begin();
            long long sum = it->first;
            int i = it->second;
            st.erase(it);

            int j = nxt[i];
            if (j >= n || prv[j] != i)
                continue;

            if (arr[i] > arr[j])
                inversions--;

            int p = prv[i];
            int k = nxt[j];

            if (p >= 0)
            {
                if (arr[p] > arr[i])
                    inversions--;
                st.erase({arr[p] + arr[i], p});
            }

            if (k < n)
            {
                if (arr[j] > arr[k])
                    inversions--;
                st.erase({arr[j] + arr[k], j});
            }

            arr[i] = sum;

            if (p >= 0)
            {
                st.insert({arr[p] + arr[i], p});
                if (arr[p] > arr[i])
                    inversions++;
            }

            if (k < n)
            {
                nxt[i] = k;
                prv[k] = i;
                st.insert({arr[i] + arr[k], i});
                if (arr[i] > arr[k])
                    inversions++;
            }
            else
            {
                nxt[i] = n;
            }

            operations++;
        }

        return operations;
    }
};
