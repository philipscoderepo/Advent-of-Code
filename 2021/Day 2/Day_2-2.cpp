#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream input;
    input.open("day2_input.txt");
    string line;
    int horizontal=0, depth=0, aim=0;

    while(getline(input, line)){
        string direction;
        int value;
        direction = line.substr(0, line.find(" "));
        value = stoi(line.substr(line.find(" ")), size_t());

        if(direction == "forward"){
            horizontal += value;
            depth += value * aim;
        }
        else if(direction == "down"){
            aim += value;
        }else{
            aim -= value;
        }
    }

    cout << horizontal << " * " << depth << " = " << horizontal * depth;
    return 0;
}
