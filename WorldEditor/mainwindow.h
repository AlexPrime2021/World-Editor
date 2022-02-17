#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "camera3d.h"
#include "viewport3d.h"
#include "contextnavigation3d.h"
#include "glgeometry.h"
#include "vertexdata.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    WorldEditor::Camera3D *m_camera = nullptr;
    WorldEditor::ContextNavigation3D *m_context = nullptr;
    WorldEditor::Viewport3D *m_viewport = nullptr;

    void initCube(const float &edgeLength, QVector<WorldEditor::VertexData> &vertexes, QVector<int> &indices);
};
#endif // MAINWINDOW_H
