#ifndef TEMPLETECLASS_H
#define TEMPLETECLASS_H

#include <vector>
#include <algorithm>

template <class T>
class TempleteClass {
private:
    std::vector<T> dataVector;
    T data;
    T data1;

public:
    TempleteClass(T data) : data(data) {}

    TempleteClass(T data, T data1) : data(data), data1(data1) {}

    explicit TempleteClass(std::vector<T> dataVector) : dataVector(dataVector) {}

    T getData() {
        return data;
    }

    std::pair<T, T> getPair() {
        T temp = data;
        data = data1;
        data1 = temp;
        return std::make_pair(data, data1);
    }

    std::vector<T> bubbleSort() {
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            for (int i = 0; i < dataVector.size() - 1; i++) {
                if (dataVector[i] > dataVector[i + 1]) {
                    sorted = false;
                    std::swap(dataVector[i], dataVector[i + 1]);
                }
            }
        }
        return dataVector;

    }
};

#endif