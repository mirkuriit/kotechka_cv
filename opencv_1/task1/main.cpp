#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

void save_img(cv::Mat img, std::string filename){
    if (!cv::imwrite(filename, img)) {
        std::cerr << "Error: Could not save image!" << std::endl;
    }

}

int main(int argc, char* argv[]) {
    int cols = std::stoi(argv[2]);
    int rows = std::stoi(argv[4]);
    int cell = std::stoi(argv[6]);

    cv::Mat image(
        rows*cell,
        cols*cell, 
        CV_8UC3, 
        cv::Scalar(255, 255, 255)
    ); 
    for (int i=0;i <= cols; i++){
        for (int j=0; j<=rows; j++){
            int col = (i+j)%2;
            cv::rectangle(
                image,
                cv::Point(cell*i, cell*j),
                cv::Point(cell*i+cell, cell*j+cell),
                cv::Scalar(255*col, 255*col, 255*col),        
                cv::FILLED
            );
        }
    }

    save_img(image, "../meow.jpg");
    return 0;
}