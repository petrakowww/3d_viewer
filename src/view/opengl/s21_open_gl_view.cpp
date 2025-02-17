#include "s21_open_gl_view.h"

namespace s21 {
OpenGLView::OpenGLView(QWidget *parent) : QOpenGLWidget(parent) {}

void OpenGLView::initializeGL() { glEnable(GL_DEPTH_TEST); }

void OpenGLView::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void OpenGLView::paintGL() {
  if (!controller_) return;

  const auto &vertices = controller_->getVertexes();
  const auto &indices = controller_->getPolygons();

  QColor bgColor = settings_.backgroundColor;
  glClearColor(bgColor.redF(), bgColor.greenF(), bgColor.blueF(),
               bgColor.alphaF());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  setupProjection();
  drawVertices(vertices);
  drawEdges(indices);
}

void OpenGLView::mousePressEvent(QMouseEvent *event) {
  mousePos_ = event->pos();
  xRotLast = xRot;
  yRotLast = yRot;
}

void OpenGLView::mouseMoveEvent(QMouseEvent *event) {
  float dx = rotationFactor * (event->pos().y() - mousePos_.y());
  float dy = rotationFactor * (event->pos().x() - mousePos_.x());
  xRot = xRotLast + dx;
  yRot = yRotLast + dy;
  update();
}

void OpenGLView::setController(ObjectController *controller) {
  controller_ = controller;
}

void OpenGLView::setupProjection() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (settings_.projectionType == ProjectionType::PARALLEL) {
    glOrtho(-1.0, 1.0, -1.0, 1.0, 2, 100);
  } else {
    glFrustum(-1.0, 1.0, -1.0, 1.0, 2, 100);
  }
  glTranslated(0.0, 0.0, -3);
  glRotatef(xRot, 1.0f, 0.0f, 0.0f);
  glRotatef(yRot, 0.0f, 1.0f, 0.0f);
}

void OpenGLView::drawVertices(const std::vector<float> &vertices) {
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(VERTEX_DIMENSION, GL_FLOAT, 0, vertices.data());

  if (settings_.vertexType != VertexType::NONE) {
    glColor3f(settings_.vertexColor.redF(), settings_.vertexColor.greenF(),
              settings_.vertexColor.blueF());
    glPointSize(settings_.vertexThickness);

    if (settings_.vertexType == VertexType::CIRCLE) {
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glEnable(GL_POINT_SMOOTH);
    } else if (settings_.vertexType == VertexType::SQUARE) {
      glDisable(GL_POINT_SMOOTH);
    }

    glDrawArrays(GL_POINTS, 0, vertices.size() / VERTEX_DIMENSION);
  }

  glDisableClientState(GL_VERTEX_ARRAY);
}

void OpenGLView::drawEdges(const std::vector<unsigned int> &indices) {
  glEnableClientState(GL_VERTEX_ARRAY);
  glColor3f(settings_.edgeColor.redF(), settings_.edgeColor.greenF(),
            settings_.edgeColor.blueF());
  glLineWidth(settings_.edgeThickness);

  if (settings_.lineType == LineType::DASHED) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(dashedLineRepeat, dashedLinePattern);
  }

  glDrawElements(GL_LINES, indices.size(), GL_UNSIGNED_INT, indices.data());

  if (settings_.lineType == LineType::DASHED) {
    glDisable(GL_LINE_STIPPLE);
  }

  glDisableClientState(GL_VERTEX_ARRAY);
}

Settings &OpenGLView::getSettingsReference() { return settings_; }
}  // namespace s21
