#include <QApplication>

#include "controller/s21_controller.h"
#include "model/object/s21_object_model.h"
#include "view/qt/s21_view.h"

int main(int argc, char *argv[]) {
  QApplication application(argc, argv);

  s21::ObjectController controller;

  s21::ViewPresenter &window = s21::ViewPresenter::getInstance(&controller);

  window.show();

  return application.exec();
}
