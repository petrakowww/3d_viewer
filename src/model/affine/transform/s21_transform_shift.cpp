#include "s21_transformation.h"

/**
 * @file s21_transform_shift.cpp
 * @brief Реализация сдвига вершин в пространстве.
 *
 * Этот файл содержит реализацию класса Shift, который применяет сдвиг к
 * координатам вершин вдоль осей X, Y и Z.
 */

namespace s21 {
/**
 * @brief Конструктор класса Shift, инициализирующий значения сдвига вдоль осей
 * X, Y и Z.
 *
 * @param shiftX Значение сдвига вдоль оси X.
 * @param shiftY Значение сдвига вдоль оси Y.
 * @param shiftZ Значение сдвига вдоль оси Z.
 */
Shift::Shift(float shiftX, float shiftY, float shiftZ)
    : shiftX_(shiftX), shiftY_(shiftY), shiftZ_(shiftZ) {}

/**
 * @brief Применяет сдвиг координат вершин на заданные значения вдоль осей X, Y
 * и Z.
 *
 * Функция добавляет значения сдвига к координатам всех вершин в переданном
 * векторе.
 *
 * @param vectorVertexes Вектор, содержащий координаты вершин.
 *        Вершины предполагается хранить последовательно с фиксированным
 * размером измерения (VERTEX_DIMENSION).
 */
void Shift::apply(std::vector<float> &vectorVertexes) {
  size_t vertexCount = vectorVertexes.size() / VERTEX_DIMENSION;
  for (size_t i = 0; i < vertexCount; i++) {
    vectorVertexes[i * VERTEX_DIMENSION + X_AXIS] += shiftX_;
    vectorVertexes[i * VERTEX_DIMENSION + Y_AXIS] += shiftY_;
    vectorVertexes[i * VERTEX_DIMENSION + Z_AXIS] += shiftZ_;
  }
}

}  // namespace s21