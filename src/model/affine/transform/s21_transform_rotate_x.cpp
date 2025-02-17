#include "s21_transformation.h"

/**
 * @file s21_transform_rotate_x.cpp
 * @brief Реализация поворота вершин вокруг оси X.
 *
 * Этот файл содержит реализацию класса RotateX, который применяет поворот к
 * координатам вершин вокруг оси X на заданный угол.
 */

namespace s21 {
/**
 * @brief Конструктор класса RotateX, инициализирующий угол поворота вокруг оси
 * X.
 *
 * @param angle Угол поворота в радианах.
 */
RotateX::RotateX(float angle) : Rotate(angle) {}

/**
 * @brief Применяет поворот координат вокруг оси X.
 *
 * Функция изменяет координаты вершин, вращая их вокруг оси X на заданный угол.
 * Для вычислений используются предвычисленные значения косинуса и синуса угла
 * поворота. Вращение затрагивает только координаты Y и Z.
 *
 * @param vectorVertexes Вектор, содержащий координаты вершин.
 *        Вершины предполагается хранить последовательно с фиксированным
 * размером измерения (VERTEX_DIMENSION).
 */
void RotateX::apply(std::vector<float> &vectorVertexes) {
  size_t vertexCount = vectorVertexes.size() / VERTEX_DIMENSION;

  for (size_t i = 0; i < vertexCount; i++) {
    float y = vectorVertexes[i * VERTEX_DIMENSION + Y_AXIS];
    float z = vectorVertexes[i * VERTEX_DIMENSION + Z_AXIS];

    vectorVertexes[i * VERTEX_DIMENSION + Y_AXIS] =
        cosAngle_ * y + sinAngle_ * z;
    vectorVertexes[i * VERTEX_DIMENSION + Z_AXIS] =
        -sinAngle_ * y + cosAngle_ * z;
  }
}
}  // namespace s21