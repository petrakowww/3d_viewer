#ifndef S21_TRANSFORMATION_H_
#define S21_TRANSFORMATION_H_

#include <cmath>
#include <vector>

#include "../../constants/s21_constants.h"
#include "../utils/s21_utils_vector.h"

/**
 * @file s21_transformation.h
 * @brief Заголовочный файл, содержащий объявления классов для трансформаций
 * (поворот, сдвиг, масштабирование, нормализация, централизатор) вершин.
 *
 * Этот файл предоставляет интерфейсы и классы, которые выполняют различные
 * трансформации вершин в 3D пространстве, включая повороты вокруг осей X, Y и
 * Z, сдвиг, масштабирование и нормализацию.
 */

namespace s21 {
/**
 * @class ITransformation
 * @brief Абстрактный интерфейс для всех типов трансформаций.
 *
 * Этот интерфейс определяет метод `apply`, который должен быть реализован в
 * каждом классе, выполняющем определенную трансформацию вершин.
 */
class ITransformation {
 public:
  virtual void apply(std::vector<float> &vectorVertexes) = 0;
  virtual ~ITransformation() = default;
};

/**
 * @class Normalize
 * @brief Класс для нормализации вершин.
 *
 * Нормализация масштабирует все вершины так, чтобы их максимальная координата
 * была равна заданному значению коэффициента масштабирования.
 */
class Normalize : public ITransformation {
 public:
  explicit Normalize(float scaleFactor);
  void apply(std::vector<float> &vectorVertexes) override;

 private:
  float scaleFactor_;
};

/**
 * @class ChangeScale
 * @brief Класс для масштабирования вершин.
 *
 * Масштабирует все вершины с заданным коэффициентом.
 */
class ChangeScale : public ITransformation {
 public:
  explicit ChangeScale(float coefficient);
  void apply(std::vector<float> &vectorVertexes) override;

 private:
  float coefficient_;
};

/**
 * @class Centralize
 * @brief Класс для центрирования вершин.
 *
 * Централизует все вершины, устанавливая их центр в начало координат (0, 0, 0).
 */
class Centralize : public ITransformation {
 public:
  void apply(std::vector<float> &vectorVertexes) override;
};

/**
 * @class Shift
 * @brief Класс для сдвига вершин.
 *
 * Выполняет сдвиг вершин на заданное расстояние вдоль осей X, Y и Z.
 */
class Shift : public ITransformation {
 public:
  Shift(float shiftX, float shiftY, float shiftZ);
  void apply(std::vector<float> &vectorVertexes) override;

 private:
  float shiftX_, shiftY_, shiftZ_;
};

/**
 * @class Rotate
 * @brief Абстрактный класс для поворота вершин.
 *
 * Этот класс реализует общий функционал для всех поворотов вершин вокруг осей.
 * Он хранит угол поворота и предвычисленные значения синуса и косинуса угла.
 */
class Rotate : public ITransformation {
 public:
  explicit Rotate(float angle)
      : angle_(angle), cosAngle_(std::cos(angle)), sinAngle_(std::sin(angle)) {}

 protected:
  float angle_;
  float cosAngle_;
  float sinAngle_;
};

/**
 * @class RotateX
 * @brief Класс для поворота вершин вокруг оси X.
 *
 * Выполняет поворот всех вершин вокруг оси X на заданный угол.
 */
class RotateX : public Rotate {
 public:
  explicit RotateX(float angle);
  void apply(std::vector<float> &vectorVertexes) override;
};

/**
 * @class RotateY
 * @brief Класс для поворота вершин вокруг оси Y.
 *
 * Выполняет поворот всех вершин вокруг оси Y на заданный угол.
 */
class RotateY : public Rotate {
 public:
  explicit RotateY(float angle);
  void apply(std::vector<float> &vectorVertexes) override;
};

/**
 * @class NormaRotateZlize
 * @brief Класс для поворота вершин вокруг оси Z.
 *
 * Выполняет поворот всех вершин вокруг оси Z на заданный угол.
 */
class RotateZ : public Rotate {
 public:
  explicit RotateZ(float angle);
  void apply(std::vector<float> &vectorVertexes) override;
};
}  // namespace s21

#endif  // S21_TRANSFORMATION_H_
