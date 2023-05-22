#include "Iterator.hpp"

int main() {
    Set<int> a{1, 1, 2, 3, 4, 9, 5};
    Set<int> b{3, 4, 12};
    std::cout << a.get_length() << std::endl;
    Set<int> c = a.intersection(b);
    std::cout << c << std::endl;
    //std::cout << c.get_length() << std::endl;
    return 0;
}
