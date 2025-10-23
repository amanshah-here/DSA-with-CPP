#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// jobSequencing: given parallel vectors `deadline` and `profit` (same length),
// pick jobs greedily to maximize total profit and return {jobsDone, totalProfit}.

vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
    // Pair each job as (deadline, profit) to keep values together while sorting
    vector<pair<int, int>> jobs(profit.size(), make_pair(0, 0));

    for (int i = 0; i < jobs.size(); i++) {
        jobs[i] = make_pair(deadline[i], profit[i]);
    }

    // Sort jobs by profit in descending order (greedy: pick largest profit first)
    sort(jobs.begin(), jobs.end(), [](auto& p1, auto& p2) {
        return p1.second > p2.second;
    });

    // Initialize with the highest-profit job
    // `safeDeadline` tracks the next minimum deadline required to schedule another job
    int safeDeadline = jobs[0].first + 1;
    int totalProfit = jobs[0].second; // accumulated profit
    int jobDone = 1;                   // count of scheduled jobs

    // Try to schedule remaining jobs in order of decreasing profit.
    // If a job's deadline is >= safeDeadline, we can schedule it (earliest available slot).
    for (int i = 1; i < jobs.size(); i++) {
        if (jobs[i].first >= safeDeadline) {
            totalProfit += jobs[i].second;
            jobDone++;
            safeDeadline++; // occupy the next slot
        }
    }
    return { jobDone, totalProfit };
}

int main() {
    // sample input: parallel vectors of deadlines and profits
    vector<int> deadline = { 4, 1, 1, 1 };
    vector<int> profit = { 20, 10, 40, 30 };

    // run the job sequencing helper and print the result
    vector<int> ans = jobSequencing(deadline, profit);

    cout << ans[0] << ", " << ans[1] << endl;

    return 0;
}