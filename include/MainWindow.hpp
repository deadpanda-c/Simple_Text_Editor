#pragma once

#include <iostream>

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>

namespace ui {
  class MainWindow : public QWidget
  {
    public:
      MainWindow(QWidget *parent = nullptr);
      virtual ~MainWindow() {};

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

