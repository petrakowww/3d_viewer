#include "s21_parser.h"

/**
 * @file s21_vertex_parser.cpp
 * @brief Реализация парсера для вершин, который обрабатывает строки с данными о
 * вершинах.
 *
 * Этот файл содержит реализацию класса VertexParser, который предназначен для
 * парсинга строк, содержащих данные о вершинах, извлекая их координаты и
 * добавляя в менеджер вершин.
 */

namespace s21 {
/**
 * @brief Конструктор класса VertexParser, связывающий парсер с менеджером
 * вершин.
 *
 * @param manager Ссылка на объект VertexManager, который управляет вершинами.
 */
VertexParser::VertexParser(VertexManager &manager) : manager_(manager) {}
/**
 * @brief Обрабатывает строку, содержащую данные о вершине, и добавляет её в
 * менеджер вершин.
 *
 * Функция считывает координаты вершины из строки формата "v x y z" и передаёт
 * их в объект VertexManager для добавления. Если строка имеет некорректный
 * формат, выбрасывается исключение.
 *
 * @param line Строка, содержащая данные о вершине (должна начинаться с "v" и
 * содержать три координаты).
 *
 * @throw std::runtime_error Если строка имеет неверный формат вершины.
 */
void VertexParser::parseLine(const std::string &line) {
  float a = 0, b = 0, c = 0;
  if (std::sscanf(line.c_str(), "v %f %f %f", &a, &b, &c) ==
      s21::VERTEX_DIMENSION) {
    manager_.addVertex(a, b, c);
  } else {
    throw std::runtime_error("Invalid vertex format: " + line);
  }
}
}  // namespace s21