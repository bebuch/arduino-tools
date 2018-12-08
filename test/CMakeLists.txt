project(test)

# Add test cpp file
file(GLOB SOURCE_FILES "*.cpp")

add_executable(tests ${SOURCE_FILES})

set_property(TARGET tests PROPERTY CXX_STANDARD 17)
set_property(TARGET tests PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(tests PUBLIC arduino_tools GTest::GTest GTest::Main)

target_include_directories(tests PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
