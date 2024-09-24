# Networking demo AIS2203

Code showcasing data transmission using various networking technologies using C++.

Tested on Windows with Visual Studio 2022.

### Features:
* UDP
* TCP/IP
* WebSockets
* ZMQ (Jack of all trades)
* Thrift (RPC framework)

Code is for demonstration purposes only, and is not necessary perfect.

### Building with vcpkg (using manifest mode)

Call CMake with 
```
-DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake
```

By default, only UDP, TCP/IP and WS demos are enabled (Boost dependency).
Add optional features by listing them with: 
```
-DVCPKG_MANIFEST_FEATURES=feature1;feature2
```
See [vcpkg.json](vcpkg.json) for available features.


#### Building under MinGW

Under MinGW you'll need to specify the vcpkg triplet:
```
-DVCPKG_TARGET_TRIPLET=x64-mingw-[static|dynamic]   # choose either `static` or `dynamic`.
-DVCPKG_HOST_TRIPLET=x64-mingw-[static|dynamic]       # <-- needed only if MSVC cannot be found. 
```
