#pragma once

#include "ITextFormatter.hpp"

class PlainFormatter : public ITextFormatter {
public:
    QString format(QString text) override {
        return text.toHtmlEscaped(); // Just escape HTML, no formatting
    }
};
