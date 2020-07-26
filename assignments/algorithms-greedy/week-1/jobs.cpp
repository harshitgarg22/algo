// Answer is 69119377652 for w - l
// Answer is 67311454237 for w / l

#include <bits/stdc++.h>

using namespace std;

bool metric(pair<int, int> a, pair<int, int> b){
    // type cast everything to double because we need fractions
    
    pair<double, double> one, two;
    one.first = (double) a.first;
    one.second= (double) a.second;
    two.first = (double) b.first;
    two.second = (double) b.second;
    
    if(one.first / one.second > two.first / two.second){
        return true;
    }   else if (one.first / one.second == two.first / two.second){
        return one.first > two.first;
    }   else{
        return false;
    }
}

int main(){
    ifstream jobs;
    jobs.open("./jobs.txt");
    
    string input;
    long n = 0;
    vector<pair<int, int> > data; // first is weight, second is length
    
    if(jobs.is_open()){
        getline(jobs, input, '\n');
        n = stol(input);
        while(getline(jobs, input, '\n')){
            char *token = strtok(const_cast<char*>(input.c_str()), " ");
            int val[2];
            for(int i = 0; token != nullptr; ++i){
                val[i] = stoi(token);
                token = strtok(nullptr, " ");
            }
            data.push_back(make_pair((val[0]), (val[1])));
        }
        jobs.close();
    }
    
    sort(data.begin(), data.end(), metric);
    
    long long weighted_sum = 0;
    long long time_elapsed = 0;
    for(pair<int, int> ele : data){
        time_elapsed += ele.second;
        weighted_sum += ele.first * time_elapsed;
    }
    
    cout<<weighted_sum;
}
