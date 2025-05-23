#include <iostream>
#include "vector.h"

template <typename T>
Vector<T>::Vector() : Size(0), Capacity(1)
{
    array = alloc.allocate(Capacity);
}

template <typename T>
Vector<T>::Vector(const Vector<T> &rhs) : Size(rhs.Size), Capacity(rhs.Capacity)
{
    array = alloc.allocate(Capacity);
    for (int i = 0; i < Size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i], rhs.array[i]);
    }
}

template <typename T>
Vector<T>::Vector(Vector<T> &&rhs) noexcept : Size(rhs.Size), Capacity(rhs.Capacity), array(rhs.array)
{
    rhs.Size = 0;
    rhs.Capacity = 0;
    rhs.array = nullptr;
}

template <typename T>
Vector<T>::Vector(int elements, const T &value) : Size(elements), Capacity(elements)
{
    array = alloc.allocate(Capacity);
    for (int i = 0; i < Size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i], value);
    }
}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T> &list) : Size(0), Capacity(list.size())
{
    array = alloc.allocate(Capacity);
    for (const T &elem : list)
    {
        emplace_back(elem);
    }
}

template <typename T>
Vector<T>::~Vector()
{
    Size = Capacity = 0;
    for (int i = 0; i < Size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
    }
    alloc.deallocate(array, Capacity);
}

template <typename T>
void Vector<T>::push_back(const T &value)
{
    if (Size >= Capacity)
    {
        reserve(Capacity * 2);
    }

    std::allocator_traits<decltype(alloc)>::construct(alloc, &array[Size], value);
    ++Size;
}

template <typename T>
void Vector<T>::pop_back()
{
    if (Size == 0)
    {
        throw std::exception();
    }
    --Size;
}

template <typename T>
bool Vector<T>::empty() const
{
    return Size == 0;
}

template <typename T>
int Vector<T>::size() const
{
    return Size;
}

template <typename T>
int Vector<T>::capacity() const
{
    return Capacity;
}

template <typename T>
void Vector<T>::reserve(int new_cap)
{
    if (new_cap <= Capacity)
        return;
    T *newArray = alloc.allocate(new_cap);
    for (int i = 0; i < Size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::construct(alloc, &newArray[i], std::move(array[i]));
        std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
    }
    alloc.deallocate(array, Capacity);
    array = newArray;
    Capacity = new_cap;
}

template <typename T>
void Vector<T>::shrink_to_fit()
{
    if (Capacity == Size)
        return;
    Capacity = Size;
    T *newArray = alloc.allocate(Capacity);
    for (int i = 0; i < Size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::construct(alloc, &newArray[i], array[i]);
    }
    for (int i = 0; i < Size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
    }
    alloc.deallocate(array, Capacity);
    array = newArray;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T> &rhs) const
{
    if (Size != rhs.size())
        return false;

    for (int i = 0; i < size(); ++i)
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
    int minSize = std::min(Size, rhs.Size);
    for (int i = 0; i < minSize; ++i)
    {
        if (array[i] > rhs.array[i])
            return true;
        if (rhs.array[i] > array[i])
            return false;
    }
    return Size > rhs.Size;
}

template <typename T>
bool Vector<T>::operator>=(const Vector<T> &rhs) const
{
    return !(*this < rhs);
}

template <typename T>
bool Vector<T>::operator<(const Vector<T> &rhs) const
{
    int minSize = std::min(Size, rhs.Size);
    for (int i = 0; i < minSize; ++i)
    {
        if (array[i] < rhs.array[i])
            return true;
        if (rhs.array[i] < array[i])
            return false;
    }
    return Size < rhs.Size;
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
        clear();
        alloc.deallocate(array, Capacity);

        Size = rhs.Size;
        Capacity = rhs.Capacity;
        array = alloc.allocate(Capacity);
        for (int i = 0; i < Size; ++i)
        {
            std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i], rhs.array[i]);
        }
    }
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&rhs) noexcept
{
    if (this != &rhs)
    {
        clear();
        alloc.deallocate(array, Capacity);

        Size = rhs.Size;
        Capacity = rhs.Capacity;
        array = rhs.array;

        rhs.Size = 0;
        rhs.Capacity = 0;
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
    if ((index < 0) || (index >= Size))
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
    return array[Size - 1];
}

template <typename T>
void Vector<T>::insert(int index, const T &value)
{
    if ((index < 0) || (index >= Size))
    {
        throw std::out_of_range("Insert: Indeksas uz ribu");
    }

    if (Size != Capacity)
    {
        for (int i = Size - 1; i >= index; --i)
        {
            std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i + 1], array[i]);
        }
        array[index] = value;
        ++Size;
    }
    else
    {
        Capacity *= 2;
        T *newArray = alloc.allocate(Capacity);
        for (int i = 0; i < Size; ++i)
        {
            std::allocator_traits<decltype(alloc)>::construct(alloc, &newArray[i], array[i]);
        }
        for (int i = 0; i < Size; ++i)
        {
            std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
        }
        alloc.deallocate(array, Capacity);
        array = newArray;
        insert(index, value);
    }
}

template <typename T>
void Vector<T>::erase(int index)
{
    if ((index < 0) || (index >= Size))
    {
        throw std::out_of_range("Erase: Indeksas uz ribu");
    }

    for (int i = index; i < Size - 1; ++i)
    {
        std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i], array[i + 1]);
    }
    --Size;
}
template <typename T>
typename Vector<T>::iterator Vector<T>::erase(const_iterator pos)
{
    int index = pos - array;
    if (index < 0 || index >= Size)
    {
        throw std::out_of_range("Erase: Indeksas uz ribu");
    }
    std::allocator_traits<allocator_type>::destroy(alloc, &array[index]);
    for (int i = index; i < Size - 1; ++i)
    {
        std::allocator_traits<allocator_type>::construct(alloc, &array[i], std::move(array[i + 1]));
        std::allocator_traits<allocator_type>::destroy(alloc, &array[i + 1]);
    }

    --Size;
    return array + index;
}
template <typename T>
typename Vector<T>::iterator Vector<T>::erase(const_iterator first, const_iterator last)
{
    int start = first - array;
    int end = last - array;

    if (start < 0 || start > end || end > Size)
    {
        throw std::out_of_range("Erase: Indeksai uz ribu");
    }

    int count = end - start;
    for (int i = start; i < end; ++i)
    {
        std::allocator_traits<allocator_type>::destroy(alloc, &array[i]);
    }
    for (int i = end; i < Size; ++i)
    {
        std::allocator_traits<allocator_type>::construct(alloc, &array[i - count], std::move(array[i]));
        std::allocator_traits<allocator_type>::destroy(alloc, &array[i]);
    }

    Size -= count;
    return array + start;
}

template <typename T>
void Vector<T>::clear()
{
    Size = 0;
}

template <typename T>
template <typename... Args>
void Vector<T>::emplace_back(Args &&...args)
{
    if (Size >= Capacity)
    {
        reserve(Capacity == 0 ? 1 : Capacity * 2);
    }
    std::allocator_traits<decltype(alloc)>::construct(alloc, &array[Size], std::forward<Args>(args)...);
    ++Size;
}

template <typename T>
template <typename... Args>
T *Vector<T>::emplace(int index, Args &&...args)
{
    if (index < 0 || index > Size)
        throw std::out_of_range("Emplace: Indeksas uz ribu");

    if (Size >= Capacity)
        reserve(Capacity == 0 ? 1 : Capacity * 2);

    for (int i = Size; i > index; --i)
    {
        std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i], std::move(array[i - 1]));
        std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i - 1]);
    }
    std::allocator_traits<decltype(alloc)>::construct(alloc, &array[index], std::forward<Args>(args)...);
    ++Size;

    return &array[index];
}

template <typename T>
void Vector<T>::assign(int count, const T &value)
{
    for (int i = 0; i < Size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
    }
    alloc.deallocate(array, Capacity);
    Size = 0;
    array = alloc.allocate(Capacity);
    for (int i = 0; i < count; ++i)
    {
        push_back(value);
    }
}

template <typename T>
void Vector<T>::assign(std::initializer_list<T> ilist)
{
    for (int i = 0; i < Size; ++i)
    {
        std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
    }
    alloc.deallocate(array, Capacity);
    Size = 0;
    Capacity = ilist.size();
    array = alloc.allocate(ilist.size());
    for (const T &i : ilist)
    {
        push_back(i);
    }
}

template <typename T>
T *Vector<T>::data()
{
    if (empty())
        return nullptr;
    return array;
}

template <typename T>
const T *Vector<T>::data() const
{
    if (empty())
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
    if (count == Size)
        return;
    else if (count < Size)
    {
        for (int i = count; i < Size; ++i)
        {
            std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
        }
        Size = count;
    }
    else
    {
        reserve(std::max(count, Capacity * 2));
        for (int i = Size; i < count; ++i)
        {
            std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i]);
        }
        Size = count;
    }
}

template <typename T>
void Vector<T>::resize(int count, const T &value)
{
    if (count < 0)
    {
        throw std::exception();
    }
    if (count == Size)
        return;
    else if (count < Size)
    {
        for (int i = count; i < Size; ++i)
        {
            std::allocator_traits<decltype(alloc)>::destroy(alloc, &array[i]);
        }
        Size = count;
    }
    else
    {
        reserve(std::max(count, Capacity * 2));
        for (int i = Size; i < count; ++i)
        {
            std::allocator_traits<decltype(alloc)>::construct(alloc, &array[i], value);
        }
        Size = count;
    }
}
