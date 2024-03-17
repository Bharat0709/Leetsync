#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size();
        vector<int> result(size, -1); // Initialize result with -1

        // Map each element of nums2 to its next greater element
        unordered_map<int, int> nextGreater;
        for (int i = 0; i < nums2.size(); i++) {
            int next = -1;
            for (int j = i + 1; j < nums2.size(); j++) {
                if (nums2[j] > nums2[i]) {
                    next = nums2[j];
                    break;
                }
            }
            nextGreater[nums2[i]] = next;
        }

        // Fill result using the map
        for (int i = 0; i < nums1.size(); i++) {
            result[i] = nextGreater[nums1[i]];
        }
        return result;
    }
};
