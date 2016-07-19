// Given a pattern and a string str, find if str follows the same pattern.

//   Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

//   Examples:

//   pattern = "abba", str = "dog cat cat dog" should return true.
//   pattern = "abba", str = "dog cat cat fish" should return false.
//   pattern = "aaaa", str = "dog cat cat dog" should return false.
//   pattern = "abba", str = "dog dog dog dog" should return false.

//   Notes:
//   You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

// Author: Songpeng Zu
// Time: July 2, 2016


#include<string>
#include<map>

using namespace std;

// Solver 1
// Accepted

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (str.size() == 0){return false;}
        map<char,string> namehash;
        map<string,bool> nameunique;
        string tmp;
        int pos = 0;
        for(int i=0;i<str.size();++i){
            if(str[i] != ' ') {
                tmp.push_back(str[i]);
            } else {
                if(namehash.find(pattern[pos]) != namehash.end()){
                    if(namehash[pattern[pos]].compare(tmp) != 0){return false;}
                } else{
                    if(nameunique.find(tmp) != nameunique.end()){return false;}
                    else{
                        namehash.insert(pair<char, string>(pattern[pos],tmp));
                        nameunique.insert(pair<string,bool>(tmp,true));
                    }
                }
                pos++;
                tmp.clear();
            }
            if(i == str.size()-1){
                if(pos != pattern.size() -1) {return false;}
                if(namehash.find(pattern[pattern.size()-1]) != namehash.end()){
                    if(namehash[pattern[pattern.size()-1]].compare(tmp) != 0){return false;}
                    else {return true;}
                } else {
                    if(nameunique.find(tmp) != nameunique.end()){return false;}
                    else {return true;}
                }
            }
        }
        return true;
    }
};
