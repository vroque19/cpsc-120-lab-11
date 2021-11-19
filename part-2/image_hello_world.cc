
#include <Magick++.h>

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace Magick;

/// Entry point to the image_hello_world program
/// \remark Must have 1 argument. The argument is a path to a file. In the
/// simpliest case, it can be the name of a file in the same directory
/// as the program.
int main(int argc, char const *argv[]) {
  InitializeMagick(*argv);
  auto args = vector<string>(argv, argv + argc);
  if (args.size() < 2) {
    cout << "Please provide a path to a file.\n";
    exit(1);
  }
  string output_file_name;
  try {
    output_file_name = args.at(1);
  } catch (exception const& problem) {
    cout << "There was a problem getting the file name.\n";
    cout << problem.what() << "\n";
    exit(1);
  }
  // If you wish to change the size of the image, stick to square
  // dimensions and powers of 2. Remember the larger the width and height
  // the longer it will take to make the image and the more storage on
  // disk it will use.
  // Good choices are 256, 512, 1024, 2048, 4096, 8192
  // The width of the image is the number of columns.
  // The height of the image is the number of rows.
  // Remember `make test` will only work with 512 x 512
  const int kImageWidth = 512;
  const int kImageHeight = 512;

  ColorRGB white(1, 1, 1);
  Image image(Geometry(kImageWidth, kImageHeight), white);

  // Keep column as an int because we're counting down and only stop after
  // columns < 0
  for (int column = int(image.columns() - 1); column >= 0; column--) {
    for (unsigned int row = 0; row < image.rows(); row++) {
      // TODO: Declare a double variable named red
      // TODO: Declare a double variable named green
      // TODO: Declare a double variable named blue; initialize blue to 0.25
      // TODO: Convert row to a double using double() and convert (kImageWidth -1) to a double using double() then calculate the ratio of row:(kImageWidth -1). Assign this ratio to red.
      // TODO: Convert column to a double using double() and convert (kImageHeight -1) to a double using double() then calculate the ratio of row:(kImageWidth -1). Assign this ratio to green.
      // TODO: Declare a new GraphicsMagick color variable. Set the color to the color defined by the variables red, green, blue declared above.
      // TODO: Using the variable image and the member function pixelColor(), set the pixel at row, column to color.
    }
  }

  image.write(output_file_name);

  return 0;
}
