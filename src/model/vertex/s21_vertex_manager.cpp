/**
 * @file s21_vertex_manager.h
 * @brief Реализация класса VertexManager.
 *
 * Класс VertexManager управляет добавлением вершин, полигонов и рёбер в модель.
 * Он отслеживает количество вершин, полигонов и рёбер и предоставляет методы
 * для получения этих данных и работы с ними.
 */

#include "s21_vertex_manager.h"

namespace s21 {
/**
 * @brief Конструктор класса VertexManager.
 *
 * Инициализирует счетчики полигонов, вершин и рёбер значениями 0.
 */
VertexManager::VertexManager()
    : countPolygons_(0), countVertexes_(0), countEdges_(0) {}

/**
 * @brief Добавляет вершину в модель.
 *
 * Метод добавляет вершину с координатами (x, y, z) в модель.
 * Вершины добавляются в вектор вершин, и увеличивается количество вершин.
 *
 * @param x Координата X вершины.
 * @param y Координата Y вершины.
 * @param z Координата Z вершины.
 */
void VertexManager::addVertex(float x, float y, float z) {
  vertices_.push_back(x);
  vertices_.push_back(y);
  vertices_.push_back(z);
  ++countVertexes_;
}

/**
 * @brief Добавляет полигон в модель.
 *
 * Метод добавляет полигон, состоящий из индексов вершин. Также обновляется
 * количество рёбер и полигонов в модели. Индексы вершин в полигоне
 * преобразуются (уменьшаются на 1), чтобы соответствовать используемому в
 * системе индексации (с 0).
 *
 * @param polygon Вектор индексов вершин, составляющих полигон.
 */
void VertexManager::addPolygon(std::vector<unsigned int> &polygon) {
  polygons_.push_back(--polygon.front());
  for (auto it = polygon.begin() + 1; it != polygon.end(); ++it) {
    polygons_.push_back(--(*it));
    ++countEdges_;
    polygons_.push_back(*it);
  }
  polygons_.push_back(polygon.front());
  ++countEdges_;
  ++countPolygons_;
}

/**
 * @brief Получает количество вершин в модели.
 *
 * Возвращает количество вершин в модели, рассчитанное как размер вектора
 * вершин, делённый на размерность вершины (обычно 3).
 *
 * @return Количество вершин в модели.
 */
int VertexManager::getCountVertexes() const {
  return vertices_.size() / VERTEX_DIMENSION;
}

/**
 * @brief Получает количество полигонов в модели.
 *
 * Возвращает количество полигонов, добавленных в модель.
 *
 * @return Количество полигонов в модели.
 */
int VertexManager::getCountPolygons() const { return countPolygons_; }

/**
 * @brief Получает количество рёбер в модели.
 *
 * Возвращает количество рёбер в модели. Каждый полигон добавляет два рёбра,
 * поэтому количество рёбер зависит от количества полигонов.
 *
 * @return Количество рёбер в модели.
 */
int VertexManager::getCountEdges() const { return countEdges_; }

/**
 * @brief Получает список всех вершин модели.
 *
 * Возвращает ссылку на вектор, содержащий все вершины модели.
 * Вершины хранятся последовательно, каждая вершина состоит из 3 значений (x, y,
 * z).
 *
 * @return Ссылка на вектор вершин.
 */
const std::vector<float> &VertexManager::getVertices() const {
  return vertices_;
}

/**
 * @brief Получает список всех полигонов модели.
 *
 * Возвращает ссылку на вектор, содержащий все полигоны модели. Полигоны
 * представлены в виде индексов вершин, где индексы находятся в порядке обхода
 * рёбер.
 *
 * @return Ссылка на вектор полигонов.
 */
std::vector<unsigned int> &VertexManager::getPolygons() { return polygons_; }
}  // namespace s21
