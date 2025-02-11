#include <algorithm>
#include <array>
#include <array>
#include <iostream>
#include <string>
#include <vector>

int binarySearch(std::vector<std::string> array, std::string target) {
  int low = 0;
  int high = array.size() -1;
  std::sort(array.begin(), array.end());
  do {
    int mid = (low+high) / 2;
    if (array[mid] == target)
      return mid;
    if (array[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
    } while (low <= high);
  return -1;
  }

  int main(){
  int index = binarySearch({"hi","bye","here","there","apple"}, "apple");
  std::cout << index << std::endl;
  return 0;
}
