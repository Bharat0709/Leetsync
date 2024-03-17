#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater; // Stores next greater element for each element in nums2
        stack<int> s;

        // Iterate through nums2 to find next greater element for each element
        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                nextGreater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        // Elements left in stack have no next greater element
        while (!s.empty()) {
            nextGreater[s.top()] = -1;
            s.pop();
        }

        // Create result vector using nextGreater map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
    }
};
