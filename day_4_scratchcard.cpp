#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>

using namespace std;

int main() {
    
    int sum = 0;
    int card_count = 0;

    string input, line;
    
    int card_num = 1;
    map<int, int> copies;
    while (getline(cin, line))
    {   
        line = line.substr(line.find(':')+2);
        string winning_str, cards;
        winning_str = line.substr(0,line.find("|")-1);
        cards = line.substr(line.find("|")+2);

        set<string> winning;
        stringstream ss_1(winning_str);
        string token;
        while (ss_1 >> token){
            winning.insert(token);
        }

        stringstream ss_2(cards);
        int count = 0;
        while (ss_2 >> token){
            if (winning.find(token) != winning.end()) { 

                count ++;
            }
        }
        if (count > 0) 
            sum += 1 << (count-1);
        
        if (copies.find(card_num) == copies.end())
            copies[card_num] = 1;

        // Part 2
        for (int i=1; i<=count; i++){
            if (copies.find(card_num+i) == copies.end()){
                copies[card_num+i] = 1;
            }
            copies[card_num+i] += copies[card_num];;
        }
        card_count += copies[card_num];
        card_num += 1;
    } 
    cout << sum << "\n";
    
    cout << card_count << "\n";
}