#pragma once

#include "ITextFormatter.hpp"

#include <string>
#include <QWidget>
#include <QString>

class BoldFormatter : public ITextFormatter
{
  public:

    QString format(QString text) override
    {
      return "<b>" + text + "</b>";
    }
};
