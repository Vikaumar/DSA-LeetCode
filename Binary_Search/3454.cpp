#include <bits/stdc++.h>
using namespace std;

/*
 LeetCode 3454 - Separate Squares II

 Approach:
 - Sweep line along Y-axis
 - Convert squares into entering and leaving events
 - Maintain active X-intervals using Segment Tree
 - Compute union area
 - Find minimum Y where area below == area above

 Time Complexity: O(N log N)
 Space Complexity: O(N)
*/

class Solution {
public:
    struct Event {
        double y;
        int type;          // +1 = add interval, -1 = remove interval
        double x1, x2;

        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    // Segment Tree for tracking union length on X-axis
    struct SegmentTree {
        int n;
        vector<int> count;
        vector<double> length;
        vector<double> xs;

        SegmentTree(int n, vector<double>& xs)
            : n(n), count(4 * n, 0), length(4 * n, 0), xs(xs) {}

        void pushUp(int node, int l, int r) {
            if (count[node] > 0) {
                length[node] = xs[r + 1] - xs[l];
            } else if (l == r) {
                length[node] = 0;
            } else {
                length[node] = length[node * 2] + length[node * 2 + 1];
            }
        }

        void update(int node, int l, int r, int ql, int qr, int val) {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                count[node] += val;
                pushUp(node, l, r);
                return;
            }

            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid + 1, r, ql, qr, val);
            pushUp(node, l, r);
        }

        double totalCoveredLength() {
            return length[1];
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        vector<double> xs;

        // Create sweep events
        for (auto& s : squares) {
            double x = s[0], y = s[1], l = s[2];
            events.push_back({y, +1, x, x + l});
            events.push_back({y + l, -1, x, x + l});
            xs.push_back(x);
            xs.push_back(x + l);
        }

        // Coordinate compression
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        sort(events.begin(), events.end());

        SegmentTree st(xs.size() - 1, xs);

        auto getIndex = [&](double x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };

        // First pass: compute total area
        double totalArea = 0.0;
        for (int i = 0; i + 1 < events.size(); i++) {
            int l = getIndex(events[i].x1);
            int r = getIndex(events[i].x2) - 1;
            st.update(1, 0, st.n - 1, l, r, events[i].type);

            double height = events[i + 1].y - events[i].y;
            totalArea += st.totalCoveredLength() * height;
        }

        // Second pass: find Y where area reaches half
        double halfArea = totalArea / 2.0;
        st = SegmentTree(xs.size() - 1, xs);

        double currentArea = 0.0;
        for (int i = 0; i + 1 < events.size(); i++) {
            int l = getIndex(events[i].x1);
            int r = getIndex(events[i].x2) - 1;
            st.update(1, 0, st.n - 1, l, r, events[i].type);

            double height = events[i + 1].y - events[i].y;
            double sliceArea = st.totalCoveredLength() * height;

            if (currentArea + sliceArea >= halfArea) {
                double remaining = halfArea - currentArea;
                return events[i].y + remaining / st.totalCoveredLength();
            }

            currentArea += sliceArea;
        }

        return 0.0;
    }
};
