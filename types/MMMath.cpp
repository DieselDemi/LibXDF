#include "../include/MMMath.h"
#include "../crossplatform/XdfStringFormat.h"

#include <utility>

namespace dd::libxdf::types {
    MMMath::MMMath(std::string equation) :
            MMElement("MATH", enums::ElementType::MATH, {{.name="equation", .value=std::move(equation)}}) {

        for (const auto &equationVariable: GetAllVariables(equation)) {
            this->InsertElement(new MMVar(equationVariable));
        }
    }

    MMMath::MMMath(std::string equation, std::initializer_list<MMVar> variables) :
            MMElement("MATH", enums::ElementType::MATH, {{.name="equation", .value=std::move(equation)}})
    {
        for (auto &var: variables) {
            this->InsertElement(new MMVar(var.GetVariable(), var.GetLinkId()));
        }
    }

    MMVar::MMVar(char variable) :
            MMElement("VAR", enums::ElementType::VAR, {{.name="id", .value=std::to_string(variable)}}),
            variable(variable)
    { }

    //      <VAR id="X" type="link" linkid="0x394C" />
    MMVar::MMVar(char variable, uint64_t linkId) :
            MMElement("VAR", enums::ElementType::VAR, {
                {.name="id", .value=std::to_string(variable)},
                {.name="type", .value="link"},
                {.name="linkid", .value=format(":#x", linkId)}
            }),
            linkId(linkId),
            variable(variable)
    { }

    uint64_t MMVar::GetLinkId() const {
        return this->linkId;
    }

    char MMVar::GetVariable() const {
        return this->variable;
    }

    std::vector<char> MMMath::GetAllVariables(std::string &equation) {
        //Remove all the whitespace and iterators
        equation.erase(std::remove_if(equation.begin(), equation.end(), [](char c) {
            return c == '+' ||
                   c == '-' ||
                   c == '*' ||
                   c == '/' ||
                   c == '(' ||
                   c == ')' ||
                   ::isspace(c);
        }), equation.end());

        //Now take return the remaining characters
        return {equation.begin(), equation.end()};
    }
} // types