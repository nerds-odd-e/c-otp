set(Main_SRCS birthday.h birthday.c today_provider.h today_provider.c)

add_library(core ${Main_SRCS})
add_executable(c-otp main.c)
target_link_libraries(c-otp core)

