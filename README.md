Example Usage: 

```c++
#include <iostream> 
#include <XDFTypes> 

int main(int argc, char** argv) { 
    
    dd::libxdf::types::elements::XDFRootTag rootTag;

    rootTag.AddElement(new dd::libxdf::types::elements::MMXDFHeader(
            dd::libxdf::types::elements::XDFHeaderFlags::UNKNOWN,
            0.f, //File Version
            "Example Title", //Title
            "Description", //Description
            "Author", //Author
            0, //Base offset, as an integer
            0, //Base offset subtraction as an integer
            {} //An initializer list of categories
    ));
    
    rootTag.AddElement(new dd::libxdf::types::elements::MMXDFFlag(
            new dd::libxdf::types::MMEmbeddedData(
                0 //Address
            ), //Embedded Data
            "Basic Flag",
            "Description", 
            0 //Mask value as uint8_t 
    ));
    
    std::cout << rootTag.ToString() << std::endl; 
    
    return 0; 
}
```