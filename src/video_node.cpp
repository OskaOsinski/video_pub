#include "video_loader.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Please provide the path to the video \n";
        return -1;
    }

    rclcpp::init(argc, argv);
    std::shared_ptr<Video> node = std::make_shared<Video>("video_loader", argv[1]);

    rclcpp::shutdown();
    return 0;
}