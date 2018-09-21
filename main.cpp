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
        int n = nums.size();
        if (nums.empty() || k <= 0 || (k %= n) == 0)
            return;

        int i = 0;
        int begin = 0;
        int temp = nums[0];
        for (int m = 0; m < n; ++m) {
            i = (i + k) % n;// 变相地按照每隔k个数的规则来遍历数组
            swap(temp, nums[i]); // temp保存了被替换的值

            if (i == begin) {
                temp = nums[++i];
                begin = i;
            }
        }
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
    int k = 3;
    Solution s;
    s.betterRotate(nums, k);
    s.show(nums);
    return 0;
}