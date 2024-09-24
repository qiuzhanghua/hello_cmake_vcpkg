# Learn CMake and vcpkg

1. Install vcpkg

```powershell
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg 
./bootstrap-vcpkg.sh
```

```powershell
$env:VCPKG_ROOT = "C:\Users\Admin\code\vcpkg"
$env:PATH = "$env:VCPKG_ROOT;$env:PATH"
```

2. Create a C++ Project

```powershell
mkidr hello_cmake_vcpkg
cd hello_cmake_vcpkg
```

3. Use vcpkg
```powershell
vcpkg add port fmt
```
4. Add a CMakeLists.txt
```txt
cmake_minimum_required(VERSION 3.30)

project(Hello)

find_package(fmt CONFIG REQUIRED)

add_executable(Hello main.cpp)

target_link_libraries(Hello PRIVATE fmt::fmt)
```
4. Create a file named CMakePresets.json
```json
{
  "version": 2,
  "configurePresets": [
    {
      "name": "default",
      "generator": "Ninja",
      "binaryDir": "${sourceDir}/build",
      "cacheVariables": {
        "CMAKE_TOOLCHAIN_FILE": "$env{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      }
    }
  ]
}
```

5. Build
```powershell
mkdir build
cd build
cmake ..
# 
cmake --build .
# or
 cmake --build . --config Release

```

6. Run

```powershell
.\Debug\Hello.exe
#
.\Release\Hello.exe 
```