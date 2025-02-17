#ifndef S21_VIEW_H_
#define S21_VIEW_H_

#include <QCloseEvent>
#include <QColorDialog>
#include <QDebug>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QProcess>
#include <QSettings>
#include <QString>
#include <QTimer>

#include "../../controller/s21_controller.h"
#include "../../gif/gifimage/qgifimage.h"
#include "../settings/s21_settings_view.h"
#include "./ui_mainwindow.h"
#include "opengl/s21_open_gl_view.h"

namespace s21 {
class ViewPresenter : public QMainWindow {
  Q_OBJECT

 public:
  ViewPresenter(ViewPresenter const &) = delete;
  void operator=(ViewPresenter const &) = delete;
  void setController(ObjectController *controller);

  static ViewPresenter &getInstance(ObjectController *controller);

  ~ViewPresenter() override;

 protected:
  void closeEvent(QCloseEvent *event) override;
 private slots:
  void on_open_file_clicked();

  void on_move_x__valueChanged(int value);

  void on_rotate_x__valueChanged(int value);

  void on_rotate_y__valueChanged(int value);

  void on_rotate_z__valueChanged(int value);

  void on_move_y__valueChanged(int value);

  void on_move_z__valueChanged(int value);

  void on_scale__valueChanged(int value);

  void on_set_center__clicked();

  void on_background_color__clicked();

  void on_line_color__clicked();

  void on_vertexes_color__clicked();

  void on_central_but__clicked();

  void on_parralel_but__clicked();

  void on_none__clicked();

  void on_square__clicked();

  void on_cicle__clicked();

  void on_size_vertices__valueChanged(int value);

  void on_solid__clicked();

  void on_dotted__clicked();

  void on_line_thickness__valueChanged(int value);

  void on_save_jpg_clicked();

  void on_save_bmp_clicked();

  void on_save_gif_clicked();

  void openQColorDialogWindow(QColor &color, const QString &title);

  void captureFrame();

  void createGif();

  void setSettingsReference(Settings &settings);

 private:
  explicit ViewPresenter(QWidget *parent = nullptr,
                         ObjectController *controller = nullptr);

  void saveSettings();

  void loadSettings();

  void applySettingsForRendering();

  void screen(bool type);

  void setDarkTheme();

 private:
  Ui::ViewPresenter *ui;
  ObjectController *controller_;
  Settings *settingsRef_ = nullptr;
  QColor backgroundColor = palette().color(QPalette::Window);
  QList<QImage> frames;

  void updateFileInfo(const QString &file_path);

  double sliderToScale(int sliderValue) const;

  int scaleToSlider(double scale) const;

  template <typename T>
  T getSetting(QSettings &settings, const QString &key, const T &defaultValue);

  void toggleButtons(QAbstractButton *enableButton,
                     QAbstractButton *disableButton, bool condition);

  void settingBasicParameters(bool isSetInit);

  QString constructFilePath(const QString &modelPath,
                            const QString &fileExtension) const;

  bool saveScreenshot(const QImage &image, const QString &filePath) const;

  void showInfo(const QString &title, const QString &message) const;

  void showError(const QString &title, const QString &message) const;

  QMessageBox::StandardButton showConfirmation(
      const QString &title, const QString &message,
      QMessageBox::StandardButtons buttons) const;
};
}  // namespace s21

#endif  // S21_VIEW_H_
