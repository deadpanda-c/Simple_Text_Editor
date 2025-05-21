#pragma once

#include "ITextFormatter.hpp"

class UpperCaseFormatter : public ITextFormatter {
public:
    std::string format(const std::string& text) override {
        std::string result = text;
        for (char& c : result) c = toupper(c);
        return result;
    }
};

