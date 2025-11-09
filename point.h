#ifndef POINT_H
#define POINT_H

#include <string>
#include "vector.h"

// Structure représentant un point 2D
struct Point2f {
    float x;
    float y;
};

// Fonction de création
Point2f MakeP2f(float x, float y);

// Transformations de points
Point2f Translate(const Point2f& p, float dx, float dy);
Point2f Translate(const Point2f& p, const Vector2f& v);

Point2f Scale(const Point2f& p, float sx, float sy);
Point2f Scale(const Point2f& p, const Vector2f& s);

Point2f Rotate(const Point2f& p, float angleDegree);

// Conversion en chaîne
std::string ToString(const Point2f& p);

#endif