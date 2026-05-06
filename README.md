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
  
This will create the executable at `./build/animation`.

## Usage
### Examples:

Running road animation.
```shell
./build/animation -a road
```
    
### The `--help`:

```text
Usage: animation [--help] [--version] --animation VAR

Optional arguments:
-h, --help       shows help message and exits
-v, --version    prints version information and exits
-a, --animation  The animation to display. [required]
```

## CLI arguments

| name            | brief                                                          | required |
|-----------------|----------------------------------------------------------------|----------|
| -a, --animation | The animation to display. Allowed options: [sin, road, spiral] | true     |
