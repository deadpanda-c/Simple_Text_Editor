#include "MainWindow.hpp"

ui::MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // Create a button
    QPushButton *button = new QPushButton("Click Me", this);
    connect(button, &QPushButton::clicked, this, &ui::MainWindow::sayHello);

    // Set the layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(button);
    setLayout(layout);

    // Setup the UI components
    setupUi();
}


void ui::MainWindow::setupUi()
{
    // Set the window title
    setWindowTitle("Text Editor");
    // Set the window size
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
