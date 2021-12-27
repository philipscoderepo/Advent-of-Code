#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Point{
    int x;
    int y;
};
struct Line{
    Point lineStart;
    Point lineEnd;
};

int stringToInt(string str){
    int num = 0;
    for(int i=str.length()-1, t=1; i>-1; i--, t*=10){
        num += (str[i] - 48) * t;
    }
    return num;
}

Line parseLine(string input){
    string x1, y1, x2, y2;
    //get x1
    x1 = input.substr(0, input.find(","));
    input = input.substr(input.find(",") + 1);
    //get y1
    y1 = input.substr(0, input.find(" "));
    input = input.substr(input.find(" -> ") + 4);
    //get x2
    x2 = input.substr(0, input.find(","));
    input = input.substr(input.find(",") + 1);
    //get y2
    y2 = input;
    cout << x1 << "," << y1 << " -> ";
    cout << x2 << "," << y2 << endl;
    Point p1, p2;
    p1.x = stringToInt(x1);
    p1.y = stringToInt(y1);
    p2.x = stringToInt(x2);
    p2.y = stringToInt(y2);
    Line line;
    line.lineStart = p1;
    line.lineEnd = p2;
    return line;
}

int MAP_SIZE = 10;

int main(){
    ifstream input("day5_input(Example).txt");
    string line;
    vector<Line> lines;
    //Get the input
    while(getline(input, line)){
        lines.push_back(parseLine(line));
    }
    //VentMap will plot the lines
    int **ventMap = new int*[MAP_SIZE];
    for(int i=0; i<MAP_SIZE; i++){
        ventMap[i] = new int[MAP_SIZE];
    }
    for(int i=0; i<MAP_SIZE; i++){
        for(int j=0; j<MAP_SIZE; j++){
            ventMap[i][j] = 0;
        }
    }
    //ventMap[y][x]
    //Iterate over the lines to draw on the map
    for(Line l : lines){
        //first determine whether the line is
        //vertical (x1 = x2) or horizontal (y1 = y2)
        if(l.lineStart.x == l.lineEnd.x){
            int x = l.lineStart.x;
            if(l.lineStart.y < l.lineEnd.y){
                for(int y=l.lineStart.y; y<l.lineEnd.y+1; y++){
                    ventMap[y][x] += 1;
                }
            }else{
                for(int y=l.lineEnd.y; y<l.lineStart.y+1; y++){
                    ventMap[y][x] += 1;
                }
            }
        }else if(l.lineStart.y == l.lineEnd.y){
            int y = l.lineStart.y;
            if(l.lineStart.x < l.lineEnd.x){
                for(int x=l.lineStart.x; x<l.lineEnd.x+1; x++){
                    ventMap[y][x] += 1;
                }
            }else{
                for(int x=l.lineEnd.x; x<l.lineStart.x+1; x++){
                    ventMap[y][x] += 1;
                }
            }
        }
    }
    ofstream mapOutput("day5-1_map(Example).txt");

    //Find the number of times the lines crossed
    int numPointsIntersected = 0;
    for(int y=0; y<MAP_SIZE; y++){
        for(int x=0; x<MAP_SIZE; x++){
            if(ventMap[y][x] == 0){
                mapOutput << ".";
            }else{
                mapOutput << ventMap[y][x];
            }
            if(ventMap[y][x] >= 2){
                numPointsIntersected += 1;
            }
        }
        mapOutput << endl;
    }
    mapOutput.close();
    //3472 too low
    cout << "Points intersected: " << numPointsIntersected << endl;
    return 0;
}
