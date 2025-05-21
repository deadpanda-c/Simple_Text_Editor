#pragma once

#include <iostream>
#include <string>
#include <stdbool.h>

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
#include <QTextCursor>

#include "Logging.hpp"

#include "text_formatter/BoldFormatter.hpp"
#include "text_formatter/ItalicFormatter.hpp"
#include "text_formatter/UnderlineFormatter.hpp"
#include "text_formatter/PlainFormatter.hpp"

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

      void resetTextFormat();
      void applyBoldFormatter();
      void applyItalicFormatter();
      void applyUnderlineFormatter();

      QTextEdit *_textEdit;
      QMenuBar *_menuBar;
      QMenu *_fileMenu;
      QAction *_openAction;
      QAction *_saveAction;
      QAction *_exitAction;

      QAction *_boldAction;
      QAction *_italicAction;
      QAction *_underlineAction;

      bool _isBold;
      bool _isItalic;
      bool _isUnderline;

  };
}

