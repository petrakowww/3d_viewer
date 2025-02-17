/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>

#include "opengl/s21_open_gl_view.h"

QT_BEGIN_NAMESPACE

class Ui_ViewPresenter {
 public:
  QWidget *centralwidget;
  s21::OpenGLView *openGLWidget;
  QWidget *gridLayoutWidget;
  QGridLayout *gridLayout;
  QPushButton *open_file;
  QPushButton *background_color_;
  QScrollBar *rotate_x_;
  QScrollBar *move_x_;
  QLabel *label_21;
  QLabel *label_3;
  QScrollBar *move_y_;
  QScrollBar *move_z_;
  QHBoxLayout *horizontalLayout;
  QLabel *label_4;
  QLabel *file_name_;
  QHBoxLayout *horizontalLayout_7;
  QLabel *label_13;
  QLabel *label_14;
  QLabel *label_11;
  QHBoxLayout *horizontalLayout_8;
  QLabel *label_15;
  QLabel *label_16;
  QLabel *label_24;
  QHBoxLayout *horizontalLayout_3;
  QLabel *label;
  QPushButton *set_center_;
  QHBoxLayout *horizontalLayout_5;
  QLabel *label_7;
  QLabel *countEdges_;
  QScrollBar *rotate_z_;
  QScrollBar *scale_;
  QHBoxLayout *horizontalLayout_2;
  QLabel *label_5;
  QLabel *count_vertexes_;
  QLabel *label_2;
  QHBoxLayout *horizontalLayout_4;
  QLabel *label_6;
  QLabel *count_polygons_;
  QScrollBar *rotate_y_;
  QLabel *label_9;
  QLabel *path_file_;
  QWidget *gridLayoutWidget_2;
  QGridLayout *gridLayout_2;
  QHBoxLayout *horizontalLayout_6;
  QRadioButton *central_but_;
  QRadioButton *parralel_but_;
  QLabel *label_10;
  QPushButton *save_bmp;
  QLabel *label_19;
  QLabel *label_23;
  QHBoxLayout *horizontalLayout_9;
  QRadioButton *solid_;
  QRadioButton *dotted_;
  QLabel *label_8;
  QScrollBar *line_thickness_;
  QScrollBar *size_vertices_;
  QPushButton *line_color_;
  QPushButton *save_jpg;
  QPushButton *vertexes_color_;
  QLabel *label_12;
  QHBoxLayout *horizontalLayout_14;
  QRadioButton *none_;
  QRadioButton *square_;
  QRadioButton *cicle_;
  QLabel *label_20;
  QLabel *label_18;
  QLabel *label_22;
  QPushButton *save_gif;
  QMenuBar *menubar;
  QButtonGroup *buttonGroup_2;
  QButtonGroup *buttonGroup;
  QButtonGroup *buttonGroup_3;

  void setupUi(QMainWindow *ViewPresenter) {
    if (ViewPresenter->objectName().isEmpty())
      ViewPresenter->setObjectName(QString::fromUtf8("ViewPresenter"));
    ViewPresenter->resize(1051, 604);
    centralwidget = new QWidget(ViewPresenter);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    openGLWidget = new s21::OpenGLView(centralwidget);
    openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
    openGLWidget->setGeometry(QRect(220, 30, 601, 541));
    gridLayoutWidget = new QWidget(centralwidget);
    gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(10, 30, 191, 541));
    gridLayout = new QGridLayout(gridLayoutWidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);
    open_file = new QPushButton(gridLayoutWidget);
    open_file->setObjectName(QString::fromUtf8("open_file"));

    gridLayout->addWidget(open_file, 1, 0, 1, 1);

    background_color_ = new QPushButton(gridLayoutWidget);
    background_color_->setObjectName(QString::fromUtf8("background_color_"));

    gridLayout->addWidget(background_color_, 9, 0, 1, 1);

    rotate_x_ = new QScrollBar(gridLayoutWidget);
    rotate_x_->setObjectName(QString::fromUtf8("rotate_x_"));
    rotate_x_->setMinimum(-100);
    rotate_x_->setMaximum(100);
    rotate_x_->setValue(0);
    rotate_x_->setOrientation(Qt::Orientation::Horizontal);

    gridLayout->addWidget(rotate_x_, 18, 0, 1, 1);

    move_x_ = new QScrollBar(gridLayoutWidget);
    move_x_->setObjectName(QString::fromUtf8("move_x_"));
    move_x_->setMinimum(-100);
    move_x_->setMaximum(100);
    move_x_->setSingleStep(10);
    move_x_->setValue(0);
    move_x_->setOrientation(Qt::Orientation::Horizontal);

    gridLayout->addWidget(move_x_, 12, 0, 1, 1);

    label_21 = new QLabel(gridLayoutWidget);
    label_21->setObjectName(QString::fromUtf8("label_21"));

    gridLayout->addWidget(label_21, 8, 0, 1, 1);

    label_3 = new QLabel(gridLayoutWidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout->addWidget(label_3, 21, 0, 1, 1);

    move_y_ = new QScrollBar(gridLayoutWidget);
    move_y_->setObjectName(QString::fromUtf8("move_y_"));
    move_y_->setMinimum(-101);
    move_y_->setMaximum(100);
    move_y_->setValue(0);
    move_y_->setOrientation(Qt::Orientation::Horizontal);

    gridLayout->addWidget(move_y_, 13, 0, 1, 1);

    move_z_ = new QScrollBar(gridLayoutWidget);
    move_z_->setObjectName(QString::fromUtf8("move_z_"));
    move_z_->setMinimum(-100);
    move_z_->setMaximum(100);
    move_z_->setValue(0);
    move_z_->setOrientation(Qt::Orientation::Horizontal);

    gridLayout->addWidget(move_z_, 14, 0, 1, 1);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label_4 = new QLabel(gridLayoutWidget);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    horizontalLayout->addWidget(label_4);

    file_name_ = new QLabel(gridLayoutWidget);
    file_name_->setObjectName(QString::fromUtf8("file_name_"));
    QFont font;
    font.setPointSize(11);
    file_name_->setFont(font);
    file_name_->setAlignment(Qt::AlignmentFlag::AlignRight |
                             Qt::AlignmentFlag::AlignTrailing |
                             Qt::AlignmentFlag::AlignVCenter);

    horizontalLayout->addWidget(file_name_);

    gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

    horizontalLayout_7 = new QHBoxLayout();
    horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
    label_13 = new QLabel(gridLayoutWidget);
    label_13->setObjectName(QString::fromUtf8("label_13"));
    label_13->setStyleSheet(QString::fromUtf8("color: #ff0000;"));
    label_13->setAlignment(Qt::AlignmentFlag::AlignCenter);

    horizontalLayout_7->addWidget(label_13);

    label_14 = new QLabel(gridLayoutWidget);
    label_14->setObjectName(QString::fromUtf8("label_14"));
    label_14->setStyleSheet(QString::fromUtf8("color: #00ff00;"));
    label_14->setAlignment(Qt::AlignmentFlag::AlignCenter);

    horizontalLayout_7->addWidget(label_14);

    label_11 = new QLabel(gridLayoutWidget);
    label_11->setObjectName(QString::fromUtf8("label_11"));
    label_11->setStyleSheet(QString::fromUtf8("color: #ffff00;"));
    label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);

    horizontalLayout_7->addWidget(label_11);

    gridLayout->addLayout(horizontalLayout_7, 11, 0, 1, 1);

    horizontalLayout_8 = new QHBoxLayout();
    horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
    label_15 = new QLabel(gridLayoutWidget);
    label_15->setObjectName(QString::fromUtf8("label_15"));
    label_15->setStyleSheet(QString::fromUtf8("color: #ff0000;"));
    label_15->setAlignment(Qt::AlignmentFlag::AlignCenter);

    horizontalLayout_8->addWidget(label_15);

    label_16 = new QLabel(gridLayoutWidget);
    label_16->setObjectName(QString::fromUtf8("label_16"));
    label_16->setStyleSheet(QString::fromUtf8("color: #00ff00;"));
    label_16->setAlignment(Qt::AlignmentFlag::AlignCenter);

    horizontalLayout_8->addWidget(label_16);

    label_24 = new QLabel(gridLayoutWidget);
    label_24->setObjectName(QString::fromUtf8("label_24"));
    label_24->setStyleSheet(QString::fromUtf8("color: #ffff00;"));
    label_24->setAlignment(Qt::AlignmentFlag::AlignCenter);

    horizontalLayout_8->addWidget(label_24);

    gridLayout->addLayout(horizontalLayout_8, 17, 0, 1, 1);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    label = new QLabel(gridLayoutWidget);
    label->setObjectName(QString::fromUtf8("label"));

    horizontalLayout_3->addWidget(label);

    set_center_ = new QPushButton(gridLayoutWidget);
    set_center_->setObjectName(QString::fromUtf8("set_center_"));

    horizontalLayout_3->addWidget(set_center_);

    gridLayout->addLayout(horizontalLayout_3, 10, 0, 1, 1);

    horizontalLayout_5 = new QHBoxLayout();
    horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
    label_7 = new QLabel(gridLayoutWidget);
    label_7->setObjectName(QString::fromUtf8("label_7"));

    horizontalLayout_5->addWidget(label_7);

    countEdges_ = new QLabel(gridLayoutWidget);
    countEdges_->setObjectName(QString::fromUtf8("countEdges_"));
    countEdges_->setFont(font);
    countEdges_->setAlignment(Qt::AlignmentFlag::AlignRight |
                              Qt::AlignmentFlag::AlignTrailing |
                              Qt::AlignmentFlag::AlignVCenter);

    horizontalLayout_5->addWidget(countEdges_);

    gridLayout->addLayout(horizontalLayout_5, 6, 0, 1, 1);

    rotate_z_ = new QScrollBar(gridLayoutWidget);
    rotate_z_->setObjectName(QString::fromUtf8("rotate_z_"));
    rotate_z_->setMinimum(-100);
    rotate_z_->setMaximum(100);
    rotate_z_->setValue(0);
    rotate_z_->setOrientation(Qt::Orientation::Horizontal);

    gridLayout->addWidget(rotate_z_, 20, 0, 1, 1);

    scale_ = new QScrollBar(gridLayoutWidget);
    scale_->setObjectName(QString::fromUtf8("scale_"));
    scale_->setMinimum(1);
    scale_->setMaximum(50);
    scale_->setSingleStep(1);
    scale_->setValue(10);
    scale_->setOrientation(Qt::Orientation::Horizontal);
    scale_->setInvertedControls(false);

    gridLayout->addWidget(scale_, 22, 0, 1, 1);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    label_5 = new QLabel(gridLayoutWidget);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    horizontalLayout_2->addWidget(label_5);

    count_vertexes_ = new QLabel(gridLayoutWidget);
    count_vertexes_->setObjectName(QString::fromUtf8("count_vertexes_"));
    count_vertexes_->setFont(font);
    count_vertexes_->setAlignment(Qt::AlignmentFlag::AlignRight |
                                  Qt::AlignmentFlag::AlignTrailing |
                                  Qt::AlignmentFlag::AlignVCenter);

    horizontalLayout_2->addWidget(count_vertexes_);

    gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

    label_2 = new QLabel(gridLayoutWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 16, 0, 1, 1);

    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    label_6 = new QLabel(gridLayoutWidget);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    horizontalLayout_4->addWidget(label_6);

    count_polygons_ = new QLabel(gridLayoutWidget);
    count_polygons_->setObjectName(QString::fromUtf8("count_polygons_"));
    count_polygons_->setFont(font);
    count_polygons_->setAlignment(Qt::AlignmentFlag::AlignRight |
                                  Qt::AlignmentFlag::AlignTrailing |
                                  Qt::AlignmentFlag::AlignVCenter);

    horizontalLayout_4->addWidget(count_polygons_);

    gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 1);

    rotate_y_ = new QScrollBar(gridLayoutWidget);
    rotate_y_->setObjectName(QString::fromUtf8("rotate_y_"));
    rotate_y_->setMinimum(-100);
    rotate_y_->setMaximum(100);
    rotate_y_->setValue(0);
    rotate_y_->setOrientation(Qt::Orientation::Horizontal);

    gridLayout->addWidget(rotate_y_, 19, 0, 1, 1);

    label_9 = new QLabel(gridLayoutWidget);
    label_9->setObjectName(QString::fromUtf8("label_9"));

    gridLayout->addWidget(label_9, 7, 0, 1, 1);

    path_file_ = new QLabel(centralwidget);
    path_file_->setObjectName(QString::fromUtf8("path_file_"));
    path_file_->setGeometry(QRect(10, 10, 411, 21));
    QFont font1;
    font1.setPointSize(10);
    path_file_->setFont(font1);
    gridLayoutWidget_2 = new QWidget(centralwidget);
    gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
    gridLayoutWidget_2->setGeometry(QRect(840, 30, 203, 578));
    gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    gridLayout_2->setContentsMargins(0, 0, 0, 0);
    horizontalLayout_6 = new QHBoxLayout();
    horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
    central_but_ = new QRadioButton(gridLayoutWidget_2);
    buttonGroup = new QButtonGroup(ViewPresenter);
    buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
    buttonGroup->addButton(central_but_);
    central_but_->setObjectName(QString::fromUtf8("central_but_"));
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(
        central_but_->sizePolicy().hasHeightForWidth());
    central_but_->setSizePolicy(sizePolicy);
    central_but_->setChecked(true);

    horizontalLayout_6->addWidget(central_but_);

    parralel_but_ = new QRadioButton(gridLayoutWidget_2);
    buttonGroup->addButton(parralel_but_);
    parralel_but_->setObjectName(QString::fromUtf8("parralel_but_"));

    horizontalLayout_6->addWidget(parralel_but_);

    gridLayout_2->addLayout(horizontalLayout_6, 1, 0, 1, 1);

    label_10 = new QLabel(gridLayoutWidget_2);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    QFont font2;
    font2.setPointSize(14);
    font2.setBold(true);
    label_10->setFont(font2);
    label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);

    gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

    save_bmp = new QPushButton(gridLayoutWidget_2);
    save_bmp->setObjectName(QString::fromUtf8("save_bmp"));

    gridLayout_2->addWidget(save_bmp, 15, 0, 1, 1);

    label_19 = new QLabel(gridLayoutWidget_2);
    label_19->setObjectName(QString::fromUtf8("label_19"));
    label_19->setFont(font2);
    label_19->setAlignment(Qt::AlignmentFlag::AlignCenter);

    gridLayout_2->addWidget(label_19, 8, 0, 1, 1);

    label_23 = new QLabel(gridLayoutWidget_2);
    label_23->setObjectName(QString::fromUtf8("label_23"));

    gridLayout_2->addWidget(label_23, 19, 0, 1, 1);

    horizontalLayout_9 = new QHBoxLayout();
    horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
    solid_ = new QRadioButton(gridLayoutWidget_2);
    buttonGroup_2 = new QButtonGroup(ViewPresenter);
    buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
    buttonGroup_2->addButton(solid_);
    solid_->setObjectName(QString::fromUtf8("solid_"));
    solid_->setChecked(true);

    horizontalLayout_9->addWidget(solid_);

    dotted_ = new QRadioButton(gridLayoutWidget_2);
    buttonGroup_2->addButton(dotted_);
    dotted_->setObjectName(QString::fromUtf8("dotted_"));

    horizontalLayout_9->addWidget(dotted_);

    gridLayout_2->addLayout(horizontalLayout_9, 4, 0, 1, 1);

    label_8 = new QLabel(gridLayoutWidget_2);
    label_8->setObjectName(QString::fromUtf8("label_8"));

    gridLayout_2->addWidget(label_8, 13, 0, 1, 1);

    line_thickness_ = new QScrollBar(gridLayoutWidget_2);
    line_thickness_->setObjectName(QString::fromUtf8("line_thickness_"));
    line_thickness_->setMinimum(0);
    line_thickness_->setMaximum(200);
    line_thickness_->setSingleStep(10);
    line_thickness_->setValue(5);
    line_thickness_->setOrientation(Qt::Orientation::Horizontal);

    gridLayout_2->addWidget(line_thickness_, 6, 0, 1, 1);

    size_vertices_ = new QScrollBar(gridLayoutWidget_2);
    size_vertices_->setObjectName(QString::fromUtf8("size_vertices_"));
    size_vertices_->setMinimum(0);
    size_vertices_->setMaximum(100);
    size_vertices_->setSingleStep(10);
    size_vertices_->setValue(10);
    size_vertices_->setOrientation(Qt::Orientation::Horizontal);

    gridLayout_2->addWidget(size_vertices_, 11, 0, 1, 1);

    line_color_ = new QPushButton(gridLayoutWidget_2);
    line_color_->setObjectName(QString::fromUtf8("line_color_"));

    gridLayout_2->addWidget(line_color_, 7, 0, 1, 1);

    save_jpg = new QPushButton(gridLayoutWidget_2);
    save_jpg->setObjectName(QString::fromUtf8("save_jpg"));

    gridLayout_2->addWidget(save_jpg, 14, 0, 1, 1);

    vertexes_color_ = new QPushButton(gridLayoutWidget_2);
    vertexes_color_->setObjectName(QString::fromUtf8("vertexes_color_"));

    gridLayout_2->addWidget(vertexes_color_, 12, 0, 1, 1);

    label_12 = new QLabel(gridLayoutWidget_2);
    label_12->setObjectName(QString::fromUtf8("label_12"));
    label_12->setFont(font2);
    label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);

    gridLayout_2->addWidget(label_12, 5, 0, 1, 1);

    horizontalLayout_14 = new QHBoxLayout();
    horizontalLayout_14->setObjectName(
        QString::fromUtf8("horizontalLayout_14"));
    none_ = new QRadioButton(gridLayoutWidget_2);
    buttonGroup_3 = new QButtonGroup(ViewPresenter);
    buttonGroup_3->setObjectName(QString::fromUtf8("buttonGroup_3"));
    buttonGroup_3->addButton(none_);
    none_->setObjectName(QString::fromUtf8("none_"));
    none_->setChecked(true);

    horizontalLayout_14->addWidget(none_);

    square_ = new QRadioButton(gridLayoutWidget_2);
    buttonGroup_3->addButton(square_);
    square_->setObjectName(QString::fromUtf8("square_"));
    square_->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

    horizontalLayout_14->addWidget(square_);

    cicle_ = new QRadioButton(gridLayoutWidget_2);
    buttonGroup_3->addButton(cicle_);
    cicle_->setObjectName(QString::fromUtf8("cicle_"));

    horizontalLayout_14->addWidget(cicle_);

    gridLayout_2->addLayout(horizontalLayout_14, 9, 0, 1, 1);

    label_20 = new QLabel(gridLayoutWidget_2);
    label_20->setObjectName(QString::fromUtf8("label_20"));
    label_20->setFont(font2);
    label_20->setAlignment(Qt::AlignmentFlag::AlignCenter);

    gridLayout_2->addWidget(label_20, 10, 0, 1, 1);

    label_18 = new QLabel(gridLayoutWidget_2);
    label_18->setObjectName(QString::fromUtf8("label_18"));
    label_18->setFont(font2);
    label_18->setAlignment(Qt::AlignmentFlag::AlignCenter);

    gridLayout_2->addWidget(label_18, 2, 0, 1, 1);

    label_22 = new QLabel(gridLayoutWidget_2);
    label_22->setObjectName(QString::fromUtf8("label_22"));

    gridLayout_2->addWidget(label_22, 17, 0, 1, 1);

    save_gif = new QPushButton(gridLayoutWidget_2);
    save_gif->setObjectName(QString::fromUtf8("save_gif"));

    gridLayout_2->addWidget(save_gif, 16, 0, 1, 1);

    ViewPresenter->setCentralWidget(centralwidget);
    menubar = new QMenuBar(ViewPresenter);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 1051, 21));
    ViewPresenter->setMenuBar(menubar);

    retranslateUi(ViewPresenter);

    QMetaObject::connectSlotsByName(ViewPresenter);
  }  // setupUi

  void retranslateUi(QMainWindow *ViewPresenter) {
    ViewPresenter->setWindowTitle(
        QCoreApplication::translate("ViewPresenter", "ViewPresenter", nullptr));
    open_file->setText(QCoreApplication::translate(
        "ViewPresenter",
        "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
    background_color_->setText(QCoreApplication::translate(
        "ViewPresenter",
        "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260",
        nullptr));
    label_21->setText(QString());
    label_3->setText(
        QCoreApplication::translate("ViewPresenter", "Scale", nullptr));
    label_4->setText(
        QCoreApplication::translate("ViewPresenter", "File name", nullptr));
    file_name_->setText(QString());
    label_13->setText(
        QCoreApplication::translate("ViewPresenter", "x", nullptr));
    label_14->setText(
        QCoreApplication::translate("ViewPresenter", "y", nullptr));
    label_11->setText(
        QCoreApplication::translate("ViewPresenter", "z", nullptr));
    label_15->setText(
        QCoreApplication::translate("ViewPresenter", "x", nullptr));
    label_16->setText(
        QCoreApplication::translate("ViewPresenter", "y", nullptr));
    label_24->setText(
        QCoreApplication::translate("ViewPresenter", "z", nullptr));
    label->setText(
        QCoreApplication::translate("ViewPresenter", "Position", nullptr));
    set_center_->setText(QCoreApplication::translate(
        "ViewPresenter", "\320\241\320\261\321\200\320\276\321\201", nullptr));
    label_7->setText(
        QCoreApplication::translate("ViewPresenter", "Edges", nullptr));
    countEdges_->setText(QString());
    label_5->setText(
        QCoreApplication::translate("ViewPresenter", "Vertexes", nullptr));
    count_vertexes_->setText(QString());
    label_2->setText(
        QCoreApplication::translate("ViewPresenter", "Rotation", nullptr));
    label_6->setText(
        QCoreApplication::translate("ViewPresenter", "Polygons", nullptr));
    count_polygons_->setText(QString());
    label_9->setText(QString());
    path_file_->setText(QString());
    central_but_->setText(
        QCoreApplication::translate("ViewPresenter", "Central", nullptr));
    parralel_but_->setText(
        QCoreApplication::translate("ViewPresenter", "Parralel", nullptr));
    label_10->setText(QCoreApplication::translate(
        "ViewPresenter",
        "\320\242\320\270\320\277 "
        "\320\277\321\200\320\276\320\265\320\272\321\206\320\270\320\270",
        nullptr));
    save_bmp->setText(QCoreApplication::translate(
        "ViewPresenter",
        "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321"
        "\214 \320\272\320\260\320\272 BMP",
        nullptr));
    label_19->setText(QCoreApplication::translate(
        "ViewPresenter",
        "\320\242\320\270\320\277 "
        "\320\262\320\265\321\200\321\210\320\270\320\275",
        nullptr));
    label_23->setText(QString());
    solid_->setText(
        QCoreApplication::translate("ViewPresenter", "Solid", nullptr));
    dotted_->setText(
        QCoreApplication::translate("ViewPresenter", "Dotted", nullptr));
    label_8->setText(QString());
    line_color_->setText(
        QCoreApplication::translate("ViewPresenter",
                                    "\320\246\320\262\320\265\321\202 "
                                    "\320\273\320\270\320\275\320\270\320\271",
                                    nullptr));
    save_jpg->setText(QCoreApplication::translate(
        "ViewPresenter",
        "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321"
        "\214 \320\272\320\260\320\272 JPG",
        nullptr));
    vertexes_color_->setText(QCoreApplication::translate(
        "ViewPresenter",
        "\320\246\320\262\320\265\321\202 "
        "\320\262\320\265\321\200\321\210\320\270\320\275",
        nullptr));
    label_12->setText(QCoreApplication::translate(
        "ViewPresenter",
        "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 "
        "\320\273\320\270\320\275\320\270\320\271",
        nullptr));
    none_->setText(
        QCoreApplication::translate("ViewPresenter", "None", nullptr));
    square_->setText(
        QCoreApplication::translate("ViewPresenter", "Square", nullptr));
    cicle_->setText(
        QCoreApplication::translate("ViewPresenter", "Cicle", nullptr));
    label_20->setText(QCoreApplication::translate(
        "ViewPresenter",
        "\320\240\320\260\320\267\320\274\320\265\321\200 "
        "\320\262\320\265\321\200\321\210\320\270\320\275",
        nullptr));
    label_18->setText(QCoreApplication::translate(
        "ViewPresenter",
        "\320\242\320\270\320\277 \320\273\320\270\320\275\320\270\320\271",
        nullptr));
    label_22->setText(QString());
    save_gif->setText(QCoreApplication::translate(
        "ViewPresenter",
        "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321"
        "\214 \320\272\320\260\320\272 GIF",
        nullptr));
  }  // retranslateUi
};

namespace Ui {
class ViewPresenter : public Ui_ViewPresenter {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
