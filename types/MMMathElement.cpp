#include "MMMathElement.h"

#include <utility>

namespace dd::libxdf::types {
    MMMathElement::MMMathElement(std::string equation) {
        this->name = "MATH";
        this->InsertAttribute({.name="equation", .value=std::move(equation)});

        auto* mathVarElement = new MMElement();
        mathVarElement->SetName("VAR");
        mathVarElement->AddAttribute({.name="id", .value="X"});
        this->InsertElement(mathVarElement);
    }
} // types