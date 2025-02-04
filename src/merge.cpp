#include<iostream>
#include<vector>
#include<utility>
#include<cstdlib>
#include<ctime>
#include <random>

using namespace std;

class Solution { //实现快速排序
public:

    void swap(vector<int>& nums, int a, int b) {
    if (a != b) { // 避免自交换
        nums[a] = nums[a] ^ nums[b];
        nums[b] = nums[a] ^ nums[b];
        nums[a] = nums[a] ^ nums[b];
    }
    }

    void quick(vector<int>& nums, int L, int R) {
        if (L < R) {
            // 随机选择一个基准值，并将其放到末尾
            int randomIndex = L + rand() % (R - L + 1); // 随机选择一个索引
            swap(nums, randomIndex, R); // 将基准值放到末尾
            int pivot = nums[R]; // 基准值

            // 分区
            pair<int, int> p = partition(nums, L, R, pivot);
            // 递归排序左边和右边
            quick(nums, L, p.first - 1);
            quick(nums, p.second + 1, R);
        }
    }

    pair<int, int> partition(vector<int>& nums, int L, int R, int pivot) {
        int i = L - 1; // 小于区的右边界
        int j = R + 1; // 大于区的左边界
        int k = L;     // 当前遍历的位置

        while (k < j) {
            if (nums[k] < pivot) {
                // 如果当前值小于基准值，放到小于区
                swap(nums, ++i, k++);
            } else if (nums[k] > pivot) {
                // 如果当前值大于基准值，放到大于区
                swap(nums, --j, k);
            } else {
                // 如果当前值等于基准值，直接跳过
                k++;
            }
        }

        // 返回等于区的左右边界
        return {i + 1, j - 1};
    }

     

};


int main() {
    // 创建一个测试数组
    vector<int> nums = {3, 6, 8, 10, 1, 2, 1,999,123,3,4,0,0,0,1};

    // 输出排序前的数组
    cout << "before sort: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // 创建 Solution 对象并调用快速排序函数
    Solution a;
    a.quick(nums, 0, nums.size() - 1);

    // 输出排序后的数组
    cout << "after sort: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}