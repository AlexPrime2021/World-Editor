#ifndef GLGEOMETRY_H
#define GLGEOMETRY_H

#include "globject.h"
#include "vertexdata.h"
#include <QOpenGLBuffer>

namespace WorldEditor {

class GLGeometry : public GLObject
{
public:
    GLGeometry(const QVector<VertexData> &vertexes, const QVector<int> &indices);
    ~GLGeometry();

    void setColor(const QColor &color);
    void enableWireframe(const bool enabled);

    void draw(const View &view) override;

    void setTranslation(const QVector3D &translation);
    void setRotation(const QVector3D &EulerAngle);
    void setScale(const float &scale);
    void setScale(const QVector3D &scale);

private:
    QOpenGLBuffer m_vertexBuffer;
    QOpenGLBuffer m_indexBuffer;

    QOpenGLShaderProgram *m_modelShaderProgram = nullptr;
    QOpenGLShaderProgram *m_wireframeShaderProgram = nullptr;

    QVector4D m_color = QVector4D(0.0f, 0.0f, 1.0f, 1.0f);
    bool m_isEnabledWireframe = false;

    QMatrix4x4 m_modelMatrix;
    QVector3D m_translation;
    QVector3D m_EulerAngle;
    QVector3D m_scaleVector = QVector3D(-1.0f, -1.0f, -1.0f);
    float m_scale = -1.0f;

    void initialize(const QVector<VertexData> &vertexes, const QVector<int> &indices);
    void clear();
};

}

#endif // GLGEOMETRY_H
