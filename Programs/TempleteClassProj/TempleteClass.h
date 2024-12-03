#ifndef TEMPLETECLASS_H
#define TEMPLETECLASS_H


template <class T>
class TempleteClass {
private:
    T data;
    T data1;

public:
    TempleteClass(T data) : data(data) {}
    TempleteClass(T data, T data1) : data(data), data1(data1) {}

    T getData() {
        return data;
    }

    std::pair<T, T> getPair() {
        T temp = data;
        data = data1;
        data1 = temp;
        return std::make_pair(data, data1);
    }
};

#endif