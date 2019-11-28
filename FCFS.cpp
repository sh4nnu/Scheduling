// First Come First Serve

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

vector<int> findTurnAroundTime(vector<int> v, vector<vector<int> > sev){
    vector<int> tat;
    for(int i =0; i < v.size(); i++){
        tat.push_back(v[i]-sev[i][2]);
    }
    return tat;
}

vector<int> findWaitingTime(vector<int> v, vector<vector<int> >inp ){
    vector<int> wt;
    for(int i =0; i < v.size(); i++){
        
        wt.push_back(v[i]-inp[i][2]);
    }
    return wt;
}

vector<int> findCompletionTime(vector<vector<int> > v, vector<int> sev){
    vector<int> ct;
    for(int i =0; i < v.size(); i++){
        ct.push_back(v[i][1]+sev[i]);
    }
    return ct;
}

bool sortCol(const vector<int>& a, const vector<int>& b)
    {
        return a[2] < b[2];
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
    for (int i = 0; i < c; i++){
        for(int j = 0; j < 3; j++)
            cout<<input[i][j]<<"   ";
        cout<<"\n";
    }
 

    

    sort(begin(input), end(input), sortCol);
        

       
    for(int i =0; i<c; i++){
        if(i == 0){
            service.push_back(input[i][2]);
           
        }
        
        else{
            service.push_back(service[i-1]+input[i-1][1]);
        }
       
    }
    comp_time = findCompletionTime(input, service);
    TurnAroundTime = findTurnAroundTime(comp_time, input);
    WaitingTime = findWaitingTime(service, input);



    cout<< "Process   |   Service time    | TAT      |   CT   |   WT   |\n";
    for (int i =0; i<input.size(); i++){
        cout<< input[i][0]<< "      |     "<< service[i]<< "    |    "<<TurnAroundTime[i]<< "    |     "<<comp_time[i]<< "    |     "<<  WaitingTime[i]<< "   |    \n";


    }

return 0;
}

