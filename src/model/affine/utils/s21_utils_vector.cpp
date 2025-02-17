#include "s21_utils_vector.h"

/**
 * @file s21_utils_vector.cpp
 * @brief Заголовочный файл с утилитами для работы с векторами координат вершин.
 *
 * Этот файл предоставляет вспомогательные функции для работы с векторами
 * координат вершин, такие как вычисление и установка центра вдоль заданной оси.
 */

namespace s21 {
/**
 * @brief Вычисляет центр вдоль заданной оси для вектора координат вершин.
 *
 * Функция находит центр (среднее между минимальным и максимальным значением)
 * вдоль указанной оси для координат, хранящихся в переданном векторе.
 *
 * @param vectorVertexes Вектор, содержащий координаты вершин.
 *        Вершины предполагается хранить последовательно с фиксированным
 * размером измерения (VERTEX_DIMENSION).
 * @param axis Ось (0 для x, 1 для y, 2 для z и т.д.), вдоль которой вычисляется
 * центр.
 * @return Вычисленное значение центра вдоль заданной оси.
 */
float VectorUtils::getCenter(const std::vector<float> &vectorVertexes,
                             int axis) {
  float min = vectorVertexes[axis];
  float max = vectorVertexes[axis];
  for (size_t i = 0; i < vectorVertexes.size() / VERTEX_DIMENSION; i++) {
    float value = vectorVertexes[i * VERTEX_DIMENSION + axis];
    min = std::min(min, value);
    max = std::max(max, value);
  }
  return (max + min) / 2.0f;
}
/**
 * @brief Устанавливает центр вдоль заданной оси для вектора координат вершин.
 *
 * Функция сдвигает координаты вершин вдоль указанной оси так, чтобы их центр
 * совпал с заданным значением.
 *
 * @param vectorVertexes Вектор, содержащий координаты вершин.
 *        Вершины предполагается хранить последовательно с фиксированным
 * размером измерения (VERTEX_DIMENSION).
 * @param axis Ось (0 для x, 1 для y, 2 для z и т.д.), вдоль которой будет
 * установлен новый центр.
 * @param center Новое значение центра вдоль заданной оси.
 */
void VectorUtils::setCenter(std::vector<float> &vectorVertexes, int axis,
                            float center) {
  float currentCenter = getCenter(vectorVertexes, axis);
  float delta = center - currentCenter;
  for (size_t i = 0; i < vectorVertexes.size() / VERTEX_DIMENSION; i++) {
    vectorVertexes[i * VERTEX_DIMENSION + axis] += delta;
  }
}
}  // namespace s21