#ifndef XDFCREATOR_MMXDFTABLE_H
#define XDFCREATOR_MMXDFTABLE_H

#include "../MMElement.h"
#include "MMXDFAxis.h"

namespace dd::libxdf::types::elements {

    class MMXDFTable : public MMElement {
    public:
        explicit MMXDFTable(ParsedTag);
        explicit MMXDFTable(std::string title,  std::string description, std::initializer_list<MMXDFAxis*> axis);
        explicit MMXDFTable(std::string title,  std::string description, const std::vector<MMXDFAxis*>& axis);
        [[nodiscard]] std::vector<MMXDFAxis*> GetAxes();
        [[nodiscard]] MMXDFAxis* GetAxis(const std::string& axisId);
    };

} // elements

#endif //XDFCREATOR_MMXDFTABLE_H
