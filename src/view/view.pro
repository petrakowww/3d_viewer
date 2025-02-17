TEMPLATE = app
CONFIG += c++17

TARGET = 3DViewer

FORMS += mainwindow.ui

include(../gif/gifimage/qtgifimage.pri)

SOURCES += ../controller/s21_controller.cpp \
           ../model/object/s21_object_model.cpp \
           ../model/parser/s21_parser.cpp \
           ../model/parser/s21_model_parser.cpp \
           ../model/parser/s21_polygon_parser.cpp \
           ../model/parser/s21_vertex_parser.cpp \
           ../model/affine/utils/s21_utils_vector.cpp \
           ../model/affine/transform/s21_transform_shift.cpp \
           ../model/affine/transform/s21_transform_rotate_x.cpp \
           ../model/affine/transform/s21_transform_rotate_y.cpp \
           ../model/affine/transform/s21_transform_rotate_z.cpp \
           ../model/affine/transform/s21_transform_change_scale.cpp \
           ../model/affine/transform/s21_transform_centralize.cpp \
           ../model/affine/transform/s21_transform_normalize.cpp \
           ../model/validation/s21_validator.cpp \
           ../model/vertex/s21_vertex_manager.cpp \
           ../s21_3d_viewer.cpp \
           opengl/s21_open_gl_view.cpp \
           qt/s21_view.cpp

HEADERS += opengl/s21_open_gl_view.h \
           qt/s21_view.h \
           settings/s21_settings_view.h \
           ../controller/s21_controller.h \
           ../model/object/s21_object_model.h \
           ../model/parser/s21_parser.h \
           ../model/constants/s21_constants.h \
           ../model/affine/utils/s21_utils_vector.h \
           ../model/affine/transform/s21_transformation.h \
           ../model/validation/s21_validator.h \
           ../model/vertex/s21_vertex_manager.h

INCLUDEPATH += view

QT += core gui widgets opengl

game_file_path = 3DViewer

src_directory_path = $$OUT_PWD/../..

ui_mainwindow = ui_mainwindow.h
game_directory = 3dviewer_app

library_path = $$src_directory_path/view
game_path = $$src_directory_path/$$game_directory

QMAKE_POST_LINK = \
    $$QMAKE_COPY $$game_file_path $$game_path && \
    $$QMAKE_COPY $$ui_mainwindow $$library_path
