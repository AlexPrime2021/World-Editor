#ifndef VIEWPORT3D_H
#define VIEWPORT3D_H

#include <QOpenGLWidget>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>
#include <QOpenGLContext>
#include "camera.h"
#include "globject.h"
#include "view.h"

namespace WorldEditor {

class Viewport3D : public QOpenGLWidget
{
    Q_OBJECT
public:
    Viewport3D(Camera *camera, QWidget *parent = nullptr);
    ~Viewport3D();

    void addObject(GLObject *geom);
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    Camera *m_camera = nullptr;
    QMatrix4x4 m_projectionMatrix;

    View m_view;

    QVector<GLObject *> m_objects;
};

}

#endif // VIEWPORT3D_H
