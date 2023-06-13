#ifndef SET_SET_HPP
#define SET_SET_HPP

#include "exceptions.hpp"

template <typename T>
class Base {
public:
    virtual void add(const T& value) = 0;
    virtual void sort() = 0;
    virtual void memory_alloc() = 0;
    //virtual bool contains(const T& value) const = 0;
    virtual int get_length() const = 0;
    virtual ~Base() {}
};

template<typename T>
class Iterator;

template<typename T>
class Set{
protected:
    T* data;
    size_t length;

public:

    Set();

    Set(const Set<T> &s);

    Set(Set<T> &&s);

    explicit Set(std::initializer_list<T> lst);

    ~Set();

    Set<T> &operator=(const Set<T> &lst);

    int get_length() const;

    bool contains(const T &elem) const;

    virtual void add(const T &elem);

    void remove(const T &elem);

    T *to_array();

    void memory_alloc();

    void sort();

    Set<T> &union_1(const Set<T> &s);

    Set<T> &intersection(const Set<T> &s);

    Set<T> &subtract(const Set<T> s);

    template<typename _T>
    friend std::ostream &operator<<(std::ostream &os, const Set<_T> &lst);

    Set<T> &operator+=(const Set<T> &s);

    Set<T> &operator*=(const Set<T> &s);

    Set<T> &operator/=(const Set<T> &s);

    template<typename _T>
    friend Set<_T> operator+(const Set<_T> &s1, const Set<_T> &s2);

    template<typename _T>
    friend Set<_T> operator*(const Set<_T> &s1, const Set<_T> &s2);

    template<typename _T>
    friend Set<_T> operator/(const Set<_T> &s1, const Set<_T> &s2);

    T &operator[](int index);

    Iterator<T> iterator_begin();

    Iterator<T> iterator_end();

    void clear();

};

template<typename T>
void Set<T>::memory_alloc() {
    if (data != nullptr) {
        try {
            T *new_data = new T[length+1];
            for (size_t i = 0; i < length; ++i) {
                new_data[i] = data[i];
            }
            //delete[] data;
            data = new_data;
        }
        catch (std::bad_alloc &ex) {
            throw Exceptions("Failed to allocate memory");
        }
    } else {
        try {
            data = new T[length];
        } catch (std::bad_alloc &ex) {
            throw Exceptions("Failed to allocate memory");
        }
    }
}

template<typename T>
Set<T>::Set() : data(nullptr), length(0) {}

template<typename T>
Set<T>::Set(const Set<T> &s) : data(nullptr), length(s.length) {
    if (length == 0) {
        throw Exceptions("Incorrect length of choosen set");
    }
    memory_alloc();
    for (size_t i = 0; i < length; ++i) {
        data[i] = s.data[i];
    }
    sort();
}

template<typename T>
Set<T>::Set(Set<T> &&s) : data(s.data), length(s.length) {
    if (length == 0) {
        throw Exceptions("Incorrect length of choosen set");
    }
    s.data = nullptr;
    s.length = 0;
    sort();
}

template<typename T>
Set<T>::Set(std::initializer_list<T> lst) : data(nullptr), length(0) {
    for (const T &elem: lst) {
        add(elem);
    }
    sort();
}

template<typename T>
Set<T>::~Set() {
    if (data!=nullptr)
        delete[] data;
    length = 0;
}

template<typename T>
Set<T> &Set<T>::operator=(const Set<T> &s) {
    if (this != &s) {
        //delete[] data;
        length = s.length;
        memory_alloc();
        for (size_t i = 0; i < length; ++i)
            data[i] = s.data[i];
    }
    return *this;
}

template<typename T>
int Set<T>::get_length() const {
    return length;
}

template<typename T>
bool Set<T>::contains(const T &elem) const {
    for (size_t i = 0; i < length; ++i) {
        if (data[i] == elem) {
            return true;
        }
    }
    return false;
}

template<typename T>
void Set<T>::add(const T &elem) {
    if (!contains(elem)) {
        memory_alloc();
        data[length] = elem;
        ++length;
    }
    sort();
}

template<typename T>
void Set<T>::remove(const T &elem) {
    int cur = length;
    if (!contains(elem)) {
        throw Exceptions("This element is not in the set");
    }
    T *new_data = new T[length - 1];
    size_t j = 0;
    for (size_t i = 0; i < length; ++i) {
        if (data[i] != elem) {
            new_data[j] = data[i];
            ++j;
        } else {
            cur--;
        }
    }
    delete[] data;
    data = new_data;
    length=cur;
}

template<typename T>
T *Set<T>::to_array() {
    if (data == nullptr) {
        throw Exceptions("Data is null");
    }
    try {
        T *arr = new T[length];
        for (size_t i = 0; i < length; ++i) {
            arr[i] = data[i];
        }
        return arr;
    } catch (std::bad_alloc &ex) {
        throw Exceptions("Failed to allocate memory");
    }
}

template<typename T>
Set<T> &Set<T>::union_1(const Set<T> &s) {
    for (size_t i = 0; i < s.length; ++i) {
        add(s.data[i]);
    }
    return *this;
}

template<typename T>
Set<T> &Set<T>::intersection(const Set<T> &s) {
    Set<T> result;
    for (size_t i = 0; i < length; ++i) {
        if (s.contains(data[i])) {
            result.add(data[i]);
        }
    }
    *this = result;
    return *this;
}

template<typename T>
Set<T> &Set<T>::subtract(const Set<T> s) {
    Set<T> result{};
    for (size_t i = 0; i < length; ++i) {
        if (!s.contains(data[i])) {
            result.add(data[i]);
        }
    }
    for (size_t i = 0; i < s.length; ++i) {
        if (!contains(s.data[i])) {
            result.add(s.data[i]);
        }
    }
    *this = result;
    return *this;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Set<T> &lst) {
    for (size_t i = 0; i < lst.length; ++i) {
        os << lst.data[i] << " ";
    }
    return os;
}

template<typename T>
Set<T> &Set<T>::operator+=(const Set<T> &s) {
    union_1(s);
    return *this;
}

template<typename T>
Set<T> &Set<T>::operator*=(const Set<T> &s) {
    intersection(s);
    return *this;
}

template<typename T>
Set<T> &Set<T>::operator/=(const Set<T> &s) {
    subtract(s);
    return *this;
}

template<typename T>
Set<T> operator+(const Set<T> &s1, const Set<T> &s2) {
    Set<T> result = s1;
    result += s2;
    return result;
}

template<typename T>
Set<T> operator*(const Set<T> &s1, const Set<T> &s2) {
    Set<T> result = s1;
    result *= s2;
    return result;
}

template<typename T>
Set<T> operator/(const Set<T> &s1, const Set<T> &s2) {
    Set<T> result = s1;
    result /= s2;
    return result;
}

template<typename T>
Iterator<T> Set<T>::iterator_begin() {
    return Iterator<T>(*this, 0);
}

template<typename T>
Iterator<T> Set<T>::iterator_end() {
    return Iterator<T>(*this, length);
}

template<typename T>
void Set<T>::clear() {
    delete[] data;
    data = nullptr;
    length = 0;
}

template<typename T>
T &Set<T>::operator[](int index) {
    if (index < 0 || index >= length) {
        throw Exceptions("Incorrect index.");
    }
    return data[index];
}

template<typename T>
void Set<T>::sort() {
    for (size_t i = 0;i < length; ++i){
        for (size_t j = 0; j < length; ++j){
            if (data[i] < data[j]){
                T cur = data[i];
                data[i] = data[j];
                data[j] = cur;
            }
        }
    }
}

#endif //SET_SET_HPP
