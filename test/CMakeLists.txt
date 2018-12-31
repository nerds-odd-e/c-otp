set(Test_SRCS stub_today_provider.h birthday_unittest.cc authentication_service_unittest.cc fff.h stub_rsa_token_dao.h tennis_unittest.cc)

add_executable(c-otp-test ${Test_SRCS})
target_link_libraries(c-otp-test gtest gtest_main core)


