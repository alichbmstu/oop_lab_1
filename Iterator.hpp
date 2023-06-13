#ifndef SET_ITERATOR_HPP
#define SET_ITERATOR_HPP

#include "set.hpp"

template<typename T>
class Iterator {
private:
    Set<T> set;
    size_t index;

public:
    explicit Iterator(const Set<T>& set) : set(set), index(0) {}

    explicit Iterator(const Set<T>& set, size_t index) : set(set), index(index) {}

    Iterator<T> next() {
        if (index >= set.get_length()) {
            throw Exceptions("It is already the end of the set! There is no place to move!");
        }
        return Iterator<T>(set, index + 1);
    }

    T& value() {
        if (index >= set.get_length()) {
            throw Exceptions("It is the end of the set");
        }
        return set[index];
    }

    bool is_end() {
        return index >= set.get_length();
    }

    Iterator<T>& operator++() {
        ++index;
        return *this;
    }

    bool operator==(const Iterator<T>& other) const {
        return &set == &other.set && index == other.index;
    }

    bool operator!=(const Iterator<T>& other) const {
        return (*this != other);
    }
};




#endif //SET_ITERATOR_HPP


