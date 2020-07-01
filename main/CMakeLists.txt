set(Main_SRCS birthday.c today_provider.c authentication_service.c profile_dao.c map.c rsa_token_dao.c logger.c tennis.c queue.c )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(core ${Main_SRCS})
add_executable(c-otp main.c queue_malloc.c)
target_link_libraries(c-otp core)

