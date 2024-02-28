#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void displayImage(const Mat& image) {
    namedWindow("Image", WINDOW_NORMAL);
    imshow("Image", image);
    waitKey(0);
    destroyAllWindows();
}

void applyGrayscale(const Mat& inputImage, Mat& outputImage) {
    cvtColor(inputImage, outputImage, COLOR_BGR2GRAY);
}

void applyBlur(const Mat& inputImage, Mat& outputImage) {
    GaussianBlur(inputImage, outputImage, Size(5, 5), 0);
}

void applySharpen(const Mat& inputImage, Mat& outputImage) {
    Mat kernel = (Mat_<char>(3,3) <<  0, -1,  0,
                                      -1,  5, -1,
                                       0, -1,  0);
    filter2D(inputImage, outputImage, inputImage.depth(), kernel);
}

void adjustBrightness(const Mat& inputImage, Mat& outputImage, int brightness) {
    inputImage.convertTo(outputImage, -1, 1, brightness);
}

void adjustContrast(const Mat& inputImage, Mat& outputImage, double contrast) {
    inputImage.convertTo(outputImage, -1, contrast);
}

void cropImage(const Mat& inputImage, Mat& outputImage, int x, int y, int width, int height) {
    Rect roi(x, y, width, height);
    outputImage = inputImage(roi);
}

void resizeImage(const Mat& inputImage, Mat& outputImage, int width, int height) {
    resize(inputImage, outputImage, Size(width, height));
}

void saveImage(const Mat& image, const string& filename) {
    imwrite(filename, image);
}

int main() {
    Mat image = imread("path_to_image.jpg");
    if (image.empty()) {
        cerr << "Error: Unable to load image." << endl;
        return -1;
    }

    Mat processedImage;
    applyGrayscale(image, processedImage);
    displayImage(processedImage);

    applyBlur(image, processedImage);
    displayImage(processedImage);

    applySharpen(image, processedImage);
    displayImage(processedImage);

    adjustBrightness(image, processedImage, 50);
    displayImage(processedImage);

    adjustContrast(image, processedImage, 1.5);
    displayImage(processedImage);

    cropImage(image, processedImage, 100, 100, 300, 200);
    displayImage(processedImage);

    resizeImage(image, processedImage, 400, 300);
    displayImage(processedImage);

    saveImage(processedImage, "processed_image.jpg");

    return 0;
}

