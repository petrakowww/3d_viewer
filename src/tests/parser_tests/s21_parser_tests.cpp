#include <fstream>
#include <sstream>

#include "../../model/parser/s21_parser.h"
#include "../s21_tests.h"

class VertexParserTest : public ::testing::Test {
 protected:
  s21::VertexManager manager;
  s21::VertexParser parser{manager};
};

TEST_F(VertexParserTest, ValidVertexParse) {
  std::string line = "v 1.0 2.0 3.0";
  EXPECT_NO_THROW(parser.parseLine(line));

  // Проверяем, что вершина добавлена
  EXPECT_EQ(manager.getCountVertexes(), 1);
}

TEST_F(VertexParserTest, InvalidVertexParse) {
  std::string line = "v 1.0 2.0";  // Недостаточно координат
  EXPECT_THROW(parser.parseLine(line), std::runtime_error);
}

class PolygonParserTest : public ::testing::Test {
 protected:
  s21::VertexManager manager;
  s21::PolygonParser parser{manager};
};

TEST_F(PolygonParserTest, ValidPolygonParse) {
  std::string line = "f 1/2/3 4/5/6 2/5/6";
  EXPECT_NO_THROW(parser.parseLine(line));

  // Проверяем, что полигон добавлен
  EXPECT_EQ(manager.getCountPolygons(), 1);
}

class ModelParserTest : public ::testing::Test {
 protected:
  s21::VertexManager manager;
  s21::ModelParser parser{manager};
};

TEST_F(ModelParserTest, ValidModelParse) {
  std::string vertexLine = "v 1.0 2.0 3.0";
  std::string polygonLine = "f 1/2/3 2/5/6 3/5/6";

  // Проверка разбора вершины
  EXPECT_NO_THROW(parser.parseLine(vertexLine));
  EXPECT_EQ(manager.getCountVertexes(), 1);

  // Проверка разбора полигона
  EXPECT_NO_THROW(parser.parseLine(polygonLine));
  EXPECT_EQ(manager.getCountPolygons(), 1);
}

class ParserFileTest : public ::testing::Test {
 protected:
  s21::VertexManager manager;
  s21::ModelParser parser{manager};
};

TEST_F(ParserFileTest, ValidFileParse) {
  // Создаем временный файл
  std::ofstream file("test_model.obj");
  file << "v 1.0 2.0 3.0\n";
  file << "f 1/2/3 4/5/6 2/5/6\n";
  file.close();

  // Проверяем парсинг файла
  EXPECT_NO_THROW(parser.parseFile("test_model.obj"));
  EXPECT_EQ(manager.getCountVertexes(), 1);
  EXPECT_EQ(manager.getCountPolygons(), 1);

  // Удаляем файл
  std::remove("test_model.obj");
}

TEST_F(ParserFileTest, InvalidFileParse) {
  // Создаем файл с ошибкой
  std::ofstream file("test_model_invalid.obj");
  file << "v 1.0 2.0\n";
  file << "f 1/2\n";  // Ошибка в полигоне
  file.close();

  // Проверяем выброс исключения
  EXPECT_THROW(parser.parseFile("test_model_invalid.obj"), std::runtime_error);

  // Удаляем файл
  std::remove("test_model_invalid.obj");
}
