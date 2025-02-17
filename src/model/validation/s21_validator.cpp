#include "s21_validator.h"

/**
 * @file s21_validator.cpp
 * @brief Реализация класса Validator для проверки корректности данных модели.
 *
 * Этот файл содержит реализацию класса Validator, который проверяет
 * корректность данных модели: вершин и полигонов (граней). Класс позволяет
 * проверить, что количество вершин корректно, а индексы граней соответствуют
 * существующим вершинам.
 */

namespace s21 {
/**
 * @brief Инициализация проверки данных.
 *
 * Этот метод инициализирует флаги проверки вершин и граней на true.
 *
 * @return Ссылка на объект Validator для продолжения цепочки вызовов.
 */
Validator &Validator::check() {
  vertexesValid = true;
  facetsValid = true;
  return *this;
}

/**
 * @brief Проверяет корректность данных о вершинах.
 *
 * Этот метод проверяет, что размер вектора вершин кратен количеству компонент
 * каждой вершины (по умолчанию 3: x, y, z). Если это условие нарушено, флаг
 * корректности вершин устанавливается в false.
 *
 * @param vectorVertexes Вектор данных о вершинах.
 * @return Ссылка на объект Validator для продолжения цепочки вызовов.
 */
Validator &Validator::checkVertexes(const std::vector<float> &vectorVertexes) {
  if (vectorVertexes.size() % VERTEX_DIMENSION != 0) {
    vertexesValid = false;
    return *this;
  }

  return *this;
}

/**
 * @brief Проверяет корректность данных о гранях (полигонах).
 *
 * Этот метод проверяет, что количество элементов в векторе граней кратно
 * длине префикса полигона (по умолчанию 2), а также, что все индексы граней
 * соответствуют существующим вершинам. Если хотя бы одно из этих условий не
 * выполняется, флаг корректности граней устанавливается в false.
 *
 * @param polygons Вектор индексов граней.
 * @param countVertexes Общее количество вершин в модели.
 * @return Ссылка на объект Validator для продолжения цепочки вызовов.
 */
Validator &Validator::checkFacets(std::vector<unsigned int> &polygons,
                                  int countVertexes) {
  if (polygons.size() % POLYGON_PREFIX_LENGTH != 0) {
    facetsValid = false;
    return *this;
  }

  for (unsigned int element : polygons) {
    if (element >= static_cast<unsigned int>(countVertexes)) {
      facetsValid = false;
      return *this;
    }
  }

  return *this;
}

/**
 * @brief Проверяет, все ли данные о вершинах и гранях корректны.
 *
 * Этот метод возвращает результат валидации: если все проверки прошли успешно,
 * возвращается true, в противном случае — false.
 *
 * @return true, если все данные корректны, false — в противном случае.
 */
bool Validator::validate() const { return vertexesValid && facetsValid; }

}  // namespace s21
