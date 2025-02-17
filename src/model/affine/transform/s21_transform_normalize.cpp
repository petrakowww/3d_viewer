/**
 * @file s21_transform_normalize.cpp
 * @brief Реализация нормализации координат вершин.
 * Этот файл содержит реализацию метода для нормализации координат вершин.
 * Нормализация приводит максимальное значение координат к заданному
 * коэффициенту нормализации.
 */

#include "s21_transformation.h"

namespace s21 {
/**
 * @brief Конструктор класса Normalize, задающий коэффициент нормализации.
 * @param scaleFactor Коэффициент нормализации, определяющий размер координат
 * после обработки.
 */
Normalize::Normalize(float scaleFactor) : scaleFactor_(scaleFactor) {}
/**
 * @brief Применяет нормализацию к координатам вершин.
 *
 * Функция вычисляет максимальное значение координат по модулю и нормализует их
 * так, чтобы оно стало равным заданному коэффициенту нормализации
 * (scaleFactor). Если вектор пустой или максимальное значение координат слишком
 * мало (меньше EPSILON), нормализация не выполняется.
 *
 * @param vectorVertexes Вектор, содержащий координаты вершин.
 *        Вершины предполагается хранить последовательно с фиксированным
 * размером измерения (VERTEX_DIMENSION).
 */
void Normalize::apply(std::vector<float>& vectorVertexes) {
  if (vectorVertexes.empty()) return;

  float maxVector = 0.0f;
  for (float vertex : vectorVertexes) {
    maxVector = std::max(maxVector, std::fabs(vertex));
  }

  if (maxVector > EPSILON) {
    float scale = scaleFactor_ / maxVector;
    for (float& vertex : vectorVertexes) {
      vertex *= scale;
    }
  }
}
}  // namespace s21