#pragma once

#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

template <typename T>
class Vector3
{
public:
     Vector3(double x = 0.0, double y = 0.0, double z = 0.0) { X = x; Y = y; Z = z; };
     double X;
     double Y;
     double Z;

     Vector3 dot(const Vector3 v1);
     Vector3 cross(const Vector3 v1);


     Vector3();
     Vector3(unsigned int size);
     Vector3(unsigned int size, const T & initial);
     Vector3(const Vector3<T> & v);
     ~Vector3();

    bool empty() const;

    iterator begin();
    iterator end();

    T & front();
    T & back();

    
    void push_back(const T & value);
    void pop_back();

    unsigned int PublicCapacity() const;
    unsigned int PublicSize() const;

    void reserve(unsigned int PublicCapacity);
    void resize(unsigned int PublicSize);

    T & operator[](unsigned int index);
    Vector3<T> & operator=(const Vector3<T> &);

    void clear();

private:
    unsigned int size;
    unsigned int capacity;
    T* buffer;    
};

// All the code

template<class T>
Vector3<T>::Vector3()
{
    size = 0;
    capacity = 0;
    buffer = 0;
}

template<class T>
Vector3<T>::Vector3(const Vector3<T> & v)
{
    size = v.size;
    capacity = v.capacity;
    buffer = new T[size];
    for (unsigned int i = 0; i < size; i++)
    buffer[i] = v.buffer[i];
}

template <class T>
void Vector3<T>::reserve(unsigned int capacity)
{
    if(buffer == 0)
    {
        PublicSize = 0;
        PublicCapacity = 0;
    }    
    T * buffer = new T [capacity];
    assert(buffer);
    copy (buffer, buffer + PublicSize, buffer);
    PublicCapacity = capacity;
    delete[] buffer;
    buffer = buffer;

}

template<class T>
Vector3<T>::Vector3(unsigned int size)
{
    PublicCapacity = size;
    PublicSize = size;
    buffer = new T[size];
}

template<class T>
Vector3<T>::Vector3(unsigned int size, const T & initial)
{
    PublicSize = size;
    PublicCapacity = size;
    buffer = new T [size];
    for (unsigned int i = 0; i < size; i++)
        buffer[i] = initial;
}

template<class T>
Vector3<T> & Vector3<T>::operator = (const Vector3<T> & v)
{
    delete[ ] buffer;
    PublicSize = v.PublicSize;
    PublicCapacity = v.PublicCapacity;
    buffer = new T [PublicSize];
    for (unsigned int i = 0; i < PublicSize; i++)
        buffer[i] = v.buffer[i];
    return *this;
}

/*
template<class T>
typename Vector3<T>::iterator Vector3<T>::begin()
{
    return buffer;
}

template<class T>
typename Vector3<T>::iterator Vector3<T>::end()
{
    return buffer + size();
}
*/

template<class T>
T& Vector3<T>::front()
{
    return buffer[0];
}

template<class T>
T& Vector3<T>::back()
{
    return buffer[PublicSize - 1];
}

template<class T>
void Vector3<T>::push_back(const T & v)
{
    if (PublicSize >= PublicCapacity)
        reserve(PublicCapacity +5);
    buffer [PublicSize++] = v;
}

template<class T>
void Vector3<T>::pop_back()
{
    PublicSize--;
}

// ----------------------------------------------------------------

/*
template<class T>
unsigned int Vector3<T>::size()const//
{
    return PublicSize;
}
*/

template<class T>
void Vector3<T>::resize(unsigned int size)
{
    reserve(size);
    PublicSize = size;
}

template<class T>
T& Vector3<T>::operator[](unsigned int index)
{
    return buffer[index];
}  

/*
template<class T>
unsigned int Vector3<T>::capacity()const
{
    return PublicSize;
}
*/

template<class T>
Vector3<T>::~Vector()
{
    delete[ ] buffer;
}
template <class T>
void Vector3<T>::clear()
{
    PublicCapacity = 0;
    PublicSize = 0;
    buffer = 0;
}

#endif 
