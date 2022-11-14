add_executable(demo main.cpp)


target_compile_features(demo PRIVATE cxx_std_20)

target_compile_options(demo PRIVATE
            ${CXX_FLAGS}
            "$<$<CONFIG:Debug>:${CXX_FLAGS_DEBUG}>"
            "$<$<CONFIG:Release>:${CXX_FLAGS_RELEASE}>")

#target_compile_options(app PRIVATE "-fsanitize=address" "-fsanitize=undefined")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_options(demo PRIVATE ${SANITIZE_FLAG})
endif()

# target_link_libraries(app PRIVATE TinyJson)
target_link_libraries(demo ${OpenCV_LIBS})