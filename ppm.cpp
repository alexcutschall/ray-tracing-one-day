#include <iostream>

int main() {

    // Image
    const int image_width = 256;
    const int image_height = 256;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // This is starting at 256 and goes down to 0, meaning it goes top to bottom
    for(int j = image_height - 1; j >= 0; --j) {
        // This helps identify issues such as infinite loops
        std::cerr << "\rScalines remaining: " << j << ' ' << std::flush;
        // This starts at 0 and goes to 256, meaning it goes left to right
        for (int i = 0; i < image_width; ++i) {
            // This is calculating the color based of the position on the screen
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.25;

            // Why are we know transforming them into ints multiplied?
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            // Syntax here is very important because it is structuring the ppm properly
            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::cerr << "\nDone.\n";
}
