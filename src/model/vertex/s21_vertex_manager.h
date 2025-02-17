/**
 * @file s21_vertex_manager.h
 * @brief Менеджер для управления вершинами и полигонами 3D-модели.
 *
 * Этот файл содержит определение класса `VertexManager`, который предназначен
 * для хранения и управления вершинами, полигонами и ребрами 3D-модели. Класс
 * предоставляет методы для добавления вершин и полигонов, а также получения
 * информации о модели.
 */

#ifndef S21_VERTEX_MANAGER_H_
#define S21_VERTEX_MANAGER_H_

#include <set>
#include <stdexcept>
#include <vector>

#include "../constants/s21_constants.h"

namespace s21 {
/**
 * @brief Класс для управления вершинами, полигонами и ребрами 3D-модели.
 *
 * Класс `VertexManager` предоставляет функциональность для добавления вершин и
 * полигонов, а также для получения информации о количестве вершин, полигонов и
 * рёбер. Он используется для хранения данных 3D-модели и выполнения операций с
 * этими данными.
 */
class VertexManager {
 public:
  VertexManager();
  void addVertex(float x, float y, float z);
  void addPolygon(std::vector<unsigned int> &polygon);

  const std::vector<float> &getVertices() const;
  std::vector<unsigned int> &getPolygons();

  int getCountVertexes() const;
  int getCountPolygons() const;
  int getCountEdges() const;

 private:
  std::vector<float> vertices_;
  std::vector<unsigned int> polygons_{};
  std::set<std::pair<unsigned int, unsigned int>> edgeSet_;
  int countPolygons_;
  int countVertexes_;
  int countEdges_;
};
}  // namespace s21

#endif  // S21_VERTEX_MANAGER_H_
