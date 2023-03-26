#include <opencv2/opencv.hpp>

int main() {
    // Open the video file
    cv::VideoCapture cap;
    
    cap.open("</path/to/video>");

    // Check if the video file was successfully opened
    if (!cap.isOpened()) {
        std::cerr << "Error: Failed to open video file" << std::endl;
        return -1;
    }

    // Create a window to display the video frames
    cv::namedWindow("Video", cv::WINDOW_NORMAL);

    // Initialize the face detector
    cv::CascadeClassifier face_detector;
    bool is_success = face_detector.load("</path/to/haarcascade_frontalface_alt.xml>");

    if (!is_success)
    {
        return 0;
    }
    
    cv::Mat frame;
    std::vector<cv::Rect> faces;

    // Loop through the frames of the video
    while (true) {
        // Read a frame from the video
        cap.read(frame);

        // Check if the frame was successfully read
        if (frame.empty()) {
            break;
        }

        // Detect faces in the input image
        faces.clear();
        face_detector.detectMultiScale(frame, faces);

        // Draw rectangles around the detected faces
        for (size_t i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i], cv::Scalar(0, 255, 0), 2);
        }

        // Display the frame in the window
        cv::imshow("Video", frame);

        // Wait for a key press
        int key = cv::waitKey(30);

        // Exit the loop if the 'q' key is pressed
        if (key == 'q') {
            break;
        }
    }

    // Release the video file and destroy the window
    cap.release();
    cv::destroyAllWindows();

    return 0;
}

