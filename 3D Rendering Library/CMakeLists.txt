# CMakeList.txt : CMake project for 3D Rendering Library, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("3D Rendering Library")

include(FetchContent)
FetchContent_Declare(
	GLFW
	GIT_REPOSITORY https://github.com/glfw/glfw.git
	GIT_TAG 7b6aead9fb88b3623e3b3725ebb42670cbe4c579
)
FetchContent_MakeAvailable(GLFW)

FetchContent_Declare(
	GLM
	GIT_REPOSITORY https://github.com/g-truc/glm.git
	GIT_TAG 0af55ccecd98d4e5a8d1fad7de25ba429d60e863
)
FetchContent_MakeAvailable(GLM)

# Add source to this project's executable.
add_executable (Renderer 
"main.cpp"  
"glad/include/glad/glad.h"
"glad/include/KHR/khrplatform.h" 
"glad/src/glad.c" 
"imgui-1.92.5/imconfig.h"
"imgui-1.92.5/imgui.cpp" 
"imgui-1.92.5/imgui.h"
"imgui-1.92.5/imgui_demo.cpp" 
"imgui-1.92.5/imgui_draw.cpp"
"imgui-1.92.5/imgui_internal.h"
"imgui-1.92.5/imgui_tables.cpp" 
"imgui-1.92.5/imgui_widgets.cpp"
"imgui-1.92.5/imstb_rectpack.h"
"imgui-1.92.5/imstb_textedit.h"
"imgui-1.92.5/imstb_truetype.h"
"imgui-1.92.5/backends/imgui_impl_glfw.cpp"
"imgui-1.92.5/backends/imgui_impl_glfw.h" 
"imgui-1.92.5/backends/imgui_impl_opengl3.cpp"
"imgui-1.92.5/backends/imgui_impl_opengl3.h"
"imgui-1.92.5/backends/imgui_impl_opengl3_loader.h"
"imgui-1.92.5/misc/cpp/imgui_stdlib.cpp" 
"imgui-1.92.5/misc/cpp/imgui_stdlib.h" 
"imgui-1.92.5/misc/fonts/binary_to_compressed_c.cpp" 
"imgui-1.92.5/misc/single_file/imgui_single_file.h" 
"src/Engine/Game.h"
"src/Dependencies.h" 
"src/Engine/Game.cpp"
"src/Engine/Window/Window.h" 
"src/Engine/Window/Window.cpp" 
"src/Engine/Material/Material.h"
"src/Engine/Material/Material.cpp"
"src/Engine/Material/Shader.h" 
"src/Engine/Material/Texture.h" 
"src/Engine/Material/Texture.cpp"
"stb_image/stb_image.h" 
"src/Engine/Transform/Transform.h" 
"src/Engine/Transform/Transform.cpp"
"src/Engine/Mesh/Mesh.h"
"src/Engine/Mesh/Mesh.cpp" 
"src/Engine/Object/Object.h"
"src/Engine/Object/Object.cpp" 
"src/Engine/Camera/Camera.h"
"src/Engine/Camera/Camera.cpp"
"src/Engine/Key/Key.h" 
"src/Engine/Key/Key.cpp"
"src/Engine/Debugger/Debugger.h"
"src/Engine/Debugger/Debugger.cpp" "src/Engine/Factory/Factory.h" "src/Engine/Factory/Factory.cpp")

target_link_libraries(Renderer PRIVATE glfw)
target_link_libraries(Renderer PRIVATE glm::glm)

target_include_directories(Renderer PRIVATE "glad/include")
target_include_directories(Renderer PRIVATE "glad/src")
target_include_directories(Renderer PRIVATE "stb_image")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Renderer PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
