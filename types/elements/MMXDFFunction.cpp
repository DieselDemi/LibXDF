#include "../../include/elements/MMXDFFunction.h"

namespace dd::libxdf::types::elements {
    MMXDFFunction::MMXDFFunction(ParsedTag) : MMElement("XDFFUNCTION", enums::ElementType::FUNCTION) {}

    MMXDFFunction::MMXDFFunction(
            std::string title,
            std::string description,
            std::initializer_list<MMXDFAxis *> axis
    ) : MMElement(
            "XDFFUNCTION", enums::ElementType::FUNCTION,
            {
                    {.name="flags", .value="0x0"}
            },
            true
    ) {
        this->InsertElement(new MMElement("title", enums::ElementType::GENERIC, std::move(title)));
        this->InsertElement(new MMElement("description", enums::ElementType::GENERIC, std::move(description)));

        for (auto axi: axis) {
            this->InsertElement(static_cast<MMElement *>(axi));
        }
    }

    std::vector<MMXDFAxis*> MMXDFFunction::GetAxes() {
        std::vector<MMXDFAxis*> axes;
        for (auto* element : GetElementsByName("XDFAXIS")) {
            if (auto* axis = dynamic_cast<MMXDFAxis*>(element)) axes.push_back(axis);
        }
        return axes;
    }

    MMXDFAxis* MMXDFFunction::GetAxis(const std::string& axisId) {
        for (auto* axis : GetAxes()) {
            if (axis->GetAxisId() == axisId) return axis;
        }
        return nullptr;
    }
}
