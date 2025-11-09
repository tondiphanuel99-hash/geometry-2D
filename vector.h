#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <cmath>

// Déclaration anticipée de Point2f pour éviter les dépendances circulaires
struct Point2f;

// Structure représentant un vecteur 2D
struct Vector2f {
    float x;
    float y;
};

// Fonctions de création (Make)
Vector2f MakeV2f(float x, float y);
Vector2f MakeV2f(const Point2f& a, const Point2f& b);

// Opérations sur les vecteurs
Vector2f Add(const Vector2f& a, const Vector2f& b);
Vector2f Sub(const Vector2f& a, const Vector2f& b);
Vector2f Scale(const Vector2f& v, float scalar);

// Produits et mesures
float Dot(const Vector2f& a, const Vector2f& b);
float Length(const Vector2f& v);
float Determinant(const Vector2f& a, const Vector2f& b);

// Normalisation et interpolation
Vector2f Normalize(const Vector2f& v);
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t);

// Conversion en chaîne
std::string ToString(const Vector2f& v);

#endif