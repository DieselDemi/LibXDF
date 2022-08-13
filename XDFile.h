#ifndef XDFCREATOR_XDFILE_H
#define XDFCREATOR_XDFILE_H

#include <string>
#include <ctime>
#include <map>
#include <utility>
#include <vector>
#include <fileio/file.h>

#include "types/elements/XDFRootTag.h"

namespace dd::libxdf {
    static uint64_t unique;

    class XDFile {

    public:
        //// Statics
        static uint64_t NextUnique() {
            return ++unique;
        };

        ///Templates
        template<typename T>
        void AddElement(T* element) {
            documentRoot.AddElement(element);
        }

        ///Standard member functions
        void RemoveElement(std::string&);
        bool WriteToDisk(const std::string& fileName);
        std::string Print();


    private:
        types::elements::XDFRootTag documentRoot;

    };
}


#endif //XDFCREATOR_XDFILE_H
