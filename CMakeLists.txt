cmake_minimum_required(VERSION 3.13)
project(SokuLib)

set(CMAKE_CXX_STANDARD 20)

add_library(
	SokuLib STATIC
	src/AnimationObject.cpp
	src/AnimationObject.hpp
	src/BattleManager.cpp
	src/BattleManager.hpp
	src/BattleMode.cpp
	src/BattleMode.hpp
	src/Camera.cpp
	src/Camera.hpp
	src/Cards.cpp
	src/Cards.hpp
	src/Character.cpp
	src/Character.hpp
	src/CharacterManager.cpp
	src/CharacterManager.hpp
	src/dlls/D3D9.DLL.cpp
	src/dlls/D3D9.DLL.hpp
	src/dlls/D3DX9_33.DLL.cpp
	src/dlls/D3DX9_33.DLL.hpp
	src/dlls/DLL.hpp
	src/dlls/GDI32.DLL.cpp
	src/dlls/GDI32.DLL.hpp
	src/dlls/IMAGEHLP.DLL.cpp
	src/dlls/IMAGEHLP.DLL.hpp
	src/dlls/IMM32.DLL.cpp
	src/dlls/IMM32.DLL.hpp
	src/dlls/KERNEL32.DLL.cpp
	src/dlls/KERNEL32.DLL.hpp
	src/dlls/OLE32.DLL.cpp
	src/dlls/OLE32.DLL.hpp
	src/dlls/USER32.DLL.cpp
	src/dlls/USER32.DLL.hpp
	src/dlls/WINMM.DLL.cpp
	src/dlls/WINMM.DLL.hpp
	src/dlls/WS2_32.DLL.cpp
	src/dlls/WS2_32.DLL.hpp
	src/DrawUtils.cpp
	src/DrawUtils.hpp
	src/Deque.hpp
	src/Design.cpp
	src/Design.hpp
	src/Exceptions.hpp
	src/Font.cpp
	src/Font.hpp
	src/HandleManager.hpp
	src/Hash.cpp
	src/Hash.hpp
	src/IEffectManager.cpp
	src/IEffectManager.hpp
	src/IFileReader.cpp
	src/IFileReader.hpp
	src/InputManager.cpp
	src/InputManager.hpp
	src/Key.cpp
	src/Key.hpp
	src/LinkedList.hpp
	src/Map.hpp
	src/Memory.cpp
	src/Memory.hpp
	src/Menus.cpp
	src/Menus.hpp
	src/Menus/ConnectMenu.cpp
	src/Menus/ProfileDeckEdit.cpp
	src/Menus/ProfileDeckEdit.hpp
	src/NetObject.cpp
	src/NetObject.hpp
	src/Packet.cpp
	src/Packet.hpp
	src/PracticeSettings.cpp
	src/PracticeSettings.hpp
	src/Profile.cpp
	src/Profile.hpp
	src/Renderer.cpp
	src/Renderer.hpp
	src/SceneCreaters.hpp
	src/Scenes.cpp
	src/Scenes.hpp
	src/SceneScript.cpp
	src/SceneScript.hpp
	src/SceneSize.cpp
	src/SceneSize.hpp
	src/SokuAddresses.hpp
	src/UnionCast.hpp
	src/SokuLib.hpp
	src/SoundData.hpp
	src/SoundManager.cpp
	src/SoundManager.hpp
	src/Stack.cpp
	src/Stack.hpp
	src/Stage.cpp
	src/Stage.hpp
	src/String.cpp
	src/String.hpp
	src/Tamper.hpp
	src/TextureManager.cpp
	src/TextureManager.hpp
	src/VTables.cpp
	src/VTables.hpp
	src/Weather.cpp
	src/Weather.hpp
	src/DeprecatedElements.hpp
	src/Sprite.cpp
	src/Sprite.hpp
	src/Vector2.hpp
	src/Action.hpp
	src/FrameData.cpp
	src/FrameData.hpp
	src/Boxes.hpp
	src/DeprecatedElements.cpp
	src/CsvParser.cpp
	src/CsvParser.hpp
	src/Menus/ResultMenu.cpp
	src/Menus/ResultMenu.hpp
	src/Misc.cpp
	src/Misc.hpp
	src/GameObject.cpp
	src/GameObject.hpp
	src/GameData.cpp
	src/GameData.hpp
	src/Player.cpp
	src/Player.hpp
	src/InputCombination.hpp
	src/Menus/PauseMenu.cpp
	src/Menus/PauseMenu.hpp
)

if ("${CMAKE_BUILD_TYPE}" STREQUAL Debug)
	target_compile_definitions(
		SokuLib PRIVATE
		_SOKU_LIB_DEBUG=1
	)
endif()

target_include_directories(SokuLib INTERFACE src/ PUBLIC directx)

add_executable(
	SokuLibTests
	test/main.cpp
)
target_include_directories(SokuLibTests PRIVATE directx)
target_link_libraries(SokuLibTests SokuLib)

add_library(
	SokuLibDllTests SHARED
	test/main.dll.cpp
)
target_include_directories(SokuLibDllTests PRIVATE directx)
target_link_libraries(SokuLibDllTests SokuLib)
