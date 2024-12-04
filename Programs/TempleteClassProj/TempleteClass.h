#ifndef TEMPLETECLASS_H
#define TEMPLETECLASS_H

#include <vector>

template <class T>
class TempleteClass {
private:
    std::vector<T> dataVector;
    T data;
    T data1;

public:
    TempleteClass(T data) : data(data) {}

    TempleteClass(T data, T data1) : data(data), data1(data1) {}

    TempleteClass(std::vector<T> daTTa) : data(data) {}

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

    }
};

#endif