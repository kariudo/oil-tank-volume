# oil-tank-volume

This library provides functions for calculating volumes, specifically those required to calculate the volume in a
standard home heating oil tank with an oval shape, of liquid inside. In this case when laying on it's side.
These include:

* Oval oil tanks (horizontal)
* Cylinders (horizontal)
* Rectangles

## Installation

This library is a header-only library, so no installation is required. Just include the `oiltank.hpp` header file in your project:

```c++
#include "oiltank.hpp"
...
```

## Building the Project

This project uses CMake for building from source. Here are the steps to compile the project:

1. **Create a build directory**: This keeps the build files separate from the source files.

   ```sh
   mkdir build
   cd build
   ```

2. Generate the build system: Run CMake to create the makefiles.

    ```sh
    cmake ..
    ```

3. Compile the code: Use the generated makefiles to compile the project.

    ```sh
    make
    ```


After these steps, you will find the executable and/or library files in the build directory. You can then run your program directly from there.

