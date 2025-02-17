#include "s21_transformation.h"

/**
 * @file s21_transform_rotate_y.cpp
 * @brief Реализация поворота вершин вокруг оси Y.
 *
 * Этот файл содержит реализацию класса RotateY, который применяет поворот к
 * координатам вершин вокруг оси Y на заданный угол.
 */

namespace s21 {
/**
 * @brief Конструктор класса RotateY, инициализирующий угол поворота вокруг оси
 * Y.
 *
 * @param angle Угол поворота в радианах.
 */
RotateY::RotateY(float angle) : Rotate(angle) {}

/**
 * @brief Применяет поворот координат вокруг оси Y.
 *
 * Функция изменяет координаты вершин, вращая их вокруг оси Y на заданный угол.
 * Для вычислений используются предвычисленные значения косинуса и синуса угла
 * поворота. Вращение затрагивает только координаты X и Z.
 *
 * @param vectorVertexes Вектор, содержащий координаты вершин.
 *        Вершины предполагается хранить последовательно с фиксированным
 * размером измерения (VERTEX_DIMENSION).
 */
void RotateY::apply(std::vector<float> &vectorVertexes) {
  size_t vertexCount = vectorVertexes.size() / VERTEX_DIMENSION;
  for (size_t i = 0; i < vertexCount; i++) {
    float x = vectorVertexes[i * VERTEX_DIMENSION];
    float z = vectorVertexes[i * VERTEX_DIMENSION + Z_AXIS];
    vectorVertexes[i * VERTEX_DIMENSION] = cosAngle_ * x + sinAngle_ * z;
    vectorVertexes[i * VERTEX_DIMENSION + Z_AXIS] =
        -sinAngle_ * x + cosAngle_ * z;
  }
}
}  // namespace s21