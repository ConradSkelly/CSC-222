#ifndef TEMPLETECLASS_H
#define TEMPLETECLASS_H

#include <vector>
#include <iostream>


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

    T getDataVector() {
        return dataVector;
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

    std::vector<T> mergeSort() {
      int size = dataVector.size();
       mergeSetUp(dataVector, 0, size - 1);
        return dataVector;
    }

    void mergeSetUp(std::vector<T>& dataVector, int left, int right ) {
        if (left >= right) {
            return;
        }

        int middle = (left + right) / 2;
        mergeSetUp(dataVector, left, middle);
        mergeSetUp(dataVector, middle + 1, right);
        merge(dataVector, left, middle, right);
    }

    void merge(std::vector<T>& dataVector, int left, int middle, int right ) {
        int n1 = middle - left + 1;
        int n2 = right - middle;

        std::vector<T> tempVectorLeft(n1), tempVectorRight(n2);
        for (int i = 0; i < n1; i++) {
            tempVectorLeft[i] = dataVector[left + i];
        }
        for (int j = 0; j < n2; j++) {
            tempVectorRight[j] = dataVector[middle + 1 + j];
        }

        int i = 0, j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (tempVectorLeft[i] <= tempVectorRight[j]) {
                dataVector[k] = tempVectorLeft[i];
                i++;
            }
            else {
                dataVector[k] = tempVectorRight[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            dataVector[k] = tempVectorLeft[i];
            i++;
            k++;
        }
        while (j < n2) {
            dataVector[k] = tempVectorRight[j];
            j++;
            k++;
        }
    }

};

#endif