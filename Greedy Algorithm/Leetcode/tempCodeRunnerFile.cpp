int safeDeadline = jobs[0].first + 1;
    int totalProfit = jobs[0].second;
    int jobDone = 1;

    for (int i = 1; i < jobs.size(); i++) {
        if (jobs[i].first >= safeDeadline) {
            totalProfit += jobs[i].second;
            jobDone++;
            safeDeadline++;
        }
    }