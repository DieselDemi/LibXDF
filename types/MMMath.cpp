#include "../include/MMMath.h"
#include "../crossplatform/XdfStringFormat.h"

#include <algorithm>
#include <charconv>
#include <cctype>
#include <utility>

namespace dd::libxdf::types {
    MMMath::MMMath(ParsedTag) : MMElement("MATH", enums::ElementType::MATH) {}

    MMVar::MMVar(ParsedTag) : MMElement("VAR", enums::ElementType::VAR) {}

    MMMath::MMMath(std::string equation) :
            MMElement("MATH", enums::ElementType::MATH, {{.name="equation", .value=equation}}) {

        for (const auto &equationVariable: GetAllVariables(equation)) {
            this->InsertElement(new MMVar(equationVariable));
        }
    }

    MMMath::MMMath(std::string equation, std::initializer_list<MMVar> variables) :
            MMElement("MATH", enums::ElementType::MATH, {{.name="equation", .value=equation}})
    {
        for (auto &var: variables) {
            this->InsertElement(new MMVar(var.GetVariable(), var.GetLinkId()));
        }
    }

    MMVar::MMVar(char variable) :
            MMElement("VAR", enums::ElementType::VAR, {{.name="id", .value=std::string(1, variable)}}),
            variable(variable)
    { }

    //      <VAR id="X" type="link" linkid="0x394C" />
    MMVar::MMVar(char variable, uint64_t linkId) :
            MMElement("VAR", enums::ElementType::VAR, {
                {.name="id", .value=std::string(1, variable)},
                {.name="type", .value="link"},
                {.name="linkid", .value=format(":#x", linkId)}
            }),
            linkId(linkId),
            variable(variable)
    { }

    uint64_t MMVar::GetLinkId() const {
        const auto* attribute = FindAttribute("linkid");
        if (attribute == nullptr) return this->linkId;

        std::string_view value = attribute->value;
        if (value.starts_with("0x") || value.starts_with("0X")) value.remove_prefix(2);
        uint64_t result{};
        const auto parsed = std::from_chars(value.data(), value.data() + value.size(), result, 16);
        return parsed.ec == std::errc{} && parsed.ptr == value.data() + value.size() ? result : 0;
    }

    char MMVar::GetVariable() const {
        const auto id = GetVariableId();
        return id.empty() ? this->variable : id.front();
    }

    std::string MMVar::GetVariableId() const {
        const auto* attribute = FindAttribute("id");
        return attribute == nullptr ? std::string{} : attribute->value;
    }

    std::string MMVar::GetVariableType() const {
        const auto* attribute = FindAttribute("type");
        return attribute == nullptr ? std::string{} : attribute->value;
    }

    std::optional<uint64_t> MMVar::GetAddress() const {
        const auto* attribute = FindAttribute("address");
        if (attribute == nullptr) return std::nullopt;
        std::string_view value = attribute->value;
        if (value.starts_with("0x") || value.starts_with("0X")) value.remove_prefix(2);
        uint64_t result{};
        const auto parsed = std::from_chars(value.data(), value.data() + value.size(), result, 16);
        if (parsed.ec != std::errc{} || parsed.ptr != value.data() + value.size()) return std::nullopt;
        return result;
    }

    std::string MMMath::GetEquation() const {
        const auto* attribute = FindAttribute("equation");
        return attribute == nullptr ? std::string{} : attribute->value;
    }

    std::vector<MMVar*> MMMath::GetVariables() {
        std::vector<MMVar*> variables;
        for (auto* child : GetAllElements()) {
            if (auto* variable = dynamic_cast<MMVar*>(child)) variables.push_back(variable);
        }
        return variables;
    }

    std::vector<char> MMMath::GetAllVariables(const std::string &equation) {
        std::vector<char> variables;
        for (const char character : equation) {
            if (std::isalpha(static_cast<unsigned char>(character)) &&
                std::find(variables.begin(), variables.end(), character) == variables.end()) {
                variables.push_back(character);
            }
        }
        return variables;
    }
} // types
