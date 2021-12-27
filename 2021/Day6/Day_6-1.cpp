#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> parseInput(string line){
    vector<int> data;
    for(char c : line){
        if(isdigit(c)){
            data.push_back(c - 48);
        }
    }
    return data;
}

int NUM_DAYS = 10;

int main(){
    ifstream input("day6_input.txt");
    string line;
    getline(input, line);
    vector<int> data = parseInput(line);
    for(int d : data){
        cout << d << " ";
    }
    cout << endl;
    for(int d=0; d<NUM_DAYS; d++){
        int numFish = data.size();
        for(int i=0; i<numFish; i++){
            if(data[i] == 0){
                data[i] = 6;
                data.push_back(8);
            }else{
                data[i]--;
            }
        }
        cout << "Num fish " << d + 1 << ": " << data.size() << "; ";
        //cout << "Fish State: ";
        sort(data.begin(), data.end());
        for(int f : data){
            cout << f << ", ";
        }
        cout << endl;
    }
    cout << "Number of lantern fish after " << NUM_DAYS << " days: " << data.size();
    return 0;
}
