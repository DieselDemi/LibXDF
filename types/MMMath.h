#ifndef XDFCREATOR_MMMATH_H
#define XDFCREATOR_MMMATH_H

#include "MMElement.h"

namespace dd::libxdf::types {

    class MMMath : public MMElement {
    public:
        MMMath(std::string equation);
    private:
        std::vector<char> GetAllVariables(std::string& equation);
    };

} // types

#endif //XDFCREATOR_MMMATH_H
