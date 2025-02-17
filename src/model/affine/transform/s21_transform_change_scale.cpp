#include "s21_transformation.h"

/**
 * @file s21_transform_change_scale.cpp
 * @brief Реализация функции для изменения масштаба координат вершин.
 *
 * Этот файл содержит реализацию метода, который масштабирует координаты вершин
 * с использованием заданного коэффициента масштабирования.
 */

namespace s21 {
/**
 * @brief Конструктор класса ChangeScale, задающий коэффициент масштабирования.
 *
 * @param coefficient Коэффициент масштабирования, который будет применён к
 * координатам вершин.
 */
ChangeScale::ChangeScale(float coefficient) : coefficient_(coefficient) {}

/**
 * @brief Применяет изменение масштаба к координатам вершин.
 *
 * Функция масштабирует координаты вершин, используя заданный коэффициент
 * масштабирования. Если коэффициент равен 1 (DEFAULT_SCALE_FACTOR), изменений
 * не производится. Если коэффициент равен 0, все координаты устанавливаются в
 * 0.
 *
 * @param vectorVertexes Вектор, содержащий координаты вершин.
 *        Вершины предполагается хранить последовательно с фиксированным
 * размером измерения (VERTEX_DIMENSION).
 */
void ChangeScale::apply(std::vector<float>& vectorVertexes) {
  if (std::fabs(coefficient_ - DEFAULT_SCALE_FACTOR) <= EPSILON_SCALE) return;

  if (coefficient_ == 0) {
    std::fill(vectorVertexes.begin(), vectorVertexes.end(), 0.0f);
  } else {
    for (float& vertex : vectorVertexes) {
      vertex *= coefficient_;
    }
  }
}
}  // namespace s21