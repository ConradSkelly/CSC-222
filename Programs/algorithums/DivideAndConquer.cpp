#include <array>
#include <iostream>
#include <vector>
int sum(std::vector<int> Numbers) {
    if (Numbers.size() == 0)
        return 0;
    if (Numbers.size() == 1)
        return Numbers[0];
    return Numbers[0] + sum(std::vector(Numbers.begin() + 1, Numbers.end()));
}

int NumberOfElemnts(std::vector<int> Numbers) {
    if (Numbers == std::vector<int>{})
        return 0;
    return 1 + NumberOfElemnts(std::vector<int>(Numbers.begin() + 1, Numbers.end()));

}

int HighestNumber(std::vector<int> Numbers) {
    if (Numbers == std::vector<int>{})
        return 0;
    if (Numbers.size() == 1)
        return Numbers[0];
    int LastNumber = HighestNumber(std::vector<int>(Numbers.begin() + 1, Numbers.end()));
    if (LastNumber > Numbers[0])
        return LastNumber;
    return Numbers[0];
}

int BinarySearch(std::vector<int> Numbers, int target, int low, int high) {
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (Numbers[mid] == target)
        return mid;
    if (Numbers[mid] > target)
        return BinarySearch(Numbers, target, low, mid - 1);
    if (Numbers[mid] < target)
        return BinarySearch(Numbers, target, mid + 1, high);
}

std::vector<int> QuickSort(std::vector<int> Numbers) {
    std::vector<int> less;
    std::vector<int> greater;
    if (Numbers.size() < 2)
        return Numbers;
    int pivot = Numbers[0];
    for (int i = 1; i < Numbers.size(); i++) {
        if (Numbers[i] <= pivot)
            less.push_back(Numbers[i]);
        else
            greater.push_back(Numbers[i]);
    }
    std::vector<int> sorted;
    std::vector<int> sortedLess = QuickSort(less);
    std::vector<int> sortedGreater = QuickSort(greater);

    sorted.insert(sorted.end(), sortedLess.begin(), sortedLess.end());
    sorted.push_back(pivot);
    sorted.insert(sorted.end(), sortedGreater.begin(), sortedGreater.end());
    return sorted;
}


int main() {
    std::vector<int> Numbers = {99, 123, 34, 634, 2, 0, 1, 2, 94, 100, 7};
    Numbers = QuickSort(Numbers);
    for (int i = 0; i < Numbers.size(); i++) {
        std::cout << Numbers[i] << " ";
    }
    std::cout << std::endl;
    std::cout << sum(Numbers) << std::endl;
    std::cout << NumberOfElemnts(Numbers) << std::endl;
    std::cout << HighestNumber(Numbers) << std::endl;
    std::cout << BinarySearch(Numbers, 0, 0 , Numbers.size() -1) << std::endl;


    return 0;
}