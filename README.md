# 3D Rendering Library

<p align="center">
<img width="521" height="460" alt="02-06-2026 Testing scene" src="https://github.com/user-attachments/assets/644a3d18-7d74-43ff-8691-3821ee30ab40" />
</p>   

This library is made as a wrapper for OpenGL to make the setup of a 3D environment simpler and faster. Inspired somewhat by [SFML](https://www.sfml-dev.org), which creates a simple way of using OpenGL for 2D graphics, the aim is to be able to create simple games without needing to use a game engine and gives people a platform to learn the lower level of games programming.

The various libraries that are used to create this are:
  - [GLFW](https://github.com/glfw/glfw)
  - [GLAD](https://github.com/Dav1dde/glad)
  - [GLM](https://github.com/g-truc/glm)
  - [stb_image](https://github.com/nothings/stb/blob/master/stb_image.h)
  - [Assimp](https://github.com/assimp/assimp)

The main resource used to learn OpenGL and create this project is [LearnOpenGL](https://learnopengl.com) and the currently planned developments will continue to use information provided through the tutrials on this site.

## Using this project

### Implementation into projects

Implementation into other projects has not, so far, been as heavily considered as implementing the basics of functionality, however within this repository are all the resources for implementing it into other projects.

The best way currently for implementing the code into your own repository is to directly copy the files for glad, imgui, stb_image, and src into your project and use the CMakelists.txt to gather and link the dependencies in your CMakeLists to use the resources.

### Usage in your own projects

Currently this project is made to support windows machines and the majority of development will continue to target these machines, however considerations for implementing Linux and Mac capability may happen in the future.

The simplest way to get this project to start rendering to a window is to create a class that inherits from the Game class and override functions in there to create Objects using the Object class (or creating an Object factory to create and automatically render objects). This is a basic overview which will be talked about in more depth in the wiki pages.
