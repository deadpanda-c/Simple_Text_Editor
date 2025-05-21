#pragma once

#include "ITextFormatter.hpp"

class LowerCaseFormatter : public ITextFormatter {
  public:
    std::string format(const std::string& text) override {
      std::string result = text;
      for (char& c : result) c = tolower(c);
      return result;
    }
};
