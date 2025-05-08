#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit; // Sort by descending profit
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter job details (id deadline profit):\n";
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // Sort jobs by decreasing profit
    sort(jobs.begin(), jobs.end(), compare);

    // Find maximum deadline to size the time slots
    int maxDeadline = 0;
    for (const auto& job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    vector<int> slot(maxDeadline + 1, -1); // slot[i] = job id at time i
    int totalProfit = 0;
    int countJobs = 0;

    for (const auto& job : jobs) {
        // Try to place job in the latest available slot before its deadline
        for (int t = job.deadline; t > 0; --t) {
            if (slot[t] == -1) {
                slot[t] = job.id;
                totalProfit += job.profit;
                countJobs++;
                break;
            }
        }
    }

    // Output results
    cout << "\nScheduled Jobs (by Job ID): ";
    for (int i = 1; i <= maxDeadline; ++i) {
        if (slot[i] != -1)
            cout << slot[i] << " ";
    }
    cout << "\nTotal Jobs Done: " << countJobs;
    cout << "\nTotal Profit: " << totalProfit << endl;

    return 0;
}
