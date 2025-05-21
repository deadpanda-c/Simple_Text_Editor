#pragma once

#include "ITextFormatter.hpp"

class UnderlineFormatter : public ITextFormatter
{
  public:
    QString format(QString text) override
    {
        return "<u>" + text + "</u>";
    }
};
