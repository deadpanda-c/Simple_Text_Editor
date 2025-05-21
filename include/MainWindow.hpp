#pragma once

#include <iostream>

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>

#include "Logging.hpp"

namespace ui {
  class MainWindow : public QWidget
  {
    public:
      MainWindow(QWidget *parent = nullptr);
      virtual ~MainWindow() {
        delete _textEdit;
      };

    private slots:
      void sayHello();

    private:
      void setupUi();
      void setupActions();
      void setupMenuBar();
      void setupToolBar();

      QTextEdit *_textEdit;

  };
}

