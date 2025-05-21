#include "MainWindow.hpp"


ui::MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    _textEdit = new QTextEdit(this); // Create the text editor

    QVBoxLayout *layout = new QVBoxLayout(this);
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
