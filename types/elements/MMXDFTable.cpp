#include "../../include/elements/MMXDFTable.h"

namespace dd::libxdf::types::elements {
    MMXDFTable::MMXDFTable(ParsedTag) : MMElement("XDFTABLE", enums::ElementType::TABLE) {}

    MMXDFTable::MMXDFTable(
            std::string title,
            std::string description,
            std::initializer_list<MMXDFAxis*> axis
    ) : MMElement("XDFTABLE", enums::ElementType::TABLE, {}, true)
    {
        this->InsertElement(new MMElement("title", enums::ElementType::GENERIC, std::move(title)));
        this->InsertElement(new MMElement("description", enums::ElementType::GENERIC, std::move(description)));

        for(auto axi : axis) {
            this->InsertElement(static_cast<MMElement*>(axi));
        }
    }

    MMXDFTable::MMXDFTable(
            std::string title,
            std::string description,
            const std::vector<MMXDFAxis*>& axis
    ) : MMElement("XDFTABLE", enums::ElementType::TABLE, {}, true)
    {
        this->InsertElement(new MMElement("title", enums::ElementType::GENERIC, std::move(title)));
        this->InsertElement(new MMElement("description", enums::ElementType::GENERIC, std::move(description)));

        for(auto axi : axis) {
            this->InsertElement(static_cast<MMElement*>(axi));
        }
    }

    std::vector<MMXDFAxis*> MMXDFTable::GetAxes() {
        std::vector<MMXDFAxis*> axes;
        for (auto* element : GetElementsByName("XDFAXIS")) {
            if (auto* axis = dynamic_cast<MMXDFAxis*>(element)) axes.push_back(axis);
        }
        return axes;
    }

    MMXDFAxis* MMXDFTable::GetAxis(const std::string& axisId) {
        for (auto* axis : GetAxes()) {
            if (axis->GetAxisId() == axisId) return axis;
        }
        return nullptr;
    }
}
