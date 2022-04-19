npm config set msbuild_path "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\MSBuild\Current\Bin\MSBuild.exe"
npm config set msvs_version 2019 --global

npm install -g yo
npm install -g generator-napi-module

yo napi-module

For debugging uses CodeLLDB:
https://github.com/vadimcn/vscode-lldb

Useful links:
https://github.com/nodejs/node-addon-examples

example c_cpp_properties.json for intellisense:
{
"configurations": [
{
"name": "Win32",
"includePath": [
"${workspaceFolder}/**",
"C:\\Users\\<user>\\AppData\\Local\\node-gyp\\Cache\\<node version>\\include\\node"
],
"defines": ["_DEBUG", "UNICODE", "_UNICODE"],
"windowsSdkVersion": "10.0.19041.0",
"compilerPath": "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\BuildTools\\VC\\Tools\\MSVC\\14.29.30133\\bin\\Hostx64\\x64\\cl.exe",
"cStandard": "c17",
"cppStandard": "c++17",
"intelliSenseMode": "windows-msvc-x64"
}
],
"version": 4
}
