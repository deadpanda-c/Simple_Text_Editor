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
}

void ui::MainWindow::setupActions()
{
    std::cout << "Setting up actions..." << std::endl;
}

void ui::MainWindow::setupMenuBar()
{
    std::cout << "Setting up menu bar..." << std::endl;
}

void ui::MainWindow::setupToolBar()
{
    std::cout << "Setting up toolbar..." << std::endl;
}

void ui::MainWindow::sayHello()
{
    std::cout << "Hello, World!" << std::endl;
}
