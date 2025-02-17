#include "s21_view.h"

namespace s21 {
ViewPresenter::ViewPresenter(QWidget *parent, ObjectController *controller)
    : QMainWindow(parent), ui(new Ui::ViewPresenter), controller_(controller) {
  ui->setupUi(this);
  setSettingsReference(ui->openGLWidget->getSettingsReference());
  ui->openGLWidget->setController(controller_);
  loadSettings();
  applySettingsForRendering();
  setDarkTheme();
}

ViewPresenter &ViewPresenter::getInstance(
    ObjectController *controller = nullptr) {
  static ViewPresenter *instance = nullptr;
  if (instance == nullptr) {
    instance = new ViewPresenter(nullptr, controller);
  } else if (controller != nullptr) {
    instance->setController(controller);
  }
  return *instance;
}

void ViewPresenter::setSettingsReference(Settings &settings) {
  settingsRef_ = &settings;
}

double ViewPresenter::sliderToScale(int sliderValue) const {
  return std::clamp(
      minScale + ((sliderValue - sliderMin) / (sliderMax - sliderMin)) *
                     (maxScale - minScale),
      minScale, maxScale);
}

int ViewPresenter::scaleToSlider(double scale) const {
  return static_cast<int>(sliderMin +
                          ((scale - minScale) / (maxScale - minScale)) *
                              (sliderMax - sliderMin));
}

ViewPresenter::~ViewPresenter() {
  saveSettings();
  delete ui;
}

void ViewPresenter::setDarkTheme() {
  QString darkTheme = styles::DARK_THEME_STYLES;
  this->setStyleSheet(darkTheme);
}

void ViewPresenter::updateFileInfo(const QString &file_path) {
  QFileInfo fileInfo(file_path);
  QString file_name = fileInfo.fileName();

  ui->path_file_->setText(file_path);
  ui->file_name_->setText(file_name);
  ui->countEdges_->setText(QString::number(controller_->getCountEdges()));
  ui->count_polygons_->setText(
      QString::number(controller_->getCountPolygons()));
  ui->count_vertexes_->setText(
      QString::number(controller_->getCountVertexes()));
  ui->openGLWidget->update();
}

void ViewPresenter::saveSettings() {
  QSettings appSettings(info::nameProject, info::nameApp);
  qDebug() << "Saving settings...";
  appSettings.setValue(keys::backgroundColor,
                       settingsRef_->backgroundColor.name());
  appSettings.setValue(keys::vertexColor, settingsRef_->vertexColor.name());
  appSettings.setValue(keys::edgeColor, settingsRef_->edgeColor.name());
  appSettings.setValue(keys::vertexType,
                       static_cast<int>(settingsRef_->vertexType));
  appSettings.setValue(keys::projectionType,
                       static_cast<int>(settingsRef_->projectionType));
  appSettings.setValue(keys::lineType,
                       static_cast<int>(settingsRef_->lineType));
  appSettings.setValue(keys::vertexThickness, settingsRef_->vertexThickness);
  appSettings.setValue(keys::edgeThickness, settingsRef_->edgeThickness);
  appSettings.setValue(keys::moveX, settingsRef_->moveX);
  appSettings.setValue(keys::moveY, settingsRef_->moveY);
  appSettings.setValue(keys::moveZ, settingsRef_->moveZ);
  appSettings.setValue(keys::rotateX, settingsRef_->rotateX);
  appSettings.setValue(keys::rotateY, settingsRef_->rotateY);
  appSettings.setValue(keys::rotateZ, settingsRef_->rotateZ);
  appSettings.setValue(keys::scale, settingsRef_->scale);
  qDebug() << "scale save" << settingsRef_->scale;
}

void ViewPresenter::loadSettings() {
  QSettings appSettings(info::nameProject, info::nameApp);

  settingsRef_->backgroundColor =
      getSetting(appSettings, keys::backgroundColor, defaultBackgroundColor);
  settingsRef_->vertexColor =
      getSetting(appSettings, keys::vertexColor, defaultVertexColor);
  settingsRef_->edgeColor =
      getSetting(appSettings, keys::edgeColor, defaultEdgeColor);

  settingsRef_->vertexType =
      getSetting(appSettings, keys::vertexType, defaultVertexType);

  settingsRef_->projectionType =
      getSetting(appSettings, keys::projectionType, defaultProjectionType);

  settingsRef_->lineType =
      getSetting(appSettings, keys::lineType, defaultLineType);

  settingsRef_->vertexThickness =
      getSetting(appSettings, keys::vertexThickness, defaultVertexThickness);
  settingsRef_->edgeThickness =
      getSetting(appSettings, keys::edgeThickness, defaultEdgeThickness);

  settingsRef_->moveX = getSetting(appSettings, keys::moveX, defaultMove);
  settingsRef_->moveY = getSetting(appSettings, keys::moveY, defaultMove);
  settingsRef_->moveZ = getSetting(appSettings, keys::moveZ, defaultMove);

  settingsRef_->rotateX = getSetting(appSettings, keys::rotateX, defaultRotate);
  settingsRef_->rotateY = getSetting(appSettings, keys::rotateY, defaultRotate);
  settingsRef_->rotateZ = getSetting(appSettings, keys::rotateZ, defaultRotate);

  settingsRef_->scale = getSetting(appSettings, keys::scale, baseScaleFactor);

  qDebug() << "scale load" << settingsRef_->scale;

  qDebug() << "Loaded settings: Scale =" << settingsRef_->scale
           << ", MoveX =" << settingsRef_->moveX
           << ", RotateX =" << settingsRef_->rotateX;
}

template <typename T>
T ViewPresenter::getSetting(QSettings &settings, const QString &key,
                            const T &defaultValue) {
  if constexpr (std::is_enum_v<T>) {
    return static_cast<T>(
        settings.value(key, static_cast<int>(defaultValue)).toInt());
  } else {
    return settings.value(key, defaultValue).template value<T>();
  }
}

void ViewPresenter::applySettingsForRendering() {
  toggleButtons(ui->parralel_but_, ui->central_but_,
                settingsRef_->projectionType == ProjectionType::PARALLEL);
  toggleButtons(ui->dotted_, ui->solid_,
                settingsRef_->lineType == LineType::DASHED);
  toggleButtons(ui->cicle_, ui->square_,
                settingsRef_->vertexType == VertexType::CIRCLE);

  ui->line_thickness_->setValue(settingsRef_->edgeThickness);
  ui->size_vertices_->setValue(settingsRef_->vertexThickness);

  ui->scale_->blockSignals(true);
  ui->scale_->setValue(settingsRef_->scale);
  ui->scale_->blockSignals(false);

  settingsRef_->scale = baseScaleFactor;

  ui->move_x_->setValue(settingsRef_->moveX);
  ui->move_y_->setValue(settingsRef_->moveY);
  ui->move_z_->setValue(settingsRef_->moveZ);
  ui->rotate_x_->setValue(settingsRef_->rotateX);
  ui->rotate_y_->setValue(settingsRef_->rotateY);
  ui->rotate_z_->setValue(settingsRef_->rotateZ);

  ui->openGLWidget->update();
}

void ViewPresenter::toggleButtons(QAbstractButton *enableButton,
                                  QAbstractButton *disableButton,
                                  bool condition) {
  enableButton->setChecked(condition);
  disableButton->setChecked(!condition);
}

void ViewPresenter::screen(bool isJpgFormat) {
  if (ui->path_file_->text().isEmpty()) {
    showError(info::ERROR, info::MODEL_ERROR_LABEL_SET);
    return;
  }

  QString modelPath = ui->path_file_->text();
  QString savePath =
      constructFilePath(modelPath, isJpgFormat ? ".jpg" : ".bmp");

  if (saveScreenshot(ui->openGLWidget->grabFramebuffer(), savePath)) {
    showInfo(info::NOTIFICATION, info::MODEL_SUCCESS_LABEL);
  } else {
    showError(info::ERROR, info::MODEL_ERROR_LABEL_SAVE);
  }
}

QString ViewPresenter::constructFilePath(const QString &modelPath,
                                         const QString &fileExtension) const {
  QFileInfo fileInfo(modelPath);
  QString directoryPath = fileInfo.dir().absolutePath();
  QString baseName = fileInfo.baseName();
  return directoryPath + "/" + baseName + fileExtension;
}

bool ViewPresenter::saveScreenshot(const QImage &image,
                                   const QString &filePath) const {
  QImage resizedImage =
      image.scaled(window::width, window::heigth, Qt::IgnoreAspectRatio,
                   Qt::SmoothTransformation);

  return resizedImage.save(filePath);
}

void ViewPresenter::showInfo(const QString &title,
                             const QString &message) const {
  QMessageBox::information(nullptr, title, message, QMessageBox::Ok);
}

void ViewPresenter::showError(const QString &title,
                              const QString &message) const {
  QMessageBox::warning(nullptr, title, message, QMessageBox::Ok);
}

void ViewPresenter::openQColorDialogWindow(QColor &color,
                                           const QString &title) {
  QColor selectedColor = QColorDialog::getColor(color, this, title);
  if (selectedColor.isValid()) {
    color = selectedColor;

    ui->openGLWidget->update();

    qDebug() << title << "color updated to:" << color.name();
  } else {
    showInfo(info::NOTIFICATION, info::CANCEL_ACTION);
  }
}

void ViewPresenter::createGif() {
  QGifImage gif(QSize(window::width, window::heigth));
  gif.setDefaultDelay(100);

  for (const QImage &frame : std::as_const(frames)) {
    gif.addFrame(frame);
  }

  QString savePath = constructFilePath(ui->path_file_->text(), ".gif");

  if (gif.save(savePath)) {
    showInfo(info::NOTIFICATION, info::GIF_SUCCESS_LABEL);
  } else {
    showError(info::ERROR, info::GIF_ERROR_LABEL_SAVE);
  }
}

void ViewPresenter::captureFrame() {
  QImage frame = ui->openGLWidget->grabFramebuffer();
  QImage scaledFrame =
      frame.scaled(window::width, window::heigth, Qt::IgnoreAspectRatio,
                   Qt::SmoothTransformation);
  frames.push_back(scaledFrame);
}

void ViewPresenter::closeEvent(QCloseEvent *event) {
  delete this;

  QMainWindow::closeEvent(event);
}

void ViewPresenter::setController(ObjectController *controller) {
  if (controller_ == nullptr) {
    controller_ = controller;
  }
}

void ViewPresenter::settingBasicParameters(bool isSetInit = true) {
  ui->move_x_->setValue(0);
  ui->move_y_->setValue(0);
  ui->move_z_->setValue(0);
  ui->rotate_x_->setValue(0);
  ui->rotate_y_->setValue(0);
  ui->rotate_z_->setValue(0);

  if (!isSetInit) {
    ui->scale_->setValue(settingsRef_->scale);
    qDebug() << "Scale adjusted to original: " << settingsRef_->scale;
  } else {
    settingsRef_->scale = baseScaleFactor;
    ui->scale_->setValue(scaleToSlider(baseScaleFactor));

    qDebug() << "Scale reset to base: " << settingsRef_->scale;
  }
}

void ViewPresenter::on_save_bmp_clicked() { screen(bmpFormat); }

void ViewPresenter::on_save_gif_clicked() {
  if (ui->path_file_->text().isEmpty()) {
    showInfo(info::NOTIFICATION, info::GIF_NO_MODEL_ALERT);
    return;
  }

  auto userResponse =
      showConfirmation(info::NOTIFICATION, info::GIF_RECORD_PROMPT,
                       QMessageBox::Ok | QMessageBox::Cancel);

  if (userResponse == QMessageBox::Ok) {
    frames.clear();

    QTimer *frameCaptureTimer = new QTimer(this);
    connect(frameCaptureTimer, &QTimer::timeout, this,
            &ViewPresenter::captureFrame);
    frameCaptureTimer->start(100);

    QTimer::singleShot(5000, this, [this, frameCaptureTimer]() {
      frameCaptureTimer->stop();
      frameCaptureTimer->deleteLater();
      createGif();
    });
  }
}

QMessageBox::StandardButton ViewPresenter::showConfirmation(
    const QString &title, const QString &message,
    QMessageBox::StandardButtons buttons) const {
  return QMessageBox::information(nullptr, title, message, buttons);
}

void ViewPresenter::on_save_jpg_clicked() { screen(jpgFormat); }

void ViewPresenter::on_open_file_clicked() {
  QString filePath_ = QFileDialog::getOpenFileName(
      this, info::OPEN_FILE_DIALOG_TITLE, QDir::homePath(), info::FILE_FILTER);

  if (filePath_.isEmpty()) {
    return;
  }

  bool status = controller_->loadModel(filePath_.toStdString());
  if (!status) {
    QMessageBox::information(this, info::INVALID_MODEL_TITLE,
                             info::INVALID_MODEL_DATA_MSG);
    controller_->clearModel();
    return;
  }

  settingBasicParameters();

  updateFileInfo(filePath_);
}

void ViewPresenter::on_move_x__valueChanged(int value) {
  controller_->moveModel((settingsRef_->moveX - value) / moveScaleFactor, 0, 0);
  settingsRef_->moveX = value;
  ui->openGLWidget->update();
}

void ViewPresenter::on_rotate_x__valueChanged(int value) {
  controller_->rotateModelX((settingsRef_->rotateX - value) / moveScaleFactor);
  settingsRef_->rotateX = value;
  ui->openGLWidget->update();
}

void ViewPresenter::on_rotate_y__valueChanged(int value) {
  controller_->rotateModelY((settingsRef_->rotateY - value) / moveScaleFactor);
  settingsRef_->rotateY = value;
  ui->openGLWidget->update();
}

void ViewPresenter::on_rotate_z__valueChanged(int value) {
  controller_->rotateModelZ((settingsRef_->rotateZ - value) / moveScaleFactor);
  settingsRef_->rotateZ = value;
  ui->openGLWidget->update();
}

void ViewPresenter::on_move_y__valueChanged(int value) {
  controller_->moveModel(0, (settingsRef_->moveY - value) / moveScaleFactor, 0);
  settingsRef_->moveY = value;
  ui->openGLWidget->update();
}

void ViewPresenter::on_move_z__valueChanged(int value) {
  controller_->moveModel(0, 0, (settingsRef_->moveZ - value) / moveScaleFactor);
  settingsRef_->moveZ = value;
  ui->openGLWidget->update();
}

void ViewPresenter::on_scale__valueChanged(int value) {
  double newScale = sliderToScale(value);

  double scaleFactor = newScale / settingsRef_->scale;

  controller_->changeScale(scaleFactor);
  settingsRef_->scale = newScale;

  qDebug() << "Scale updated: " << settingsRef_->scale;

  ui->openGLWidget->update();
}

void ViewPresenter::on_set_center__clicked() {
  settingBasicParameters(false);

  settingsRef_->vertexType = VertexType::NONE;

  ui->none_->setChecked(true);
  ui->square_->setChecked(false);
  ui->cicle_->setChecked(false);

  ui->openGLWidget->update();

  qDebug() << "Settings reset. Scale set to base: " << baseScaleFactor;
}

void ViewPresenter::on_background_color__clicked() {
  openQColorDialogWindow(settingsRef_->backgroundColor,
                         info::BACKGROUND_COLOR_TITLE);
  ui->openGLWidget->update();
}

void ViewPresenter::on_line_color__clicked() {
  openQColorDialogWindow(settingsRef_->edgeColor, info::LINE_COLOR_TITLE);
  ui->openGLWidget->update();
}

void ViewPresenter::on_vertexes_color__clicked() {
  openQColorDialogWindow(settingsRef_->vertexColor, info::VERTEX_COLOR_TITLE);
  ui->openGLWidget->update();
}

void ViewPresenter::on_central_but__clicked() {
  settingsRef_->projectionType = ProjectionType::CENTRAL;
  ui->openGLWidget->update();
}

void ViewPresenter::on_parralel_but__clicked() {
  settingsRef_->projectionType = ProjectionType::PARALLEL;
  ui->openGLWidget->update();
}

void ViewPresenter::on_none__clicked() {
  settingsRef_->vertexType = VertexType::NONE;
  ui->openGLWidget->update();
}

void ViewPresenter::on_square__clicked() {
  settingsRef_->vertexType = VertexType::SQUARE;
  ui->openGLWidget->update();
}

void ViewPresenter::on_cicle__clicked() {
  settingsRef_->vertexType = VertexType::CIRCLE;
  ui->openGLWidget->update();
}

void ViewPresenter::on_size_vertices__valueChanged(int value) {
  settingsRef_->vertexThickness = value;
  ui->openGLWidget->update();
}

void ViewPresenter::on_solid__clicked() {
  settingsRef_->lineType = LineType::SOLID;
  ui->openGLWidget->update();
}

void ViewPresenter::on_dotted__clicked() {
  settingsRef_->lineType = LineType::DASHED;
  ui->openGLWidget->update();
}

void ViewPresenter::on_line_thickness__valueChanged(int value) {
  settingsRef_->edgeThickness = value / edgeThicknessScale;
  ui->openGLWidget->update();
}

}  // namespace s21