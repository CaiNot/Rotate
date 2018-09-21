#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int len = nums.size();
        if (len < 2)
            return;
        k = k % len;
        int lastNum;
        while (k-- > 0) {
            lastNum = nums[len - 1];
            for (int i = len - 2; i >= 0; i--) {
                nums[i + 1] = nums[i];
            }
            nums[0] = lastNum;
        }
    }

    void betterRotate(vector<int> &nums, int k) {
        
    }

    void show(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << ",";
        }
        cout << endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    Solution s;
    s.rotate(nums, k);
    s.show(nums);
    return 0;
}