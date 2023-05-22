#include "exceptions.hpp"

std::ostream& operator <<(std::ostream& out, Exceptions mistake) {
    out << "Error has occurred: " << mistake.problem << std::endl;
    return out;
}
