#include <iostream>
#include <ctype.h>
#include <string>
#include <stdexcept>


using namespace std;

int get_first_digit(string line){
    for (int i=0; i<line.length(); i++){
        if (isdigit(line[i])){
            return int(line[i]-'0');
        }
    }
    throw std::invalid_argument( "digit not found in string" );
}

int get_last_digit(string line){
    for (int i=line.length()-1; i>=0; i--){
        if (isdigit(line[i])){
            return int(line[i]-'0');
        }
    }
    throw std::invalid_argument( "digit not found in string" );
}

int main() {
    int sum = 0;
    string line;
    while (getline(cin, line))
    {
        sum += 10*get_first_digit(line) + get_last_digit(line);
    }
    cout << sum;
}

