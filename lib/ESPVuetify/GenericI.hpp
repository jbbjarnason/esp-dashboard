#pragma once

namespace ESPVuetify {

class GenericI {
public:
    virtual ~GenericI() {
        onDestruct_();
    }
    [[nodiscard]] virtual std::string_view getName() const noexcept = 0;
    void setOnDestruct(const std::function<void()>& onDestruct) {
        onDestruct_ = onDestruct;
    }
private:
    std::function<void()> onDestruct_{ [](){} };
};

}
