#include <iostream>
#include <string>
#include <stdexcept>
#include <assert.h> 
#include <sstream>

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
            while (isdigit(lines[i][j])){
                num_str += lines[i][j];
                j++;
                if (valid) continue;

                for (int a=-1; a<=1; a++){
                    for (int b=-1; b<=1; b++){
                        if (a==0 && b==0) continue;
                        if (!in_bounds(a+i, b+j, width, height)) {
                            cout << "Invalid bounds: " << a << " " << b << "\n";
                            continue;                    
                        }

                        if (is_symbol(lines[a+i][b+j])) 
                            valid = true;
                        
                        if (false && lines[i][j] == '7'){
                            cout << a << " " << b << "\n";
                            cout << lines[a+i][b+j] << "valid?: " << is_symbol(lines[a+i][b+j]) << " " << valid << "\n";
                            
                        }
                    }
                }
            }

            if (valid) 
                sum += stoi(num_str);     
            else {
                cout << "Invalid num: " <<  num_str << "\n";    
            }   
        }
    }
    cout << sum;
}