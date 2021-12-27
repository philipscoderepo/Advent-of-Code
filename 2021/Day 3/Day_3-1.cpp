#include <iostream>
#include <fstream>

using namespace std;

int INPUT_LEN = 12;
int main(){
    ifstream input("day3_input.txt");
    string line;
    int gamma_rate[INPUT_LEN] = {},
     epsilon_rate[INPUT_LEN] = {},
     ones[INPUT_LEN] = {},
     zeros[INPUT_LEN] = {};
    //Find the most common digit in each line
    while(getline(input, line)){
        for(int i=0; i<line.length(); i++){
            if(line[i] == '0'){
                zeros[i] += 1;
            }else{
                ones[i] += 1;
            }
        }
    }
    //Determine gamma rate and epsilon rate in binary
    for(int i=0; i<INPUT_LEN; i++){
        gamma_rate[i] = (ones[i] > zeros[i]) ? 1 : 0;
        epsilon_rate[i] = (ones[i] < zeros[i]) ? 1 : 0;
    }

    cout << "gamma rate: ";
    for(int i=0; i<INPUT_LEN; i++){
         cout << gamma_rate[i];
    }
    cout << endl;
    cout << "epsilon rate: ";
    for(int i=0; i<INPUT_LEN; i++){
         cout << epsilon_rate[i];
    }
    cout << endl;

    //Convert from binary to decimal
    int gamma = 0, epsilon = 0;
    for(int i=0; i<INPUT_LEN; i++){
        gamma = 2 * gamma + gamma_rate[i];
        epsilon = 2 * epsilon + epsilon_rate[i];
    }

    cout << gamma << " * " << epsilon << " = " << gamma * epsilon;
}
