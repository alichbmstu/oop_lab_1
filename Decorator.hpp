#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include "set.hpp"

template<typename T>
class MultiSet : public Set<T> {

public:
    MultiSet() : Set<T>() {}

    MultiSet(const Set<T>& set) : Set<T>(set) {}

    void add(const T& elem) override {
        this->memory_alloc(); // Выделение памяти для нового элемента
        this->data[this->get_length()] = elem; // Добавление элемента в конец массива
        ++(this->length); // Увеличение длины
        this->sort(); // Сортировка элементов
    }

    int count(const T& value) const {
            int cnt = 0;
            for (int i = 0; i < this->get_length(); i++) {
                if (this->data[i] == value)
                    cnt++;
            }
            return cnt;
    }
};


#endif // DECORATOR_HPP
