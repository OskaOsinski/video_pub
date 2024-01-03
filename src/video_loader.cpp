#include "video_loader.hpp"

Video::Video(const std::string &name, const std::string &video_path)
    : Node(name)
{
    initParams();
    initPublisher();
    std::cout << "OpenCV version : " << CV_VERSION << std::endl;
    std::cout << "Major version : " << CV_MAJOR_VERSION << std::endl;
    std::cout << "Minor version : " << CV_MINOR_VERSION << std::endl;
    std::cout << "Subminor version : " << CV_SUBMINOR_VERSION << std::endl;
    loadVideo(video_path);
}

void Video::initParams()
{
    declare_parameter("pub_img_topic", "video_publisher");
    declare_parameter("hz", 30);

    _img_topic = get_parameter("pub_img_topic").as_string();
    _hz = get_parameter("hz").as_int();
}
void Video::initPublisher()
{
    _img_pub = create_publisher<sensor_msgs::msg::Image>("sebil", 10);
}

// void Video::loadVideo(const std::string &video_path)
// {
//     cv::VideoCapture cap(video_path);
//     if (!cap.isOpened())
//     {
//         RCLCPP_INFO(this->get_logger(), "Failed to open the video: %s", video_path);
//         return;
//     }

//     cv::Mat frame(cv::Size(1280, 720), CV_8UC3);
//     sensor_msgs::msg::Image::SharedPtr msg;

//     while (rclcpp::ok())
//     {
//         cap >> frame;

//         if (frame.empty())
//             break;

//         msg =
//             cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame)
//                 .toImageMsg();

//         _img_pub->publish(*msg.get());

//         cv::imshow("Frame", frame);

//         char c = (char)cv::waitKey(25);
//         if (c == 27)
//             break;
//     }
//     cap.release();
//     cv::destroyAllWindows();
// }

void Video::loadVideo(const std::string &video_path)
{

    cv::VideoCapture cap(video_path);

    if (!cap.isOpened())
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to open the video file: ");
        return;
    }
    std::cout << "test0" << std::endl;

    cv::Mat frame(cv::Size(1920, 1208), CV_8UC3);
    std::cout << "test1" << std::endl;

    while (rclcpp::ok())
    {
        std::cout << "test2" << std::endl;
        cap.read(frame);
        std::cout << frame.size();

        if (frame.empty())
            break;

        cv::Mat frame_for_imshow = frame.clone();

        cv::imshow("Frame", frame_for_imshow);
        cv::waitKey(1);

        // sensor_msgs::msg::Image::SharedPtr msg =
        //     cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame).toImageMsg();

        // _img_pub->publish(*msg.get());

        // char c = (char)cv::waitKey(25);
        // if (c == 27)
        //     break;
    }
}