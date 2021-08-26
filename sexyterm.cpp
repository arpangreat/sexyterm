#include <QApplication>
#include <QKeySequence>
#include <QMainWindow>

#include "qtermwidget5/qtermwidget.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QMainWindow *mainWindow = new QMainWindow();

  // Set the environment variable here
  setenv("TERM", "xterm-256color", 1);

  QTermWidget *console = new QTermWidget();

  QFont font = QApplication::font();
  font.setFamily("Monospace");
  font.setPointSize(12);

  console->setTerminalFont(font);
  // Add setting the colorscheme here. Choose whatever one suits your fancy
  console->setColorScheme("Solarized");

  QObject::connect(console, SIGNAL(finished()), mainWindow, SLOT(close()));

  mainWindow->setCentralWidget(console);

  mainWindow->show();
  return app.exec();
}
