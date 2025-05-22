#include <iostream>
#include "vector.h"

template <typename T>
Vector<T>::Vector() : size(0), capacity(1)
{
    array = alloc.allocate(capacity);
}

template <typename T>
Vector<T>::Vector(const Vector<T> &rhs) : size(rhs.size), capacity(rhs.capacity)
{
    array = alloc.allocate(capacity);
    for (int i = 0; i < size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i], rhs.array[i]);
    }
}

template <typename T>
Vector<T>::Vector(Vector<T> &&rhs) noexcept : size(rhs.size), capacity(rhs.capacity), array(rhs.array)
{
    rhs.size = 0;
    rhs.capacity = 0;
    rhs.array = nullptr;
}

template <typename T>
Vector<T>::Vector(int elements, const T &value) : size(elements), capacity(elements)
{
    array = alloc.allocate(capacity);
    for (int i = 0; i < size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i], value);
    }
}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T> &list) : size(0), capacity(list.size())
{
    array = alloc.allocate(capacity);
    for (const T &elem : list)
    {
        Emplace_back(elem);
    }
}

template <typename T>
Vector<T>::~Vector()
{
    size = capacity = 0;
    for (int i = 0; i < size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
    }
    alloc.deallocate(array, capacity);
}

template <typename T>
void Vector<T>::push_back(const T &value)
{
    if (size >= capacity)
    {
        Reserve(capacity * 2);
    }

    std::allocator_traits<decltype(alloc)>::construct(alloc, &array[size], value);
    ++size;
}

template <typename T>
void Vector<T>::pop_back()
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
int Vector<T>::Capacity() const
{
    return capacity;
}

template <typename T>
void Vector<T>::reserve(int new_cap)
{
    if (new_cap <= capacity)
        return;
    T *newArray = alloc.allocate(new_cap);
    for (int i = 0; i < size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::construct(alloc, &newArray[i], std::move(array[i]));
        std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
    }
    for (int i = 0; i < size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
    }
    alloc.deallocate(array, capacity);
    array = newArray;
    capacity = new_cap;
}

template <typename T>
void Vector<T>::shrink_to_fit()
{
    if (capacity == size)
        return;
    capacity = size;
    T *newArray = alloc.allocate(capacity);
    for (int i = 0; i < size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::construct(alloc, &newArray[i], array[i]);
    }
    for (int i = 0; i < size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
    }
    alloc.deallocate(array, capacity);
    array = newArray;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T> &rhs) const
{
    if (size != rhs.Size())
        return false;

    for (int i = 0; i < Size(); ++i)
    {
        if (!(array[i] == rhs.array[i]))
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
    if (this != &rhs)
    {
        Clear();
        alloc.deallocate(array, capacity);

        size = rhs.size;
        capacity = rhs.capacity;
        array = alloc.allocate(capacity);
        for (int i = 0; i < size; ++i)
        {
            std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i], rhs.array[i]);
        }
    }
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &&rhs) noexcept
{
    if (this != &rhs)
    {
        Clear();
        alloc.deallocate(array, capacity);

        size = rhs.size;
        capacity = rhs.capacity;
        array = rhs.array;

        rhs.size = 0;
        rhs.capacity = 0;
        rhs.array = nullptr;
    }
    return *this;
}

template <typename T>
std::allocator<T> Vector<T>::get_allocator() const
{
    return alloc;
}

template <typename T>
T &Vector<T>::operator[](int index)
{
    return array[index];
}

template <typename T>
T &Vector<T>::at(int index)
{
    if ((index < 0) || (index >= size))
    {
        throw std::out_of_range("At: Indeksas uz ribu");
    }
    return array[index];
}

template <typename T>
T &Vector<T>::front()
{
    return array[0];
}

template <typename T>
T &Vector<T>::back()
{
    return array[size - 1];
}

template <typename T>
void Vector<T>::insert(int index, const T &value)
{
    if ((index < 0) || (index >= size))
    {
        throw std::out_of_range("Insert: Indeksas uz ribu");
    }

    if (size != capacity)
    {
        for (int i = size - 1; i >= index; --i)
        {
            std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i + 1], array[i]);
        }
        array[index] = value;
        ++size;
    }
    else
    {
        capacity *= 2;
        T *newArray = alloc.allocate(capacity);
        for (int i = 0; i < size; ++i)
        {
            std::allocator_traits<decltype(alloc)>::construct(alloc, &newArray[i], array[i]);
        }
        for (int i = 0; i < size; ++i)
        {
            std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
        }
        alloc.deallocate(array, capacity);
        array = newArray;
        Insert(index, value);
    }
}

template <typename T>
void Vector<T>::erase(int index)
{
    if ((index < 0) || (index >= size))
    {
        throw std::out_of_range("Erase: Indeksas uz ribu");
    }

    for (int i = index; i < size - 1; ++i)
    {
        std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i], array[i + 1]);
    }
    --size;
}

template <typename T>
void Vector<T>::clear()
{
    size = 0;
}

template <typename T>
template <typename... Args>
void Vector<T>::emplace_back(Args &&...args)
{
    if (size >= capacity)
    {
        Reserve(capacity == 0 ? 1 : capacity * 2);
    }
    std::allocator_traits<decltype(alloc)>::construct(alloc, &array[size], std::forward<Args>(args)...);
    ++size;
}

template <typename T>
template <typename... Args>
T *Vector<T>::emplace(int index, Args &&...args)
{
    if (index < 0 || index > size)
        throw std::out_of_range("Emplace: Indeksas uz ribu");

    if (size >= capacity)
        Reserve(capacity == 0 ? 1 : capacity * 2);

    for (int i = size; i > index; --i)
    {
        std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i], std::move(array[i - 1]));
        std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i - 1]);
    }
    std::allocator_traits<decltype(alloc)>::construct(alloc, &array[index], std::forward<Args>(args)...);
    ++size;

    return &array[index];
}

template <typename T>
void Vector<T>::assign(int count, const T &value)
{
    for (int i = 0; i < size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
    }
    alloc.deallocate(array, capacity);
    size = 0;
    array = alloc.allocate(capacity);
    for (int i = 0; i < count; ++i)
    {
        Push_back(value);
    }
}

template <typename T>
void Vector<T>::assign(std::initializer_list<T> ilist)
{
    for (int i = 0; i < size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
    }
    alloc.deallocate(array, capacity);
    size = 0;
    capacity = ilist.size();
    array = alloc.allocate(ilist.size());
    for (const T &i : ilist)
    {
        Push_back(i);
    }
}

template <typename T>
T *Vector<T>::data()
{
    if (isEmpty())
        return nullptr;
    return array;
}

template <typename T>
const T *Vector<T>::data() const
{
    if (isEmpty())
        return nullptr;
    return array;
}

template <typename T>
void Vector<T>::resize(int count)
{
    if (count < 0)
    {
        throw std::exception();
    }
    if (count == size)
        return;
    else if (count < size)
    {
        for (int i = count; i < size; ++i)
        {
            std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
        }
        size = count;
    }
    else
    {
        Reserve(std::max(count, capacity * 2));
        for (int i = size; i < count; ++i)
        {
            std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i]);
        }
        size = count;
    }
}

template <typename T>
void Vector<T>::resize(int count, const T &value)
{
    if (count < 0)
    {
        throw std::exception();
    }
    if (count == size)
        return;
    else if (count < size)
    {
        for (int i = count; i < size; ++i)
        {
            std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
        }
        size = count;
    }
    else
    {
        Reserve(std::max(count, capacity * 2));
        for (int i = size; i < count; ++i)
        {
            std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i], value);
        }
        size = count;
    }
}
