#ifndef SET_H
#define SET_H

#include <iostream>

template <typename T>
class Iterator;

template <typename T>

class Set{
private:
    T* data;
    size_t length;
    void memory_alloc();
public:
    Set();
    Set(const Set<T>& s);
    Set(Set<T>&& s);
    explicit Set(std::initializer_list<T> lst);
    ~Set();
    Set<T>& operator =(const Set<T>& lst);
    int get_length() const;
    bool contains(const T& elem);
    void add(const T& elem);
    void remove(const T& elem);
    T* to_array();
    Set<T>& union_1(const Set<T>& s);
    Set<T>& intersection(const Set<T>& s);
    Set<T>& subtract(const Set<T>& s);
    template<typename _T>
    friend std::ostream& operator <<(std::ostream& os, const Set<_T>& lst);
    Set<T>& operator +=(const Set<T>& s);
    Set<T>& operator *=(const Set<T>& s);
    Set<T>& operator /=(const Set<T>& s);
    template<typename _T>
    friend Set<_T> operator +(const Set<_T>& s1, const Set<_T>& s2);
    template<typename _T>
    friend Set<_T> operator *(const Set<_T>& s1, const Set<_T>& s2);
    template<typename _T>
    friend Set<_T> operator /(const Set<_T>& s1, const Set<T>& s2);

    Iterator<T> iterator_begin();
    Iterator<T> iterator_end();

    void clear();
};

#endif // SET_H
