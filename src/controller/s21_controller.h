/**
 * @file s21_controller.h
 * @brief Заголовочный файл контроллера объекта.
 *
 * Этот файл содержит объявление класса `ObjectController`, который управляет
 * моделью объекта и взаимодействует с представлением. Контроллер предоставляет
 * функции для загрузки модели, управления её положением, поворотом, масштабом и
 * получения информации о модели.
 */

#ifndef S21_CONTROLLER_H_
#define S21_CONTROLLER_H_

namespace s21 {

/**
 * @class ObjectController
 * @brief Класс-контроллер для управления 3D-моделью и её представлением.
 *
 * `ObjectController` предоставляет интерфейс для загрузки, изменения и
 * получения информации о 3D-модели. Используется для взаимодействия между
 * моделью и представлением.
 */
class ObjectModel;
class ViewPresenter;
}  // namespace s21

#include <string>
#include <vector>

namespace s21 {
class ObjectController {
 public:
  ObjectController();

  bool loadModel(const std::string& path);

  void moveModel(float x, float y, float z);

  void rotateModelX(float angle);

  void rotateModelY(float angle);

  void rotateModelZ(float angle);

  void changeScale(float scale);

  void setCenter();

  const std::vector<float>& getVertexes();

  std::vector<unsigned int> getPolygons();

  int getCountVertexes() const;

  int getCountPolygons() const;

  int getCountEdges() const;

  void clearModel();

 private:
  ObjectModel& model_;
  ViewPresenter& view_;
};
}  // namespace s21

#include "../model/object/s21_object_model.h"
#include "../view/qt/s21_view.h"

#endif  // S21_CONTROLLER_H_
