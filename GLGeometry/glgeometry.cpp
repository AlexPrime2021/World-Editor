#include "glgeometry.h"
#include <QColor>

using namespace WorldEditor;

GLGeometry::GLGeometry(const QVector<VertexData> &vertexes, const QVector<int> &indices) :
    m_vertexBuffer(QOpenGLBuffer::VertexBuffer),
    m_indexBuffer(QOpenGLBuffer::IndexBuffer),
    GLObject()
{
    initialize(vertexes, indices);
}

GLGeometry::~GLGeometry()
{
    clear();
}

void GLGeometry::setColor(const QColor &color)
{
    m_color = QVector4D(color.red() / 255.0f, color.green() / 255.0f, color.blue() / 255.0f, 1.0f);
}

void GLGeometry::enableWireframe(const bool enabled)
{
    m_isEnabledWireframe = enabled;
}

void GLGeometry::draw(const View &view)
{
    m_modelShaderProgram->bind();

    m_modelMatrix.setToIdentity();
    m_modelMatrix.translate(m_translation);
    m_modelMatrix.rotate(QQuaternion::fromEulerAngles(m_EulerAngle));

    if (qFuzzyCompare(m_scale, -1.0f) && (qFuzzyCompare(m_scaleVector.x(), -1.0f) || qFuzzyCompare(m_scaleVector.y(), -1.0f) || qFuzzyCompare(m_scaleVector.z(), -1.0f)))
        m_modelMatrix.scale(1.0f);
    else if (qFuzzyCompare(m_scale, -1.0f))
        m_modelMatrix.scale(m_scaleVector);
    else
        m_modelMatrix.scale(m_scale);

    m_modelShaderProgram->setUniformValue("u_viewMatrix", view.viewMatrix);
    m_modelShaderProgram->setUniformValue("u_projectionMatrix", view.projectionMatrix);
    m_modelShaderProgram->setUniformValue("u_modelMatrix", m_modelMatrix);
    m_modelShaderProgram->setUniformValue("u_color", m_color);

    m_vertexBuffer.bind();

    int offset = 0;

    int vertexLoc = m_modelShaderProgram->attributeLocation("a_vertex");
    m_modelShaderProgram->enableAttributeArray(vertexLoc);
    m_modelShaderProgram->setAttributeBuffer(vertexLoc, GL_FLOAT, offset, 3, sizeof(VertexData));

    offset += sizeof(QVector3D);

    int texCoordLoc = m_modelShaderProgram->attributeLocation("a_texCoord");
    m_modelShaderProgram->enableAttributeArray(texCoordLoc);
    m_modelShaderProgram->setAttributeBuffer(texCoordLoc, GL_FLOAT, offset, 2, sizeof(VertexData));

    offset += sizeof(QVector2D);

    int normalLoc = m_modelShaderProgram->attributeLocation("a_normal");
    m_modelShaderProgram->enableAttributeArray(normalLoc);
    m_modelShaderProgram->setAttributeBuffer(normalLoc, GL_FLOAT, offset, 3, sizeof(VertexData));

    m_indexBuffer.bind();
    view.glFunction->glDrawElements(GL_TRIANGLES, m_vertexBuffer.size(), GL_UNSIGNED_INT, nullptr);
    m_indexBuffer.release();

    m_modelShaderProgram->disableAttributeArray(vertexLoc);
    m_modelShaderProgram->disableAttributeArray(texCoordLoc);
    m_modelShaderProgram->disableAttributeArray(normalLoc);

    m_vertexBuffer.release();
    m_modelShaderProgram->release();
}

void GLGeometry::setTranslation(const QVector3D &translation)
{
    m_translation = translation;
}

void GLGeometry::setRotation(const QVector3D &EulerAngle)
{
    m_EulerAngle = EulerAngle;
}

void GLGeometry::setScale(const float &scale)
{
    m_scale = scale;
}

void GLGeometry::setScale(const QVector3D &scale)
{
    m_scaleVector = scale;
}

void GLGeometry::initialize(const QVector<VertexData> &vertexes, const QVector<int> &indices)
{
    m_vertexBuffer.create();
    m_vertexBuffer.bind();
    m_vertexBuffer.allocate(vertexes.constData(), vertexes.size() * sizeof(VertexData));
    m_vertexBuffer.release();

    m_indexBuffer.create();
    m_indexBuffer.bind();
    m_indexBuffer.allocate(indices.constData(), indices.size() * sizeof(int));
    m_indexBuffer.release();

    m_modelShaderProgram = makeShaderProgramFromSourceFile(":/modelVertexShader.vsh", ":/modelFragmentShader.fsh");
//    m_wireframeShaderProgram = makeShaderProgramFromSourceFile(":/lineVertexShader.vsh", ":/lineFragmentShader.fsh");
}

void GLGeometry::clear()
{
    if (m_vertexBuffer.isCreated())
        m_vertexBuffer.destroy();

    if (m_indexBuffer.isCreated())
        m_indexBuffer.destroy();

    if (m_modelShaderProgram) {
        delete m_modelShaderProgram;
        m_modelShaderProgram = nullptr;
    }

    if (m_wireframeShaderProgram) {
        delete m_modelShaderProgram;
        m_modelShaderProgram = nullptr;
    }
}
