#ifndef S21_SETTINGS_VIEW_H_
#define S21_SETTINGS_VIEW_H_

#include <QColor>
#include <QOpenGLBuffer>
#include <cmath>

namespace s21 {
constexpr int jpgFormat = 1;
constexpr int bmpFormat = 0;

constexpr float baseScaleFactor = 25.0;
constexpr float moveScaleFactor = 20.0;
constexpr float edgeThicknessScale = 10.0;
constexpr float rotationFactor = 2.0f / M_PI;

constexpr double maxScale = 50.0;
constexpr double minScale = 1;

const float sliderMax = 50.0;
const float sliderMin = 1;

const float defaultVertexThickness = 0.5f;
const float defaultEdgeThickness = 0.5f;
const int defaultMove = 0;
const int defaultRotate = 0;

constexpr GLuint dashedLinePattern = 0x0101;
constexpr GLint dashedLineRepeat = 1;

enum class ProjectionType { PARALLEL, CENTRAL };
enum class LineType { SOLID, DASHED };
enum class VertexType { NONE, CIRCLE, SQUARE };

const QColor defaultBackgroundColor = Qt::black;
const QColor defaultVertexColor = Qt::white;
const QColor defaultEdgeColor = Qt::white;
const VertexType defaultVertexType = VertexType::NONE;
const ProjectionType defaultProjectionType = ProjectionType::CENTRAL;
const LineType defaultLineType = LineType::SOLID;

struct Settings {
  int moveX = defaultMove;
  int moveY = defaultMove;
  int moveZ = defaultMove;
  int rotateX = defaultRotate;
  int rotateY = defaultRotate;
  int rotateZ = defaultRotate;
  double scale = baseScaleFactor;

  ProjectionType projectionType = defaultProjectionType;
  LineType lineType = defaultLineType;
  VertexType vertexType = defaultVertexType;

  QColor backgroundColor = defaultBackgroundColor;
  QColor vertexColor = defaultVertexColor;
  QColor edgeColor = defaultEdgeColor;

  float vertexThickness = defaultVertexThickness;
  float edgeThickness = defaultEdgeThickness;
};

namespace info {
const QString nameProject = "S21_ABALONEM_SAMUROSE_CASANDRA_PROJECT";
const QString nameApp = "3DViewer";
const QString BACKGROUND_COLOR_TITLE = "Выберите цвет фона";
const QString LINE_COLOR_TITLE = "Выберите цвет линий";
const QString VERTEX_COLOR_TITLE = "Выберите цвет вершин";

const QString INVALID_MODEL_DATA_MSG = "Некорректные данные в модели!!!";
const QString INVALID_MODEL_TITLE = "Некорректные данные в модели";
const QString OPEN_FILE_DIALOG_TITLE = "Open OBJ File";
const QString FILE_FILTER = "OBJ Files (*.obj)";

const QString NOTIFICATION = "Уведомление";
const QString ERROR = "Ошибка";

const QString MODEL_ERROR_LABEL_SET = "Не выбрана модель для рендеринга";
const QString MODEL_SUCCESS_LABEL = "Изображение сохранено в папке с моделью";

const QString MODEL_ERROR_LABEL_SAVE =
    "Не удалось сохранить изображение. Проверьте права для записи в папке с "
    "моделью.";
const QString CANCEL_ACTION = "При выборе действие было отменено";

const QString GIF_SUCCESS_LABEL =
    QObject::tr("Анимация сохранена в папке с моделью.");
const QString GIF_ERROR_LABEL_SAVE =
    QObject::tr("Не удалось сохранить анимацию.");

const QString GIF_NO_MODEL_ALERT =
    QObject::tr("Вы не загрузили модель для демонстрации.");
const QString GIF_RECORD_PROMPT =
    QObject::tr("Будут записаны все действия с моделью в течение 5 секунд.");
}  // namespace info

namespace keys {
const QString backgroundColor = "backgroundColor";
const QString vertexColor = "vertexColor";
const QString edgeColor = "edgeColor";
const QString vertexType = "vertexType";
const QString projectionType = "projectionType";
const QString lineType = "lineType";
const QString vertexThickness = "vertexThickness";
const QString edgeThickness = "edgeThickness";
const QString moveX = "moveX";
const QString moveY = "moveY";
const QString moveZ = "moveZ";
const QString rotateX = "rotateX";
const QString rotateY = "rotateY";
const QString rotateZ = "rotateZ";
const QString scale = "scale";
}  // namespace keys

namespace window {
const int width = 640;
const int heigth = 480;
}  // namespace window

namespace styles {
const QString DARK_THEME_STYLES = R"(
    QMainWindow {
      background-color: #121212;
      color: rgb(228, 228, 228);
    }
    QWidget {
      background-color: #121212;
      color:rgb(228, 228, 228);
      font-family: Roboto, sans-serif;
      font-size: 12px;
    }
    QPushButton {
      background-color: #1e1e1e;
      color: rgb(228, 228, 228);
      border-radius: 5px;
      padding: 5px 10px;
    }
    QPushButton:hover {
      background-color: #323232;
      border-color: #c0c0c0;
    }

    QPushButton:pressed {
      background-color: #454545;
      border-color: rgb(228, 228, 228);
    }
    QScrollBar:horizontal {
      background: #2e2e2e;
      height: 14px;
      border: none;
      border-radius: 4px;
      padding: 0px 14px 0px 14px;
    }

    QScrollBar::handle:horizontal {
        background:rgb(97, 97, 97);
        border: none;
        border-radius: 7px;
        width: 14px;
        height: 14px;
        min-width: 14px;
        max-width: 14px;
    }

    QScrollBar::handle:horizontal:hover {
        background: rgb(102, 102, 102);
    }
    QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {
        border: none;
        width: 0px
    }
)";
}
}  // namespace s21

#endif  // S21_SETTINGS_VIEW_H_
