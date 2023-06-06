#include "../include/radix.h"

int maxInt(const int numbers[], const int& size) {
  int prev = numbers[0];
  for (int i = 1; i < size; i++) {
    if (numbers[i] > prev) prev = numbers[i];
  }
  return prev;
}

void sortByRadix(std::vector<int>& numbers) {
  const int digits = 10;
  const int size = numbers.size();

  for (int j = 0; j < size; j++) {
    int occurs[10] = {0};
    int* tmp = new int[size]();

    int tens = std::pow(10, j);

    for (int i = 0; i < size; i++) occurs[(numbers[i] / tens) % 10]++;
    for (int i = 1; i < digits; i++) occurs[i] += occurs[i - 1];
    for (int i = size - 1; i >= 0; i--) {
      int& current = occurs[(numbers[i] / tens) % 10];
      tmp[--current] = numbers[i];
    }

    for (int i = 0; i < size; i++) numbers[i] = tmp[i];
    delete[] tmp;
  }
}
