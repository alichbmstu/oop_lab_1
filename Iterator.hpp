#ifndef SET_ITERATOR_HPP
#define SET_ITERATOR_HPP

#include "set.hpp"

template <typename T>
class Iterator {
private:
    T* element;
public:
    Iterator<T>(Set<T> container_obj) : element(container_obj.to_array()) {}

    Iterator<T> next() {
        ++element;
        return *this;
    }

    T value() {
        return *element;
    }

    bool is_end() {
        // Проверяем, достигли ли конца контейнера (nullptr)
        return *element == nullptr;
    }

    Iterator<T>& operator++() {
        ++element;
        return *this;
    }

    T& operator*() {
        return *element;
    }

    bool operator==(Iterator<T>& b) {
        return element == b.element;
    }

    bool operator!=(Iterator<T>& b) {
        return !(*this == b);
    }
};


#endif //SET_ITERATOR_HPP
