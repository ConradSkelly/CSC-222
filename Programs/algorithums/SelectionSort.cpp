// todo find the lowest number
// todo append the shortest number
#include <iostream>
#include <vector>

int selectionSort(std::vector<int>& array) {
  int smallest = array[0];
  int smallestIndex = 0;
  for (int i =1; i < array.size(); i++) {
    if (array[i] < smallest) {
      smallest = array[i];
      smallestIndex = i;
    }
  }

  array.erase(array.begin() + smallestIndex);
  return smallest;
}

int main(){
  std::vector<int> array = {8,7,3,9,1,2,8,2,6};
  int len = array.size();
  std::vector<int> sortedArray = {};
  sortedArray.reserve(array.size());

for (int i = 0; i < len; i++) {
    sortedArray.push_back(selectionSort(array));
  }

  for (int i = 0; i < sortedArray.size(); i++) {
    std::cout << sortedArray[i] << " ";
  }
  return 0;
}