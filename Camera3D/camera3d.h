#ifndef CAMERA3D_H
#define CAMERA3D_H

#include "camera.h"
#include <QMatrix4x4>
#include <QVector3D>
#include <cmath>

namespace WorldEditor {

class Camera3D : public Camera
{
public:
    Camera3D() = default;
    Camera3D(const QVector3D &position, const float &fovY);
    Camera3D(const QVector3D &position, const QVector3D &EulerAngles, const float &fovY);

    void setFovY(const float &fovY);
    void setPosition(const QVector3D &position);
    void setRotation(const QVector3D &EulerAngles);
    void setNear(const float &near);
    void setFar(const float &far);

    QVector3D position() const;
    QVector3D EulerAngles() const;
    QVector3D scale() const;

    QMatrix4x4 projectionMatrix(const int width, const int height) const override;
    QMatrix4x4 viewMatrix() const override;

private:
    QVector3D m_position;
    QQuaternion m_rotation;
    float m_fovY = 45.f;

    float m_near = 1e-3f;
    float m_far = 1e4f;
};

}

#endif // CAMERA3D_H
