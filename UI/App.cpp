#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QPalette>
#include <QDialog>
#include <QString>

const QString LIGHT_BLUE = "#ADD8E6";

// Button style
const QString BUTTON_STYLE = R"(
    QPushButton {
        background-color: #B0E0E6;       /* Slightly darker blue */
        color: #000000;                   /* Black text */
        font-size: 14pt;
        font-weight: bold;
        border-radius: 10px;
        padding: 8px 16px;
    }
    QPushButton:hover {
        background-color: #87CEEB;       /* Hover effect */
    }
    QPushButton:pressed {
        background-color: #5CADFF;       /* Pressed effect */
    }
)";

// Forward declarations
class MainWindow;
class SpamWindow;
class HamWindow;

// Spam Window 
class SpamWindow : public QDialog {
public:
    SpamWindow(QWidget* parent = nullptr) : QDialog(parent) {
        setWindowTitle("Spam Window");
        setFixedSize(800, 500);
        setStyleSheet("background-color:" + LIGHT_BLUE + ";");

        QLabel* label = new QLabel("Spam Emails are Here", this);
        label->setStyleSheet("font-size:16pt; font-weight:bold;");
        label->setAlignment(Qt::AlignCenter);

        QPushButton* btnClose = new QPushButton("Close Window", this);
        btnClose->setStyleSheet(BUTTON_STYLE);
        connect(btnClose, &QPushButton::clicked, this, &SpamWindow::close);

        QVBoxLayout* layout = new QVBoxLayout();
        layout->addWidget(label);
        layout->addWidget(btnClose);
        layout->setAlignment(btnClose, Qt::AlignCenter);
        setLayout(layout);
    }
};

// Ham Window 
class HamWindow : public QDialog {
public:
    HamWindow(QWidget* parent = nullptr) : QDialog(parent) {
        setWindowTitle("Ham Window");
        setFixedSize(800, 500);
        setStyleSheet("background-color:" + LIGHT_BLUE + ";");

        QLabel* label = new QLabel("Your Ham Emails are Here", this);
        label->setStyleSheet("font-size:16pt; font-weight:bold;");
        label->setAlignment(Qt::AlignCenter);

        QPushButton* btnClose = new QPushButton("Close Window", this);
        btnClose->setStyleSheet(BUTTON_STYLE);
        connect(btnClose, &QPushButton::clicked, this, &HamWindow::close);

        QVBoxLayout* layout = new QVBoxLayout();
        layout->addWidget(label);
        layout->addWidget(btnClose);
        layout->setAlignment(btnClose, Qt::AlignCenter);
        setLayout(layout);
    }
};

// Main Window 
class MainWindow : public QWidget {
public:
    MainWindow(QWidget* parent = nullptr) : QWidget(parent) {
        setWindowTitle("Main Window");
        setFixedSize(800, 500);
        setStyleSheet("background-color:" + LIGHT_BLUE + ";");

        QLabel* label = new QLabel("Choose a category", this);
        label->setStyleSheet("font-size:18pt; font-weight:bold;");
        label->setAlignment(Qt::AlignCenter);

        QPushButton* btnSpam = new QPushButton("View Spam Emails", this);
        QPushButton* btnHam = new QPushButton("View Ham Emails", this);
        QPushButton* btnExit = new QPushButton("Exit Application", this);

        btnSpam->setStyleSheet(BUTTON_STYLE);
        btnHam->setStyleSheet(BUTTON_STYLE);
        btnExit->setStyleSheet(BUTTON_STYLE);

        connect(btnSpam, &QPushButton::clicked, this, [this]() {
            SpamWindow* win = new SpamWindow(this);
            win->exec();
        });

        connect(btnHam, &QPushButton::clicked, this, [this]() {
            HamWindow* win = new HamWindow(this);
            win->exec();
        });

        connect(btnExit, &QPushButton::clicked, this, &QWidget::close);

        QVBoxLayout* layout = new QVBoxLayout();
        layout->addWidget(label);
        layout->addWidget(btnSpam);
        layout->addWidget(btnHam);
        layout->addWidget(btnExit);
        layout->setAlignment(btnSpam, Qt::AlignCenter);
        layout->setAlignment(btnHam, Qt::AlignCenter);
        layout->setAlignment(btnExit, Qt::AlignCenter);
        setLayout(layout);
    }
};

// Welcome Window 
class WelcomeWindow : public QWidget {
public:
    WelcomeWindow() {
        setWindowTitle("Welcome Window");
        setFixedSize(800, 500);
        setStyleSheet("background-color:" + LIGHT_BLUE + ";");

        QLabel* label = new QLabel("Welcome to Julian's Spam Email Detector!", this);
        label->setStyleSheet("font-size:20pt; font-weight:bold;");
        label->setAlignment(Qt::AlignCenter);

        QPushButton* btnNext = new QPushButton("Go to Main Menu", this);
        btnNext->setStyleSheet(BUTTON_STYLE);
        connect(btnNext, &QPushButton::clicked, this, &WelcomeWindow::openMainWindow);

        QVBoxLayout* layout = new QVBoxLayout();
        layout->addWidget(label);
        layout->addWidget(btnNext);
        layout->setAlignment(btnNext, Qt::AlignCenter);
        setLayout(layout);
    }

    void openMainWindow() {
        MainWindow* mainWin = new MainWindow();
        mainWin->show();
        this->close();
    }
};

// To run use command line: ./SpamApp.app/Contents/MacOS/SpamApp
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    WelcomeWindow welcome;
    welcome.show();

    return app.exec();
}
