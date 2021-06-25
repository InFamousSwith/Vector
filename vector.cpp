#include <iostream>
using namespace std;

using ValueType = double;


class IVector {
private:
    ValueType* array;
    int size;
    int capacity;
public:
    IVector() : array(nullptr), size(0), capacity(0) {}

    IVector(const int& capacity) : capacity(capacity), size(0) {
        array = new ValueType[capacity];
    }

    IVector(const IVector& other) {
        capacity = other.capacity;
        size = other.size;
        array = new ValueType[size];
        for (int i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }


    void pushBack(const ValueType& value) {
        if (size < capacity) {
            ++size;
            array[size - 1] = value;
        }
        else {
            ValueType* tmp = array;

            array = new ValueType[++capacity];
            for (int i = 0; i < size; ++i) {
                array[i] = tmp[i];
            }

            ++size;
            array[size - 1] = value;

            delete[] tmp;
        }
    }



    void pushFront(const ValueType& value) {
        ValueType* tmp = array;
        if (size == capacity) {
            array = new ValueType[++capacity];
        }
        else {
            array = new ValueType[capacity];
        }

        for (int i = 0; i < size; ++i) {
            array[i + 1] = tmp[i];
        }
        array[0] = value;
        ++size;
        delete[] tmp;
    }

    void insert(const ValueType& value, size_t idx) {
        ValueType* tmp = array;
        if (size == capacity) {
            array = new ValueType[++capacity];
        }
        else {
            array = new ValueType[capacity];
        }

        for (int i = 0; i < idx; ++i) {
            array[i] = tmp[i];
        }

        array[idx] = value;

        for (size_t i = idx; i < size; ++i) {
            array[i + 1] = tmp[i];
        }

        ++size;
        delete[] tmp;
    }

    void Print() const {
        for (int i = 0; i < size; ++i) {
            cout << array[i] << ' ';
        }
        cout << endl;
    }

    ValueType& at(size_t idx) {
        return array[idx];
    }

    const ValueType& at(size_t idx) const {
        return array[idx];
    }

    void clear() {
        delete[] array;
        array = nullptr;
        size = capacity = 0;
    }

    ~IVector() {
        delete[] array;
    }
};



int main() {
    IVector v1;
    IVector v2(10);
    for (int i = 0; i < 10; ++i) {
        v2.pushBack(i);
    }
    v2.Print();
    v2.insert(100, 4);
    v2.Print();
    v2.pushBack(200);
    v2.Print();
    v2.pushFront(34);
    v2.Print();
    return 0;
}