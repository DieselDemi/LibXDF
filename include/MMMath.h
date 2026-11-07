#ifndef XDFCREATOR_MMMATH_H
#define XDFCREATOR_MMMATH_H

#include "MMElement.h"
#include <optional>

namespace dd::libxdf::types {
    class MMVar : public MMElement {
    public:
        explicit MMVar(ParsedTag);
        explicit MMVar(char variable);
        explicit MMVar(char variable, uint64_t linkId);

        [[nodiscard]]
        uint64_t GetLinkId() const;

        [[nodiscard]]
        char GetVariable() const;

        [[nodiscard]] std::string GetVariableId() const;
        [[nodiscard]] std::string GetVariableType() const;
        [[nodiscard]] std::optional<uint64_t> GetAddress() const;

    private:
        uint64_t linkId = 0;
        char variable = '\0';
    };

    class MMMath : public MMElement {
    public:
        explicit MMMath(ParsedTag);
        explicit MMMath(std::string equation);
        explicit MMMath(std::string equation, std::initializer_list<MMVar> variables);
        [[nodiscard]] std::string GetEquation() const;
        [[nodiscard]] std::vector<MMVar*> GetVariables();
    private:
        static std::vector<char> GetAllVariables(const std::string& equation);
    };

} // types

#endif //XDFCREATOR_MMMATH_H
