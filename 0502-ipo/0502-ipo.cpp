#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        vector<pair<int, int>> projects;
        for(int i = 0; i < profits.size(); i++) {
            projects.push_back({capital[i], profits[i]});
        }

        // Sort projects by the capital required to start
        sort(projects.begin(), projects.end());

        priority_queue<int> maxProfitQueue;
        int j = 0;

        for(int i = 0; i < k; i++) {
            // Push all projects that can be started with the current capital to the max heap
            while(j < projects.size() && projects[j].first <= w) {
                maxProfitQueue.push(projects[j].second);
                j++;
            }

            // If no project can be started, break early
            if(!maxProfitQueue.empty()) {
                w += maxProfitQueue.top();
                maxProfitQueue.pop();
            }

            // Add the most profitable project

        }

        return w;
    }
};
