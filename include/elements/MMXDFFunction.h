#ifndef XDFCREATOR_MMXDFFUNCTION_H
#define XDFCREATOR_MMXDFFUNCTION_H

#include "../MMElement.h"
#include "MMXDFAxis.h"

namespace dd::libxdf::types::elements {

    class MMXDFFunction : public MMElement {
    public:
        explicit MMXDFFunction(ParsedTag);
        explicit MMXDFFunction(std::string title, std::string description, std::initializer_list<MMXDFAxis*> axis);
        [[nodiscard]] std::vector<MMXDFAxis*> GetAxes();
        [[nodiscard]] MMXDFAxis* GetAxis(const std::string& axisId);
    };

} // elements

#endif //XDFCREATOR_MMXDFFUNCTION_H
