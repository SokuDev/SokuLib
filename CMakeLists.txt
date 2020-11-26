cmake_minimum_required(VERSION 3.15)
project(SokuLib)

set(CMAKE_CXX_STANDARD 14)

add_library(
	SokuLib
	src/Core/BattleManager.hpp
	src/Core/Core.hpp
	src/Core/Font.hpp
	src/Core/HandleManager.hpp
	src/Core/IEffectManager.hpp
	src/Core/IFileReader.hpp
	src/Core/InfoManager.hpp
	src/Core/InputManager.hpp
	src/Core/Key.hpp
	src/Core/Math.hpp
	src/Core/Memory.hpp
	src/Core/Menus/
	src/Core/Misc.hpp
	src/Core/NetObject.hpp
	src/Core/PackageLoader.hpp
	src/Core/Renderer.hpp
	src/Core/SceneCreaters.hpp
	src/Core/SceneSize.hpp
	src/Core/SelectManager.hpp
	src/Core/SokuAddresses.hpp
	src/Core/SokuFct.hpp
	src/Core/SoundManager.hpp
	src/Core/Tamper.hpp
	src/Core/TextureManager.hpp
	src/Core/UnknownStuff.hpp
	src/Core/Vector.hpp
	src/Core/VTables.hpp
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
	src/Core/Menus/ConnectMenu.cpp src/Core/Menus.hpp)


if (DEFINED VERSION_110a)
	target_compile_definitions(
		SokuLib PRIVATE
		SOKU_VER_110a=${VERSION_110a}
	)
endif ()