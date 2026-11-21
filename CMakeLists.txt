
cmake_minimum_required(VERSION 3.21)
project(AudioProcessingEngine
	VERSION 0.1.0
	LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

add_executable(audio-analyzer src/main.cpp)
target_compile_features(audio-analyzer PRIVATE cxx_std_17)

add_library(project_warnings INTERFACE)

target_compile_options(project_warnings
	INTERFACE
	"$<$<CXX_COMPILER_ID:GNU,Clang>:-Wall;-Wextra;-Wpedantic>"
    	"$<$<CXX_COMPILER_ID:MSVC>:/W4>"
)
add_library(audio_core STATIC
	src/AudioAnalyzer.cpp)

target_link_libraries(audio_core
	PRIVATE project_warnings)

target_link_libraries(audio-analyzer
	PRIVATE audio_core project_warnings)

target_compile_features(audio_core PRIVATE cxx_std_17)

target_include_directories(audio_core
	PUBLIC include)

enable_testing()

add_executable(audio_tests 
	tests/AudioAnalyzerTest.cpp
)

target_compile_features(audio_tests PRIVATE cxx_std_17)

target_link_libraries(audio_tests
	PRIVATE
	audio_core
	project_warnings
	GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(audio_tests)



