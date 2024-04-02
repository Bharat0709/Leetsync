#include <string>
#include <stack>

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string segment;
        path += '/';

        for (char c : path) {
            if (c == '/') {
                if (segment == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                } else if (segment != "." && !segment.empty()) {
                    st.push(segment);
                }
                segment.clear();
            } else {
                segment += c;
            }
        }

        // Construct the simplified path string
        string simplifiedPath;
        while (!st.empty()) {
            simplifiedPath = "/" + st.top() + simplifiedPath;
            st.pop();
        }

        // If the simplified path is empty, return "/"
        if (simplifiedPath.empty()) {
            return "/";
        } else {
            return simplifiedPath;
        }
    }
};
