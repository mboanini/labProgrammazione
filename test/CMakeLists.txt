cmake_minimum_required(VERSION 3.19)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})
set(TEST_SOURCE_FILES runAllTests.cpp NoteTest.cpp UserTest.cpp ImportantNotesTest.cpp NotesCollectionTest.cpp)
add_executable(runNoteTests ${TEST_SOURCE_FILES})
target_link_libraries(runNoteTests gtest gtest_main core)