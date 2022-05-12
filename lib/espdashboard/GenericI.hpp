#pragma once
#include <string_view>
#include <functional>

#include "json.hpp"


namespace ESPVuetify {

class GenericI {
public:
    virtual ~GenericI() {
        onDestruct_();
    }
    [[nodiscard]] virtual std::string_view getTagName() const noexcept = 0;
    void setOnDestruct(const std::function<void()>& onDestruct) {
        onDestruct_ = onDestruct;
    }
private:
    std::function<void()> onDestruct_{ [](){} };
};

static void to_json(nlohmann::json& j, const GenericI& genericI) {
    j["tagName"] = genericI.getTagName();
}

}
