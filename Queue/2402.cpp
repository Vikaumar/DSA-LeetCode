// LeetCode 2402. Meeting Rooms III
// Approach: Greedy Scheduling using Min-Heaps
// Idea:
//  - Sort meetings by start time
//  - Use one min-heap to track available rooms (by room index)
//  - Use another min-heap to track busy rooms (by earliest end time)
//  - If no room is free, delay the meeting to the earliest available room
//
// Time Complexity: O(m log m + m log n)
// Space Complexity: O(n)
// Where m = number of meetings, n = number of rooms

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++)
            freeRooms.push(i);

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            busyRooms;

        vector<int> cnt(n, 0);

        for (auto &m : meetings)
        {
            long long start = m[0], end = m[1];
            long long duration = end - start;

            while (!busyRooms.empty() && busyRooms.top().first <= start)
            {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!freeRooms.empty())
            {
                int room = freeRooms.top();
                freeRooms.pop();
                cnt[room]++;
                busyRooms.push({end, room});
            }
            else
            {
                auto p = busyRooms.top();
                busyRooms.pop();

                long long freeTime = p.first;
                int room = p.second;

                cnt[room]++;
                busyRooms.push({freeTime + duration, room});
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (cnt[i] > cnt[ans])
                ans = i;
        }
        return ans;
    }
};
