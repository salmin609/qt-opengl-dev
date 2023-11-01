#pragma once

class RectangleWindow;

#include "QDialog"

class TestDialogue : public QDialog
{
    Q_OBJECT
public:
    TestDialogue();
    ~TestDialogue();
private slots:
    void onChangeColors();
    void onAnimateColors();
private:
    RectangleWindow* rectWindow;
};
