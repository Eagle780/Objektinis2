#pragma once

#include <iostream>
#include <memory>

template <typename T>
class Vector
{
public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using pointer = T *;
    using const_pointer = const T *;
    using iterator = T *;
    using const_iterator = const T *;
    using reverse_iterator = T *;
    using const_reverse_iterator = const T *;
    using allocator_type = std::allocator<T>;

private:
    int size;
    int capacity;
    T *array;
    allocator_type alloc;

public:
    Vector();
    Vector(const Vector<T> &rhs);
    Vector(int elements, const T &value = T());
    Vector(const std::initializer_list<T> &list);
    ~Vector();

    void Push_back(const T &value);
    void Pop_back();

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

    value_type &operator[](int index);
    value_type &At(int index);
    value_type &Front();
    value_type &Back();

    pointer Data();
    const_pointer Data() const;

    void Insert(int index, const T &value);
    void Erase(int index);
    void Clear();

    void Assign(int count, const T &value);
    void Assign(std::initializer_list<T> ilist);

    iterator Begin() { return array; }
    iterator End() { return array + size; }
    const_iterator Begin() const { return array; }
    const_iterator End() const { return array + size; }
    const_iterator Cbegin() const { return array; }
    const_iterator Cend() const { return array + size; }

    iterator Rbegin() { return array + size - 1; }
    iterator Rend() { return array - 1; }
    const_iterator Rbegin() const { return array + size - 1; }
    const_iterator Rend() const { return array - 1; }

    void Resize(int count);
    void Resize(int count, const T &value);
};

#include "vector.tpp"