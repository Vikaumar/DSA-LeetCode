#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;
        vector<long long> arr(nums.begin(), nums.end());
        vector<int> nxt(n), prv(n);
        for(int i = 0; i < n; i++){
            nxt[i] = i + 1;
            prv[i] = i - 1;
        }
        auto cmp = [&](const pair<long long,int>& a, const pair<long long,int>& b){
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        };
        set<pair<long long,int>, decltype(cmp)> st(cmp);
        int inv = 0;
        for(int i = 0; i + 1 < n; i++){
            st.insert({arr[i] + arr[i+1], i});
            if(arr[i] > arr[i+1]) inv++;
        }
        int ans = 0;
        while(inv > 0){
            auto it = st.begin();
            auto [s, i] = *it;
            st.erase(it);
            int j = nxt[i];
            if(j >= n || prv[j] != i) continue;
            if(arr[i] > arr[j]) inv--;
            int p = prv[i];
            int k = nxt[j];
            if(p >= 0){
                if(arr[p] > arr[i]) inv--;
                st.erase({arr[p] + arr[i], p});
            }
            if(k < n){
                if(arr[j] > arr[k]) inv--;
                st.erase({arr[j] + arr[k], j});
            }
            arr[i] = s;
            if(p >= 0){
                st.insert({arr[p] + arr[i], p});
                if(arr[p] > arr[i]) inv++;
            }
            if(k < n){
                nxt[i] = k;
                prv[k] = i;
                st.insert({arr[i] + arr[k], i});
                if(arr[i] > arr[k]) inv++;
            } else {
                nxt[i] = n;
            }
            ans++;
        }
        return ans;
    }
};
