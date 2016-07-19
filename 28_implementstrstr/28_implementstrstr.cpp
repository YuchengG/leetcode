// Implement strStr().

//   Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Author: Songpeng Zu
// Time: July 10, 2016

#include<string>;
#include<vector>;

using namespace std;

// Solver 1
// Accepted
// Bruce force search.

class Solution {
public:
  int strStr(string haystack, string needle) {
    if(needle.size() == 0 && haystack.size() == 0)  {return 0;}
    if(needle.size() == 0) {return 0;}
    if(haystack.size() < needle.size()) {return -1;}
    int temp;
    int match;
    for(int i=0;i<(haystack.size()-needle.size()+1);++i){
      temp = i;
      match = 0;
      for(int j=0;j<needle.size();++j){
        if(haystack[temp] != needle[j]){break;}
        else{temp++;match++;}
      }
      if (match == needle.size()) {return i;}
    }
    return -1;
  }
};

// Solver 2
// Accepted
// From Discussion
// KMP algorithm

class Solution {
public:
  int strStr(string haystack, string needle) {
    int m = haystack.length(), n = needle.length();
    if (!n) return 0;
    vector<int> lps = kmpProcess(needle);
    for (int i = 0, j = 0; i < m; ) {
      if (haystack[i] == needle[j]) {
        i++;
        j++;
      }
      if (j == n) return i - j;
      if (i < m && haystack[i] != needle[j]) {
        if (j) j = lps[j - 1];
        else i++;
      }
    }
    return -1;
  }
private:
  vector<int> kmpProcess(string& needle) {
    int n = needle.length();
    vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n; ) {
      if (needle[i] == needle[len])
        lps[i++] = ++len;
      else if (len) len = lps[len - 1];
      else lps[i++] = 0;
    }
    return lps;
  }
};
