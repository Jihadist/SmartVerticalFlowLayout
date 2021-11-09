#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class SmartVerticalFlowLayout;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

protected:
    void resizeEvent(QResizeEvent* event) override;

private slots:
    void on_boxExample_currentIndexChanged(int index);
    void on_boxAlignment_currentIndexChanged(int index);

    void updateNumberOfElement(int number);

    void updateMargin();

    void on_spinBoxVerticalSpace_valueChanged(int space);
    void on_spinBoxHorizontalSpace_valueChanged(int space);

    void on_spinBoxMaxElements_valueChanged(int count);

    void updateElementsPolicy();

private:
    QWidget* createWidget(SmartVerticalFlowLayout* layout, QWidget* master) const;

    QSizePolicy elementPolicy() const;

private:
    Ui::MainWindow* ui;

    SmartVerticalFlowLayout* mp_scrollLayout;
};

#include <QPushButton>

class DemoWidget : public QPushButton {
    Q_OBJECT
public:
    explicit DemoWidget(QWidget* parent, const QSize& hint)
        : QPushButton(parent)
    {
        trueHintSize = hint;
    }
    virtual ~DemoWidget() override {}

    QSize sizeHint() const override { return trueHintSize; }

private:
    QSize trueHintSize;
};

#endif // MAINWINDOW_H
