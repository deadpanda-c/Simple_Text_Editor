#pragma once

#include <iostream>
#include <string>

#include <QString>

class ITextFormatter {
  public:
    virtual QString format(QString text) = 0;
    virtual ~ITextFormatter() = default;
};
