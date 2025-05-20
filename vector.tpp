#include "vector.h"

Vector::Vector() : size(0), capacity(5), array(new int[capacity])
{
}

Vector::Vector(const Vector &rhs) : size(rhs.size), capacity(rhs.capacity), array(new int[capacity])
{
    for (int i = 0; i < rhs.Size(); ++i)
    {
        array[i] = rhs.array[i];
    }
}

Vector::Vector(int elements, const T &value = T()) : size(elements), capacity(elements), array(new int[capacity])
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = value;
    }
}

Vector::Vector(const std::initializer_list<int> &list) : size(0), capacity(list.size()), array(new int[capacity])
{
    for (int i : list)
    {
        PushBack(i);
    }
}

Vector::~Vector()
{
    size = capacity = 0;
    delete[] array;
    std::cout << "done" << std::endl;
}

void Vector::PushBack(int value)
{
    if (size < capacity)
    {
        array[size] = value;
        ++size;
    }
    else
    {
        capacity *= 2;
        int *newArray = new int[capacity];
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

void Vector::PopBack()
{
    if (size == 0)
    {
        throw std::exception();
    }
    --size;
}

bool Vector::isEmpty() const
{
    return size == 0;
}

int Vector::Size() const
{
    return size;
}

int Vector::Capacity() const
{
    return capacity;
}

int Vector::Array(int pos) const
{
    return array[pos];
}

bool Vector::operator==(const Vector &rhs) const
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

bool Vector::operator!=(const Vector &rhs) const
{
    return !(*this == rhs);
}

Vector &Vector::operator=(const Vector &rhs)
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

int &Vector::operator[](int index)
{
    return array[index];
}

int &Vector::At(int index)
{
    if ((index < 0) || (index >= size))
    {
        throw std::exception();
    }
    return array[index];
}

int &Vector::Front()
{
    return array[0];
}

int &Vector::Back()
{
    return array[size - 1];
}

void Vector::Insert(int index, int value)
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
        int *newArray = new int[capacity];
        for (int i = 0; i < size; ++i)
        {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        Insert(index, value);
    }
}

void Vector::Erase(int index)
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

void Vector::Clear()
{
    size = 0;
}
