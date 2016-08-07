// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

//   P   A   H   N
//   A P L S I I G
//   Y   I   R

//   And then read line by line: "PAHNAPLSIIGYIR"

//   Write the code that will take a string and make this conversion given a number of rows:

//             string convert(string text, int nRows);

// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

// Author: Songpeng Zu
// Time: August 7, 2016

#include<vector>
#include<string>

using namespace std;

// Solver 1
// Accepted

class Solution {
public:
    int lastEle(int length, int numRows){
        // length > numRows;
        // numRows > 2;
        int i = 1;
        while(true){
            int accum = i*numRows + (i-1)*(numRows-2);
            int left = length - accum;
            if (left >= numRows) {i++;}
            else {
                return (numRows-left-1);
            }
        }
    }
    void convert(string& s, int curRow, vector<bool>& isIn, vector<int>& lastIn, int numRows, string& result){
        if (curRow == 0){
            int i = 0;
            while(i < s.size()){
                result.push_back(s[i]);
                isIn[i] = true;
                lastIn.push_back(i);
                i += numRows -1 + numRows-2 + 1;
            }
            return;
        } else {
            vector<int> temp;
            for(int i=0;i<lastIn.size();++i){
                if (lastIn[i] > 0 && (!isIn[lastIn[i]-1])) {
                    result.push_back(s[lastIn[i]-1]);
                    isIn[lastIn[i]-1] = true;
                    temp.push_back(lastIn[i]-1);
                }
                if ((lastIn[i] < s.size()-1) && (!isIn[lastIn[i]+1])){
                    result.push_back(s[lastIn[i]+1]);
                    isIn[lastIn[i]+1] = true;
                    temp.push_back(lastIn[i]+1);
                }
            }
            if((curRow == lastEle(s.size(), numRows)) && (!isIn[s.size()-1])) {
                result.push_back(s[s.size()-1]);
                isIn[s.size()-1] = true;
                temp.push_back(s.size()-1);
            }
            lastIn.clear();
            lastIn = temp;
            return;
        }
    }
    string convert(string s, int numRows) {
        //if (s.size() == 0 || numRows <= 0) {return result;} // non sense
        if (s.size() <= numRows) {return s;}
        if (numRows == 1) {return s;}
        string result;
        if (numRows == 2) {
            for(int i=0;i<s.size();i+=2){
                result.push_back(s[i]);
            }
            for(int i=1;i<s.size();i+=2){
                result.push_back(s[i]);
            }
            return result;
        }
        vector<bool> isIn(s.size(), false);
        vector<int> lastIn;
        int curRow = 0;
        while(curRow < numRows){
            convert(s,curRow,isIn,lastIn,numRows,result);
            curRow++;
        }
        return result;
    }
};

// Solver 2
// From Discussion
// Java
 public class Solution {
public String convert(String s, int numRows) {
  if(numRows<=1)return s;
  StringBuilder[] sb=new StringBuilder[numRows];
  for(int i=0;i<sb.length;i++){
    sb[i]=new StringBuilder("");   //init every sb element **important step!!!!
  }
  int incre=1;
  int index=0;
  for(int i=0;i<s.length();i++){
    sb[index].append(s.charAt(i));
    if(index==0){incre=1;}
    if(index==numRows-1){incre=-1;}
    index+=incre;
  }
  String re="";
  for(int i=0;i<sb.length;i++){
    re+=sb[i];
  }
  return re.toString();
}
