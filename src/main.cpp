#include <vector>
#include <algorithm>
#include "../include/AVL.h"
#include "../include/read.h"
#include "../include/radix.h"
using namespace std;

int getSum(const vector<int>& vec) {
  int sum = 0;
  for (const auto &j : vec) {
    sum += j;
  }
  return sum;
}

int main(int argc, char *argv[]) {
  vector<vector<int>> numbers;

  read(numbers);

  vector<int> sum;
  sum.reserve(numbers.size());


  for (int i = 0; i < numbers.size(); i++) {
    sortByRadix(numbers[i]);
    sum.emplace_back(getSum(numbers[i]));
  }  

  sort(numbers.begin(), numbers.end(), [](const vector<int>& a, const vector<int>& b) {
    return getSum(a) > getSum(b);
  });

  sort(sum.begin(), sum.end(), [](int a, int b) { return a > b; });
  AVL *root = NULL;

  for (int i = 0; i < sum.size(); i++) {
    root = root->insert(root, sum[i]);
  }

  root->preOrder(root, [&sum, &numbers](int num, bool yukari) {
    int idx = distance(sum.begin(), find(sum.begin(), sum.end(), num));
    cout << num << ": ";
    if (yukari) {
      numbers[idx].erase(numbers[idx].begin());
    } else {
      numbers[idx].erase(numbers[idx].end() - 1);
    }
    for (const auto &i : numbers[idx]) {
      cout << i << " ";
    }
    cout << endl;
  }, true);

  delete root;

  return 0;
}
