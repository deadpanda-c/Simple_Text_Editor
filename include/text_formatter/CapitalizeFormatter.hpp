#pragma once

#include "ITextFormatter.hpp"

class CapitalizeFormatter : public ITextFormatter {
  public:
    std::string format(const std::string& text) override {
      if (text.empty()) return "";
      std::string result = text;
      result[0] = toupper(result[0]);
      for (size_t i = 1; i < result.size(); ++i)
        result[i] = tolower(result[i]);
      return result;
    }
};
