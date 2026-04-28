// Lab 9.2: WAP to implement Job Sequencing with Deadlines (With Trace Output)

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Job
{
    int id;
    int deadline;
    double profit;
};

struct ScheduleStep
{
    int jobId;
    int deadline;
    double profit;
    int assignedSlot;
    double totalProfit;
};

// Border printing
void border(bool wide)
{
    cout << (wide ? "+------+----------+------------+--------------+---------------+"
                  : "+------+----------+------------+")
         << endl;
}

// Print sorted job row
void printRow(const Job &j)
{
    cout << left
         << "| " << setw(4) << j.id
         << " | " << setw(8) << j.deadline
         << " | " << setw(10) << j.profit << " |" << endl;
    border(false);
}

// Print scheduling step row
void printRow(const ScheduleStep &s)
{
    cout << left << fixed << setprecision(2)
         << "| " << setw(4) << s.jobId
         << " | " << setw(8) << s.deadline
         << " | " << setw(10) << s.profit
         << " | " << setw(12) << (s.assignedSlot >= 0 ? to_string(s.assignedSlot + 1) : "Not Assigned")
         << " | " << setw(13) << s.totalProfit
         << " |" << endl;
    border(true);
}

// Print sorted jobs
void printSortedJobs(const vector<Job> &jobs)
{
    cout << endl
         << "--- Job Sequencing with Deadlines ---" << endl
         << endl
         << "Jobs Sorted by Profit (Descending):" << endl;
    border(false);
    cout << "| Job  | Deadline | Profit     |" << endl;
    border(false);

    for (const auto &job : jobs)
        printRow(job);
}

// Scheduling function
vector<ScheduleStep> scheduleJobs(const vector<Job> &jobs, double &maxProfit)
{
    int maxDeadline = 0;
    for (const auto &job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    vector<int> slots(maxDeadline, -1);
    vector<ScheduleStep> trace;
    maxProfit = 0;

    for (const auto &job : jobs)
    {
        int assignedSlot = -1;

        for (int j = min(maxDeadline, job.deadline) - 1; j >= 0; j--)
        {
            if (slots[j] == -1)
            {
                slots[j] = job.id;
                assignedSlot = j;
                maxProfit += job.profit;
                break;
            }
        }

        trace.push_back({job.id, job.deadline, job.profit, assignedSlot, maxProfit});
    }

    return trace;
}

// Print scheduling trace
void printScheduleTrace(const vector<ScheduleStep> &trace)
{
    cout << endl
         << "Scheduling Process (Trace):" << endl;
    border(true);
    cout << "| Job  | Deadline | Profit     | Assigned Slot | Total Profit |" << endl;
    border(true);

    for (const auto &step : trace)
        printRow(step);
}

int main()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter deadline and profit for each job:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Job " << i + 1 << " : ";
        cin >> jobs[i].deadline >> jobs[i].profit;

        if (jobs[i].deadline <= 0)
            return cout << "Deadline must be greater than 0." << endl, 0;

        jobs[i].id = i + 1;
    }

    // Sort by profit descending (Greedy choice)
    sort(jobs.begin(), jobs.end(),
         [](const Job &a, const Job &b)
         { return a.profit > b.profit; });

    printSortedJobs(jobs);

    double maxProfit;
    vector<ScheduleStep> trace = scheduleJobs(jobs, maxProfit);

    printScheduleTrace(trace);

    cout << endl
         << "Maximum Profit = " << fixed << setprecision(2) << maxProfit << endl;

    return 0;
}