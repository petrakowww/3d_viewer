#ifndef S21_OPEN_GL_VIEW_H_
#define S21_OPEN_GL_VIEW_H_

#include <QImage>
#include <QMouseEvent>
#include <QOpenGLWidget>

#include "../settings/s21_settings_view.h"

namespace s21 {
class ObjectController;
}

namespace s21 {
class OpenGLView : public QOpenGLWidget {
  Q_OBJECT
 public:
  explicit OpenGLView(QWidget* parent = nullptr);
  void setController(ObjectController* controller);
  Settings& getSettingsReference();
  QImage captureFrameBuffer();

 protected:
  void initializeGL() override;
  void resizeGL(int width, int height) override;
  void paintGL() override;

 private:
  Settings settings_{};
  void mousePressEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;

  void setupProjection();
  void drawVertices(const std::vector<float>& vertices);
  void drawEdges(const std::vector<unsigned int>& indices);

  ObjectController* controller_ = nullptr;

  float xRot = 0.0f;
  float yRot = 0.0f;
  float xRotLast = 0.0f;
  float yRotLast = 0.0f;
  QPoint mousePos_;
};
}  // namespace s21

#include "../../controller/s21_controller.h"

#endif  // S21_OPEN_GL_VIEW_H_
