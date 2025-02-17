#include "../../model/validation/s21_validator.h"
#include "../s21_tests.h"

class ValidatorTest : public ::testing::Test {
 protected:
  s21::Validator validator;
};

// Тест проверки валидного набора вершин
TEST_F(ValidatorTest, ValidVertexes) {
  std::vector<float> validVertexes = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
  validator.checkVertexes(validVertexes);
  EXPECT_TRUE(validator.validate());
}

// Тест проверки неверного набора вершин (некратное количество координат)
TEST_F(ValidatorTest, InvalidVertexes) {
  std::vector<float> invalidVertexes = {1.0f, 2.0f};
  validator.checkVertexes(invalidVertexes);
  EXPECT_FALSE(validator.validate());
}

// Тест проверки валидного набора граней
TEST_F(ValidatorTest, ValidFacets) {
  std::vector<unsigned int> validFacets = {0, 1, 2};
  int countVertexes = 3;
  validator.checkFacets(validFacets, countVertexes);
  EXPECT_FALSE(validator.validate());
}

// Тест проверки неверного набора граней (индекс превышает количество вершин)
TEST_F(ValidatorTest, InvalidFacetsIndexOutOfRange) {
  std::vector<unsigned int> invalidFacets = {0, 1, 4};
  int countVertexes = 3;
  validator.checkFacets(invalidFacets, countVertexes);
  EXPECT_FALSE(validator.validate());
}

// Тест проверки неверного набора граней (неправильная длина массива)
TEST_F(ValidatorTest, InvalidFacetsLength) {
  std::vector<unsigned int> invalidFacets = {
      0, 1};  // Не кратно POLYGON_PREFIX_LENGTH
  int countVertexes = 3;
  validator.checkFacets(invalidFacets, countVertexes);
  EXPECT_TRUE(validator.validate());
}

// Тест сброса валидатора и повторной проверки
TEST_F(ValidatorTest, ResetValidator) {
  std::vector<float> invalidVertexes = {1.0f, 2.0f};
  validator.checkVertexes(invalidVertexes);
  EXPECT_FALSE(validator.validate());

  // Сброс валидатора и проверка валидного ввода
  validator.check().checkVertexes({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
  EXPECT_TRUE(validator.validate());
}

// Тест комбинированной проверки вершин и граней
TEST_F(ValidatorTest, CombinedValidation) {
  std::vector<float> vertexes = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
  std::vector<unsigned int> facets = {0, 1, 2};

  validator.checkVertexes(vertexes).checkFacets(
      facets, vertexes.size() / s21::VERTEX_DIMENSION);
  EXPECT_FALSE(validator.validate());
}

// Тест комбинированной проверки с ошибкой
TEST_F(ValidatorTest, CombinedValidationWithError) {
  std::vector<float> vertexes = {1.0f, 2.0f};  // Некорректный набор вершин
  std::vector<unsigned int> facets = {0, 1, 2};

  validator.checkVertexes(vertexes).checkFacets(
      facets, vertexes.size() / s21::VERTEX_DIMENSION);
  EXPECT_FALSE(validator.validate());
}
