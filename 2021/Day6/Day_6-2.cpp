#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int NUM_DAYS = 256;

vector<int> parseInput(string line){
    vector<int> data;
    for(char c : line){
        if(isdigit(c)){
            data.push_back(c - 48);
        }
    }
    return data;
}

vector<unsigned long long> initDays(vector<int> internalStates){
    //                  internal state 0  1  2  3  4  5  6  7  8
    vector<unsigned long long> days = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i : internalStates){
        days[i]++;
    }
    for(int d : days){
        cout << d << " ";
    }
    return days;
}

unsigned long long calcTotal(vector<unsigned long long> days){
    for(int d=0; d<NUM_DAYS; d++){
        if(days[0] > 0){
            unsigned long long tempZero = days[0];
            days[0] = days[1];
            days[1] = days[2];
            days[2] = days[3];
            days[3] = days[4];
            days[4] = days[5];
            days[5] = days[6];
            days[6] = tempZero + days[7];
            days[7] = days[8];
            days[8] = tempZero;
        }else{
            days[0] = days[1];
            days[1] = days[2];
            days[2] = days[3];
            days[3] = days[4];
            days[4] = days[5];
            days[5] = days[6];
            days[6] = days[7];
            days[7] = days[8];
            days[8] = 0;
        }
        //cout << "Day " << d+1 << ": ";
        //for(int da : days){
        //   cout << da << " ";
        //}
        //cout << endl;
    }
    unsigned long long total = 0;
    for(unsigned long long d : days){total += d;}
    return total;
}

int main(){
    ifstream input("day6_input.txt");
    string line;
    getline(input, line);
    vector<int> data = parseInput(line);
    vector<unsigned long long> days = initDays(data);
    unsigned long long total = calcTotal(days);
    cout << "Total: " << total;
    return 0;
}
