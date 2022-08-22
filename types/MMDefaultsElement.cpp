#include "MMDefaultsElement.h"

namespace dd::libxdf::types {
    MMDefaultsElement::MMDefaultsElement(
            uint32_t dataSizeInBits,
            uint8_t sigDigits,
            uint8_t outputType,
            uint8_t signedValue,
            uint8_t lsbFirst,
            uint8_t floatValue
    ) : MMElement("DEFAULTS", {
            {.name="datasizeinbits", .value=std::to_string(dataSizeInBits)},
            {.name="sigdigits", .value=std::to_string(sigDigits)},
            {.name="outputtype", .value=std::to_string(outputType)},
            {.name="signed", .value=std::to_string(signedValue)},
            {.name="lsbfirst", .value=std::to_string(lsbFirst)},
            {.name="float", .value=std::to_string(floatValue)}
    })
    { /** nothing to do here **/ }
} // types