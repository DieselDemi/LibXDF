#include "../XDFile.h"

#include "MMElement.h"

#include <string>

//TODO(Demi): This has to move in order not to poision other libraries
#ifdef _WIN32

#include <format>
#include <utility>

#define format(arg, ...) std::format(arg, __VA_ARGS__)
#else
#include <memory>
template<typename ... Args>
std::string string_format( const std::string& format, Args ... args )
{
    int size_s = std::snprintf( nullptr, 0, format.c_str(), args ... ) + 1; // Extra space for '\0'
    if( size_s <= 0 ){ throw std::runtime_error( "Error during formatting." ); }
    auto size = static_cast<size_t>( size_s );
    std::unique_ptr<char[]> buf( new char[ size ] );
    std::snprintf( buf.get(), size, format.c_str(), args ... );
    return std::string( buf.get(), buf.get() + size - 1 ); // We don't want the '\0' inside
}
#define format(arg, ...) string_format(arg, __VA_ARGS__)
#endif


namespace dd::libxdf::types {

    MMElement::MMElement() {
        this->uniqueId = XDFile::NextUnique();
    }


    void MMElement::SetName(const std::string &newName) {
        this->name = newName;
    }

    void MMElement::AddElement(MMElement *element) {
        InsertElement(element);
    }

    void MMElement::AddAttribute(MMAttribute attribute) {
        InsertAttribute(std::move(attribute));
    }

    MMElement &MMElement::GetElement(const std::string &elementHexId) {
        return *this->children.find(elementHexId)->second;
    }

    MMAttribute &MMElement::GetAttribute(const std::string &attributeName) {
        return this->attributes.find(attributeName)->second;
    }

    uint64_t MMElement::GetUniqueId() const {
        return this->uniqueId;
    }

    std::string MMElement::GetUniqueHexId() const {
        return format("{:#x}", this->uniqueId);
    }

    void MMElement::InsertAttribute(const MMAttribute &attribute) {
        this->attributes.insert({attribute.name, attribute});
    }

    void MMElement::InsertElement(MMElement *element) {
        this->children.insert({element->GetUniqueHexId(), element});
    }

    void MMElement::SetUniqueId(uint64_t id) {
        this->uniqueId = id;
    }

    std::string MMElement::ToString() { // NOLINT(misc-no-recursion)
        std::stringstream toStringStream;

        toStringStream << "<" << this->name;

        if (!this->attributes.empty()) {
            for (auto &attribute: this->attributes) {
                toStringStream << " " << attribute.second.ToString();
            }
        }

        //Check if element is empty - if it is, quick close it.
        if (this->children.empty() && this->text.empty()) {
            toStringStream << "/>" << std::endl;
            return toStringStream.str();
        } else {
            toStringStream << ">";
            toStringStream << this->text;

            for (auto &element: this->children) {
                toStringStream << std::endl << element.second->ToString();
            }

            toStringStream << "</" << this->name << ">" << std::endl;
        }

        return toStringStream.str();
    }

    void MMElement::SetText(const std::string &newText) {
        this->text = newText;
    }

    MMElement::~MMElement() {
        //TODO(Demi): Implement destructor
    }


} // types