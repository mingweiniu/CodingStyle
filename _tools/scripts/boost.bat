REM http://www.boost.org/doc/libs/1_63_0/more/getting_started/windows.html
.\bootstrap.bat
.\b2.exe --help
.\b2.exe -j8 address-model=64 link=shared,static threading=multi toolset=msvc-14.0 variant=debug,release --build-type=complete stage
