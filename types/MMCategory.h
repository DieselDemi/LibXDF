#ifndef XDFCREATOR_MMCATEGORY_H
#define XDFCREATOR_MMCATEGORY_H

#include "MMElement.h"

namespace dd::libxdf::types {

    class MMCategory : public MMElement {
    public:
        MMCategory(std::string name, uint16_t index);
    private:
        uint32_t index;
    };

} // types

#endif //XDFCREATOR_MMCATEGORY_H
