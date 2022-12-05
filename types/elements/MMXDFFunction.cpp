#include "../../include/elements/MMXDFFunction.h"

namespace dd::libxdf::types::elements {
    MMXDFFunction::MMXDFFunction(
            std::string title,
            std::string description,
            std::initializer_list<MMXDFAxis *> axis
    ) : MMElement(
            "XDFFUNCTION",
            {
                    {.name="flags", .value="0x0"}
            },
            true
    ) {
        this->InsertElement(new MMElement("title", std::move(title)));
        this->InsertElement(new MMElement("description", std::move(description)));

        for (auto axi: axis) {
            this->InsertElement(static_cast<MMElement *>(axi));
        }
    }
}