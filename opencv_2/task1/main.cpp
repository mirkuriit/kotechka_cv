#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace cv;

void save_img(Mat img, std::string filename){
    if (!imwrite(filename, img)) {
        std::cerr << ":(" << std::endl;
    }

}

int main(int argc, char* argv[]) {
    std::string input_path = argv[2];
    std::string out_path = argv[4];
    int n = std::stoi(argv[6]);
    Mat kernel = Mat::ones(n, n, CV_32F) / (float)(n * n);
    

    Mat src = imread(input_path);
    int ROWS = src.rows;
    int COLS = src.cols;
    int K_ROWS = kernel.rows;
    int K_COLS = kernel.cols;
    int kCenY = K_ROWS / 2;
    int kCenX = K_COLS / 2;

    Mat dst = Mat::zeros(src.rows - 2*kCenY, src.cols - 2*kCenX, src.type());

    std::cout << src.rows << " " << src.cols;
    for(int y=kCenY;y<src.rows-kCenY;y++) {
        for(int x=kCenX;x<src.cols-kCenX;x++){
            std::vector<float> sums(3, 0.0f);


            Vec3b color = src.at<Vec3b>(y,x);
            for (int m = 0; m < K_ROWS; ++m) {
                for (int n = 0; n < K_COLS; ++n) {
                    Vec3b& pixel = src.at<Vec3b>(y + m - kCenY, x + n - kCenX);
                    float k = kernel.at<float>(m, n);

                    sums[0] += pixel[0] * k;  
                    sums[1] += pixel[1] * k;  
                    sums[2] += pixel[2] * k;
                }
            }
            dst.at<Vec3b>(y - kCenY, x - kCenX) = Vec3b(
                saturate_cast<uchar>(sums[0]),
                saturate_cast<uchar>(sums[1]),
                saturate_cast<uchar>(sums[2])
            );

        }
    }

    //Mat out_img = src.clone();

    save_img(dst, out_path);
    return 0;
}