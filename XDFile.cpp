#include "XDFile.h"

#include <fstream>

namespace dd::libxdf {
    bool XDFile::WriteToDisk(const std::string& fileName) {
        std::ofstream file(fileName, std::ios::binary);

        if(!file.is_open())
            return false;

        file << documentRoot.ToString();

        return true;
    }

    void XDFile::RemoveElement(std::string& uid) {
        //TODO Implement this method
    }

    //TODO This is a big string to just pass lol
    std::string XDFile::Print() {
        return documentRoot.ToString();
    }

}
