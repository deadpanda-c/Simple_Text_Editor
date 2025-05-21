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
        delete _menuBar;
        delete _fileMenu;
        delete _openAction;
        delete _saveAction;
        delete _exitAction;

        delete _textEdit;
      };

    private:
      void setupUi();
      void setupActions();
      void setupMenuBar();
      void setupToolBar();

      void fileOpen();
      void fileSave();

      QTextEdit *_textEdit;
      QMenuBar *_menuBar;
      QMenu *_fileMenu;
      QAction *_openAction;
      QAction *_saveAction;
      QAction *_exitAction;

  };
}

