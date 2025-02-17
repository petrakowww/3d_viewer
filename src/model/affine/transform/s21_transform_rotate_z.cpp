/**
 * @file s21_transform_rotate_z.cpp
 * @brief Реализация поворота вершин вокруг оси Z.
 *
 * Этот файл содержит реализацию класса RotateZ, который применяет поворот к
 * координатам вершин вокруг оси Z на заданный угол.
 */

#include "s21_transformation.h"

namespace s21 {
/**
 * @brief Конструктор класса RotateZ, инициализирующий угол поворота вокруг оси
 * Z.
 *
 * @param angle Угол поворота в радианах.
 */
RotateZ::RotateZ(float angle) : Rotate(angle) {}
/**
 * @brief Применяет поворот координат вокруг оси Z.
 *
 * Функция изменяет координаты вершин, вращая их вокруг оси Z на заданный угол.
 * Для вычислений используются предвычисленные значения косинуса и синуса угла
 * поворота. Вращение затрагивает только координаты X и Y.
 *
 * @param vectorVertexes Вектор, содержащий координаты вершин.
 *        Вершины предполагается хранить последовательно с фиксированным
 * размером измерения (VERTEX_DIMENSION).
 */
void RotateZ::apply(std::vector<float> &vectorVertexes) {
  size_t vertexCount = vectorVertexes.size() / VERTEX_DIMENSION;
  for (size_t i = 0; i < vertexCount; i++) {
    float x = vectorVertexes[i * VERTEX_DIMENSION];
    float y = vectorVertexes[i * VERTEX_DIMENSION + Y_AXIS];
    vectorVertexes[i * VERTEX_DIMENSION] = cosAngle_ * x + sinAngle_ * y;
    vectorVertexes[i * VERTEX_DIMENSION + Y_AXIS] =
        -sinAngle_ * x + cosAngle_ * y;
  }
}
}  // namespace s21