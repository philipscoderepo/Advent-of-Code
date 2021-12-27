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

    int timesIncreased = 0;
    for(int i=1; i<inputs.size(); i++){
        if(inputs[i] > inputs[i-1]){
            timesIncreased++;
        }
    }
    cout << timesIncreased;
    return 0;
}
