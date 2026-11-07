#include "../include/MMAttribute.h"

namespace dd::libxdf::types {
    namespace {
        std::string EscapeAttribute(const std::string& value) {
            std::string escaped;
            escaped.reserve(value.size());

            for (const char character : value) {
                switch (character) {
                    case '&': escaped += "&amp;"; break;
                    case '<': escaped += "&lt;"; break;
                    case '>': escaped += "&gt;"; break;
                    case '"': escaped += "&quot;"; break;
                    case '\'': escaped += "&apos;"; break;
                    default: escaped += character; break;
                }
            }

            return escaped;
        }
    }

    std::string MMAttribute::ToString() const {
        std::stringstream output_stream;

        output_stream << name << "=\"" << EscapeAttribute(value) << "\"";

        return output_stream.str();
    }

} // types
