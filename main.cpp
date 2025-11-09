#include <iostream>
#include "point.h"
#include "vector.h"
#include "utils.h"

using namespace std;

int main() {
    cout << "=== TEST DES POINTS 2D ===" << endl << endl;
    
    // 1. Création de points
    Point2f p1 = MakeP2f(2.0f, 3.0f);
    Point2f p2 = MakeP2f(5.0f, 7.0f);
    
    Print("Point 1:", ToString(p1));
    Print("Point 2:", ToString(p2));
    cout << endl;
    
    // 2. Translation avec déplacements
    Point2f p3 = Translate(p1, 10.0f, 5.0f);
    Print("Point 1 translaté de (10, 5):", ToString(p3));
    cout << endl;
    
    // 3. Mise à l'échelle
    Point2f p4 = Scale(p1, 2.0f, 3.0f);
    Print("Point 1 mis à l'échelle (2x, 3x):", ToString(p4));
    cout << endl;
    
    // 4. Rotation
    Point2f p5 = Rotate(p1, 90.0f);
    Print("Point 1 tourné de 90 degrés:", ToString(p5));
    cout << endl;
    
    cout << "=== TEST DES VECTEURS 2D ===" << endl << endl;
    
    // 5. Création de vecteurs
    Vector2f v1 = MakeV2f(1.0f, -1.0f);
    Vector2f v2 = MakeV2f(3.0f, 4.0f);
    
    Print("Vecteur 1:", ToString(v1));
    Print("Vecteur 2:", ToString(v2));
    cout << endl;
    
    // 6. Vecteur entre deux points
    Vector2f v3 = MakeV2f(p1, p2);
    Print("Vecteur de Point1 vers Point2:", ToString(v3));
    cout << endl;
    
    // 7. Addition et soustraction
    Vector2f v4 = Add(v1, v2);
    Vector2f v5 = Sub(v2, v1);
    
    Print("v1 + v2 =", ToString(v4));
    Print("v2 - v1 =", ToString(v5));
    cout << endl;
    
    // 8. Multiplication par un scalaire
    Vector2f v6 = Scale(v2, 2.5f);
    Print("v2 * 2.5 =", ToString(v6));
    cout << endl;
    
    // 9. Produit scalaire
    float dotProduct = Dot(v1, v2);
    Print("Produit scalaire v1 · v2 =", dotProduct);
    cout << endl;
    
    // 10. Longueur d'un vecteur
    float len = Length(v2);
    Print("Longueur de v2 =", len);
    cout << endl;
    
    // 11. Normalisation
    Vector2f v7 = Normalize(v2);
    Print("v2 normalisé:", ToString(v7));
    Print("Longueur après normalisation:", Length(v7));
    cout << endl;
    
    // 12. Interpolation linéaire
    Vector2f v8 = Lerp(v1, v2, 0.5f);
    Print("Interpolation entre v1 et v2 (t=0.5):", ToString(v8));
    cout << endl;
    
    // 13. Déterminant
    float det = Determinant(v1, v2);
    Print("Déterminant de v1 et v2:", det);
    cout << endl;
    
    cout << "=== TEST COMBINÉ ===" << endl << endl;
    
    // 14. Translation avec un vecteur
    Point2f p6 = Translate(p1, v1);
    Print("Point 1 translaté par v1:", ToString(p6));
    cout << endl;
    
    // 15. Mise à l'échelle avec un vecteur
    Vector2f scaleVec = MakeV2f(2.0f, 0.5f);
    Point2f p7 = Scale(p1, scaleVec);
    Print("Point 1 mis à l'échelle par", ToString(scaleVec), "=", ToString(p7));
    cout << endl;
    
    // 16. Test de la fonction Print avec plusieurs arguments
    Print("Test multi-arguments:", "Point =", ToString(p1), "Vecteur =", ToString(v1));
    
    cout << endl << "=== FIN DES TESTS ===" << endl;
    
    return 0;
}