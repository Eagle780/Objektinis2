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
    Vector(Vector<T> &&rhs) noexcept;
    Vector(int elements, const T &value = T());
    Vector(const std::initializer_list<T> &list);
    ~Vector();

    void push_back(const T &value);
    void pop_back();

    bool empty() const;
    int Size() const;
    int Capacity() const;
    void reserve(int new_cap);
    void shrink_to_fit();

    bool operator==(const Vector<T> &rhs) const;
    bool operator!=(const Vector<T> &rhs) const;
    bool operator>(const Vector<T> &rhs) const;
    bool operator>=(const Vector<T> &rhs) const;
    bool operator<(const Vector<T> &rhs) const;
    bool operator<=(const Vector<T> &rhs) const;

    Vector<T> &operator=(const Vector<T> &rhs);
    Vector<T> &operator=(const Vector<T> &&rhs) noexcept;
    allocator_type get_allocator() const;

    value_type &operator[](int index);
    value_type &at(int index);
    value_type &front();
    value_type &back();

    pointer data();
    const_pointer data() const;

    void insert(int index, const T &value);
    void erase(int index);
    void clear();

    template <typename... Args>
    void emplace_back(Args &&...args);
    template <typename... Args>
    T *emplace(int index, Args &&...args);

    void assign(int count, const T &value);
    void assign(std::initializer_list<T> ilist);

    iterator begin() { return array; }
    iterator end() { return array + size; }
    const_iterator begin() const { return array; }
    const_iterator end() const { return array + size; }
    const_iterator cbegin() const { return array; }
    const_iterator cend() const { return array + size; }

    iterator rbegin() { return array + size - 1; }
    iterator rend() { return array - 1; }
    const_iterator rbegin() const { return array + size - 1; }
    const_iterator rend() const { return array - 1; }

    void resize(int count);
    void resize(int count, const T &value);
};

#include "vector.tpp"