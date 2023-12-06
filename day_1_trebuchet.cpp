#include <iostream>
#include <ctype.h>
#include <string>
#include <stdexcept>


using namespace std;

string digits[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int get_first_digit(string line){
    int min_ind = line.length();
    int num = 0;
    for (int i=0; i<size(digits); i++){
        string digit = digits[i];
        int ind = line.find(digit);
        if (ind != string::npos){
            if (ind < min_ind){
                min_ind = ind;
                num = i+1;
            }
        }
    }

    int to_return = -1;
    for (int i=0; i<line.length(); i++){
        if (isdigit(line[i])){
            if (i > min_ind) { 
                to_return = num;
            }
            else{
                
                to_return = int(line[i]-'0');
                
            }
            break;
        }
    }
    if (to_return == -1) 
        to_return = num;
    
    
    
    return to_return;
}

int get_last_digit(string line){
    int max_ind = -1;
    int num = 0;
    for (int i=0; i<size(digits); i++){
        string digit = digits[i];
        int ind = line.rfind(digit);
        if (ind != string::npos){
            if (ind > max_ind){
                max_ind = ind;
                num = i+1;
            }
        }
    }
    
    int to_return = -1;
    for (int i=line.length()-1; i>=0; i--){
        if (isdigit(line[i])){
            
            if (i < max_ind) { 
                to_return = num;
            }
            else {
                to_return = int(line[i]-'0');
            }
            break;
        }
    }
    if (to_return == -1) to_return = num;
    
    return to_return;
}

int main() {
    
    int sum = 0;
    int num;
    string line;
    
    while (getline(cin, line))
    {
        num = 10*get_first_digit(line) + get_last_digit(line);
        
        sum += num;
    }
    cout << sum;    
}

