#include "point.h"
#include <sstream>
#include <cmath>

// Valeur de PI pour les calculs de rotation
const float PI = 3.14159265358979323846f;

// Créer un point à partir de coordonnées
Point2f MakeP2f(float x, float y) {
    Point2f p;
    p.x = x;
    p.y = y;
    return p;
}

// Translation d'un point avec des déplacements dx et dy
Point2f Translate(const Point2f& p, float dx, float dy) {
    return MakeP2f(p.x + dx, p.y + dy);
}

// Translation d'un point avec un vecteur
Point2f Translate(const Point2f& p, const Vector2f& v) {
    return MakeP2f(p.x + v.x, p.y + v.y);
}

// Mise à l'échelle d'un point avec des facteurs sx et sy
Point2f Scale(const Point2f& p, float sx, float sy) {
    return MakeP2f(p.x * sx, p.y * sy);
}

// Mise à l'échelle d'un point avec un vecteur
Point2f Scale(const Point2f& p, const Vector2f& s) {
    return MakeP2f(p.x * s.x, p.y * s.y);
}

// Rotation d'un point autour de l'origine
Point2f Rotate(const Point2f& p, float angleDegree) {
    // Conversion de degrés en radians
    float angleRad = angleDegree * PI / 180.0f;
    
    // Calcul du cosinus et sinus
    float cosA = std::cos(angleRad);
    float sinA = std::sin(angleRad);
    
    // Application de la matrice de rotation
    return MakeP2f(
        p.x * cosA - p.y * sinA,
        p.x * sinA + p.y * cosA
    );
}

// Conversion en chaîne de caractères
std::string ToString(const Point2f& p) {
    std::ostringstream oss;
    oss << "Point2f(" << p.x << ", " << p.y << ")";
    return oss.str();
}