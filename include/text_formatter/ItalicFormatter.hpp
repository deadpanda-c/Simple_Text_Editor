#pragma once

#include "ITextFormatter.hpp"

class ItalicFormatter : public ITextFormatter
{
  public:

    QString format(QString text) override
    {
        return "<i>" + text + "</i>";
    }
};
