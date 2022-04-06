#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(int a, int b) {
        long long int ta = 10, tb = 10;
        while (ta <= a) ta *= 10;
        while (tb <= b) tb *= 10;
        return a * tb + b > b * ta + a;
    }
    string largestNumber(vector<int>& nums) {
        string res;
        if (nums.empty()) return res;
        // sort(nums.begin(), nums.end(), cmp);
        sort(nums.begin(), nums.end(), [](const int &a, const int &b){
          long long int ta = 10, tb = 10;
          while (ta <= a) ta *= 10;
          while (tb <= b) tb *= 10;
          return a * tb + b > b * ta + a;
        });
        for (int i = 0; i < nums.size(); i++) {
            res += to_string(nums[i]);
        }
        return res[0] == '0' ? to_string(0) : res;
    }
};

void Test1() {
  std::cout << "------------------------------start Test1------------------------------" << std::endl;
  // https://leetcode-cn.com/problems/largest-number/
  std::vector<int> nums {3, 30, 34, 5, 9};
  Solution solution;
  std::string res = solution.largestNumber(nums);
  std::cout << "largestNumber is " << res << std::endl;
  std::vector<int> nums1 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  res = solution.largestNumber(nums1);
  std::cout << "largestNumber is " << res << std::endl;
  std::cout << "------------------------------end Test1------------------------------" << std::endl;
}

void Test2() {
  std::cout << "------------------------------start Test2------------------------------" << std::endl;

  std::cout << "------------------------------end 2------------------------------" << std::endl;
}

int main(int argc, char **argv) {
  std::cout << "hello lch !" << std::endl;
  (void)Test1();
  (void)Test2();
  std::cout << "end lch !" << std::endl;
}
