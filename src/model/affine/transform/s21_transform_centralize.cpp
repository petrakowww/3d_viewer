/**
 * @file s21_transform_centralize.cpp
 * @brief Реализация функции для централизования координат вершин.
 *
 * Этот файл содержит реализацию метода для смещения координат вершин в так
 * называемое централизованное положение, где центр модели оказывается в начале
 * координат (0, 0, 0).
 */

#include "../utils/s21_utils_vector.h"
#include "s21_transformation.h"

namespace s21 {
/**
 * @brief Централизует координаты вершин, смещая их так, чтобы центр оказался в
 * начале координат (0, 0, 0).
 *
 * Функция последовательно вызывает утилиту для установки центра на каждой из
 * осей (X, Y, Z), чтобы выровнять координаты вершин относительно начала
 * координат.
 *
 * @param vectorVertexes Вектор, содержащий координаты вершин.
 *        Вершины предполагается хранить последовательно с фиксированным
 * размером измерения (VERTEX_DIMENSION).
 */
void Centralize::apply(std::vector<float> &vectorVertexes) {
  VectorUtils::setCenter(vectorVertexes, X_AXIS, 0);
  VectorUtils::setCenter(vectorVertexes, Y_AXIS, 0);
  VectorUtils::setCenter(vectorVertexes, Z_AXIS, 0);
}
}  // namespace s21