#include "Design.hpp"

namespace {
	// private
	struct CGaugeValue : public SokuLib::CGauge::IValue {
		void* value;
		int offset, length;

		inline CGaugeValue(void** vtable, void* value, int offset, int length)
			: value(value), offset(offset), length(length) { *(void***)this = vtable; }

		float getValue() override {return 0;}
	};

	struct CNumberValue : public SokuLib::CNumber::IValue {
		void* value;

		inline CNumberValue(void** vtable, void* value)
			: value(value) { *(void***)this = vtable; }

		int getInt() override {return 0;}
		float getFloat() override {return 0;}
	};
}

namespace SokuLib {

	// --- CSprite ---
	void CSprite::setColor(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable[1]))(c); }
	void CSprite::setColor2(int c[4]) { (this->*union_cast<void(IColor::*)(int[])>(_vtable[2]))(c); }
	void CSprite::setColor3(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable[3]))(c); }
	
	void CSprite::setTexture(int texture, int texOffsetX, int texOffsetY, int width, int height, int anchorX, int anchorY) {
		(this->*union_cast<void(CSprite::*)(int, int, int, int, int, int, int)>(_vtable[4]))(texture, texOffsetX, texOffsetY, width, height, anchorX, anchorY);
	}

	void CSprite::setTexture2(int texture, int texOffsetX, int texOffsetY, int width, int height) {
		(this->*union_cast<void(CSprite::*)(int, int, int, int, int)>(_vtable[5]))(texture, texOffsetX, texOffsetY, width, height);
	}

	void CSprite::renderScreen(float left, float top, float right, float bottom) {
		(this->*union_cast<void(CSprite::*)(float, float, float, float)>(_vtable[6]))(left, top, right, bottom);
	}

	void CSprite::render(float x, float y) {
		(this->*union_cast<void(CSprite::*)(float, float)>(_vtable[7]))(x, y);
	}

	// --- CTile ---
	CTile::CTile(CTile& other) { (this->*union_cast<void(CTile::*)(CTile&)>(0x43c830))(other); }
	void CTile::setColor(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable[1]))(c); }
	void CTile::setColor2(int c[4]) { (this->*union_cast<void(IColor::*)(int[])>(_vtable[2]))(c); }
	void CTile::setColor3(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable[3]))(c); }

	void CTile::createSlices(int texture, int x, int y, int w, int h) {
		(this->*union_cast<void(CTile::*)(int, int, int, int, int)>(0x409cb0))(texture, x, y, w, h);
	}

	void CTile::createSlices(int texture, int x, int y, int w, int h, int sX, int sY) {
		(this->*union_cast<void(CTile::*)(int, int, int, int, int, int, int)>(0x44e2e0))(texture, x, y, w, h, sX, sY);
	}

	void CTile::render(float x, float y, int i, int j) {
		(this->*union_cast<void(CTile::*)(float, float, int, int)>(0x409df0))(x, y, i, j);
	}

	// --- CGauge ---
	CGauge::CGauge(IValue* value) { set(value); }

	void CGauge::set(IValue* value) {
		if (this->value) SokuLib::DeleteFct(this->value);
		this->value = value;
	}

	void CGauge::set(const int* ptr, int offset, int length) {
		if (this->value) SokuLib::DeleteFct(this->value);
		this->value = SokuLib::New<CGaugeValue>(1, (void**)0x85b570, (void*)ptr, offset, length);
	}

	void CGauge::set(const short* ptr, int offset, int length) {
		if (this->value) SokuLib::DeleteFct(this->value);
		this->value = SokuLib::New<CGaugeValue>(1, (void**)0x85b574, (void*)ptr, offset, length);
	}

	CGauge::~CGauge() { if (value) SokuLib::DeleteFct(value); }
	void CGauge::setColor(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable[1]))(c); }
	void CGauge::setColor2(int c[4]) { (this->*union_cast<void(IColor::*)(int[])>(_vtable[2]))(c); }
	void CGauge::setColor3(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable[3]))(c); }

	void CGauge::setTexture(int texture, int texOffsetX, int texOffsetY, int width, int height, int anchorX, int anchorY) {
		(this->*union_cast<void(CSprite::*)(int, int, int, int, int, int, int)>(_vtable[4]))(texture, texOffsetX, texOffsetY, width, height, anchorX, anchorY);
	}

	void CGauge::setTexture2(int texture, int texOffsetX, int texOffsetY, int width, int height) {
		(this->*union_cast<void(CSprite::*)(int, int, int, int, int)>(_vtable[5]))(texture, texOffsetX, texOffsetY, width, height);
	}

	void CGauge::renderScreen(float left, float top, float right, float bottom) {
		(this->*union_cast<void(CSprite::*)(float, float, float, float)>(_vtable[6]))(left, top, right, bottom);
	}

	void CGauge::render(float x, float y) {
		(this->*union_cast<void(CSprite::*)(float, float)>(_vtable[7]))(x, y);
	}

	// --- CNumber ---
	CNumber::CNumber(IValue* value) { set(value); }

	void CNumber::set(IValue* value) {
		if (this->value) SokuLib::DeleteFct(this->value);
		this->value = value;
	}

	void CNumber::set(const char* ptr) {
		if (this->value) SokuLib::DeleteFct(this->value);
		this->value = SokuLib::New<CNumberValue>(1, (void**)0x8598e4, (void*)ptr);
	}

	void CNumber::set(const float* ptr) {
		if (this->value) SokuLib::DeleteFct(this->value);
		this->value = SokuLib::New<CNumberValue>(1, (void**)0x85b2ac, (void*)ptr);
	}

	void CNumber::set(const int* ptr) {
		if (this->value) SokuLib::DeleteFct(this->value);
		this->value = SokuLib::New<CNumberValue>(1, (void**)0x859284, (void*)ptr);
	}

	CNumber::~CNumber() { if (value) SokuLib::DeleteFct(value); }
	void CNumber::setColor(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable[1]))(c); }
	void CNumber::setColor2(int c[4]) { (this->*union_cast<void(IColor::*)(int[])>(_vtable[2]))(c); }
	void CNumber::setColor3(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable[3]))(c); }

	void CNumber::render(float val, float x, float y, int precision, bool abs) {
		(this->*union_cast<void(CNumber::*)(float, float, float, int, bool)>(0x414940))(val, x, y, precision, abs);
	}

	// --- CDesign ---
	CDesign::CDesign()                              { (this->*union_cast<void* (CDesign::*)()>(0x422b20))(); }
	void CDesign::setColor(int c)                   { (this->*union_cast<void(IColor::*)(int)>(_vtable[1]))(c); }
	void CDesign::setColor2(int c[4])               { (this->*union_cast<void(IColor::*)(int[])>(_vtable[2]))(c); }
	void CDesign::setColor3(int c)                  { (this->*union_cast<void(IColor::*)(int)>(_vtable[3]))(c); }
	void CDesign::loadResource(const char* a1)      { (this->*union_cast<void(CDesign::*)(const char*)>(_vtable[4]))(a1); }
	void CDesign::clear()                           { (this->*union_cast<void(CDesign::*)()>(_vtable[5]))(); }
	void CDesign::render(float x, float y, int id)  { (this->*union_cast<void(CDesign::*)(float, float, int)>(_vtable[6]))(x, y, id); }
	void CDesign::render2(float x, float y)         { (this->*union_cast<void(CDesign::*)(float, float)>(_vtable[7]))(x, y); }
	void CDesign::render3(int id)                   { (this->*union_cast<void(CDesign::*)(int)>(_vtable[8]))(id); }
	void CDesign::render4()                         { (this->*union_cast<void(CDesign::*)()>(_vtable[9]))(); }

	void CDesign::getById(CDesign::Object** ret, int id) { (this->*union_cast<void (CDesign::*)(CDesign::Object**, int)>(0x40cec0))(ret, id); }
	void CDesign::getById(CDesign::Sprite** ret, int id) { (this->*union_cast<void (CDesign::*)(CDesign::Sprite**, int)>(0x44e2b0))(ret, id); }

	// --- CFileList ---
	CFileList::CFileList()              { (this->*union_cast<void* (CFileList::*)()>(0x43d110))(); }
	void CFileList::updateList()        { (this->*union_cast<void(CFileList::*)()>(_vtable[1]))(); }
	void CFileList::updateResources()   { (this->*union_cast<void(CFileList::*)()>(_vtable[2]))(); }
	void CFileList::clear()             { (this->*union_cast<void(CFileList::*)()>(_vtable[3]))(); }
	int CFileList::appendLine(String& out, void* unknown, NameDeque& list, int index) {
		return (this->*union_cast<int(CFileList::*)(String&, void*, NameDeque&, int)>(_vtable[4]))(out, unknown, list, index);
	}

	bool CFileList::goToParent() {
		return (this->*union_cast<bool(CFileList::*)()>(0x43ca40))();
	}

	void CFileList::renderLine(float x, float y, int index) {
		return (this->*union_cast<void(CFileList::*)(float, float, int)>(0x43cbf0))(x, y, index);
	}

	// --- CReplayList ---
	CReplayList::CReplayList()          { (this->*union_cast<void* (CReplayList::*)()>(0x42c660))(); }
	void CReplayList::updateList()      { (this->*union_cast<void(CFileList::*)()>(_vtable[1]))(); }
	void CReplayList::updateResources() { (this->*union_cast<void(CFileList::*)()>(_vtable[2]))(); }
	void CReplayList::clear()           { (this->*union_cast<void(CFileList::*)()>(_vtable[3]))(); }
	int CReplayList::appendLine(String& out, void* unknown, NameDeque& list, int index) {
		return (this->*union_cast<int(CFileList::*)(String&, void*, NameDeque&, int)>(_vtable[4]))(out, unknown, list, index);
	}

	// --- CProfileList ---
	CProfileList::CProfileList()            { (this->*union_cast<void* (CProfileList::*)()>(0x434f30))(); }
	void CProfileList::updateList()         { (this->*union_cast<void(CFileList::*)()>(_vtable[1]))(); }
	void CProfileList::updateResources()    { (this->*union_cast<void(CFileList::*)()>(_vtable[2]))(); }
	void CProfileList::clear()              { (this->*union_cast<void(CFileList::*)()>(_vtable[3]))(); }
	int CProfileList::appendLine(String& out, void* unknown, NameDeque& list, int index) {
		return (this->*union_cast<int(CFileList::*)(String&, void*, NameDeque&, int)>(_vtable[4]))(out, unknown, list, index);
	}

	// --- CMusicList ---
	CMusicList::CMusicList()            { (this->*union_cast<void* (CMusicList::*)()>(0x449c00))(); }
	void CMusicList::updateList()       { (this->*union_cast<void(CFileList::*)()>(_vtable[1]))(); }
	void CMusicList::updateResources()  { (this->*union_cast<void(CFileList::*)()>(_vtable[2]))(); }
	void CMusicList::clear()            { (this->*union_cast<void(CFileList::*)()>(_vtable[3]))(); }
	int CMusicList::appendLine(String& out, void* unknown, NameDeque& list, int index) {
		return (this->*union_cast<int(CFileList::*)(String&, void*, NameDeque&, int)>(_vtable[4]))(out, unknown, list, index);
	}

	// --- CResultList ---
	CResultList::CResultList()          { (this->*union_cast<void* (CResultList::*)()>(0x44c060))(); }
	void CResultList::updateList()      { (this->*union_cast<void(CFileList::*)()>(_vtable[1]))(); }
	void CResultList::updateResources() { (this->*union_cast<void(CFileList::*)()>(_vtable[2]))(); }
	void CResultList::clear()           { (this->*union_cast<void(CFileList::*)()>(_vtable[3]))(); }
	int CResultList::appendLine(String& out, void* unknown, NameDeque& list, int index) {
		return (this->*union_cast<int(CFileList::*)(String&, void*, NameDeque&, int)>(_vtable[4]))(out, unknown, list, index);
	}
}