/**
 * @file s21_parser.h
 * @brief Парсер для обработки данных 3D-моделей, включая вершины и полигоны.
 *
 * Этот файл содержит определение классов для парсинга данных моделей, таких как
 * вершины и полигоны. Классы предоставляют функциональность для чтения данных
 * из файлов, а также для их обработки и сохранения в менеджер вершин.
 */

#ifndef S21_PARSER_H_
#define S21_PARSER_H_

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "../constants/s21_constants.h"
#include "../vertex/s21_vertex_manager.h"

namespace s21 {
class Parser {
 public:
  virtual ~Parser() = default;

  virtual void parseLine(const std::string &line) = 0;

  void parseFile(const std::string &path);
};

class VertexParser : public Parser {
 public:
  explicit VertexParser(VertexManager &manager);

  void parseLine(const std::string &line) override;

 private:
  VertexManager &manager_;
};

class PolygonParser : public Parser {
 public:
  explicit PolygonParser(VertexManager &manager);

  void parseLine(const std::string &line) override;

 private:
  VertexManager &manager_;
};

class ModelParser : public Parser {
 public:
  ModelParser(VertexManager &manager);

  void parseLine(const std::string &line) override;

 private:
  VertexParser vertexParser_;
  PolygonParser polygonParser_;
};
}  // namespace s21

#endif  // S21_PARSER_H_
