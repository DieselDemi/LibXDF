Example Usage: 

```c++
#include <iostream> 
#include <XDFTypes> 

int main(int argc, char** argv) { 
    
    dd::libxdf::types::elements::XDFRootTag rootTag;

    rootTag.AddElement(new dd::libxdf::types::elements::MMXDFHeader(
            dd::libxdf::types::elements::HeaderFlags::UNKNOWN,
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
##Outputs
```html
<XDFFORMAT version="1.700000"><XDFHEADER><flags>1</flags>
	
<fileversion>0.000000</fileversion>
	
<deftitle>Example Title</deftitle>
	
<description>Description</description>
	
<author>Author</author>
	
<BASEOFFSET offset="TODO - offset value" subtract="TODO - subtract value"/>
	
<DEFAULTS datasizeinbits="8" float="0" lsbfirst="0" outputtype="1" sigdigits="2" signed="0"/>
	
<REGION desc="TODO - fix these attributes" name="TODO - fix these attributes" regioncolor="TODO - fix these attributes" regionflags="TODO - fix these attributes" size="TODO - fix these attributes" startaddress="TODO - fix these attributes" type="TODO - fix these attributes"/>
	
</XDFHEADER>
	
<XDFFLAG uniqueid="0x00000020"><EMBEDDEDDATA mmedaddress="0x0000" mmedelementsizebits="32" mmedmajorstridebits="0" mmedminorstridebits="0"/>
	
<title>Basic Flag</title>
	
<description>Description</description>
	
<mask>0x0</mask>
	
</XDFFLAG>
	
</XDFFORMAT>
```