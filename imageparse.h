#ifndef IMAGEPARSE_H
#define IMAGEPARSE_H

#include <QVector>
#include <QPolygon>
#include <QImage>
#include <QRgb>

#include <windows.h>
#undef min
#undef max

#include <GL/GLU.h>

#include <functional>

class ImageParser
{
public:
    struct Shape
    {
        QPolygonF outer;
        QVector<QPolygonF> inner;
    };

    static QVector<QPolygonF> parseImage(QString fileName);
    static QVector<QPolygonF> parseImage(const QImage& image);
    static QVector<QPolygonF> parseImage(const QVector<QVector<QRgb> >& pixMap);

private:
    //Edge finding
    static QVector<QPolygonF> _findShapes(QVector<QVector<bool> > &bwImage);
    static QPair<int64_t, int64_t> _moveShape(QVector<QVector<bool> >& bwImage, QVector<QVector<bool>>& copy, int64_t x, int64_t y);
    static Shape _findPoints(QVector<QVector<bool>>& shape);
    static void _bfsBlackWhite(const QVector<QVector<bool> > &bwImage, std::function<void(int, int)> handler, int64_t x, int64_t y, bool color);
    static QPolygonF _followBoundary(const QVector<QVector<bool>>& bwImage, int64_t x, int64_t y, bool outer= true);

    //Triangulating
    static QVector<QPolygonF> _triangulate(const Shape& s);
    static QVector<QPolygonF> _triangulateC2T(const Shape& s);
    static QVector<QPolygonF> _triangulateGLU(const Shape& s);

    //Polygon simplify
    static void _simplify(Shape &s);
    static QPolygonF _simplify(const QPolygonF& p);
};

#endif // IMAGEPARSE_H
