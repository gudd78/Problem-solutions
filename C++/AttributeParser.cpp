#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <iterator>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    typedef unordered_map<string, string> TagValues;
    TagValues tagValues;
    
    string key;
    for(int n = 0; n < N; ++n) {
        string tag;
        getline(cin, tag);
        
        if(tag[1] == '/') {
            int tagLen = tag.length() - 3;
            key.erase(key.length() - tagLen, tagLen);
            if(key.length() > 0)
                key.pop_back();
        } else {
            if(key.length() != 0)
                key.push_back('.');

            int i = 1;
            while(tag[i] != ' ' && tag[i] != '>')
                key.push_back(tag[i++]);
            
            while(tag[i] != '>') {
                ++i;
                string valKey;
                valKey.push_back('~');
                while(tag[i] != ' ')
                    valKey.push_back(tag[i++]);
                
                i += 4;
                string val;
                while(tag[i] != '"')
                    val.push_back(tag[i++]);
                
                tagValues[key + valKey] = val;
                ++i;
            }
        }
    }
    
    for(int q = 0; q < Q; ++q) {
        string query;
        cin >> query;
        
        TagValues::iterator iter = tagValues.find(query);
        if(iter == tagValues.end())
            cout << "Not Found!";
        else
            cout << iter->second;
        cout << endl;
    }
   return 0;
}
