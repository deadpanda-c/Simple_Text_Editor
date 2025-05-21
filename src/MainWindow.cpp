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
  QMenu *fileMenu = new QMenu("File", this);
  QAction *openAction = new QAction("Open", this);
  QAction *saveAction = new QAction("Save", this);
  QAction *exitAction = new QAction("Exit", this);
  Logging::Log("MainWindow: Menu bar actions initialized.");

  connect(openAction, &QAction::triggered, this, &MainWindow::fileOpen);
  Logging::Log("MainWindow: Open action connected.");
  connect(saveAction, &QAction::triggered, this, &MainWindow::fileSave);
  Logging::Log("MainWindow: Save action connected.");
  connect(exitAction, &QAction::triggered, this, &QWidget::close);
  Logging::Log("MainWindow: Exit action connected.");

  fileMenu->addAction(openAction);
  Logging::Log("MainWindow: Open action added to menu.");
  fileMenu->addAction(saveAction);
  Logging::Log("MainWindow: Save action added to menu.");
  fileMenu->addSeparator();
  Logging::Log("MainWindow: Separator added to menu.");
  fileMenu->addAction(exitAction);
  Logging::Log("MainWindow: Exit action added to menu.");


  _menuBar->addMenu(fileMenu);
  Logging::Log("MainWindow: Menu bar initialized.");
}

void ui::MainWindow::setupToolBar()
{
  Logging::Log("MainWindow: Tool bar initialized.");
}

void ui::MainWindow::sayHello()
{
    std::cout << "Hello, World!" << std::endl;
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
    }
  }
}
