# LibXDF

LibXDF parses and generates TunerPro XDF documents using the same concrete
object graph. Known tags become the existing `MMXDF*`, `MMEmbeddedData`,
`MMMath`, and `MMVar` classes. Unknown vendor tags remain generic `MMElement`
children and are retained when the document is written again.

## Parsing

```cpp
#include <XDFile.h>

dd::libxdf::XDFile file;
file.ReadFromDisk("definition.xdf");

using dd::libxdf::types::elements::MMXDFTable;
auto* table = dynamic_cast<MMXDFTable*>(
        file.GetRootTag().GetElementByName("XDFTABLE"));

if (table != nullptr) {
    auto* axis = table->GetAxis("z");
    auto* data = axis == nullptr ? nullptr : axis->GetEmbeddedData();
    if (data != nullptr) {
        const auto address = data->GetAddress();
        const auto elementSize = data->GetElementSizeBits();
    }
}

const auto diagnostics = file.Validate();
file.WriteToDisk("round-trip.xdf");
```

Malformed XML throws `XdfFileException`. Semantically unusual but common XDF
content, such as duplicate placeholder IDs or label-count mismatches, remains
loaded and is reported through `Validate()`.

## Generation

Existing constructors remain available. Passing a pointer to `AddElement`
transfers ownership to its parent.

```cpp
#include <XDFile.h>

using namespace dd::libxdf::types;
using namespace dd::libxdf::types::elements;

dd::libxdf::XDFile file;
file.AddElement(new MMXDFFlag(
        new MMEmbeddedData(0x100, 8),
        "Feature switch",
        "Enables the feature",
        0x01));

file.WriteToDisk("generated.xdf");
```

TinyXML2 is resolved through CMake. Tests exercise static and shared builds,
the concrete parsed object graph, validation, XML escaping, and round trips of
the XDF files under `examples/`.
