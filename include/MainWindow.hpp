#pragma once

#include <iostream>

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

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

      void fileOpen();
      void fileSave();

      QTextEdit *_textEdit;
      QMenuBar *_menuBar;

  };
}

