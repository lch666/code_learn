#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using v_int = std::vector<int>;
using v_v_int = std::vector<std::vector<int>>;

int length_of_lis(const v_int &v) {
  int max_length = 0;
  int length = v.size();
  if (length < 2) return length;
  v_int dp(length, 1);
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < i; j++) {
      if (v[i] > v[j]) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
    max_length = std::max(max_length, dp[i]);
  }
  return max_length;
}

int length_of_lcs(const std::string &s1, const std::string &s2) {
  int m = s1.size();
  int n = s2.size();
  v_v_int dp(m  + 1, v_int(n + 1, 0));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[m][n];
}

int main () {
  std::cout << "lch begin !!!" << std::endl;
  v_int v{10, 9, 2, 5, 3, 7, 101, 18};
  std::cout << length_of_lis(v) << std::endl;

  std::string s1 = "abcde";
  std::string s2 = "ace";
  std::cout << length_of_lcs(s1, s2) << std::endl;
  std::cout << "lch end !!!" << std::endl;
  return 0;
}