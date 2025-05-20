#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>
class Vector
{
private:
    int size;
    int capacity;
    T *array;

public:
    Vector();
    Vector(const Vector &rhs);
    Vector(int elements, const T &value = T());
    Vector(const std::initializer_list<T> &list);
    ~Vector();

    void PushBack(const T &value);
    void PopBack();

    bool isEmpty() const;
    T Size() const;
    T Capacity() const;
    T Array(int pos) const;

    bool operator==(const Vector &rhs) const;
    bool operator!=(const Vector &rhs) const;
    Vector &operator=(const Vector &rhs);

    T &operator[](int index);
    T &At(int index);
    T &Front();
    T &Back();

    void Insert(int index, const T &value);
    void Erase(int index);
    void Clear();
};

#include "Vector.tpp"
#endif