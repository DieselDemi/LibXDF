#include "XdfFileException.h"

XdfFileException::XdfFileException(const std::string& message) : std::runtime_error(message) {}
