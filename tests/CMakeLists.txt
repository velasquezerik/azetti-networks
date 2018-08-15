add_executable(test_user test_user.cc ${SOURCES} )
add_test(test_user test_user)
target_link_libraries(test_user Qt5::Test)

add_executable(test_group test_group.cc ${SOURCES})
add_test(test_group test_group)
target_link_libraries(test_group Qt5::Test)