#pragma once

#include <iostream>
#include <string>

class ITextFormatter {
  public:
    virtual std::string format(const std::string &text) = 0;
    virtual ~ITextFormatter() = default;
};
