/**
 * @file s21_validator.h
 * @brief Класс для проверки валидности данных 3D-модели.
 *
 * Этот файл содержит определение класса `Validator`, который выполняет
 * валидацию данных 3D-модели, таких как вершины и полигоны. Класс предоставляет
 * методы для проверки корректности этих данных.
 */

#ifndef S21_VALIDATOR_H_
#define S21_VALIDATOR_H_

#include <algorithm>
#include <cmath>
#include <tuple>
#include <vector>

#include "../constants/s21_constants.h"

namespace s21 {
class Validator {
 public:
  Validator &check();

  Validator &checkVertexes(const std::vector<float> &vectorVertexes);

  Validator &checkFacets(std::vector<unsigned int> &polygons,
                         int countVertexes);

  bool validate() const;

 private:
  bool vertexesValid = true;
  bool facetsValid = true;
};
}  // namespace s21

#endif  // S21_VALIDATOR_H_
