#ifndef TEMPLETECLASS_H
#define TEMPLETECLASS_H

template <class T>
class TempleteClass {
private:
    T data;

public:
    TempleteClass(T data) : data(data) {}

    T getData() {
        return data;
    }

    T setData(T data) {
        this->data = data;
        return this->data;
    }
};

#endif