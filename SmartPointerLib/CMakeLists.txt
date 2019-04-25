project(SmartPointerLib)

set(HEADER_FILES
        SmartPointer.h)

set(SOURCE_FILES
        SmartPointer.cpp)

add_library(SmartPointerLib STATIC ${SOURCE_FILES} ${HEADER_FILES})
