#ifndef XDFCREATOR_MMATTRIBUTE_H
#define XDFCREATOR_MMATTRIBUTE_H

#include <string>
#include <sstream>
#include <utility>

namespace dd::libxdf::types {
    class MMAttribute {
    public:
        [[nodiscard]] std::string ToString() const;
        std::string name;
        std::string value;
    };

} // types

#endif //XDFCREATOR_MMATTRIBUTE_H
