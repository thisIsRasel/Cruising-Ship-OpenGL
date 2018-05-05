# Cruising Ship-OpenGL

Install freeglut
----------------
Install freeglut in your machine. Freeglut files are provided in this repository. 
You can also download freeglut from this url: http://freeglut.sourceforge.net/

For setting up freeglut in code block follow these steps:

1. Copy \freeglut\freeglut.dll to C:\Windows\System32 for 32-bit or C:\Windows\SysWOW64 for 64-bit

2. Copy \freeglut\lib\freeglut.lib to \MinGW\lib (i.e., C:\Program Files\CodeBlocks\MinGW\lib), and

3. Copy \freeglut\include\GL to MinGW\include\GL (i.e., C:\Program Files\CodeBlocks\MinGW\include)

4. Create Glut project from Code::Blocks. if in any step it requires GLUT location show the path upto MinGW that includes lib and include folder (i.e., C:\Program Files\CodeBlocks\MinGW).

5. Add \MinGW\lib\libopengl32.a and \MinGW\lib\freeglut.lib (i.e., C:\Program Files\CodeBlocks\MinGW\lib\freeglut.lib) from Settings > Compiler & Debugger > Linker Settings.

These are default locations, your paths may be different. But basically, you place the .lib and .h files in the location of your compiler (in this case mingw). The .dll file goes in the windows system directory.



Note: Both 32-bit and 64-bit freeglut files are provided with this repository and you may need to link more libraries from Linker settings. 