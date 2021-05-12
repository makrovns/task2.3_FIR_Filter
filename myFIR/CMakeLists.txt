set(SOURCES_LIB
FIR_coef_library.hpp
FIR_coef_library.cpp

)

add_library(${PRO}_lib ${SOURCES_LIB})

target_include_directories(${PRO}_lib PUBLIC ${CMAKE_CURRENT_LIST_DIR})

source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCES_LIB})

set_property(TARGET ${PRO}_lib PROPERTY FOLDER "FIR_library")

# включаем в сборку проекnа подпроект с тестами
add_subdirectory(tests)