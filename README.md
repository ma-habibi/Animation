# Animation

## Build
  - Install [vcpkg](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started?pivots=shell-bash)

  - Replace `<path_to_vcpkg>` within `CMakeUserPresets.json` with the actuall path to `vcpkg`

  - set cmake:

    ```sh
    cmake --preset=default
    ```

  - build:
    
    ```sh
    cmake --build build
    ```

  - run:
    
    ```sh
    ./build/animation
    ```
