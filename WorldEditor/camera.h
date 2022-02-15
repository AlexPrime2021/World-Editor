#ifndef CAMERA_H
#define CAMERA_H

#include <QMatrix4x4>

namespace WorldEditor {

class Camera
{
public:
    explicit Camera();
    virtual ~Camera();

    virtual QMatrix4x4 viewMatrix() const = 0;
    virtual QMatrix4x4 projectionMatrix(const int width, const int height) const = 0;
};

}

#endif // CAMERA_H
