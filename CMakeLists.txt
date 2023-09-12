cmake_minimum_required(VERSION 3.19)
set(GOOGLETEST_VERSION 1.14.0)
project(labProgrammazione)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILE Collection.h Collection.cpp ImportantNotes.cpp ImportantNotes.h Note.cpp Note.h
        NotesCollection.cpp NotesCollection.h Observer.cpp Observer.h Subject.h Subject.cpp User.cpp
        User.h)
add_executable(labProgrammazione main.cpp)
add_library(core ${SOURCE_FILE})
target_link_libraries(labProgrammazione core)