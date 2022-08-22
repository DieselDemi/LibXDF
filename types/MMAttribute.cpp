#include "MMAttribute.h"

namespace dd::libxdf::types {
    std::string MMAttribute::ToString() const {
        std::stringstream output_stream;

        output_stream << name << "=\"" << value << "\"";

        return output_stream.str();
    }

} // types