#ifndef XDFCREATOR_MMMATH_H
#define XDFCREATOR_MMMATH_H

#include "MMElement.h"

namespace dd::libxdf::types {
    class MMVar : public MMElement {
    public:
        explicit MMVar(char variable);
        explicit MMVar(char variable, uint64_t linkId);

        [[nodiscard]]
        uint64_t GetLinkId() const;

        [[nodiscard]]
        char GetVariable() const;

    private:
        uint64_t linkId = 0;
        char variable = '\0';
    };

    class MMMath : public MMElement {
    public:
        explicit MMMath(std::string equation);
        explicit MMMath(std::string equation, std::initializer_list<MMVar> variables);
    private:
        static std::vector<char> GetAllVariables(std::string& equation);
    };

} // types

#endif //XDFCREATOR_MMMATH_H
