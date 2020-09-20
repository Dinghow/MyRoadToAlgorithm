#include<map>

class Solution {
public:
    bool isUnique(string astr) {
        map<char, int> temp_str;
        for(int i = 0; i < astr.length(); i++){
            temp_str[astr[i]] = i;
        }
        if(astr.length()!= temp_str.size()){
            return false;
        }
        return true;
    }
};