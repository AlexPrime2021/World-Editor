#ifndef CONTEXTNAVIGATION3D_H
#define CONTEXTNAVIGATION3D_H

#include <QObject>
#include <QEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include "viewport3d.h"
#include "camera3d.h"

namespace WorldEditor {

class ContextNavigation3D : public QObject
{
    Q_OBJECT
public:
    ContextNavigation3D(Viewport3D *viewport, Camera3D *camera, QObject *parent = nullptr);
    ~ContextNavigation3D();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    Viewport3D *m_viewport = nullptr;
    Camera3D *m_camera = nullptr;

    QVector2D m_startPosition;
    QVector2D m_currentTranslation;

    QQuaternion m_rotation;
    QQuaternion m_rotationX;
    QQuaternion m_rotationY;

    const float m_zoomFactorZ = 0.25f;
    const float m_speedPan = 1200.0f; // 1000.0f
    float m_currentZoomZ = m_camera->position().z();

    void cameraZoom(const int delta);
    void cameraPan(const QVector2D &mousePosition);
    void cameraRotation(const QVector2D &mousePosition);
};

}

#endif // CONTEXTNAVIGATION3D_H
