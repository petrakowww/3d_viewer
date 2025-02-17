/**
 * @file s21_object_model.cpp
 * @brief Класс для работы с 3D-моделью, которая управляет вершинами и
 * полигонами.
 *
 * Класс `ObjectModel` реализует функциональность для загрузки, добавления и
 * обработки данных модели, таких как вершины и полигоны. Он использует паттерн
 * Singleton для получения единственного экземпляра, а также включает методы для
 * очистки и валидации данных модели.
 */

#include "s21_object_model.h"

namespace s21 {
/**
 * @brief Конструктор класса ObjectModel, инициализирующий менеджер вершин.
 *
 * Этот конструктор создает объект модели, инициализируя внутренний менеджер
 * вершин.
 */
ObjectModel::ObjectModel() : vertexManager_() {}

/**
 * @brief Получает единственный экземпляр объекта ObjectModel.
 *
 * Метод реализует паттерн Singleton, возвращая единственный экземпляр объекта
 * ObjectModel. Этот экземпляр будет существовать на протяжении всей работы
 * программы.
 *
 * @return Экземпляр объекта ObjectModel.
 */
ObjectModel &ObjectModel::getInstance() {
  static ObjectModel instance;
  return instance;
}

/**
 * @brief Загружает модель из файла по указанному пути.
 *
 * Функция очищает текущую модель, парсит файл и проверяет валидность данных
 * модели (вершин и граней). В случае успешной проверки возвращает true, в
 * противном случае - false.
 *
 * @param path Путь к файлу модели.
 * @return true, если модель загружена и проверена успешно; false, если возникла
 * ошибка.
 */
bool ObjectModel::loadModel(const std::string &path) {
  try {
    clear();
    ModelParser parser(vertexManager_);
    parser.parseFile(path);
    s21::Validator validator;
    return validator.check()
        .checkVertexes(getVertexes())
        .checkFacets(getPolygons(), getCountVertexes())
        .validate();
  } catch (const std::exception &e) {
    return false;
  }
}

/**
 * @brief Очищает текущую модель, удаляя все вершины и полигоны.
 *
 * Функция сбрасывает данные модели, восстанавливая объект в исходное состояние.
 */
void ObjectModel::clear() { vertexManager_ = VertexManager(); }

/**
 * @brief Добавляет вершину в модель.
 *
 * Метод передает координаты вершины в менеджер вершин для их добавления.
 *
 * @param x Координата X вершины.
 * @param y Координата Y вершины.
 * @param z Координата Z вершины.
 */
void ObjectModel::addVertex(float x, float y, float z) {
  return vertexManager_.addVertex(x, y, z);
}

/**
 * @brief Добавляет многоугольник в модель.
 *
 * Метод передает список индексов вершин полигона в менеджер вершин для
 * добавления.
 *
 * @param polygon Вектор индексов вершин, составляющих полигон.
 */
void ObjectModel::addPolygon(std::vector<unsigned int> &polygon) {
  return vertexManager_.addPolygon(polygon);
}

/**
 * @brief Получает список всех вершин модели.
 *
 * Функция возвращает ссылку на вектор, содержащий все вершины модели.
 * Для обеспечения совместимости с другими классами, возвращается неконстантная
 * ссылка на данные.
 *
 * @return Ссылка на вектор вершин модели.
 */
std::vector<float> &ObjectModel::getVertexes() const {
  return const_cast<std::vector<float> &>(vertexManager_.getVertices());
}

/**
 * @brief Получает список всех полигонов модели.
 *
 * Функция возвращает ссылку на вектор, содержащий все полигоны модели.
 *
 * @return Ссылка на вектор полигонов модели.
 */
std::vector<unsigned int> &ObjectModel::getPolygons() {
  return vertexManager_.getPolygons();
}

/**
 * @brief Получает количество вершин модели.
 *
 * Функция возвращает количество вершин, сохранённых в модели.
 *
 * @return Количество вершин в модели.
 */
int ObjectModel::getCountVertexes() const {
  return vertexManager_.getCountVertexes();
}

/**
 * @brief Получает количество полигонов модели.
 *
 * Функция возвращает количество полигонов, сохранённых в модели.
 *
 * @return Количество полигонов в модели.
 */
int ObjectModel::getCountPolygons() const {
  return vertexManager_.getCountPolygons();
}

/**
 * @brief Получает количество рёбер модели.
 *
 * Функция возвращает количество рёбер, сохранённых в модели.
 *
 * @return Количество рёбер в модели.
 */
int ObjectModel::getCountEdges() const {
  return vertexManager_.getCountEdges();
}

/**
 * @brief Выполняет поворот модели вокруг оси X.
 *
 * Метод применяет преобразование поворота модели на заданный угол относительно
 * оси X. Для выполнения поворота используется класс RotateX.
 *
 * @param angle Угол поворота в радианах.
 */
void ObjectModel::rotateX(float angle) const {
  Affine::applyTransformation(getVertexes(), new RotateX(angle));
}

/**
 * @brief Выполняет поворот модели вокруг оси Y.
 *
 * Метод применяет преобразование поворота модели на заданный угол относительно
 * оси Y. Для выполнения поворота используется класс RotateY.
 *
 * @param angle Угол поворота в радианах.
 */
void ObjectModel::rotateY(float angle) const {
  Affine::applyTransformation(getVertexes(), new RotateY(angle));
}

/**
 * @brief Выполняет поворот модели вокруг оси Z.
 *
 * Метод применяет преобразование поворота модели на заданный угол относительно
 * оси Z. Для выполнения поворота используется класс RotateZ.
 *
 * @param angle Угол поворота в радианах.
 */
void ObjectModel::rotateZ(float angle) const {
  Affine::applyTransformation(getVertexes(), new RotateZ(angle));
}

/**
 * @brief Масштабирует модель с использованием заданного коэффициента.
 *
 * Метод применяет преобразование масштабирования модели с заданным
 * коэффициентом. Для выполнения масштабирования используется класс ChangeScale.
 *
 * @param coefficient Коэффициент масштабирования.
 */
void ObjectModel::scale(float coefficient) const {
  Affine::applyTransformation(getVertexes(), new ChangeScale(coefficient));
}

/**
 * @brief Выполняет сдвиг модели по осям X, Y и Z.
 *
 * Метод применяет преобразование сдвига модели на заданные значения для осей X,
 * Y и Z. Для выполнения сдвига используется класс Shift.
 *
 * @param shiftX Сдвиг вдоль оси X.
 * @param shiftY Сдвиг вдоль оси Y.
 * @param shiftZ Сдвиг вдоль оси Z.
 */
void ObjectModel::shift(float shiftX, float shiftY, float shiftZ) const {
  Affine::applyTransformation(getVertexes(), new Shift(shiftX, shiftY, shiftZ));
}

/**
 * @brief Нормализует модель с использованием заданного масштабирующего фактора.
 *
 * Метод применяет преобразование нормализации модели с заданным масштабирующим
 * фактором. Для выполнения нормализации используется класс Normalize.
 *
 * @param scaleFactor Масштабирующий фактор.
 */
void ObjectModel::normalize(float scaleFactor) const {
  Affine::applyTransformation(getVertexes(), new Normalize(scaleFactor));
}

/**
 * @brief Центрирует модель в исходной системе координат.
 *
 * Метод применяет преобразование для центрирования модели, т.е. перемещает её в
 * центр координатной системы. Для выполнения центрирования используется класс
 * Centralize.
 */
void ObjectModel::centralize() const {
  Affine::applyTransformation(getVertexes(), new Centralize());
}
}  // namespace s21
