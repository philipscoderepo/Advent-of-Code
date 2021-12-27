#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Player{
public:
    int x[5];
    int y[5];
    Player(){
        for(int i=0; i<5; i++){
            x[i] = 0;
            y[i] = 0;
        }
    }
};

vector<int> convertString(string line){
    vector<int> nums;
    for(int i=0; i<line.length(); i+=3){
        int num = 0;
        if(line[i] != ' '){
            num = (line[i] - 48) * 10;
            num += line[i+1] - 48;
        }else{
            num = line[i+1] - 48;
        }
        nums.push_back(num);
    }
    return nums;
}

vector<int> convertWinning(string str){
    vector<int> nums;
    bool valid = true;
    while(valid){
        string sNum = str.substr(0,str.find(','));
        int num;
        if(sNum.length() == 2){
            num = (sNum[0] - 48) * 10;
            num += sNum[1] - 48;
        }else{
            num = sNum[0] - 48;
        }
        nums.push_back(num);
        str = str.substr(str.find(',') + 1);

        if(str.find(',') == -1){
            valid = false;
            num = str[0] - 48;
            nums.push_back(num);
        }
    }

    return nums;
}

int main(){
    ifstream input("day4_input.txt");
    string winning_str;
    string line;
    vector<vector<vector<int>>> players;
    vector<vector<int>> player;
    //Load the numbers picked
    getline(input, winning_str);
    vector<int> winning_numbers = convertWinning(winning_str);
    for(int n : winning_numbers){
        cout << n << endl;
    }
    //Load the players
    getline(input, line);
    while(getline(input, line)){
        if(line == ""){
            players.push_back(player);
            continue;
        }else{
            player.push_back(convertString(line));
        }
    }

    //Initialize Player scores
    vector<Player> playerScores;
    for(int i=0; i<players.size(); i++){
        playerScores.push_back(Player());
    }

    bool winner = false;
    int winIndex = 0;
    while(!winner && winIndex < winning_numbers.size()){
        //i represents the current player
        for(int i=0; i<players.size() && !winner; i++){
            //x and y index their board
            for(int y=0; y<5 && !winner; y++){
                for(int x=0; x<5; x++){
                    if(players[i][y][x] == winning_numbers[winIndex]){
                        playerScores[i].x[x] += 1;
                        playerScores[i].y[y] += 1;
                        if(playerScores[i].x[x] == 5 || playerScores[i].y[y] == 5){
                            winner = true;
                            cout << "Player " << i + 1 << " is the winner!" << endl;
                            cout << "Last number picked: " << players[i][y][x] << endl;
                            cout << "Numbers picked: ";
                            for(int i2=0; i2<winIndex; i2++){
                                for(int y2=0; y2<5; y2++){
                                    for(int x2=0; x2<5; x2++){
                                        if(players[i][y2][x2] == winning_numbers[i2]){
                                            cout << players[i2][y2][x2] << " ";
                                        }
                                    }
                                }
                            }
                            cout << endl;
                            break;
                        }
                    }
                }

            }
        }
        winIndex++;
    }



    return 0;
}
