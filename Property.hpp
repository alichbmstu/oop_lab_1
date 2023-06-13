#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include "set.hpp"

template<typename T>
class SetSizeProperty {
private:
    Set<T> set;
    size_t min_size;
    size_t max_size;

public:
    SetSizeProperty(Set<T> set, size_t min_size, size_t max_size)
        : set(set), min_size(min_size), max_size(max_size) {}

    int get() const {
        return set.get_length();
    }

    void setter(size_t new_size) {
        if (new_size < min_size || new_size > max_size) {
            std::cout << "The size should be in the range from " << min_size << " to " << max_size << std::endl;
        } else {
            if (new_size>=set.get_length()){
                while (set.get_length()!=new_size)
                    set.add(0);
            } else {
                Set <int> set_;
                for (int i = 0; i< new_size;i++)
                    set_.add(set[i]);
                set = set_;
            }
        }
    }
    template<typename T1>
    friend std::ostream &operator<<(std::ostream &os, SetSizeProperty<T1> &lst);
};


template<typename T>
std::ostream &operator<<(std::ostream &os, SetSizeProperty<T> &lst) {
    for (size_t i = 0; i < lst.set.get_length(); ++i) {
        os << lst.set[i] << " ";
    }
    return os;
}


#endif // PROPERTY_HPP
