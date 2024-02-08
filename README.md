# ESPHome Oil Tank Volume Component

This project includes a library `kariudo::oiltank` via `oiltank.h` that provides functions for calculating volumes, specifically those required to calculate the volume in a
standard home heating oil tank with an oval shape, of liquid inside. In this case when laying on it's side.
These include:

* Oval oil tanks (horizontal)
* Cylinders (horizontal)
* Rectangles

## ESPHome External Component

This library includes an ESPHome component to create the following sensors:

- Remaining Volume
- Remaining Percentage

This is performed by collecting data from a configured ultrasonic sensor. A reading is taken from the top of the tank to the surface of the oil using the ultrasonic sensor, and this component reads that data and provided configuration about the specific shape of the oil tank to calculate and report the approximate volume of oil in the tank, and its remaining percentage based on your tanks fill volume.

*Sample configuration of component:*

```yaml
# Define where to find this external component
external_components:
  - source:
      type: git
      url: https://github.com/kariudo/oil-tank-volume
      ref: dev
    components: [ oiltank ]
    refresh: 0s

sensor:
  # Ultrasonic distance sensor
  - platform: ultrasonic
    id: ${esp_id}_us
    ...
    # The rest of your ultrasonic sensor configuration here

  # Configuration of this external component
  - platform: oiltank
    id: ${esp_id}_oiltank
    sensor_offset: 2
    distance_sensor_id: ${esp_id}_us
    fill_limit: 250
    remaining_percentage:
      name: "Remaining Percentage"
    remaining_volume:
      name: "Remaining Volume"
```


## Installation

This library is a header-only library, so no installation is required. Just include the `oiltank.h` header file in your project:

```c++
#include "oiltank.h"
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


After these steps, you will find the files in the build directory.

There is a `test_console` included, to use for checking the function of the library.

