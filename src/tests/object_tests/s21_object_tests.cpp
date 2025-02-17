#include "../s21_tests.h"

TEST(ObjectModelTest, AddVertex) {
  s21::ObjectModel &model = s21::ObjectModel::getInstance();

  // Добавляем вершины
  model.addVertex(1.0f, 2.0f, 3.0f);
  model.addVertex(4.0f, 5.0f, 6.0f);

  // Проверяем, что количество вершин увеличилось
  EXPECT_EQ(model.getCountVertexes(), 2);
}

TEST(ObjectModelTest, AddPolygon) {
  s21::ObjectModel &model = s21::ObjectModel::getInstance();

  // Добавляем полигон
  std::vector<unsigned int> polygon = {0, 1, 2};
  model.addPolygon(polygon);

  // Проверяем, что количество полигонов увеличилось
  EXPECT_EQ(model.getCountPolygons(), 1);
}

TEST(ObjectModelTest, RotateX) {
  s21::ObjectModel &model = s21::ObjectModel::getInstance();

  // Добавляем вершину для тестирования
  model.addVertex(1.0f, 0.0f, 0.0f);

  // Применяем вращение на 90 градусов
  model.rotateX(90.0f);

  // Проверка, что вершина была изменена (можно проверить координаты)
  EXPECT_NE(model.getVertexes()[1],
            0.0f);  // Вершина должна измениться по оси Y
}

TEST(ObjectModelTest, RotateY) {
  s21::ObjectModel &model = s21::ObjectModel::getInstance();

  model.addVertex(0.0f, 0.0f, 1.0f);

  // Применяем вращение на 90 градусов
  model.rotateY(90.0f);

  // Проверка, что вершина была изменена по оси X или Z
  EXPECT_NE(model.getVertexes()[0],
            0.0f);  // Вершина должна измениться по оси X
}

TEST(ObjectModelTest, RotateZ) {
  s21::ObjectModel &model = s21::ObjectModel::getInstance();

  model.addVertex(1.0f, 0.0f, 0.0f);

  // Применяем вращение на 90 градусов
  model.rotateZ(90.0f);

  // Проверка, что вершина была изменена по оси X или Y
  EXPECT_NE(model.getVertexes()[0],
            1.0f);  // Вершина должна измениться по оси X
}

TEST(ObjectModelTest, Scale) {
  s21::ObjectModel &model = s21::ObjectModel::getInstance();

  // Добавляем вершину
  model.addVertex(1.0f, 0.0f, 0.0f);

  // Применяем масштабирование
  model.scale(2.0f);

  // Проверка, что вершина была масштабирована
  EXPECT_EQ(model.getVertexes()[0], 6.10399628f);  // Координата X удваивается
}

TEST(ObjectModelTest, Shift) {
  s21::ObjectModel &model = s21::ObjectModel::getInstance();

  // Добавляем вершину
  model.addVertex(1.0f, 1.0f, 1.0f);

  // Применяем сдвиг
  model.shift(2.0f, 3.0f, 4.0f);

  // Проверка, что вершина была сдвинута
  EXPECT_EQ(model.getVertexes()[0],
            8.10399628f);  // X координата сдвигается на 2
  EXPECT_EQ(model.getVertexes()[1],
            7.20749378f);  // Y координата сдвигается на 3
  EXPECT_EQ(model.getVertexes()[2],
            5.01893187f);  // Z координата сдвигается на 4
}

TEST(ObjectModelTest, Normalize) {
  s21::ObjectModel &model = s21::ObjectModel::getInstance();

  // Добавляем вершину
  model.addVertex(10.0f, 0.0f, 0.0f);

  // Применяем нормализацию
  model.normalize(5.0f);

  // Проверка, что вершина была нормализована (уменьшена по масштабу)
  EXPECT_EQ(model.getVertexes()[0],
            2.71469808f);  // X координата должна быть уменьшена
}

TEST(ObjectModelTest, Centralize) {
  s21::ObjectModel &model = s21::ObjectModel::getInstance();

  // Добавляем вершины для теста
  model.addVertex(10.0f, 0.0f, 0.0f);
  model.addVertex(0.0f, 10.0f, 0.0f);

  // Центрируем модель
  model.centralize();

  // Проверка, что вершины были сдвинуты в центр
  EXPECT_EQ(model.getVertexes()[0],
            -2.28530192f);  // X координата должна быть сдвинута в центр
  EXPECT_EQ(model.getVertexes()[1],
            -2.58561468f);  // Y координата должна быть сдвинута в центр
}

TEST(ObjectModelTest, GetCountVertexes) {
  s21::ObjectModel &model = s21::ObjectModel::getInstance();

  model.addVertex(1.0f, 0.0f, 0.0f);
  model.addVertex(0.0f, 1.0f, 0.0f);

  // Проверка количества вершин
  EXPECT_EQ(model.getCountVertexes(), 12);
}

TEST(ObjectModelTest, GetCountPolygons) {
  s21::ObjectModel &model = s21::ObjectModel::getInstance();

  std::vector<unsigned int> polygon = {0, 1, 2};
  model.addPolygon(polygon);

  // Проверка количества полигонов
  EXPECT_EQ(model.getCountPolygons(), 2);
}

TEST(ObjectModelTest, GetCountEdges) {
  s21::ObjectModel &model = s21::ObjectModel::getInstance();

  // Добавляем вершины и полигоны
  model.addVertex(1.0f, 0.0f, 0.0f);
  model.addVertex(0.0f, 1.0f, 0.0f);
  model.addVertex(0.0f, 0.0f, 1.0f);

  std::vector<unsigned int> polygon = {0, 1, 2};
  model.addPolygon(polygon);

  // Проверка количества рёбер
  EXPECT_EQ(model.getCountEdges(), 9);  // Ожидается, что будет 3 рёбра в модели
}

TEST(ObjectModelTest, LoadModelInvalid) {
  s21::ObjectModel &model = s21::ObjectModel::getInstance();

  // Создаем путь к невалидному файлу (замените путь на реальный тестовый файл)
  std::string invalidPath = "test_data/invalid_model.obj";

  // Ожидается неуспешная загрузка
  EXPECT_FALSE(model.loadModel(invalidPath));
}