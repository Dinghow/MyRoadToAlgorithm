#include<map>

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.length()!= s2.length()){
            return false;
        }
        map<char, int> str1, str2;
        for(int i = 0; i < s1.length(); i++){
            str1[s1[i]] = i;
        }
        for(int i = 0; i < s2.length(); i++){
            int temp = str1.count(s2[i]);
            if(!temp){
                return false;
            }
        }
        return true;
    }
};