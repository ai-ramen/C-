cmake_minimum_required(VERSION 3.14)
project(myproject3_2)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the path to Google Test
# add_subdirectory(test)
# add_subdirectory(src)
add_subdirectory(test/lib/googletest)
set(GTEST_INCLUDE_DIRS test/lib/googletest/googletest/include)
# set(GTEST_LIBRARIES test/lib/googletest/build/lib/libgtest.a)
# Add the GTest include directories
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Add the GTest include directories
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

# テスト対象のコードをコンパイルしてライブラリを生成
add_library(AddNumbers 
            src/AddNumbers.c)

# テストコードをコンパイルしてテスト用の実行ファイルを生成
add_executable(
  AddNumbersTest
  test/AddNumbersTest.cpp
  src/AddNumbers.c
)


# Set compiler flags for coverage ビルドオプションの設定
set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")

####
# set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} --coverage") # 追加
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage") # 追加

###

# ビルド後にカバレッジ情報を取得
add_custom_target(
  coverage
  COMMAND ${CMAKE_COMMAND} -E env "GTEST_COLOR=1" ./AddNumbersTest
  COMMAND lcov --capture --directory . --output-file coverage.info --ignore-errors graph
  # COMMAND lcov --remove coverage.info '/usr/*' --output-file coverage.info
  COMMAND lcov --list coverage.info
)


# Link Google Test and your project's library
target_link_libraries(AddNumbersTest gtest gtest_main AddNumbers)

include(GoogleTest)
gtest_discover_tests(AddNumbersTest)