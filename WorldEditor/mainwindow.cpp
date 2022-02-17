#include "mainwindow.h"

using namespace WorldEditor;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_camera = new Camera3D;
    m_camera->setPosition(QVector3D(0.0, 0.0, -5.0));

    QVector<VertexData> vertices;
    QVector<int> indices;
    initCube(2.0f, vertices, indices);

    GLGeometry *geom = new GLGeometry(vertices, indices);

    m_viewport = new Viewport3D(m_camera);
    m_viewport->addObject(geom);

    setCentralWidget(m_viewport);
}

MainWindow::~MainWindow()
{
}

void MainWindow::initCube(const float &edgeLength, QVector<VertexData> &vertexes, QVector<int> &indices)
{
    float width_div_2 = edgeLength / 2.0f;

    vertexes.append(VertexData(QVector3D(-width_div_2,width_div_2, width_div_2), QVector2D(0.0, 1.0), QVector3D(0.0,0.0,1.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2,-width_div_2, width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0,0.0,1.0)));
    vertexes.append(VertexData(QVector3D(width_div_2,width_div_2, width_div_2), QVector2D(1.0, 1.0), QVector3D(0.0,0.0,1.0)));
    vertexes.append(VertexData(QVector3D(width_div_2,-width_div_2, width_div_2), QVector2D(1.0, 0.0), QVector3D(0.0,0.0,1.0)));

    vertexes.append(VertexData(QVector3D(width_div_2,width_div_2, width_div_2), QVector2D(0.0, 1.0), QVector3D(1.0,0.0,0.0)));
    vertexes.append(VertexData(QVector3D(width_div_2,-width_div_2, width_div_2), QVector2D(0.0, 0.0), QVector3D(1.0,0.0,0.0)));
    vertexes.append(VertexData(QVector3D(width_div_2,width_div_2, -width_div_2), QVector2D(1.0, 1.0), QVector3D(1.0,0.0,0.0)));
    vertexes.append(VertexData(QVector3D(width_div_2,-width_div_2, -width_div_2), QVector2D(1.0, 0.0), QVector3D(1.0,0.0,0.0)));

    vertexes.append(VertexData(QVector3D(width_div_2,width_div_2, width_div_2), QVector2D(0.0, 1.0), QVector3D(0.0,1.0,0.0)));
    vertexes.append(VertexData(QVector3D(width_div_2,width_div_2, -width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0,1.0,0.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2,width_div_2, width_div_2), QVector2D(1.0, 1.0), QVector3D(0.0,1.0,0.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2,width_div_2, -width_div_2), QVector2D(1.0, 0.0), QVector3D(0.0,1.0,0.0)));

    vertexes.append(VertexData(QVector3D(width_div_2, width_div_2, -width_div_2), QVector2D(0.0, 1.0), QVector3D(0.0,0.0,-1.0)));
    vertexes.append(VertexData(QVector3D(width_div_2,-width_div_2, -width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0,0.0,-1.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2,width_div_2, -width_div_2), QVector2D(1.0, 1.0), QVector3D(0.0,0.0,-1.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2,-width_div_2, -width_div_2), QVector2D(1.0, 0.0), QVector3D(0.0,0.0,-1.0)));

    vertexes.append(VertexData(QVector3D(-width_div_2,width_div_2, width_div_2), QVector2D(0.0, 1.0), QVector3D(-1.0,0.0,0.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2,width_div_2, -width_div_2), QVector2D(0.0, 0.0), QVector3D(-1.0,0.0,0.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2,-width_div_2, width_div_2), QVector2D(1.0, 1.0), QVector3D(-1.0,0.0,0.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2,-width_div_2,-width_div_2), QVector2D(1.0, 0.0), QVector3D(-1.0,0.0,0.0)));

    vertexes.append(VertexData(QVector3D(-width_div_2,-width_div_2, width_div_2), QVector2D(0.0, 1.0), QVector3D(0.0,-1.0,0.0)));
    vertexes.append(VertexData(QVector3D(-width_div_2,-width_div_2, -width_div_2), QVector2D(0.0, 0.0), QVector3D(0.0,-1.0,0.0)));
    vertexes.append(VertexData(QVector3D(width_div_2,-width_div_2, width_div_2), QVector2D(1.0, 1.0), QVector3D(0.0,-1.0,0.0)));
    vertexes.append(VertexData(QVector3D(width_div_2,-width_div_2, -width_div_2), QVector2D(1.0, 0.0), QVector3D(0.0,-1.0,0.0)));

    for (int i = 0; i < 24; i+=4) {
        indices.append(i + 0);
        indices.append(i + 1);
        indices.append(i + 2);

        indices.append(i + 2);
        indices.append(i + 1);
        indices.append(i + 3);
    }
}
