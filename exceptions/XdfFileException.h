#ifndef XDFCREATOR_XDFFILEEXCEPTION_H
#define XDFCREATOR_XDFFILEEXCEPTION_H


#include <stdexcept>
#include <string>

class XdfFileException : public std::runtime_error {
public:
    explicit XdfFileException(const std::string& message);
};


#endif //XDFCREATOR_XDFFILEEXCEPTION_H
