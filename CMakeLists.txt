cmake_minimum_required(VERSION 3.8)
project(video_pub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(cv_bridge REQUIRED)


include_directories(include/video_pub)
add_library(video_loader src/video_loader.cpp)
target_link_libraries(video_loader ${OpenCV_LIBS} ${cv_bridge_LIBRARIES})

add_executable(video_node src/video_node.cpp)
target_link_libraries(video_node video_loader ${OpenCV_LIBS} ${cv_bridge_LIBRARIES})

ament_target_dependencies(video_node rclcpp sensor_msgs cv_bridge)
ament_target_dependencies(video_loader rclcpp sensor_msgs cv_bridge)

install(TARGETS 
  video_node 
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
