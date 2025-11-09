# 📐 Système de Géométrie 2D en C++

> Un système complet pour manipuler des points et vecteurs en 2D, développé en C++ avec compilation multi-fichiers.

---

## 📑 Table des Matières

1. [À Propos](#-à-propos-du-projet)
2. [Fonctionnalités](#-fonctionnalités)
3. [Prérequis](#-prérequis)
4. [Installation](#-installation)
5. [Compilation](#-compilation)
6. [Utilisation](#-utilisation)
7. [Documentation API](#-documentation-api)
8. [Exemples](#-exemples)
9. [Concepts Clés](#-concepts-clés)
10. [Résolution de Problèmes](#-résolution-de-problèmes)

---

## 🎯 À Propos du Projet

Bibliothèque de géométrie 2D permettant de manipuler points et vecteurs dans un plan cartésien.

### Objectifs
- Comprendre les structures en C++
- Maîtriser la compilation multi-fichiers
- Apprendre le passage de paramètres
- Utiliser la surcharge de fonctions et templates

### Cas d'Usage
🎮 Moteurs de jeux | 🖼 Logiciels graphiques | 🤖 Simulations physiques | 📊 Visualisation de données

---

## ✨ Fonctionnalités

### Points 2D (Point2f)
- *Création* : MakeP2f(5.0f, 10.0f)
- *Translation* : Translate(p, 3.0f, 4.0f)
- *Mise à l'échelle* : Scale(p, 2.0f, 2.0f)
- *Rotation* : Rotate(p, 90.0f)
- *Affichage* : ToString(p)

### Vecteurs 2D (Vector2f)
- *Création* : MakeV2f(1.0f, 2.0f) ou MakeV2f(pointA, pointB)
- *Opérations* : Add(), Sub(), Scale(), Dot(), Length()
- *Normalisation* : Normalize(v) → vecteur unitaire
- *Interpolation* : Lerp(v1, v2, 0.5f) → animation
- *Déterminant* : Determinant(v1, v2) → orientation

---

## 📥 Installation

### Structure de Fichiers


geometry2d/
├── main.cpp          # Programme principal
├── point.h           # Déclarations Point2f
├── point.cpp         # Implémentations Point2f
├── vector.h          # Déclarations Vector2f
├── vector.cpp        # Implémentations Vector2f
└── utils.h           # Utilitaires (ToString, Print)


Copiez les fichiers fournis dans les artifacts.

---

## ⚙ Compilation

### Méthode Simple
bash
g++ main.cpp point.cpp vector.cpp -o geometry
./geometry


### Avec Makefile
makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall

geometry: main.cpp point.cpp vector.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f geometry *.o


*Utilisation* : make && ./geometry

### VS Code (tasks.json)
json
{
    "version": "2.0.0",
    "tasks": [{
        "label": "Compiler",
        "type": "shell",
        "command": "g++",
        "args": ["main.cpp", "point.cpp", "vector.cpp", "-o", "geometry"],
        "group": {"kind": "build", "isDefault": true}
    }]
}


*Raccourci* : Ctrl + Shift + B

---

## 🚀 Utilisation

### Exemple Basique
cpp
#include "point.h"
#include "vector.h"
#include "utils.h"

int main() {
    Point2f p = MakeP2f(10.0f, 20.0f);
    Print("Point:", ToString(p));
    
    Vector2f v = MakeV2f(1.0f, 1.0f);
    Vector2f vNorm = Normalize(v);
    Print("Normalisé:", ToString(vNorm));
    
    return 0;
}


---

## 📚 Documentation API

### Point2f

#### MakeP2f
cpp
Point2f MakeP2f(float x, float y);

Crée un point aux coordonnées (x, y).

#### Translate
cpp
Point2f Translate(const Point2f& p, float dx, float dy);
Point2f Translate(const Point2f& p, const Vector2f& v);

Déplace un point de dx/dy ou selon un vecteur.

#### Scale
cpp
Point2f Scale(const Point2f& p, float sx, float sy);

Multiplie les coordonnées par sx et sy.

#### Rotate
cpp
Point2f Rotate(const Point2f& p, float angleDegree);

Fait pivoter autour de l'origine. Formule : x' = x*cos(θ) - y*sin(θ)

---

### Vector2f

#### MakeV2f
cpp
Vector2f MakeV2f(float x, float y);
Vector2f MakeV2f(const Point2f& a, const Point2f& b);

Crée un vecteur depuis composantes ou deux points (a → b).

#### Opérations
cpp
Vector2f Add(const Vector2f& a, const Vector2f& b);      // a + b
Vector2f Sub(const Vector2f& a, const Vector2f& b);      // a - b
Vector2f Scale(const Vector2f& v, float scalar);         // v * s
float Dot(const Vector2f& a, const Vector2f& b);         // a · b
float Length(const Vector2f& v);                         // ||v||
Vector2f Normalize(const Vector2f& v);                   // v / ||v||
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t); // Interpolation
float Determinant(const Vector2f& a, const Vector2f& b); // a × b (2D)


#### Interprétations

*Dot Product* :
- = 0 → Perpendiculaires
- > 0 → Même direction
- < 0 → Directions opposées

*Determinant* :
- > 0 → b est à gauche de a
- = 0 → Colinéaires
- < 0 → b est à droite de a

---

## 💡 Exemples

### Exemple 1 : Trajectoire
cpp
Point2f depart = MakeP2f(0, 0);
Point2f arrivee = MakeP2f(100, 50);
Vector2f deplacement = MakeV2f(depart, arrivee);

for (int i = 0; i <= 5; ++i) {
    float t = i / 5.0f;
    Vector2f current = Scale(deplacement, t);
    Point2f pos = Translate(depart, current);
    Print("Étape", i, ":", ToString(pos));
}


### Exemple 2 : Détection de Collision (Cercles)
cpp
bool CirclesCollide(Point2f c1, float r1, Point2f c2, float r2) {
    Vector2f distance = MakeV2f(c1, c2);
    return Length(distance) <= (r1 + r2);
}

Point2f cercle1 = MakeP2f(0, 0);
Point2f cercle2 = MakeP2f(8, 0);
if (CirclesCollide(cercle1, 5.0f, cercle2, 4.0f)) {
    Print("Collision détectée !");
}


### Exemple 3 : Réflexion (Rebond)
cpp
Vector2f Reflect(const Vector2f& incident, const Vector2f& normal) {
    float dot = Dot(incident, normal);
    Vector2f scaledNormal = Scale(normal, 2.0f * dot);
    return Sub(incident, scaledNormal);
}

Vector2f balle = MakeV2f(1, -1);
Vector2f mur = MakeV2f(0, 1);
Vector2f rebond = Reflect(balle, mur);
Print("Rebond:", ToString(rebond)); // (1, 1)


---

## 🔑 Concepts Clés

### Passage de Paramètres

| Type | Syntaxe | Copie ? | Modifiable ? | Quand utiliser |
|------|---------|---------|--------------|----------------|
| *Valeur* | Point2f p | ✅ | Local | Petits types |
| *Pointeur* | Point2f* p | ❌ | ✅ | Code C legacy |
| *Référence* | Point2f& p | ❌ | ✅ | Modifications |
| *Ref. const* | const Point2f& p | ❌ | ❌ | *Lectures* ⭐ |

*Règle d'or* : Utilisez const & pour lire les structures !

### Header Guards
cpp
#ifndef POINT_H
#define POINT_H
// Contenu
#endif

Évite l'inclusion multiple.

### Surcharge de Fonctions
cpp
Point2f Translate(const Point2f& p, float dx, float dy);
Point2f Translate(const Point2f& p, const Vector2f& v);

Même nom, paramètres différents → C++ choisit automatiquement.

### Templates
cpp
template<typename T>
std::string ToString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

Code générique fonctionnant avec tous les types.

---

## 🐛 Résolution de Problèmes

### "undefined reference to..."
*Cause* : Fichier .cpp non compilé.
bash
# Solution
g++ main.cpp point.cpp vector.cpp -o geometry


### "multiple definition of..."
*Cause* : Fonction définie dans un .h inclus plusieurs fois.
*Solution* : Déplacer l'implémentation dans le .cpp.

### "no matching function for call..."
*Cause* : Types incorrects (souvent int vs float).
cpp
// ❌ Erreur
Translate(p, 10, 20);

// ✅ Correct
Translate(p, 10.0f, 20.0f);


### Git : "Support for password authentication was removed"
*Solution* : Créez un Personal Access Token sur GitHub.
1. Settings → Developer settings → Personal access tokens
2. Generate token → Scope "repo"
3. Utilisez le token comme mot de passe

---

## 🎨 Extensions Possibles

### Structures 3D
cpp
struct Point3f { float x, y, z; };
struct Vector3f { float x, y, z; };
Vector3f Cross(const Vector3f& a, const Vector3f& b); // Produit vectoriel


### Système de Couleurs
cpp
struct Color { float r, g, b, a; };
Color Lerp(const Color& c1, const Color& c2, float t);


### Matrices 2x2
cpp
struct Matrix2f { float m[2][2]; };
Matrix2f MakeRotation(float angle);
Vector2f Transform(const Matrix2f& m, const Vector2f& v);


---

## 🤝 Contribuer

*Idées d'amélioration* :
- Support 3D
- Tests unitaires automatisés
- Fonctions de distance optimisées
- Système d'animation

*Convention de nommage* :
- Structures : PascalCase
- Fonctions : PascalCase
- Variables : camelCase

---

## 📜 Licence

Projet éducatif sous licence *MIT*.


Copyright (c) 2024 Rihen School in Software Engineering

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software. [...]

---

## 📊 Architecture


main.cpp
  ├─→ point.h
  │     └─→ vector.h
  ├─→ vector.h
  │     └─→ struct Point2f; (forward)
  └─→ utils.h


---

## ⚡ Optimisations

### Éviter sqrt() pour les Comparaisons
cpp
// Au lieu de :
if (Length(v) < 10.0f)

// Utilisez :
float LengthSquared(const Vector2f& v) { return v.x*v.x + v.y*v.y; }
if (LengthSquared(v) < 100.0f)  // 10² = 100


### Utiliser const &
cpp
// ❌ Lent (copie)
void Process(Point2f p);

// ✅ Rapide (référence)
void Process(const Point2f& p);


---

## 🎉 Conclusion

Vous maîtrisez maintenant :
- ✅ Structures en C++
- ✅ Compilation multi-fichiers
- ✅ Passage de paramètres optimisé
- ✅ Templates et surcharge
- ✅ Bonnes pratiques

*Prochaines étapes* : Pratiquer, étendre en 3D, optimiser !

---

<div align="center">

### ⭐ Donnez une étoile si ce projet vous a aidé ! ⭐

Made with ❤ by Rihen School in Software Engineering

[📧 Contact](mailto:contact@rihen-school.com) • [🌐 Site Web](https://rihen-school.com)

</div>