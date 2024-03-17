class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if(s[i] == '('){
                count++;
                if(count > maxCount){
                    maxCount = count;
                }
            } else if(s[i] == ')'){
                count--;
            }
        }
        return maxCount;
    }
};