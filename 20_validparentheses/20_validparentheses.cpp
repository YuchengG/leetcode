//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//  Note: ([]) is valid, while ([)]) is not.

// Author: Songpeng Zu
// Time: July 2, 2016

#include<stack>
#include<string>
using namespace std;

// Solver 1
// Accepted

class Solution {
public:
    bool isodd(int num){
        return (num%2 == 0) ? false : true;
    }
    bool ismatch(char s, char i){
        return (s=='(' && i ==')') || (s=='[' && i==']') || (s=='{' && i=='}');
    }
    bool isValid(string s) {
        if(s.size() == 0) {return true;}
        if(isodd(s.size())) {return false;}
        if(s[0]==')' || s[0]==']' || s[0]=='}') {return false;}
        if(s[s.size()-1] == '(' || s[s.size()-1] =='[' || s[s.size()-1] == '{'){return false;}
        stack<char> record;
        record.push(s[0]);
        int i = 1;
        while(!record.empty() || i<s.size()){
            if(s[i]=='(' || s[i] == '[' || s[i]=='{'){
                record.push(s[i++]);
                continue;
            }
            if(!ismatch(record.top(),s[i])) {return false;}
            else{
                if(i==s.size()-1) {return true;}
                record.pop();
                i++;
                //record.push(s[(++i)++]);
                continue;
            }
        }
        return true;
    }
};
