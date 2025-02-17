/**
 * @file s21_affine.h
 * @brief Заголовочный файл, предоставляющий класс для применения аффинных
 * преобразований.
 *
 * Этот файл содержит класс `Affine`, который используется для применения
 * различных аффинных преобразований к вектору координат вершин с использованием
 * интерфейса `ITransformation`.
 */

#ifndef S21_AFFINE_H_
#define S21_AFFINE_H_

#include <vector>

#ifndef S21_TRANSFORMATION_H_LIB
#define S21_TRANSFORMATION_H_LIB
#include "transform/s21_transformation.h"
#endif

namespace s21 {
/**
 * @class Affine
 * @brief Класс для применения аффинных преобразований.
 *
 * Класс предоставляет статический метод для применения различных аффинных
 * преобразований (например, масштабирования, поворота, сдвига и т.д.) к
 * координатам вершин. Метод использует интерфейс `ITransformation` для
 * универсальности.
 */
class Affine {
 public:
  Affine() = delete;

  static void applyTransformation(std::vector<float>& vectorVertexes,
                                  ITransformation* transformation) {
    transformation->apply(vectorVertexes);
  }
};
}  // namespace s21

#endif  // S21_AFFINE_H_