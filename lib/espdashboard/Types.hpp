#pragma once
#include <string>
#include <variant>
#include <functional>

namespace ESPVuetify {

typedef std::variant<bool, int, double, std::string> PropType;
typedef std::variant<bool, int, double, std::string, std::vector<int>> ValueType;
typedef std::function<void(const ValueType&)> Callback;

}