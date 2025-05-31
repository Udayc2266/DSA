#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> job1 , pair<int, int> job2){
    return job1.second > job2.second;
}

class Job{
    public:
        int idx;
        int deadline;
        int profit;
        Job(int idx, int deadline,int profit){
            this->idx = idx;
            this->deadline=deadline;
            this->profit=profit;
        }
};

int maxProfit1(vector<pair<int, int>> job){
    int n = job.size();
    vector<Job> jobs;
    for(int i = 0 ; i< n ;i++){
        jobs.emplace_back(i , job[i].first ,job[i].second);
    }
    sort(jobs.begin(), jobs.end(),[](Job &a , Job &b){
        return a.profit > b.profit;
    });
    cout<<jobs[0].idx<<endl;
    int profit = jobs[0].profit;
    int currDeadline = 2;

    for(int i = 1 ; i<n ; i++){

        if(jobs[i].deadline >= currDeadline){
            cout<<jobs[i].idx<<endl;
            profit += jobs[i].profit;
            currDeadline++;
        }

    }
    cout<<profit;
    return profit;

}

int maxProfit(vector<pair<int, int>> job){
    int n = job.size();
    sort(job.begin(), job.end(),compare);
    int profit = job[0].second;
    int currDeadline = 2;

    for(int i = 1 ; i<n ; i++){

        if(job[i].first >= currDeadline){
            profit += job[i].second;
            currDeadline++;
        }

    }
    cout<<profit;
    return profit;
    
}

int main(){
    int n=4;

    vector<pair<int, int>> job(n,make_pair(0,0));
    job[0] = make_pair(4,20);
    job[1] = make_pair(1,10);
    job[2] = make_pair(1,40);
    job[3] = make_pair(1,30);
    maxProfit1(job);
    return 0;
}