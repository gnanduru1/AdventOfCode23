#include <iostream>
#include <map>
#include <string>
#include <set>
#include <sstream>


using namespace std;

int main(){
    string line;
    set<long> nums;

    // Get seeds
    getline(cin, line);
    line = line.substr(line.find(":")+2);

    istringstream initial_ss(line);

    // Part 1
    /*
    string token;
    while (initial_ss >> token){
        nums.insert(stol(token));
    }
    */

    // Part 2
    string token;
    while (initial_ss >> token){
        long start = stol(token);
        initial_ss >> token;
        long end = start + stol(token);
        cout << "Inserting " << start << ", " << end << "\n";
        for (long n=start; n<end; n++)
            nums.insert(n);
    }

    // Skip blankline
    getline(cin, line);

    int step = 0;
    while (getline(cin, line))
    {      
        cout << "Step: " << step++; "\n";
        // Skip header
        getline(cin, line);

        
        // Get the next set of mappings
        set<tuple<long, long, long>> mappings;
        while (isdigit(line[0])){
            istringstream ss(line);
            ss >> token;
            long dest = stol(token);
            ss >> token;
            long start = stol(token);
            ss >> token;
            long range = stol(token);

            long offset = dest-start;
            long end = start+range;
            mappings.insert(make_tuple(start, end, offset));

            if (!getline(cin, line)) break;
        }

        // Map the current set of numbers
        set<long> new_nums;
        for (long n: nums){
            long to_insert = n;
            for (auto tup: mappings){
                long start, end, offset;
                tie(start, end, offset) = tup;

                if (n >= start && n < end) {
                    to_insert = n + offset;
                    break;
                }
            }
            new_nums.insert(to_insert);
        }
        nums = new_nums;
    }
    
    
    // Part 1
    cout << *nums.begin() << "\n";

}