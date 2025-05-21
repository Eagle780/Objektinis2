#pragma once

#include <iostream>
#include <memory>

template <typename T>
class Vector
{
private:
    int size;
    int capacity;
    T *array;
    std::allocator<T> alloc;

public:
    Vector();
    Vector(const Vector<T> &rhs);
    Vector(int elements, const T &value = T());
    Vector(const std::initializer_list<T> &list);
    ~Vector();

    void PushBack(const T &value);
    void PopBack();

    bool isEmpty() const;
    int Size() const;
    int Max_size() const;
    int Capacity() const;
    void Reserve(int new_cap);
    void Shrink_to_fit();

    bool operator==(const Vector<T> &rhs) const;
    bool operator!=(const Vector<T> &rhs) const;
    bool operator>(const Vector<T> &rhs) const;
    bool operator>=(const Vector<T> &rhs) const;
    bool operator<(const Vector<T> &rhs) const;
    bool operator<=(const Vector<T> &rhs) const;

    Vector<T> &operator=(const Vector<T> &rhs);

    T &operator[](int index);
    T &At(int index);
    T &Front();
    T &Back();

    void Insert(int index, const T &value);
    void Erase(int index);
    void Clear();

    void Assign(int count, const T &value);
    // template <class InputIt>
    //  void assign(InputIt first, InputIt last);
    void Assign(std::initializer_list<T> ilist);

    T *Data();
    const T *Data() const;

    T *Begin() { return array; }
    T *End() { return array + size; }
    const T *Begin() const { return array; }
    const T *End() const { return array + size; }
    const T *Cbegin() const { return array; }
    const T *Cend() const { return array + size; }

    T *Rbegin() { return array + size - 1; }
    T *Rend() { return array - 1; }
    const T *Rbegin() const { return array + size - 1; }
    const T *Rend() const { return array - 1; }

    void Resize(int count);
    void Resize(int count, const T &value);
};

#include "vector.tpp"