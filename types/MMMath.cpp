#include "../include/MMMath.h"

#include <utility>

namespace dd::libxdf::types {
    MMMath::MMMath(std::string equation) :
            MMElement("MATH", {{.name="equation", .value=std::move(equation)}}) {

        for (const auto &equationVariable: GetAllVariables(equation)) {
            //TODO(Demi): The var's here can be linked to other XDF items via the unique id
            this->InsertElement(new MMElement("VAR", {{.name="id", .value=std::to_string(equationVariable)}}));
        }
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