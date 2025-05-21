#include <iostream>
#include "vector.h"

template <typename T>
Vector<T>::Vector() : size(0), capacity(1)
{
    array = new T[capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T> &rhs) : size(rhs.size), capacity(rhs.capacity), array(new int[capacity])
{
    for (int i = 0; i < rhs.Size(); ++i)
    {
        array[i] = rhs.array[i];
    }
}

template <typename T>
Vector<T>::Vector(int elements, const T &value) : size(elements), capacity(elements), array(new int[capacity])
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = value;
    }
}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T> &list) : size(0), capacity(list.size()), array(new int[capacity])
{
    for (int i : list)
    {
        Push_back(i);
    }
}

template <typename T>
Vector<T>::~Vector()
{
    size = capacity = 0;
    delete[] array;
}

template <typename T>
void Vector<T>::Push_back(const T &value)
{
    if (size < capacity)
    {
        array[size] = value;
        ++size;
    }
    else
    {
        capacity *= 2;
        T *newArray = new T[capacity];
        for (int i = 0; i < size; ++i)
        {
            newArray[i] = array[i];
        }
        newArray[size] = value;
        ++size;
        delete[] array;
        array = newArray;
    }
}

template <typename T>
void Vector<T>::Pop_back()
{
    if (size == 0)
    {
        throw std::exception();
    }
    --size;
}

template <typename T>
bool Vector<T>::isEmpty() const
{
    return size == 0;
}

template <typename T>
int Vector<T>::Size() const
{
    return size;
}

template <typename T>
int Vector<T>::Max_size() const
{
    return 0;
}

template <typename T>
int Vector<T>::Capacity() const
{
    return capacity;
}

template <typename T>
void Vector<T>::Reserve(int new_cap)
{
    if (new_cap <= capacity)
        return;
    capacity = new_cap;
    T *newArray = new T[capacity];
    for (int i = 0; i < size; ++i)
    {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

template <typename T>
void Vector<T>::Shrink_to_fit()
{
    if (capacity == size)
        return;
    capacity = size;
    T *newArray = new T[capacity];
    for (int i = 0; i < size; ++i)
    {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

template <typename T>
bool Vector<T>::operator==(const Vector &rhs) const
{
    if (Size() != rhs.Size())
        return false;

    for (int i = 0; i < Size(); ++i)
    {
        if (array[i] != rhs.array[i])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector &rhs) const
{
    return !(*this == rhs);
}

template <typename T>
bool Vector<T>::operator>(const Vector<T> &rhs) const
{
    int minSize = std::min(size, rhs.size);
    for (int i = 0; i < minSize; ++i)
    {
        if (array[i] > rhs.array[i])
            return true;
        if (rhs.array[i] > array[i])
            return false;
    }
    return size > rhs.size;
}

template <typename T>
bool Vector<T>::operator>=(const Vector<T> &rhs) const
{
    return !(*this < rhs);
}

template <typename T>
bool Vector<T>::operator<(const Vector<T> &rhs) const
{
    int minSize = std::min(size, rhs.size);
    for (int i = 0; i < minSize; ++i)
    {
        if (array[i] < rhs.array[i])
            return true;
        if (rhs.array[i] < array[i])
            return false;
    }
    return size < rhs.size;
}

template <typename T>
bool Vector<T>::operator<=(const Vector<T> &rhs) const
{
    return !(*this > rhs);
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &rhs)
{
    if (rhs.Size() > size)
    {
        delete[] array;
        capacity = rhs.Capacity();
        array = new int[capacity];
    }
    for (int i = 0; i < rhs.Size(); ++i)
    {
        array[i] = rhs.array[i];
    }
    size = rhs.Size();

    return *this;
}

template <typename T>
T &Vector<T>::operator[](int index)
{
    return array[index];
}

template <typename T>
T &Vector<T>::At(int index)
{
    if ((index < 0) || (index >= size))
    {
        throw std::exception();
    }
    return array[index];
}

template <typename T>
T &Vector<T>::Front()
{
    return array[0];
}

template <typename T>
T &Vector<T>::Back()
{
    return array[size - 1];
}

template <typename T>
void Vector<T>::Insert(int index, const T &value)
{
    if ((index < 0) || (index >= size))
    {
        throw std::exception();
    }

    if (size != capacity)
    {
        for (int i = size - 1; i >= index; --i)
        {
            array[i + 1] = array[i];
        }
        array[index] = value;
        ++size;
    }
    else
    {
        capacity *= 2;
        T *newArray = new T[capacity];
        for (int i = 0; i < size; ++i)
        {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        Insert(index, value);
    }
}

template <typename T>
void Vector<T>::Erase(int index)
{
    if ((index < 0) || (index >= size))
    {
        throw std::exception();
    }

    for (int i = index; i < size - 1; ++i)
    {
        array[i] = array[i + 1];
    }
    --size;
}

template <typename T>
void Vector<T>::Clear()
{
    size = 0;
}

template <typename T>
void Vector<T>::Assign(int count, const T &value)
{
    delete[] array;
    size = 0;
    array = new T[count];
    for (int i = 0; i < count; ++i)
    {
        Push_back(value);
    }
}

template <typename T>
void Vector<T>::Assign(std::initializer_list<T> ilist)
{
    delete[] array;
    size = 0;
    array = new T[ilist.size()];
    for (auto i : ilist)
    {
        Push_back(i);
    }
}

template <typename T>
T *Vector<T>::Data()
{
    if (isEmpty())
        return nullptr;
    return array;
}

template <typename T>
const T *Vector<T>::Data() const
{
    if (isEmpty())
        return nullptr;
    return array;
}

template <typename T>
void Vector<T>::Resize(int count)
{
    if (count < 0)
    {
        throw std::exception();
    }
    if (count == size)
        return;
    else if (count < size)
        size = count;
    else
    {
        Reserve(std::max(count, capacity * 2));
        for (int i = size; i < count; ++i)
        {
            array[i] = T();
        }
        size = count;
    }
}

template <typename T>
void Vector<T>::Resize(int count, const T &value)
{
    if (count < 0)
    {
        throw std::exception();
    }
    if (count == size)
        return;
    else if (count < size)
        size = count;
    else
    {
        Reserve(std::max(count, capacity * 2));
        for (int i = size; i < count; ++i)
        {
            array[i] = value;
        }
        size = count;
    }
}
