#include "../s21_tests.h"

TEST(VertexManagerTest, ConstructorInitializesCorrectly) {
  s21::VertexManager vertexManager;

  // Проверяем, что счетчики равны 0
  EXPECT_EQ(vertexManager.getCountVertexes(), 0);
  EXPECT_EQ(vertexManager.getCountPolygons(), 0);

  // Проверяем, что списки пусты
  EXPECT_TRUE(vertexManager.getVertices().empty());
  EXPECT_TRUE(vertexManager.getPolygons().empty());
}

TEST(VertexManagerTest, AddVertexUpdatesVerticesAndCount) {
  s21::VertexManager vertexManager;

  // Добавляем вершину
  vertexManager.addVertex(1.0f, 2.0f, 3.0f);

  // Проверяем, что список вершин обновлен
  const auto& vertices = vertexManager.getVertices();
  ASSERT_EQ(vertices.size(),
            3);  // Ожидаем, что добавлены три координаты (x, y, z)
  EXPECT_FLOAT_EQ(vertices[0], 1.0f);
  EXPECT_FLOAT_EQ(vertices[1], 2.0f);
  EXPECT_FLOAT_EQ(vertices[2], 3.0f);

  // Проверяем, что счетчик вершин обновлен
  EXPECT_EQ(vertexManager.getCountVertexes(), 1);

  // Добавляем еще одну вершину
  vertexManager.addVertex(4.0f, 5.0f, 6.0f);

  // Проверяем обновленный список вершин
  ASSERT_EQ(vertices.size(),
            6);  // Ожидаем, что список теперь содержит 6 элементов
  EXPECT_FLOAT_EQ(vertices[3], 4.0f);
  EXPECT_FLOAT_EQ(vertices[4], 5.0f);
  EXPECT_FLOAT_EQ(vertices[5], 6.0f);

  // Проверяем обновленный счетчик
  EXPECT_EQ(vertexManager.getCountVertexes(), 2);
}

TEST(VertexManagerTest, AddPolygonUpdatesPolygonsAndCounters) {
  s21::VertexManager vertexManager;

  // Полигон с индексами вершин
  std::vector<unsigned int> polygon = {1, 2, 3};

  // Добавляем полигон
  vertexManager.addPolygon(polygon);

  // Проверяем, что список полигонов обновлен
  const auto& polygons = vertexManager.getPolygons();
  ASSERT_EQ(polygons.size(), 6);  // Полигон: {0, 1, 1, 2, 2, 0}
  EXPECT_EQ(polygons[0], 0);
  EXPECT_EQ(polygons[1], 1);
  EXPECT_EQ(polygons[2], 1);
  EXPECT_EQ(polygons[3], 2);
  EXPECT_EQ(polygons[4], 2);
  EXPECT_EQ(polygons[5], 0);

  // Проверяем, что счетчики обновлены
  EXPECT_EQ(vertexManager.getCountPolygons(), 1);
  EXPECT_EQ(vertexManager.getCountEdges(), 3);  // Полигон имеет 3 ребра
}

TEST(VertexManagerTest, AddMultiplePolygons) {
  s21::VertexManager vertexManager;

  // Добавляем первый полигон
  std::vector<unsigned int> polygon1 = {1, 2, 3};
  vertexManager.addPolygon(polygon1);

  // Добавляем второй полигон
  std::vector<unsigned int> polygon2 = {4, 5, 6};
  vertexManager.addPolygon(polygon2);

  // Проверяем, что список полигонов обновлен
  const auto& polygons = vertexManager.getPolygons();
  ASSERT_EQ(polygons.size(), 12);  // Два полигона по 6 индексов каждый
  EXPECT_EQ(polygons[0], 0);  // Полигон 1
  EXPECT_EQ(polygons[5], 0);  // Замыкающий индекс полигона 1
  EXPECT_EQ(polygons[6], 3);  // Полигон 2
  EXPECT_EQ(polygons[11], 3);  // Замыкающий индекс полигона 2

  // Проверяем, что счетчики обновлены
  EXPECT_EQ(vertexManager.getCountPolygons(), 2);
  EXPECT_EQ(vertexManager.getCountEdges(), 6);  // Суммарно 6 рёбер
}

TEST(VertexManagerTest, SingleVertexPolygon) {
  s21::VertexManager vertexManager;

  // Полигон с одной вершиной
  std::vector<unsigned int> singleVertexPolygon = {1};
  vertexManager.addPolygon(singleVertexPolygon);

  // Проверяем, что список полигонов корректен
  const auto& polygons = vertexManager.getPolygons();
  ASSERT_EQ(polygons.size(), 2);  // Замкнутый цикл: {0, 0}
  EXPECT_EQ(polygons[0], 0);
  EXPECT_EQ(polygons[1], 0);

  // Проверяем, что счетчики обновились корректно
  EXPECT_EQ(vertexManager.getCountPolygons(), 1);
  EXPECT_EQ(vertexManager.getCountEdges(), 1);  // Одно ребро
}

TEST(VertexManagerTest, CountVerticesInitiallyZero) {
  s21::VertexManager vertexManager;

  // Изначально список вершин пуст
  EXPECT_EQ(vertexManager.getCountVertexes(), 0);
}

TEST(VertexManagerTest, CountVerticesAfterAdding) {
  s21::VertexManager vertexManager;

  // Добавляем вершины
  vertexManager.addVertex(1.0f, 2.0f, 3.0f);
  vertexManager.addVertex(4.0f, 5.0f, 6.0f);

  // Проверяем, что метод верно возвращает количество вершин
  EXPECT_EQ(vertexManager.getCountVertexes(), 2);

  // Добавляем еще одну вершину
  vertexManager.addVertex(7.0f, 8.0f, 9.0f);

  // Проверяем обновленное количество вершин
  EXPECT_EQ(vertexManager.getCountVertexes(), 3);
}

TEST(VertexManagerTest, CountVerticesWithIncompleteData) {
  s21::VertexManager vertexManager;

  // Искусственно добавляем некорректные данные
  vertexManager.addVertex(1.0f, 2.0f, 3.0f);
  auto& vertices = const_cast<std::vector<float>&>(vertexManager.getVertices());
  vertices.push_back(4.0f);  // Добавляем "незавершённые" данные

  // Проверяем, что метод корректно игнорирует лишние элементы
  EXPECT_EQ(vertexManager.getCountVertexes(), 1);  // Только одна полная вершина
}

TEST(VertexManagerTest, CountPolygonsInitiallyZero) {
  s21::VertexManager vertexManager;

  // Изначально список полигонов пуст
  EXPECT_EQ(vertexManager.getCountPolygons(), 0);
}

TEST(VertexManagerTest, CountPolygonsAfterAdding) {
  s21::VertexManager vertexManager;

  // Добавляем полигоны
  std::vector<unsigned int> polygon1 = {1, 2, 3};
  std::vector<unsigned int> polygon2 = {4, 5, 6, 7};
  vertexManager.addPolygon(polygon1);
  vertexManager.addPolygon(polygon2);

  // Проверяем, что метод верно возвращает количество полигонов
  EXPECT_EQ(vertexManager.getCountPolygons(), 2);

  // Добавляем еще один полигон
  std::vector<unsigned int> polygon3 = {8, 9};
  vertexManager.addPolygon(polygon3);

  // Проверяем обновленное количество полигонов
  EXPECT_EQ(vertexManager.getCountPolygons(), 3);
}

TEST(VertexManagerTest, CountPolygonsAfterMultipleAdditions) {
  s21::VertexManager vertexManager;

  // Добавляем большое количество полигонов
  for (int i = 0; i < 100; ++i) {
    std::vector<unsigned int> polygon = {static_cast<unsigned int>(i),
                                         static_cast<unsigned int>(i + 1)};
    vertexManager.addPolygon(polygon);
  }

  // Проверяем, что количество полигонов корректно
  EXPECT_EQ(vertexManager.getCountPolygons(), 100);
}

TEST(VertexManagerTest, CountEdgesInitiallyZero) {
  s21::VertexManager vertexManager;

  // Изначально количество рёбер равно 0
  EXPECT_EQ(vertexManager.getCountEdges(), 0);
}

TEST(VertexManagerTest, CountEdgesAfterAddingPolygon) {
  s21::VertexManager vertexManager;

  // Добавляем первый полигон (3 вершины)
  std::vector<unsigned int> polygon1 = {1, 2, 3};
  vertexManager.addPolygon(polygon1);

  // Проверяем, что количество рёбер увеличилось (3 рёбер)
  EXPECT_EQ(vertexManager.getCountEdges(), 3);

  // Добавляем второй полигон (4 вершины)
  std::vector<unsigned int> polygon2 = {4, 5, 6, 7};
  vertexManager.addPolygon(polygon2);

  // Проверяем, что количество рёбер увеличилось (3 рёбер из первого + 4 рёбер
  // из второго)
  EXPECT_EQ(vertexManager.getCountEdges(), 7);
}

TEST(VertexManagerTest, CountEdgesAfterMultipleAdditions) {
  s21::VertexManager vertexManager;

  // Добавляем несколько полигонов
  for (int i = 0; i < 10; ++i) {
    std::vector<unsigned int> polygon = {static_cast<unsigned int>(i),
                                         static_cast<unsigned int>(i + 1)};
    vertexManager.addPolygon(polygon);
  }

  // Проверяем количество рёбер
  EXPECT_EQ(vertexManager.getCountEdges(), 20);
}

TEST(VertexManagerTest, GetVerticesInitiallyEmpty) {
  s21::VertexManager vertexManager;

  // Изначально вектор вершин пустой
  const auto& vertices = vertexManager.getVertices();
  EXPECT_TRUE(vertices.empty());
}

TEST(VertexManagerTest, GetVerticesAfterAddingOneVertex) {
  s21::VertexManager vertexManager;

  // Добавляем одну вершину
  vertexManager.addVertex(1.0f, 2.0f, 3.0f);

  // Проверяем, что вектор вершин содержит одну вершину
  const auto& vertices = vertexManager.getVertices();
  EXPECT_EQ(vertices.size(), 3);  // 3 значения для одной вершины (x, y, z)
  EXPECT_FLOAT_EQ(vertices[0], 1.0f);
  EXPECT_FLOAT_EQ(vertices[1], 2.0f);
  EXPECT_FLOAT_EQ(vertices[2], 3.0f);
}

TEST(VertexManagerTest, GetVerticesAfterAddingMultipleVertices) {
  s21::VertexManager vertexManager;

  // Добавляем несколько вершин
  vertexManager.addVertex(1.0f, 2.0f, 3.0f);
  vertexManager.addVertex(4.0f, 5.0f, 6.0f);
  vertexManager.addVertex(7.0f, 8.0f, 9.0f);

  // Проверяем, что вектор вершин содержит правильные данные
  const auto& vertices = vertexManager.getVertices();
  EXPECT_EQ(vertices.size(), 9);  // 3 вершины * 3 значения на каждую
  EXPECT_FLOAT_EQ(vertices[0], 1.0f);
  EXPECT_FLOAT_EQ(vertices[1], 2.0f);
  EXPECT_FLOAT_EQ(vertices[2], 3.0f);
  EXPECT_FLOAT_EQ(vertices[3], 4.0f);
  EXPECT_FLOAT_EQ(vertices[4], 5.0f);
  EXPECT_FLOAT_EQ(vertices[5], 6.0f);
  EXPECT_FLOAT_EQ(vertices[6], 7.0f);
  EXPECT_FLOAT_EQ(vertices[7], 8.0f);
  EXPECT_FLOAT_EQ(vertices[8], 9.0f);
}

TEST(VertexManagerTest, GetVerticesAfterAddingAndRemovingVertices) {
  s21::VertexManager vertexManager;

  // Добавляем вершины
  vertexManager.addVertex(1.0f, 2.0f, 3.0f);
  vertexManager.addVertex(4.0f, 5.0f, 6.0f);

  // Проверяем, что метод getVertices возвращает правильные данные
  const auto& vertices = vertexManager.getVertices();
  EXPECT_EQ(vertices.size(), 6);  // 2 вершины * 3 значения
  EXPECT_FLOAT_EQ(vertices[0], 1.0f);
  EXPECT_FLOAT_EQ(vertices[1], 2.0f);
  EXPECT_FLOAT_EQ(vertices[2], 3.0f);
  EXPECT_FLOAT_EQ(vertices[3], 4.0f);
  EXPECT_FLOAT_EQ(vertices[4], 5.0f);
  EXPECT_FLOAT_EQ(vertices[5], 6.0f);
}

TEST(VertexManagerTest, GetPolygonsInitiallyEmpty) {
  s21::VertexManager vertexManager;

  // Изначально вектор полигонов пуст
  const auto& polygons = vertexManager.getPolygons();
  EXPECT_TRUE(polygons.empty());
}

TEST(VertexManagerTest, GetPolygonsAfterAddingOnePolygon) {
  s21::VertexManager vertexManager;

  // Добавляем один полигон (индексы вершин)
  std::vector<unsigned int> polygon = {1, 2, 3};
  vertexManager.addPolygon(polygon);

  // Проверяем, что вектор полигонов содержит индексы добавленного полигона
  const auto& polygons = vertexManager.getPolygons();
  EXPECT_EQ(polygons.size(),
            6);  // Площадь 3 вершин -> 6 индексов (каждый ребро - два индекса)
  EXPECT_EQ(polygons[0],
            0);  // Индекс первой вершины полигона (с учётом уменьшения на 1)
  EXPECT_EQ(polygons[1], 1);  // Индекс второй вершины
  EXPECT_EQ(polygons[2], 1);  // Индекс второй вершины
  EXPECT_EQ(polygons[3], 2);  // Индекс третьей вершины
  EXPECT_EQ(polygons[4], 2);  // Индекс третьей вершины
  EXPECT_EQ(polygons[5], 0);  // Индекс первой вершины
}

TEST(VertexManagerTest, GetPolygonsAfterAddingMultiplePolygons) {
  s21::VertexManager vertexManager;

  // Добавляем два полигона
  std::vector<unsigned int> polygon1 = {1, 2, 3};
  std::vector<unsigned int> polygon2 = {4, 5, 6};
  vertexManager.addPolygon(polygon1);
  vertexManager.addPolygon(polygon2);

  // Проверяем, что вектор полигонов содержит индексы двух полигонов
  const auto& polygons = vertexManager.getPolygons();
  EXPECT_EQ(polygons.size(), 12);  // 2 полигона * 6 индексов на каждый
  EXPECT_EQ(polygons[0], 0);
  EXPECT_EQ(polygons[1], 1);
  EXPECT_EQ(polygons[2], 1);
  EXPECT_EQ(polygons[3], 2);
  EXPECT_EQ(polygons[4], 2);
  EXPECT_EQ(polygons[5], 0);
  EXPECT_EQ(polygons[6], 3);
  EXPECT_EQ(polygons[7], 4);
  EXPECT_EQ(polygons[8], 4);
  EXPECT_EQ(polygons[9], 5);
  EXPECT_EQ(polygons[10], 5);
  EXPECT_EQ(polygons[11], 3);
}

TEST(VertexManagerTest, GetPolygonsAfterAddingAndRemovingPolygons) {
  s21::VertexManager vertexManager;

  // Добавляем несколько полигонов
  std::vector<unsigned int> polygon1 = {1, 2, 3};
  std::vector<unsigned int> polygon2 = {4, 5, 6};
  vertexManager.addPolygon(polygon1);
  vertexManager.addPolygon(polygon2);

  // Проверяем, что метод getPolygons возвращает правильные индексы
  const auto& polygons = vertexManager.getPolygons();
  EXPECT_EQ(polygons.size(), 12);  // 2 полигона * 6 индексов
  EXPECT_EQ(polygons[0], 0);
  EXPECT_EQ(polygons[1], 1);
  EXPECT_EQ(polygons[2], 1);
  EXPECT_EQ(polygons[3], 2);
  EXPECT_EQ(polygons[4], 2);
  EXPECT_EQ(polygons[5], 0);
  EXPECT_EQ(polygons[6], 3);
  EXPECT_EQ(polygons[7], 4);
  EXPECT_EQ(polygons[8], 4);
  EXPECT_EQ(polygons[9], 5);
  EXPECT_EQ(polygons[10], 5);
  EXPECT_EQ(polygons[11], 3);
}