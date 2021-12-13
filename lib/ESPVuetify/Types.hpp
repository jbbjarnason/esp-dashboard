#pragma once
#include <string>
#include <variant>
#include <functional>

namespace ESPVuetify {

typedef std::variant<bool, int, double, std::string> SupportedTypes;
typedef std::function<void(const SupportedTypes&)> Callback;

}