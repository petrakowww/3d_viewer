cmake_minimum_required(VERSION 3.22)
project(CPP4_3DViewer_v2_0_1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

find_package(OpenGL REQUIRED)
find_package(Qt5 COMPONENTS Widgets OpenGL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/src/gif/gifimage)
include_directories(${CMAKE_SOURCE_DIR}/src/gif/giflib)
include_directories(src/model)
include_directories(src/view)
include_directories(src/controller)
include_directories(src)

add_executable(CPP4_3DViewer_v2_0_1
        src/model/affine/transform/s21_transformation.h
        src/model/affine/transform/s21_transform_normalize.cpp
        src/model/affine/transform/s21_transform_shift.cpp
        src/model/affine/transform/s21_transform_rotate_y.cpp
        src/model/affine/transform/s21_transform_rotate_x.cpp
        src/model/affine/transform/s21_transform_rotate_z.cpp
        src/model/affine/transform/s21_transform_centralize.cpp
        src/model/affine/transform/s21_transform_change_scale.cpp
        src/model/affine/s21_affine.h
        src/model/object/s21_object_model.h
        src/model/affine/utils/s21_utils_vector.h
        src/model/affine/utils/s21_utils_vector.cpp
        src/model/constants/s21_constants.h
        src/model/parser/s21_vertex_parser.cpp
        src/model/parser/s21_polygon_parser.cpp
        src/model/parser/s21_parser.cpp
        src/model/vertex/s21_vertex_manager.h
        src/model/vertex/s21_vertex_manager.cpp
        src/model/object/s21_object_model.cpp
        src/model/parser/s21_model_parser.cpp
        src/model/validation/s21_validator.h
        src/model/validation/s21_validator.cpp
        src/view/opengl/s21_open_gl_view.cpp
        src/view/qt/s21_view.cpp
        src/controller/s21_controller.h
        src/controller/s21_controller.cpp
        src/view/settings/s21_settings_view.h
        src/gif/gifimage/doc/snippets/doc_src_qtgifimage.cpp
        src/gif/gifimage/qgifglobal.h
        src/gif/gifimage/qgifimage_p.h
        src/gif/gifimage/qgifimage.cpp
        src/s21_3d_viewer.cpp
        src/tests/s21_tests.cpp
        src/tests/s21_tests.h
        src/tests/object_tests/s21_object_tests.cpp
        src/tests/parser_tests/s21_parser_tests.cpp
        src/tests/affine_tests/s21_affine_tests.cpp
        src/tests/validation_tests/s21_validation_tests.cpp
        src/tests/vertex_tests/s21_vertex_tests.cpp
)

add_library(gd STATIC
        src/gif/giflib/dgif_lib.c
        src/gif/giflib/egif_lib.c
        src/gif/giflib/gif_err.c
        src/gif/giflib/gif_font.c
        src/gif/giflib/gif_hash.c
        src/gif/giflib/gifalloc.c
        src/gif/giflib/quantize.c
)

target_link_libraries(CPP4_3DViewer_v2_0_1 Qt5::Widgets Qt5::OpenGL ${OPENGL_LIBRARIES} ${GD_LIBRARY})

