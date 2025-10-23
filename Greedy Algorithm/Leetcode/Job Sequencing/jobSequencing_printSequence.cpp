#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class job {
public:
    int idx, deadline, profit;

    job(int idx, int deadline, int profit) {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
    vector<job> jobs;

    for (int i = 0; i < deadline.size(); i++) {
        jobs.emplace_back(i, deadline[i], profit[i]);
    }

    sort(jobs.begin(), jobs.end(), [](auto& a, auto& b) {
        return a.profit > b.profit;
        }); // sorted in descending order based on profit.

    cout << "Selecting Job " << jobs[0].idx << endl;
    int maxProfit = jobs[0].profit;
    int safeDeadline = 2;
    int jobDone = 1;

    for (int i = 1; i < jobs.size(); i++) {
        if (jobs[i].deadline >= safeDeadline) {
            cout << "Selecting job " << jobs[i].idx << endl;
            maxProfit += jobs[i].profit;
            safeDeadline++;
            jobDone++;
        }
    }
    return { jobDone, maxProfit };
}

int main() {
    // sample input: parallel vectors of deadlines and profits
    vector<int> deadline = { 4, 1, 1, 1 };
    vector<int> profit = { 20, 10, 40, 30 };

    // run the job sequencing helper and print the result
    vector<int> ans = jobSequencing(deadline, profit);

    cout << "Total Job Done: " << ans[0] << "\nMaximum Profit: " << ans[1] << endl;

    return 0;
}