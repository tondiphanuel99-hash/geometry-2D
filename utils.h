#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

// Fonction générique ToString pour les types de base
template<typename T>
std::string ToString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

// Spécialisation pour std::vector
template<typename T>
std::string ToString(const std::vector<T>& v) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        oss << ToString(v[i]);
        if (i + 1 < v.size()) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

// Spécialisation pour std::map
template<typename K, typename V>
std::string ToString(const std::map<K, V>& m) {
    std::ostringstream oss;
    oss << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        oss << ToString(it->first) << ": " << ToString(it->second);
        if (std::next(it) != m.end()) oss << ", ";
    }
    oss << "}";
    return oss.str();
}

// Fonction Print variadique (accepte plusieurs arguments)
template<typename T, typename... Args>
void Print(const T& first, const Args&... args) {
    std::cout << ToString(first);
    ((std::cout << ", " << ToString(args)), ...);
    std::cout << std::endl;
}

#endif