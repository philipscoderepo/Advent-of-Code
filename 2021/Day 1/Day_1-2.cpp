#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream input;
    input.open("day1_input.txt");
    string line;
    vector<int> inputs;

    while(getline(input, line)){
        int i = stoi(line, size_t());
        inputs.push_back(i);
    }

    vector<int> sums;
    for(int i=2; i<inputs.size(); i++){
        int sum = inputs[i] + inputs[i-1] + inputs[i-2];
        sums.push_back(sum);
    }

    int timesIncreased = 0;
    for(int i=1; i<sums.size(); i++){
        if(sums[i] > sums[i-1]){
            timesIncreased++;
        }
    }
    cout << timesIncreased;
    return 0;
}
