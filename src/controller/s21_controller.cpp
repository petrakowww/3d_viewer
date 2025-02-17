/**
 * @file s21_controller.cpp
 * @brief Реализация методов класса ObjectController.
 *
 * Этот файл содержит реализацию методов контроллера, отвечающих за управление
 * моделью 3D-объекта и взаимодействие с представлением. Контроллер обрабатывает
 * операции над объектом, такие как загрузка, перемещение, поворот,
 * масштабирование и получение информации о модели.
 */

#include "s21_controller.h"

namespace s21 {
/**
 * @brief Конструктор класса ObjectController.
 *
 * Инициализирует объект контроллера, получая ссылки на экземпляры модели
 * (ObjectModel) и представления (ViewPresenter) через их методы
 * `getInstance()`.
 */
ObjectController::ObjectController()
    : model_(ObjectModel::getInstance()),
      view_(ViewPresenter::getInstance(this)) {}

/**
 * @brief Загружает 3D-модель из файла.
 * @param path Путь к файлу модели.
 * @return true, если модель успешно загружена, иначе false.
 */
bool ObjectController::loadModel(const std::string &path) {
  return model_.loadModel(path);
}

/**
 * @brief Перемещает модель в заданном направлении.
 * @param x Смещение по оси X.
 * @param y Смещение по оси Y.
 * @param z Смещение по оси Z.
 */
void ObjectController::moveModel(float x, float y, float z) {
  model_.shift(x, y, z);
}

/**
 * @brief Поворачивает модель вокруг оси X.
 * @param angle Угол поворота в градусах.
 */
void ObjectController::rotateModelX(float angle) { model_.rotateX(angle); }

/**
 * @brief Поворачивает модель вокруг оси Y.
 * @param angle Угол поворота в градусах.
 */
void ObjectController::rotateModelY(float angle) { model_.rotateY(angle); }

/**
 * @brief Поворачивает модель вокруг оси Z.
 * @param angle Угол поворота в градусах.
 */
void ObjectController::rotateModelZ(float angle) { model_.rotateZ(angle); }

/**
 * @brief Изменяет масштаб модели.
 * @param scale Коэффициент масштаба (больше 1 - увеличение, меньше 1 -
 * уменьшение).
 */
void ObjectController::changeScale(float scale) { model_.scale(scale); }

/**
 * @brief Устанавливает центр модели в начале координат.
 */
void ObjectController::setCenter() { model_.centralize(); }

/**
 * @brief Очищает загруженную модель.
 */
void ObjectController::clearModel() { model_.clear(); }

/**
 * @brief Возвращает количество вершин модели.
 * @return Количество вершин.
 */
int ObjectController::getCountVertexes() const {
  return model_.getCountVertexes();
}

/**
 * @brief Возвращает количество полигонов модели.
 * @return Количество полигонов.
 */
int ObjectController::getCountPolygons() const {
  return model_.getCountPolygons();
}

/**
 * @brief Возвращает количество рёбер модели.
 * @return Количество рёбер.
 */
int ObjectController::getCountEdges() const { return model_.getCountEdges(); }

/**
 * @brief Получает координаты всех вершин модели.
 * @return Константная ссылка на вектор координат вершин.
 */
const std::vector<float> &ObjectController::getVertexes() {
  return model_.getVertexes();
}

/**
 * @brief Получает индексы вершин, формирующих полигоны модели.
 * @return Вектор индексов вершин полигонов.
 */
std::vector<unsigned int> ObjectController::getPolygons() {
  return model_.getPolygons();
}
}  // namespace s21