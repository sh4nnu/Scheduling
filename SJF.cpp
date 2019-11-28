// SHORTEST JOB FIRST

/*
Input:
 -------------------------------------
|Process | Burst Time | Arrival Time |
--------------------------------------


Output:

- Order of processes in Gantt chart
- Service time, Turn Around Time, Waiting Time for each process.

*/


#include <bits/stdc++.h>

using namespace std;

vector<int> findTurnAroundTime(vector<int> v, vector<vector<int> > inp){
    vector<int> tat;
    tat.resize(inp.size()+1);
    for(int i =0; i < inp.size(); i++){
        tat[inp[i][0]] = v[inp[i][0]]-inp[i][2];
    }
    return tat;
}

vector<int> findWaitingTime(vector<int> v, vector<vector<int> >inp ){
    vector<int> wt;
    wt.resize(inp.size()+1);
    for(int i =0; i < inp.size(); i++){
        
        wt[inp[i][0]]=v[inp[i][0]]-inp[i][2];
    }
    return wt;
}

vector<int> findCompletionTime(vector<vector<int> > v, vector<int> sev){
    vector<int> ct;
    ct.resize(v.size()+1);
    for(int i =0; i < v.size(); i++){
        ct[v[i][0]] = v[i][1]+sev[v[i][0]];
    }
    return ct;
}

bool sortCol(const vector<int>& a, const vector<int>& b)
    {
        return a[2] < b[2];
    }

bool sortCol2(const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    }
bool sortCol0(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }
int main(){
    vector<vector<int> > input;
    int c=0;
    int tmp;
    vector<int> service, comp_time, TurnAroundTime, WaitingTime;
    cin>>c;
    for (int i = 0; i < c; i++){
        vector<int> row;
        for(int j = 0; j < 3; j++){
            cin>>tmp;
            row.push_back(tmp);
        }
        input.push_back(row);
    }


    vector<int> status;
    status.resize(input.size());

    // vector<int> service;
    service.resize(input.size()+1);

    int currentTime = 0;

    sort(begin(input), end(input), sortCol);
        for (int i = 0; i < c; i++){
        for(int j = 0; j < 3; j++)
            cout<<input[i][j]<<"   ";
        cout<<"\n";
    }
    for(int i=0; i<c; i++)
    {
        if(i == 0)
        {
            service[input[i][0]] = input[i][2];
            currentTime = service[input[i][0]]+ input[i][1];
            status[i] = 1;
        }
        else
        {
            vector<vector<int> > temp;
            for (int i = 0; i< c; i++){
                if(input[i][1] <= currentTime && status[i] == 0){
                    temp.push_back(input[i]);
                }
            }
            sort(temp.begin(), temp.end(), sortCol2); 

            
           
            
            service[temp[0][0]] = currentTime;
            currentTime += temp[0][1];
            for(int j = 0; j < c; j++){
                if(input[j][0] == temp[0][0]){
                    status[j] = 1;
                }

            }
            
            temp.clear();
        }
        
    }

        comp_time = findCompletionTime(input, service);
    TurnAroundTime = findTurnAroundTime(comp_time, input);
    WaitingTime = findWaitingTime(service, input);

    


    sort(input.begin(), input.end(), sortCol0 ); 
    cout<< "Process   |   Service time    | TAT      |   CT   |   WT   |\n";
     for (int i =0; i<c; i++){
         cout<< input[i][0]<< "      |     "<< service[input[i][0]]<< "    |    "<<TurnAroundTime[input[i][0]]<< "    |     "<<comp_time[input[i][0]]<< "    |     "<<  WaitingTime[input[i][0]]<< "   |    \n";
     }


}
