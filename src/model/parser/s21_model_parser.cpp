#include <string.h>

#include "s21_parser.h"

/**
 * @file s21_model_parser.cpp
 * @brief Реализация парсера модели, который обрабатывает строки с вершинами и
 * полигонами.
 *
 * Этот файл содержит реализацию класса ModelParser, который предназначен для
 * обработки строк данных модели, извлекая информацию о вершинах и полигонах.
 * Класс использует другие парсеры для обработки отдельных типов данных, таких
 * как вершины (с помощью vertexParser_) и полигоны (с помощью polygonParser_).
 */
namespace s21 {
/**
 * @brief Конструктор класса ModelParser.
 *
 * Инициализирует объекты парсеров для вершин и полигонов.
 *
 * @param manager Менеджер вершин, используемый для добавления данных в модель.
 */
ModelParser::ModelParser(VertexManager &manager)
    : vertexParser_(manager), polygonParser_(manager) {}

/**
 * @brief Парсит одну строку данных.
 *
 * В зависимости от содержимого строки, этот метод вызывает соответствующие
 * парсеры для обработки вершин или полигонов. Если строка начинается с "v ", то
 * вызывается парсер для вершин. Если строка начинается с "f ", то вызывается
 * парсер для полигонов.
 *
 * @param line Строка данных, которую нужно распарсить.
 */
void ModelParser::parseLine(const std::string &line) {
  const char *c_line = line.c_str();
  if (strncmp(c_line, "v ", 2) == 0) {
    vertexParser_.parseLine(line);
  } else if (strncmp(c_line, "f ", 2) == 0) {
    polygonParser_.parseLine(line);
  }
}
}  // namespace s21