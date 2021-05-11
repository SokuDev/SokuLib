cmake_minimum_required(VERSION 3.13)
project(SokuLib)

set(CMAKE_CXX_STANDARD 17)

add_library(
	SokuLib STATIC
	src/Core/BattleManager.cpp
	src/Core/BattleManager.hpp
	src/Core/Cards.cpp
	src/Core/Cards.hpp
	src/Core/Core.hpp
	src/Core/Exceptions.hpp
	src/Core/Font.cpp
	src/Core/Font.hpp
	src/Core/HandleManager.hpp
	src/Core/IEffectManager.hpp
	src/Core/IFileReader.hpp
	src/Core/InfoManager.hpp
	src/Core/InputManager.cpp
	src/Core/InputManager.hpp
	src/Core/Key.cpp
	src/Core/Key.hpp
	src/Core/Math.hpp
	src/Core/Memory.cpp
	src/Core/Memory.hpp
	src/Core/Menus.cpp
	src/Core/Menus.hpp
	src/Core/Menus/ConnectMenu.cpp
	src/Core/Misc.hpp
	src/Core/NetObject.cpp
	src/Core/NetObject.hpp
	src/Core/Packet.cpp
	src/Core/Packet.hpp
	src/Core/PackageLoader.hpp
	src/Core/Renderer.cpp
	src/Core/Renderer.hpp
	src/Core/SceneCreaters.hpp
	src/Core/SceneSize.cpp
	src/Core/SceneSize.hpp
	src/Core/SelectManager.hpp
	src/Core/SokuAddresses.hpp
	src/Core/SokuFct.hpp
	src/Core/SoundManager.cpp
	src/Core/SoundManager.hpp
	src/Core/Stack.cpp
	src/Core/Stack.hpp
	src/Core/Tamper.hpp
	src/Core/TextureManager.cpp
	src/Core/TextureManager.hpp
	src/Core/UnknownStuff.hpp
	src/Core/Vector.hpp
	src/Core/VTables.hpp
	src/Core/Weather.cpp
	src/Core/Weather.hpp
	src/Data/BattleMode.cpp
	src/Data/BattleMode.hpp
	src/Data/Character.cpp
	src/Data/Character.hpp
	src/Data/Data.hpp
	src/Data/Hash.cpp
	src/Data/Hash.hpp
	src/Data/Scenes.cpp
	src/Data/Scenes.hpp
	src/Data/Stage.cpp
	src/Data/Stage.hpp
	src/Data/String.cpp
	src/Data/String.hpp
	src/SokuLib.hpp
	src/Core/CharacterManager.hpp
	src/Core/LinkedList.hpp
	src/Data/DatFiles.cpp
	src/Data/DatFiles.hpp
	src/Core/CharacterManager.cpp
	src/Core/PracticeSettings.cpp
	src/Core/PracticeSettings.hpp
	src/Core/Camera.cpp
	src/Core/Camera.hpp
	src/Core/VTables.cpp
	src/Core/Menus/ProfileDeckEdit.cpp
	src/Core/Menus/ProfileDeckEdit.hpp
	src/Core/Map.hpp
	src/Core/Map.cpp
	src/Core/Profile.cpp
	src/Core/Profile.hpp
	src/Core/dlls/GDI32.DLL.cpp
	src/Core/dlls/GDI32.DLL.hpp
	src/Core/dlls/IMM32.DLL.cpp
	src/Core/dlls/IMM32.DLL.hpp
	src/Core/dlls/KERNEL32.DLL.cpp
	src/Core/dlls/KERNEL32.DLL.hpp
	src/Core/dlls/USER32.DLL.cpp
	src/Core/dlls/USER32.DLL.hpp
	src/Core/dlls/WINMM.DLL.cpp
	src/Core/dlls/WINMM.DLL.hpp
	src/Core/dlls/WS2_32.DLL.cpp
	src/Core/dlls/WS2_32.DLL.hpp
	src/Core/dlls/DLL.hpp
	src/Core/dlls/IMAGEHLP.DLL.cpp
	src/Core/dlls/IMAGEHLP.DLL.hpp
	src/Core/dlls/D3D9.DLL.cpp
	src/Core/dlls/D3D9.DLL.hpp
	src/Core/dlls/D3DX9_33.DLL.cpp
	src/Core/dlls/D3DX9_33.DLL.hpp
	src/Core/dlls/OLE32.DLL.cpp
	src/Core/dlls/OLE32.DLL.hpp
)

if ("${CMAKE_BUILD_TYPE}" STREQUAL Debug)
	target_compile_definitions(
		SokuLib PRIVATE
		_SOKU_LIB_DEBUG=1
	)
endif()

target_include_directories(SokuLib INTERFACE src/)

add_executable(
	SokuLibTests
	test/main.cpp
)

target_link_libraries(SokuLibTests SokuLib)