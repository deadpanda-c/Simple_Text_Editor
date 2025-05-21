#include "MainWindow.hpp"

ui::MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
  _isBold = false; // Initialize the bold state
  _isItalic = false; // Initialize the italic state
  _isUnderline = false; // Initialize the underline state
  _textEdit = new QTextEdit(this); // Create the text editor
  _menuBar = new QMenuBar(this); // Create the menu bar

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->addWidget(_menuBar);
  layout->addWidget(_textEdit);
  setLayout(layout);

  setupUi();
  setupActions();
  setupMenuBar();
  setupToolBar();
}

void ui::MainWindow::setupUi()
{
    setWindowTitle("Text Editor");
    resize(800, 600);
    Logging::Log("MainWindow: Graphical user interface initialized.");
}

void ui::MainWindow::setupActions()
{
  _boldAction = new QAction("Bold", this);
  _italicAction = new QAction("Italic", this);
  _underlineAction = new QAction("Underline", this);

  // add shortcuts
  _boldAction->setShortcut(QKeySequence("Ctrl+B"));
  _italicAction->setShortcut(QKeySequence("Ctrl+I"));
  _underlineAction->setShortcut(QKeySequence("Ctrl+U"));

  connect(_boldAction, &QAction::triggered, this, [this]() {
    if (_isBold) {
      resetTextFormat();
    } else {
      applyBoldFormatter();
    }
  });

  connect(_italicAction, &QAction::triggered, this, [this]() {
    if (_isItalic) {
      resetTextFormat();
    } else {
      applyItalicFormatter();
    }
  });

  connect(_underlineAction, &QAction::triggered, this, [this]() {
    if (_isUnderline) {
      resetTextFormat();
    } else {
      applyUnderlineFormatter();
    }
  });

  // Add actions to the menu bare
  _menuBar->addAction(_boldAction);
  _menuBar->addAction(_italicAction);
  _menuBar->addAction(_underlineAction);
  Logging::Log("MainWindow: Actions initialized.");
}

void ui::MainWindow::setupMenuBar()
{
  _fileMenu = new QMenu("File", this);
  _openAction = new QAction("Open", this);
  _saveAction = new QAction("Save", this);
  _exitAction = new QAction("Exit", this);

  // add shortcuts
  _openAction->setShortcut(QKeySequence::Open);
  _saveAction->setShortcut(QKeySequence::Save);
  _exitAction->setShortcut(QKeySequence::Quit);

  connect(_openAction, &QAction::triggered, this, &MainWindow::fileOpen);
  connect(_saveAction, &QAction::triggered, this, &MainWindow::fileSave);
  connect(_exitAction, &QAction::triggered, this, &QWidget::close);

  _fileMenu->addAction(_openAction);
  _fileMenu->addAction(_saveAction);
  _fileMenu->addSeparator();
  _fileMenu->addAction(_exitAction);

  _menuBar->addMenu(_fileMenu);
  Logging::Log("MainWindow: Menu bar initialized.");
}

void ui::MainWindow::setupToolBar()
{
  Logging::Log("MainWindow: Tool bar initialized.");
}

void ui::MainWindow::fileOpen()
{
  QString fileName = QFileDialog::getOpenFileName(this, "Open File");
  if (!fileName.isEmpty()) {
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QTextStream stream(&file);
      _textEdit->setPlainText(stream.readAll());
      file.close();
      Logging::Log("MainWindow: File opened successfully.");
    }
  }
}

void ui::MainWindow::fileSave()
{
  QString fileName = QFileDialog::getSaveFileName(this, "Save File");
  if (!fileName.isEmpty()) {
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
      QTextStream stream(&file);
      stream << _textEdit->toPlainText();
      file.close();
      Logging::Log("MainWindow: File saved successfully.");
    }
  }
}

void ui::MainWindow::resetTextFormat() {
  QTextCursor cursor = _textEdit->textCursor();
  QTextCharFormat format;

  if (!cursor.hasSelection()) return;

  format.setFontWeight(QFont::Normal);
  format.setFontItalic(false);
  format.setFontUnderline(false);
  cursor.mergeCharFormat(format);

  _isBold = false;
  _isItalic = false;
  _isUnderline = false;
  Logging::Log("MainWindow: Text format reset.");
}

void ui::MainWindow::applyBoldFormatter()
{
  QTextCursor cursor = _textEdit->textCursor();
  BoldFormatter formatter;


  if (!cursor.hasSelection()) return;

  QString selectedText = cursor.selectedText();

  QString formattedText = formatter.format(selectedText);

  cursor.insertHtml(formattedText);
  _isBold = true;
  Logging::Log("MainWindow: Bold formatter applied.");
}

void ui::MainWindow::applyItalicFormatter()
{
  QTextCursor cursor = _textEdit->textCursor();
  ItalicFormatter formatter;


  if (!cursor.hasSelection()) return;

  QString selectedText = cursor.selectedText();

  QString formattedText = formatter.format(selectedText);
  _isItalic = true;

  cursor.insertHtml(formattedText);
  Logging::Log("MainWindow: Italic formatter applied.");
}

void ui::MainWindow::applyUnderlineFormatter()
{
  QTextCursor cursor = _textEdit->textCursor();
  UnderlineFormatter formatter;

  if (!cursor.hasSelection()) return;

  QString selectedText = cursor.selectedText();

  QString formattedText = formatter.format(selectedText);

  _isUnderline = true;
  cursor.insertHtml(formattedText);

  // replace the content of the text edit with the formatted text
  _textEdit->setTextCursor(cursor);

  Logging::Log("MainWindow: Underline formatter applied.");
}
