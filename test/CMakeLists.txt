set(Test_SRCS birthday_unittest.cc authentication_service_unittest.cc tennis_unittest.cc queue_unittest.cc)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(c-otp-test ${Test_SRCS})
target_link_libraries(c-otp-test gtest gtest_main core)


