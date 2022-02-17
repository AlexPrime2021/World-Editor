#include "camera3d.h"

using namespace WorldEditor;

Camera3D::Camera3D(const QVector3D &position, const float &fovY) :
    m_position(position),
    m_fovY(fovY)
{
}

Camera3D::Camera3D(const QVector3D &position, const QVector3D &EulerAngles, const float &fovY) :
    m_position(position),
    m_rotation(QQuaternion::fromEulerAngles(EulerAngles)),
    m_fovY(fovY)
{
}

void Camera3D::setFovY(const float &fovY)
{
    m_fovY = fovY;
}

void Camera3D::setPosition(const QVector3D &position)
{
    m_position = position;
}

void Camera3D::setRotation(const QVector3D &EulerAngles)
{
    m_rotation = QQuaternion::fromEulerAngles(EulerAngles);
}

void Camera3D::setNear(const float &near)
{
    m_near = near;
}

void Camera3D::setFar(const float &far)
{
    m_far = far;
}

QVector3D Camera3D::position() const
{
    return m_position;
}

QVector3D Camera3D::EulerAngles() const
{
    return m_rotation.toEulerAngles();
}

QVector3D Camera3D::scale() const
{
    return QVector3D(1.0f, 1.0f, 1.0f);
}

QMatrix4x4 Camera3D::projectionMatrix(const int width, const int height) const
{
    const float aspectRatio = width / (float)(height ? height : 1);

    QMatrix4x4 projectionMatrix;
    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(m_fovY, aspectRatio, m_near, m_far);

    return projectionMatrix;
}

QMatrix4x4 Camera3D::viewMatrix() const
{
    QMatrix4x4 viewMatrix;

    viewMatrix.setToIdentity();
    viewMatrix.translate(m_position);
    viewMatrix.rotate(m_rotation);
    viewMatrix.scale(1.0f);

    return viewMatrix;
}
