#include "vector.h"
#include "point.h"
#include <sstream>
#include <cmath>

// Créer un vecteur à partir de coordonnées
Vector2f MakeV2f(float x, float y) {
    Vector2f v;
    v.x = x;
    v.y = y;
    return v;
}

// Créer un vecteur à partir de deux points (de a vers b)
Vector2f MakeV2f(const Point2f& a, const Point2f& b) {
    Vector2f v;
    v.x = b.x - a.x;
    v.y = b.y - a.y;
    return v;
}

// Addition de deux vecteurs
Vector2f Add(const Vector2f& a, const Vector2f& b) {
    return MakeV2f(a.x + b.x, a.y + b.y);
}

// Soustraction de deux vecteurs
Vector2f Sub(const Vector2f& a, const Vector2f& b) {
    return MakeV2f(a.x - b.x, a.y - b.y);
}

// Multiplication d'un vecteur par un scalaire
Vector2f Scale(const Vector2f& v, float scalar) {
    return MakeV2f(v.x * scalar, v.y * scalar);
}

// Produit scalaire (dot product)
float Dot(const Vector2f& a, const Vector2f& b) {
    return a.x * b.x + a.y * b.y;
}

// Longueur (magnitude) du vecteur
float Length(const Vector2f& v) {
    return std::sqrt(v.x * v.x + v.y * v.y);
}

// Normalisation (vecteur de longueur 1)
Vector2f Normalize(const Vector2f& v) {
    float len = Length(v);
    if (len == 0.0f) {
        return MakeV2f(0.0f, 0.0f);
    }
    return MakeV2f(v.x / len, v.y / len);
}

// Interpolation linéaire entre deux vecteurs
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t) {
    return MakeV2f(
        a.x + (b.x - a.x) * t,
        a.y + (b.y - a.y) * t
    );
}

// Déterminant (produit vectoriel en 2D)
float Determinant(const Vector2f& a, const Vector2f& b) {
    return a.x * b.y - a.y * b.x;
}

// Conversion en chaîne de caractères
std::string ToString(const Vector2f& v) {
    std::ostringstream oss;
    oss << "Vector2f(" << v.x << ", " << v.y << ")";
    return oss.str();
}