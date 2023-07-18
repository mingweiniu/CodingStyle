$env:Path = C:\Windows\Microsoft.NET\Framework\v4.0.30319;$env:Path
cd $Env:VULKAN_SDK

cd glslang
mkdir build
cd build
cmake -G "Visual Studio 14 Win64" ..
msbuild ALL_BUILD.vcxproj /p:Platform=x64 /p:Configuration=Debug
msbuild ALL_BUILD.vcxproj /p:Platform=x64 /p:Configuration=Release
cd ..
mkdir build32
cd build32
cmake -G "Visual Studio 14" ..
msbuild ALL_BUILD.vcxproj /p:Platform=x86 /p:Configuration=Debug
msbuild ALL_BUILD.vcxproj /p:Platform=x86 /p:Configuration=Release
cd ..
cd ..


cd spirv-tools
mkdir build
cd build
cmake -G "Visual Studio 14 Win64" ..
msbuild ALL_BUILD.vcxproj /p:Platform=x64 /p:Configuration=Debug
msbuild ALL_BUILD.vcxproj /p:Platform=x64 /p:Configuration=Release
cd ..
mkdir build32
cd build32
cmake -G "Visual Studio 14" ..
msbuild ALL_BUILD.vcxproj /p:Platform=x86 /p:Configuration=Debug
msbuild ALL_BUILD.vcxproj /p:Platform=x86 /p:Configuration=Release
cd ..
cd ..


cd Samples
mkdir build
cd build
cmake -G "Visual Studio 14 Win64" ..
msbuild ALL_BUILD.vcxproj /p:Platform=x64 /p:Configuration=Debug
msbuild ALL_BUILD.vcxproj /p:Platform=x64 /p:Configuration=Release
cd ..
mkdir build32
cd build32
cmake -G "Visual Studio 14" ..
msbuild ALL_BUILD.vcxproj /p:Platform=x86 /p:Configuration=Debug
msbuild ALL_BUILD.vcxproj /p:Platform=x86 /p:Configuration=Release
cd..
cd..
