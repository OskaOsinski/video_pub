// STL
#include <iostream>
#include <string>

// OpenCV2
#include <opencv2/highgui.hpp>

// ROS2
#include <rclcpp/rclcpp.hpp>
#include "cv_bridge/cv_bridge.h"
#include "sensor_msgs/msg/image.hpp"

class Video : rclcpp::Node
{
public:
    Video(const std::string &name, const std::string &video_path);

private:
    std::string _img_topic;
    int _hz;

    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr _img_pub;

    void initParams();
    void initPublisher();
    void loadVideo(const std::string &video_path);
};