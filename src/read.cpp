#include "../include/read.h"

using namespace std;

int getOccurs(const string& str, char chr) {
  int size;
  for (int i = 0; (i = str.find(chr, i)) != string::npos; i++) {
    size++;
  }
  return size;
}

void read(vector<vector<int>>& arrays) {
  ifstream File("Sayilar.txt");
  if (!File.good()) {
    cout << "File doesn't exists!" << endl;
    exit(EXIT_FAILURE);
  } else if (!File.is_open()) {
    cout << "Something went wrong!" << endl;
    exit(EXIT_FAILURE);
  }
  string line;
  for (int i = 0; getline(File, line); i++){
    stringstream ss(line);
    int num;
    size_t numCount = getOccurs(line, ' ') + 1;
    vector<int> nums;
    nums.reserve(numCount);
    for (int i = 0; ss >> num; i++) {
      nums.emplace_back(num);
    }
    arrays.push_back(nums);
  }
}

