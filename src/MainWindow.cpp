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
    Logging::Log("MainWindow: Actions initialized.");
}

void ui::MainWindow::setupMenuBar()
{
  _fileMenu = new QMenu("File", this);
  _openAction = new QAction("Open", this);
  _saveAction = new QAction("Save", this);
  _exitAction = new QAction("Exit", this);

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
