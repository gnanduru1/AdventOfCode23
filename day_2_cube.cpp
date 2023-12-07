#include <iostream>
#include <string>
#include <stdexcept>
#include <assert.h> 
#include <sstream>

using namespace std;

int main() {
    
    int sum = 0;
    int product_sum = 0;
    string line;
    

    while (getline(cin, line))
    {   
        int colors[] = {0,0,0};
        int ind = line.find(":");
        assert (ind > 5);
        int game_id = stoi(line.substr(5, ind));
        line = line.substr(ind+1);
        
        stringstream ss(line);
        string num_str;
        string rgb;

        while (ss >> num_str){
            int num = stoi(num_str);
            ss >> rgb;
            
            if (rgb[0] == 'r'){
                colors[0] = colors[0] > num ? colors[0] : num;
            }
            else if (rgb[0] == 'g'){
                colors[1] = colors[1] > num ? colors[1] : num;
            }
            else if (rgb[0] == 'b'){
                colors[2] = colors[2] > num ? colors[2] : num;
            }
            else{
                throw invalid_argument("couldnt recognize string " + rgb);
            }
        }

        if (!(colors[0]>12 || colors[1]>13 || colors[2]>14)){
            sum += game_id;
        }

        product_sum += colors[0]*colors[1]*colors[2];
    } 

    // Part 1
    cout << sum  << "\n";

    // Part 2
    cout << product_sum;
}