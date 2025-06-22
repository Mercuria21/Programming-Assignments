#include <iostream>
#include <cstdlib>

int main() {
    std::string url = "https://www.google.com/"; // You can change this to any URL
    std::cout << "Opening Chrome in incognito mode...\n";

#if defined(_WIN32) || defined(_WIN64)
    // Windows
    std::string command = "start chrome --incognito "" + url + """;
#elif defined(APPLE)
    // macOS
    std::string command = "open -a "Google Chrome" --args --incognito "" + url + """;
#elif defined(linux)
    // Linux
    std::string command = "google-chrome --incognito "" + url + "" &";
#else
    std::cerr << "Unsupported OS." << std::endl;
    return 1;
#endif

    int result = system(command.c_str());

    if (result != 0) {
        std::cerr << "Failed to launch Chrome.\n";
    } else {
        std::cout << "Chrome launched in incognito mode.\n";
    }

    return 0;
}
