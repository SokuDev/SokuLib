//
// Created by DPhoenix on 26/05/2020.
//

#ifndef SOKULIB_SCRIPT_HPP
#define SOKULIB_SCRIPT_HPP


#include <type_traits>
#include "String.hpp"
#include "Deque.hpp"
#include "Map.hpp"
#include "List.hpp"
#include "UnionCast.hpp"

namespace SokuLib {
    class CommandParser {
    public:
        class CommandBase {
        public:
            const int id;

            CommandBase() : id(-1) {}
            CommandBase(int id) : id(id) {}
            virtual ~CommandBase() = default;
            virtual void parseArgs(char*) = 0;
        };

        Map<String, void*> factoryMap;
        void* factoryEmpty = 0; char unknown10[0x4];
        Deque<CommandBase*> commands;
        struct {int _ = 0; void* container = 0; int offset = 0;} commandIterator;

        // 0x41fb40: ctor in Ending+0x4+0x18
        // 0x41fb40: ctor in Opening+0x8+0x18
        // 0x427d00: ctor in CTitle+0x8+0x18
        // 0x462330: ctor in CScenarioData+0x36C
        CommandParser() = default;
        ~CommandParser();
        bool parse(const char* filename);
    };

    class SceneScript {
    public:
        char unknown00[0x18];
        CommandParser parser;

        struct UnknownData1{char unknown00[0x7C];};
        Map<int, UnknownData1*> unknown4C;
        List<UnknownData1> unknown58;

        struct UnknownData2{char unknown00[0x14];};
        Map<int, UnknownData2> unknown64; // TODO is this actually a set?

        String bgmFilename;
        char unknown8C[4];

        void clear();
        SceneScript();
        inline ~SceneScript() { clear(); }

        bool parse(const char* filename);
        bool update();
        void render();
    };
}


#endif //SOKULIB_SCRIPT_HPP
