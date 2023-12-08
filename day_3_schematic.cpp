#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <tuple>

using namespace std;

bool is_symbol(char c){
    return ispunct(c) && c != '.';
}

bool in_bounds(int x, int y, int width, int height){
    return x>=0 && x<width && y>=0 && y<height;
}

int main() {
    
    int sum = 0;
    int height = 0;
    int width = 0;
    int product_sum = 0;
    string input, line;
    

    while (getline(cin, line))
    {   
        width = line.length();
        height++;
        input += line + "\n";
    } 

    string lines[height];
    int gears[height][width] = {};
    stringstream ss(input);
    string token;
    for (int i=0; i<height; i++) {
        getline(ss, token, '\n');
        lines[i] = token;
    }

    for (int i=0; i<height; i++) {
        int j=0;
        while(j < width) {
            if (!isdigit(lines[i][j])){
                j++;
                continue;
            }

            bool valid = false;
            string num_str = "";
            set<tuple<int, int>> seen;
            while (isdigit(lines[i][j])){
                num_str += lines[i][j];

                for (int a=-1; a<=1; a++){
                    for (int b=-1; b<=1; b++){
                        if (a==0 && b==0) continue;
                        if (!in_bounds(a+i, b+j, width, height)) continue;                   

                        if (is_symbol(lines[a+i][b+j])) 
                            valid = true;
                        
                        // Part 2
                        if (lines[a+i][b+j] == '*'){
                            seen.insert(make_tuple(a+i, b+j));
                        }
                    }
                }

                j++;
            }

            int num = stoi(num_str);            
            for (auto tup : seen) {
                int x = get<0>(tup);
                int y = get<1>(tup);

                if (gears[x][y] < 0){
                    gears[x][y] *= -num;
                }
                else{
                    gears[x][y] = -num;
                }
            }

            if (valid) 
                sum += num;
        }
    }
    
    // Part 1
    cout << sum << '\n';

    // Part 2
    long gear_ratio = 0;
    for (int i=0; i<height; i++){
        for (int j=0; j<width; j++){
            if (gears[i][j] > 0){
                //cout << "i, j, gear: " << i << " " << j << " " << gears[i][j] << "\n";
                gear_ratio += gears[i][j];
            }
        }
    }

    cout << gear_ratio << '\n';

}