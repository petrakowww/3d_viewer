#include <iostream>

#include "s21_parser.h"

/**
 * @file s21_polygon_parser.cpp
 * @brief Реализация парсера для полигонов, который обрабатывает строки с
 * полигонами.
 *
 * Этот файл содержит реализацию класса PolygonParser, который предназначен для
 * парсинга строк, содержащих полигоны, извлекая индексы вершин и добавляя их в
 * менеджер вершин.
 */

namespace s21 {
/**
 * @brief Конструктор класса PolygonParser.
 *
 * Инициализирует объект PolygonParser, который будет работать с данным
 * менеджером вершин.
 *
 * @param manager Менеджер вершин, используемый для добавления полигонов.
 */
PolygonParser::PolygonParser(VertexManager &manager) : manager_(manager) {}
/**
 * @brief Парсит строку, содержащую данные полигона.
 *
 * Этот метод разбивает строку на части и извлекает индексы вершин, которые
 * составляют полигон. Если строка имеет неправильный формат, выбрасывается
 * исключение. Извлеченные индексы добавляются в соответствующий менеджер
 * полигонов.
 *
 * Формат строки: первые значения представляют индексы вершин полигона.
 * Пример строки: "f 1/2/3 4/5/6 7/8/9", где индексы разделены слэшами.
 *
 * @param line Строка данных полигона, которую необходимо распарсить.
 * @throws std::runtime_error Если строка имеет неправильный формат.
 */
void PolygonParser::parseLine(const std::string &line) {
  std::istringstream iss(line);
  std::vector<unsigned int> polygon;
  std::string vertex;
  std::string prefix;
  iss >> prefix;
  while (iss >> vertex) {
    size_t pos = vertex.find('/');
    int index = std::stoi(vertex.substr(0, pos));
    polygon.push_back(index);
  }

  if (iss.fail() && !iss.eof()) {
    throw std::runtime_error("Invalid polygon format: " + line);
  }

  manager_.addPolygon(polygon);
}
}  // namespace s21