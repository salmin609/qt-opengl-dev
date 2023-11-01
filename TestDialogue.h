#pragma once

class RectangleWindow;
class ObjectCube;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;

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
    ObjectCube* cubeObject;
    QPushButton* changeColorBtn;
    QPushButton* changeColorAnimationBtn;
    QPushButton* closeBtn;
    QHBoxLayout* hlay;
    QVBoxLayout* vlay;

};
