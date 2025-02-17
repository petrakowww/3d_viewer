#include "../s21_tests.h"

TEST(VectorUtilsTest, GetCenterXAxis) {
  std::vector<float> vertices3D = {1.0f, 2.0f,  3.0f,  4.0f, 5.0f,
                                   6.0f, -1.0f, -2.0f, -3.0f};
  float centerX = s21::VectorUtils::getCenter(vertices3D, 0);
  EXPECT_FLOAT_EQ(centerX, 1.5f);
}

TEST(VectorUtilsTest, GetCenterYAxis) {
  std::vector<float> vertices3D = {1.0f, 2.0f,  3.0f,  4.0f, 5.0f,
                                   6.0f, -1.0f, -2.0f, -3.0f};
  float centerY = s21::VectorUtils::getCenter(vertices3D, 1);
  EXPECT_FLOAT_EQ(centerY, 1.5f);
}

TEST(VectorUtilsTest, GetCenterZAxis) {
  std::vector<float> vertices3D = {1.0f, 2.0f,  3.0f,  4.0f, 5.0f,
                                   6.0f, -1.0f, -2.0f, -3.0f};
  float centerZ = s21::VectorUtils::getCenter(vertices3D, 2);
  EXPECT_FLOAT_EQ(centerZ, 1.5f);
}

TEST(VectorUtilsTest, BoundaryValues) {
  std::vector<float> vertices3D = {1.0f, 2.0f,  3.0f,  4.0f, 5.0f,
                                   6.0f, -1.0f, -2.0f, -3.0f};
  std::vector<float> largeVertices = {
      std::numeric_limits<float>::lowest(), 0.0f, 0.0f,
      std::numeric_limits<float>::max(),    0.0f, 0.0f};
  float centerX = s21::VectorUtils::getCenter(vertices3D, 0);
  EXPECT_FLOAT_EQ(centerX, 1.5f);
}

TEST(VectorUtilsTest, SetCenterXAxis) {
  std::vector<float> vertices3D = {1.0f, 2.0f,  3.0f,  4.0f, 5.0f,
                                   6.0f, -1.0f, -2.0f, -3.0f};
  s21::VectorUtils::setCenter(vertices3D, 0, 10.0f);
  float newCenter = s21::VectorUtils::getCenter(vertices3D, 0);
  EXPECT_FLOAT_EQ(newCenter, 10.0f);
}

TEST(VectorUtilsTest, SetCenterYAxis) {
  std::vector<float> vertices3D = {1.0f, 2.0f,  3.0f,  4.0f, 5.0f,
                                   6.0f, -1.0f, -2.0f, -3.0f};
  s21::VectorUtils::setCenter(vertices3D, 1, -5.0f);
  float newCenter = s21::VectorUtils::getCenter(vertices3D, 1);
  EXPECT_FLOAT_EQ(newCenter, -5.0f);
}

TEST(VectorUtilsTest, SetCenterZAxis) {
  std::vector<float> vertices3D = {1.0f, 2.0f,  3.0f,  4.0f, 5.0f,
                                   6.0f, -1.0f, -2.0f, -3.0f};
  s21::VectorUtils::setCenter(vertices3D, 2, 0.0f);
  float newCenter = s21::VectorUtils::getCenter(vertices3D, 2);
  EXPECT_FLOAT_EQ(newCenter, 0.0f);
}

TEST(CentralizeTest, CentralizeMovesToOrigin) {
  std::vector<float> vertices3D = {1.0f, 2.0f,  3.0f,  4.0f, 5.0f,
                                   6.0f, -1.0f, -2.0f, -3.0f};
  s21::Centralize centralizer;
  centralizer.apply(vertices3D);
  EXPECT_FLOAT_EQ(s21::VectorUtils::getCenter(vertices3D, s21::X_AXIS), 0.0f);
  EXPECT_FLOAT_EQ(s21::VectorUtils::getCenter(vertices3D, s21::Y_AXIS), 0.0f);
  EXPECT_FLOAT_EQ(s21::VectorUtils::getCenter(vertices3D, s21::Z_AXIS), 0.0f);
}

TEST(CentralizeTest, AlreadyCentralizedNoChange) {
  std::vector<float> vertices3D = {-1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
                                   -1.0f, 0.0f, 0.0f, 0.0f};
  s21::Centralize centralizer;
  centralizer.apply(vertices3D);
  std::vector<float> expectedVertices = {-1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
                                         -1.0f, 0.0f, 0.0f, 0.0f};
  EXPECT_EQ(vertices3D, expectedVertices);
}

TEST(ChangeScaleTest, ScaleByTwo) {
  std::vector<float> vertices3D = {-1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
                                   -1.0f, 0.0f, 0.0f, 0.0f};
  s21::ChangeScale scaler(2.0f);
  scaler.apply(vertices3D);
  std::vector<float> expected = {-2.0f, 0.0f, 2.0f, 2.0f, 0.0f,
                                 -2.0f, 0.0f, 0.0f, 0.0f};
  EXPECT_EQ(vertices3D, expected);
}

TEST(NormalizeTest, BasicNormalization) {
  std::vector<float> vertices3D = {2.0f,  4.0f,  6.0f,  8.0f, 10.0f,
                                   12.0f, -2.0f, -4.0f, -6.0f};

  s21::Normalize normalizer(s21::DEFAULT_SCALE_FACTOR);
  normalizer.apply(vertices3D);

  // Ожидаемая максимальная величина в нормализованном векторе
  float expectedMax = s21::DEFAULT_SCALE_FACTOR;
  float actualMax = *std::max_element(
      vertices3D.begin(), vertices3D.end(),
      [](float a, float b) { return std::fabs(a) < std::fabs(b); });

  // Проверяем, что максимальная величина нормализованного вектора соответствует
  // ожидаемому значению
  EXPECT_NEAR(std::fabs(actualMax), expectedMax, s21::EPSILON);
}

TEST(NormalizeTest, DifferentScaleFactor) {
  std::vector<float> vertices3D = {2.0f,  4.0f,  6.0f,  8.0f, 10.0f,
                                   12.0f, -2.0f, -4.0f, -6.0f};

  // Пользовательский коэффициент масштабирования
  float customScaleFactor = 2.0f;
  s21::Normalize normalizer(customScaleFactor);
  normalizer.apply(vertices3D);

  // Ожидаемая максимальная величина после нормализации
  float expectedMax = customScaleFactor;
  float actualMax = *std::max_element(
      vertices3D.begin(), vertices3D.end(),
      [](float a, float b) { return std::fabs(a) < std::fabs(b); });

  // Проверяем, что максимальная величина нормализованного вектора соответствует
  // ожидаемому значению
  EXPECT_NEAR(std::fabs(actualMax), expectedMax, s21::EPSILON);
}

TEST(NormalizeTest, SingleElementVector) {
  std::vector<float> singleVertex = {42.0f};

  // Нормализуем вектор с одним элементом
  s21::Normalize normalizer(s21::DEFAULT_SCALE_FACTOR);
  normalizer.apply(singleVertex);

  // Ожидаем, что единственная вершина будет нормализована до значения
  // DEFAULT_SCALE_FACTOR
  EXPECT_NEAR(singleVertex[0], s21::DEFAULT_SCALE_FACTOR, s21::EPSILON);
}

TEST(RotateXTest, ZeroRotation) {
  // Создаем угол 0 градусов
  float angle = 0.0f;

  // Создаем объект для вращения по оси X с углом 0
  s21::RotateX rotateX(angle);

  // Исходные вершины
  std::vector<float> vertices = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};

  // Ожидаемые вершины остаются теми же
  std::vector<float> expectedVertices = vertices;

  // Применяем вращение
  rotateX.apply(vertices);

  // Проверяем, что результат соответствует ожидаемому
  for (size_t i = 0; i < vertices.size(); i++) {
    EXPECT_NEAR(vertices[i], expectedVertices[i], s21::EPSILON);
  }
}

TEST(RotateXTest, Rotation180Degrees) {
  // Создаем угол 180 градусов (Pi)
  float angle = M_PI;

  // Создаем объект для вращения по оси X с углом 180
  s21::RotateX rotateX(angle);

  // Исходные вершины
  std::vector<float> vertices = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};

  // Ожидаемые вершины после вращения на 180 градусов по оси X
  std::vector<float> expectedVertices = {1.0f, -2.0f, -3.0f,
                                         4.0f, -5.0f, -6.0f};

  // Применяем вращение
  rotateX.apply(vertices);

  // Проверяем, что результат соответствует ожидаемому с учетом EPSILON
  for (size_t i = 0; i < vertices.size(); i++) {
    EXPECT_NEAR(vertices[i], expectedVertices[i], s21::EPSILON);
  }
}

TEST(RotateYTest, BasicRotation) {
  // Создаем угол 90 градусов (Pi / 2)
  float angle = M_PI / 2.0f;

  // Создаем объект для вращения по оси Y с заданным углом
  s21::RotateY rotateY(angle);

  // Исходные вершины
  std::vector<float> vertices = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};

  // Ожидаемые вершины после вращения на 90 градусов по оси Y
  std::vector<float> expectedVertices = {3.0f, 2.0f, -1.0f, 6.0f, 5.0f, -4.0f};

  // Применяем вращение
  rotateY.apply(vertices);

  // Проверяем, что результат соответствует ожидаемому с учетом EPSILON
  for (size_t i = 0; i < vertices.size(); i++) {
    EXPECT_NEAR(vertices[i], expectedVertices[i], s21::EPSILON);
  }
}

TEST(RotateYTest, ZeroRotation) {
  // Создаем угол 0 градусов
  float angle = 0.0f;

  // Создаем объект для вращения по оси Y с углом 0
  s21::RotateY rotateY(angle);

  // Исходные вершины
  std::vector<float> vertices = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};

  // Ожидаемые вершины остаются теми же
  std::vector<float> expectedVertices = vertices;

  // Применяем вращение
  rotateY.apply(vertices);

  // Проверяем, что результат соответствует ожидаемому
  for (size_t i = 0; i < vertices.size(); i++) {
    EXPECT_NEAR(vertices[i], expectedVertices[i], s21::EPSILON);
  }
}

TEST(RotateYTest, Rotation180Degrees) {
  // Создаем угол 180 градусов (Pi)
  float angle = M_PI;

  // Создаем объект для вращения по оси Y с углом 180
  s21::RotateY rotateY(angle);

  // Исходные вершины
  std::vector<float> vertices = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};

  // Ожидаемые вершины после вращения на 180 градусов по оси Y
  std::vector<float> expectedVertices = {-1.0f, 2.0f, -3.0f,
                                         -4.0f, 5.0f, -6.0f};

  // Применяем вращение
  rotateY.apply(vertices);

  // Проверяем, что результат соответствует ожидаемому с учетом EPSILON
  for (size_t i = 0; i < vertices.size(); i++) {
    EXPECT_NEAR(vertices[i], expectedVertices[i], s21::EPSILON);
  }
}

TEST(RotateZTest, ZeroRotation) {
  // Создаем угол 0 градусов
  float angle = 0.0f;

  // Создаем объект для вращения по оси Z с углом 0
  s21::RotateZ rotateZ(angle);

  // Исходные вершины
  std::vector<float> vertices = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};

  // Ожидаемые вершины остаются теми же
  std::vector<float> expectedVertices = vertices;

  // Применяем поворот
  rotateZ.apply(vertices);

  // Проверяем, что результат соответствует ожидаемому
  for (size_t i = 0; i < vertices.size(); i++) {
    EXPECT_NEAR(vertices[i], expectedVertices[i], s21::EPSILON);
  }
}

TEST(RotateZTest, Rotation180Degrees) {
  // Создаем угол 180 градусов (Pi)
  float angle = M_PI;

  // Создаем объект для вращения по оси Z с углом 180
  s21::RotateZ rotateZ(angle);

  // Исходные вершины
  std::vector<float> vertices = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};

  // Ожидаемые вершины после поворота на 180 градусов по оси Z
  std::vector<float> expectedVertices = {-1.0f, -2.0f, 3.0f,
                                         -4.0f, -5.0f, 6.0f};

  // Применяем поворот
  rotateZ.apply(vertices);

  // Проверяем, что результат соответствует ожидаемому с учетом погрешности
  for (size_t i = 0; i < vertices.size(); i++) {
    EXPECT_NEAR(vertices[i], expectedVertices[i], s21::EPSILON);
  }
}

TEST(ShiftTest, BasicShift) {
  float shiftX = 1.0f;
  float shiftY = 2.0f;
  float shiftZ = 3.0f;
  s21::Shift shift(shiftX, shiftY, shiftZ);
  std::vector<float> vertices = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
  std::vector<float> expectedVertices = {2.0f, 4.0f, 6.0f, 5.0f, 7.0f, 9.0f};
  shift.apply(vertices);
  for (size_t i = 0; i < vertices.size(); i++) {
    EXPECT_NEAR(vertices[i], expectedVertices[i], s21::EPSILON);
  }
}

TEST(ShiftTest, ZeroShift) {
  float shiftX = 0.0f;
  float shiftY = 0.0f;
  float shiftZ = 0.0f;
  s21::Shift shift(shiftX, shiftY, shiftZ);
  std::vector<float> vertices = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
  std::vector<float> expectedVertices = vertices;
  shift.apply(vertices);
  for (size_t i = 0; i < vertices.size(); i++) {
    EXPECT_NEAR(vertices[i], expectedVertices[i], s21::EPSILON);
  }
}

TEST(ShiftTest, SingleAxisShift) {
  float shiftX = 5.0f;
  float shiftY = 0.0f;
  float shiftZ = 0.0f;
  s21::Shift shift(shiftX, shiftY, shiftZ);
  std::vector<float> vertices = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
  std::vector<float> expectedVertices = {6.0f, 2.0f, 3.0f, 9.0f, 5.0f, 6.0f};
  shift.apply(vertices);
  for (size_t i = 0; i < vertices.size(); i++) {
    EXPECT_NEAR(vertices[i], expectedVertices[i], s21::EPSILON);
  }
}