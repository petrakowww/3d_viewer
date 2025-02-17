/**
 * @file s21_object_model.h
 * @brief Класс для работы с 3D-моделью, которая управляет вершинами и
 * полигонами.
 *
 * Класс `ObjectModel` управляет вершинами, полигонами и трансформациями
 * 3D-модели. Он позволяет загружать модели из файлов, добавлять вершины и
 * полигоны, а также применять различные трансформации, такие как
 * масштабирование, повороты и сдвиг.
 */

#ifndef S21_OBJECT_MODEL_H_
#define S21_OBJECT_MODEL_H_

#include <string>
#include <vector>

#include "../affine/s21_affine.h"
#include "../affine/transform/s21_transformation.h"
#include "../parser/s21_parser.h"
#include "../validation/s21_validator.h"
#include "../vertex/s21_vertex_manager.h"
namespace s21 {
/**
 * @brief Класс для работы с 3D-моделью.
 *
 * Класс управляет вершинами и полигонами модели, предоставляя методы для их
 * добавления, загрузки, а также применения трансформаций (повороты,
 * масштабирование и сдвиг). Реализует паттерн Singleton, чтобы обеспечить
 * единственный экземпляр объекта в течение всего времени работы программы.
 */
class ObjectModel {
 public:
  ObjectModel(ObjectModel const &) = delete;
  void operator=(ObjectModel const &) = delete;

  void clear();

  void addVertex(float x, float y, float z);

  void addPolygon(std::vector<unsigned int> &polygon);

  static ObjectModel &getInstance();

  std::vector<float> &getVertexes() const;

  std::vector<unsigned int> &getPolygons();

  bool loadModel(const std::string &path);

  int getCountVertexes() const;

  int getCountPolygons() const;

  int getCountEdges() const;

  void centralize() const;

  void normalize(float scaleFactor) const;

  void shift(float shiftX, float shiftY, float shiftZ) const;

  void scale(float coefficient) const;

  void rotateZ(float angle) const;

  void rotateY(float angle) const;

  void rotateX(float angle) const;

 private:
  ObjectModel();
  VertexManager vertexManager_;
};
}  // namespace s21

#endif  // S21_OBJECT_MODEL_H_
