#ifndef XDFCREATOR_XDFILE_H
#define XDFCREATOR_XDFILE_H

#include <string>
#include <atomic>
#include <ctime>
#include <map>
#include <utility>
#include <vector>

#include "elements/XDFRootTag.h"
#include "XDFTypes.h"
#include "../exceptions/XdfFileException.h"

namespace dd::libxdf {
    inline std::atomic_uint64_t unique{0};

    enum class DiagnosticSeverity {
        WARNING,
        ERROR
    };

    struct XDFDiagnostic {
        DiagnosticSeverity severity;
        std::string message;
        const types::MMElement* element;
    };

    class XDFile {
    public:
        //// Statics
        static uint64_t NextUnique() {
            return unique.fetch_add(1, std::memory_order_relaxed) + 1;
        };

        ///Templates
        template<typename T>
        void AddElement(T* element) {
            documentRoot.AddElement(element);
        }


        ///Standard member functions
        void RemoveElement(std::string&);
        void ReadFromDisk(const std::string& fileName);
        void ReadFromString(const std::string& xml);
        bool WriteToDisk(const std::string& fileName);
        [[nodiscard]] std::vector<XDFDiagnostic> Validate() const;
        types::elements::XDFRootTag& GetRootTag();
        const types::elements::XDFRootTag& GetRootTag() const;

        std::string Print();


    private:
        types::elements::XDFRootTag documentRoot;

    };
}


#endif //XDFCREATOR_XDFILE_H
