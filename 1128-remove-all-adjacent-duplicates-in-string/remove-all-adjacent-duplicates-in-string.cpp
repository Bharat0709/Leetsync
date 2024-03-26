class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        if(s.length() == 1){
            return s ;
        } else{
            st.push(s[0]);
        }

        for (int i = 1 ; i < s.length() ; i++){
           if( !st.empty() && st.top() - s[i] == 0 ){
            st.pop();
           } else{
            st.push(s[i]);
           }
        }

        string ans ;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};