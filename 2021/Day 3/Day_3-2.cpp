#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int INPUT_LEN = 12;

void filter(vector<string> &in, int index, char con)
{
    vector<string> validLines;
    cout << "size: " << in.size() << endl;
    for(string line : in){
        //cout << line << endl;

        if(line[index] == con){
            validLines.push_back(line);
        }
    }
    in = validLines;
}

int main(){
    ifstream input("day3_input.txt");
    string line;
    vector<string> lines;

    int o_rating[INPUT_LEN] = {},
     co2_rating[INPUT_LEN] = {};

    //Read in the lines
    while(getline(input, line)){
        lines.push_back(line);
    }

    //Find the o_rating
    vector<string> o_lines = lines;
    for(int i=0; i<INPUT_LEN; i++){
        //Find the most common digit at pos i
        int ones = 0, zeros = 0;
        char con;
        for(string l : o_lines){
            if(l[i] == '0'){
                zeros++;
            }else{
                ones++;
            }
        }

        if(ones == zeros){
            con = '1';
        }else{
            con = (ones > zeros) ? '1' : '0';
        }

        filter(o_lines, i, con);
        if(o_lines.size() == 1){
            cout << "found! " << o_lines[0] << endl;
            for(int j=0; j<INPUT_LEN; j++){
                o_rating[j] = o_lines[0][j] - 48;
            }
            break;
        }
    }
    //Find the co2_rating
    vector<string> co2_lines = lines;
    for(int i=0; i<INPUT_LEN; i++){
        //Find the most common digit at pos i
        int ones = 0, zeros = 0;
        char con;
        for(string l : co2_lines){
            if(l[i] == '0'){
                zeros++;
            }else{
                ones++;
            }
        }

        if(ones == zeros){
            con = '0';
        }else{
            con = (ones < zeros) ? '1' : '0';
        }

        filter(co2_lines, i, con);
        if(co2_lines.size() == 1){
            cout << "found! " << co2_lines[0] << endl;
            for(int j=0; j<INPUT_LEN; j++){
                co2_rating[j] = co2_lines[0][j] - 48;
            }
            break;
        }
    }

    //Convert from binary to decimal
    int o_decimal = 0, co2_decimal = 0;
    for(int i=0; i<INPUT_LEN; i++){
        o_decimal = 2 * o_decimal + o_rating[i];
        co2_decimal = 2 * co2_decimal + co2_rating[i];
    }

    cout << o_decimal << " * " << co2_decimal << " = " << o_decimal * co2_decimal;
}
