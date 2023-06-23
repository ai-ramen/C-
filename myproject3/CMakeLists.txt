cmake_minimum_required(VERSION 3.14)
project(myproject3)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

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

target_link_libraries(
  AddNumbersTest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(AddNumbersTest)
