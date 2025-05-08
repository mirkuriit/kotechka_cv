#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

void save_img(cv::Mat img, std::string filename){
    if (!cv::imwrite(filename, img)) {
        std::cerr << "Error: Could not save image!" << std::endl;
    }

}

std::vector<int> splitString(const std::string& s, char delimiter) {
    std::vector<int> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(std::stoi(token));
    }
    return tokens;
}

int main(int argc, char* argv[]) {
    int width = std::stoi(argv[2]);
    int height = std::stoi(argv[4]);
    int thick = std::stoi(argv[6]);
    int step = std::stoi(argv[8]);
    std::string s = argv[10];
    auto colors = splitString(s, ',');

    int R = colors[0];
    int G = colors[1];
    int B = colors[2];

    cv::Mat image(
        width,
        height, 
        CV_8UC3, 
        cv::Scalar(255, 255, 255)
    ); 
    int x = width/2;
    int y = height/2;

    int coef_x = 1;
    int coef_y = 1;
    int r = step;
    for (int i=1;i<=width/step+10;i++){
        std::cout << "x: " << x << "    y: " << y << " coef_x:" << coef_x << " coef_y" << coef_y << "\n";
        cv::Point p1(x, y);
        cv::Point p2(x + r*coef_x, y);
        
        cv::line(image, p1, p2, cv::Scalar(R, G, B), 
        thick, cv::LINE_8); 
        x = x + r*coef_x;
        p1 = cv::Point(x, y);
        p2 = cv::Point(x, y + r*coef_y);
        
        cv::line(image, p1, p2, cv::Scalar(R, G, B), 
        thick, cv::LINE_8);
        y = y + r*coef_y;
        
        if (coef_x < 0){
            coef_x = coef_x*(-1) + 1;
        } else {
            coef_x = coef_x*(-1) - 1;
        }
        if (coef_y < 0){
            coef_y = coef_y*(-1) + 1;
        } else {
            coef_y = coef_y*(-1) - 1;
        }

        
 
        
    }

    save_img(image, "../meow.jpg");
    return 0;
}