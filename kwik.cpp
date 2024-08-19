#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
    // takes args
    string flstr = argv[1];
    string key = argv[2];
    int cn1 = atoi(argv[3]);
    int cn2 = atoi(argv[4]);
    string result;
    int t = 0;

// uses map for a clever way to look up chars position whenever it needs.
    unordered_map<char, int> keymap;
    char split_char = key[cn2];
    // used an unassigned int type, so it can store whatever sticks on its ass [https://en.m.wikipedia.org/wiki/C_data_types#stddef.h]
    for (size_t i = 0; i < key.size(); ++i) {
        keymap[key[i]] = i;
    }
    
    for (size_t i = 0; i < flstr.size(); ++i) {
        char c = flstr[i];
        if (c == split_char) {
            result += static_cast<char>(t - cn1);
            t = 0;
        } else {
            t = t * cn2 + keymap[c];
        }
    }
    
    if (t > 0) {
    	// converting 
        result += static_cast<char>(t - cn1);
    }
    
    cout << result << endl;
    return 0;
}
