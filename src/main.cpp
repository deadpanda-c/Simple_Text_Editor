#include <iostream>
#include <QApplication>
#include "MainWindow.hpp"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv); // Qt application object

  ui::MainWindow mainWindow; // Create the main window
  mainWindow.show(); // Show the main window

  return app.exec(); // Start the event loop
}
