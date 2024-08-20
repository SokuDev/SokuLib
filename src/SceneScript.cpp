//
// Created by DPhoenix on 26/05/2020.
//

#include "SceneScript.hpp"

namespace SokuLib {
    CommandParser::~CommandParser() {
        // TODO the STL may work, but it's not the ideal
        (this->*union_cast<bool(CommandParser::*)()>(0x405660))();
    }

    bool CommandParser::parse(const char* filename) { return (this->*union_cast<bool(CommandParser::*)(const char*)>(0x405810))(filename); }

    SceneScript::SceneScript() { (this->*union_cast<void(SceneScript::*)()>(0x45a110))(); }
    void SceneScript::clear() { return (this->*union_cast<void(SceneScript::*)()>(0x4593b0))(); }
    bool SceneScript::parse(const char* filename) { return (this->*union_cast<bool(SceneScript::*)(const char*)>(0x45a660))(filename); }
    bool SceneScript::update() { return (this->*union_cast<bool(SceneScript::*)()>(0x457890))(); }
    void SceneScript::render() { return (this->*union_cast<void(SceneScript::*)()>(0x4571d0))(); }
}