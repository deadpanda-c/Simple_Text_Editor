#include "MainWindow.hpp"

ui::MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
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

  connect(_boldAction, &QAction::triggered, this, &MainWindow::applyBoldFormatter);

  connect(_italicAction, &QAction::triggered, this, &MainWindow::applyItalicFormatter);
  // connect(_underlineAction, &QAction::triggered, this, &MainWindow::applyUnderlineFormatter);

  // Add actions to the menu bare
  _menuBar->addAction(_boldAction);
  _menuBar->addAction(_italicAction);
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

void ui::MainWindow::applyBoldFormatter()
{
  std::shared_ptr<ITextFormatter> formatter = std::make_shared<BoldFormatter>();

  QString text = _textEdit->toPlainText();
  QString formattedText = formatter->format(text);
  _textEdit->setPlainText(formattedText);
  Logging::Log("MainWindow: Bold formatter applied.");
}

void ui::MainWindow::applyItalicFormatter()
{
  std::shared_ptr<ITextFormatter> formatter = std::make_shared<ItalicFormatter>();
  QString text = _textEdit->toPlainText();
  QString formattedText = formatter->format(text);
  _textEdit->setPlainText(formattedText);
  Logging::Log("MainWindow: Italic formatter applied.");
}
