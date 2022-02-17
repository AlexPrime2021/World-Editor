#ifndef VERTEXDATA_H
#define VERTEXDATA_H

#include <QVector3D>
#include <QVector2D>
#include <QVector3D>

namespace WorldEditor {

struct VertexData
{
    VertexData() = default;
    VertexData(const QVector3D &position, const QVector2D &texCoord, const QVector3D &normal) :
        position(position),
        texCoord(texCoord),
        normal(normal)
    {}

    QVector3D position;
    QVector2D texCoord;
    QVector3D normal;
};

}

#endif // VERTEXDATA_H
