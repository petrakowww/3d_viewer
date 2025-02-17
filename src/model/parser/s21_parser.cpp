#include "s21_parser.h"

/**
 * @file s21_parser.cpp
 * @brief Реализация парсера, который считывает данные из файла и обрабатывает
 * их.
 *
 * Этот файл содержит реализацию класса Parser, который отвечает за чтение
 * данных из файла и их обработку строками с помощью метода `parseLine`.
 */

namespace s21 {
/**
 * @brief Парсит файл и обрабатывает каждую строку.
 *
 * Метод открывает файл по указанному пути, считывает его содержимое построчно и
 * передает каждую строку методу `parseLine` для дальнейшей обработки. Если файл
 * не может быть открыт, выбрасывается исключение.
 *
 * @param path Путь к файлу, который нужно распарсить.
 * @throws std::runtime_error Если файл не может быть открыт.
 */
void Parser::parseFile(const std::string &path) {
  std::ifstream file(path);
  if (!file.is_open()) {
    throw std::runtime_error("Unable to open the file: " + path);
  }

  std::string line;
  while (std::getline(file, line)) {
    parseLine(line);
  }
}
}  // namespace s21