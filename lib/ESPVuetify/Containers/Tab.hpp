#pragma once
#include <memory>
#include <string_view>

#include "ContainerI.hpp"

namespace ESPVuetify {

class Tab : public ContainerI {
public:
    static constexpr auto name{ "v-tab" };
    [[nodiscard]] std::string_view getTagName() const noexcept override {
        return name;
    }

    void setName(std::string_view newName) {
        name_ = newName;
    }
    [[nodiscard]] std::string_view getName() const noexcept {
        return name_;
    }
    void setHeader(std::string_view header) {
        header_ = header;
    }
    [[nodiscard]] std::string_view getHeader() const noexcept {
        return header_;
    }
    void setNavbar(std::string_view navbar) {
        navbar_ = navbar;
    }
    [[nodiscard]] std::string_view getNavbar() const noexcept {
        return navbar_;
    }

private:
    std::string_view name_;
    std::string_view header_;
    std::string_view navbar_;
};

static void to_json(nlohmann::json& j, const Tab& tab) {
    nlohmann::json obj;
    // Todo: duplicated code
    to_json(obj["containers"], tab.getContainers());
    to_json(obj["components"], tab.getComponents());
    to_json(obj, (const GenericI&) tab);
    to_json(obj, (const GenID&) tab);
    obj["name"] = tab.getName();
    obj["header"] = tab.getHeader();
    obj["navbar"] = tab.getNavbar();
    j.push_back(obj);
}

}
