/**
 * @file s21_vector_utils.h
 * @brief Заголовочный файл с утилитами для работы с векторами координат вершин.
 *
 * Этот файл содержит вспомогательные функции для работы с векторами координат
 * вершин, такие как вычисление и установка центра вдоль заданной оси для набора
 * вершин.
 */

#ifndef S21_VECTOR_UTILS_H_
#define S21_VECTOR_UTILS_H_

#include <cmath>
#include <stdexcept>
#include <vector>

#include "../../constants/s21_constants.h"

namespace s21 {
/**
 * @class VectorUtils
 * @brief Класс с утилитами для работы с векторами координат вершин.
 *
 * Этот класс предоставляет статические методы для вычисления центра координат
 * вдоль оси и сдвига координат вершин так, чтобы центр оказался на заданной
 * оси.
 */
class VectorUtils {
 public:
  static float getCenter(const std::vector<float> &vectorVertexes, int axis);

  static void setCenter(std::vector<float> &vectorVertexes, int axis,
                        float center);
};
}  // namespace s21

#endif  // S21_VECTOR_UTILS_H_
