#ifndef SET_EXCEPTIONS_HPP
#define SET_EXCEPTIONS_HPP

#include <iostream>

class Exceptions {
    std::string problem;
public:
    explicit Exceptions(std::string text) { problem = std::move(text);}
    friend std::ostream& operator <<(std::ostream& out, Exceptions mistake);
};

#endif //SET_EXCEPTIONS_HPP
