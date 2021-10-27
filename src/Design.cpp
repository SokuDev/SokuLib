#include "Design.hpp"
#include "SokuAddresses.hpp"

namespace {
	// private
	void** const _vtable_tile           = (void** const)SokuLib::ADDR_VTBL_CTILE;
	void** const _vtable_gauge          = (void** const)SokuLib::ADDR_VTBL_CGAGE;
	void** const _vtable_number         = (void** const)SokuLib::ADDR_VTBL_CNUMBER;
	void** const _vtable_design         = (void** const)SokuLib::ADDR_VTBL_CDESIGN;
	void** const _vtable_filelist       = (void** const)SokuLib::ADDR_VTBL_CFILELIST;
	void** const _vtable_replaylist     = (void** const)SokuLib::ADDR_VTBL_CREPLAYLIST;
	void** const _vtable_profilelist    = (void** const)SokuLib::ADDR_VTBL_CPROFILELIST;
	void** const _vtable_musiclist      = (void** const)SokuLib::ADDR_VTBL_MUSICLIST;
	void** const _vtable_resultlist     = (void** const)SokuLib::ADDR_VTBL_RESULTLIST;

	struct CGaugeValue {
		void *vtable, *value;
		float offset, length;
	};

	struct CNumberValue {
		void *vtable, *value;
	};
}

namespace SokuLib {
	// --- CTile ---
	CTile::CTile(CTile& other) { (this->*union_cast<void(CTile::*)(CTile&)>(ADDR_CTILE_COPY))(other); }
	void CTile::setColor(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable_tile[1]))(c); }
	void CTile::setColor2(int c[4]) { (this->*union_cast<void(IColor::*)(int[])>(_vtable_tile[2]))(c); }
	void CTile::setColor3(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable_tile[3]))(c); }

	void CTile::createSlices(int texture, int x, int y, int w, int h) {
		(this->*union_cast<void(CTile::*)(int, int, int, int, int)>(ADDR_CTILE_INIT1))(texture, x, y, w, h);
	}

	void CTile::createSlices(int texture, int x, int y, int w, int h, int sX, int sY) {
		(this->*union_cast<void(CTile::*)(int, int, int, int, int, int, int)>(ADDR_CTILE_INIT2))(texture, x, y, w, h, sX, sY);
	}

	void CTile::render(float x, float y, int i, int j) {
		(this->*union_cast<void(CTile::*)(float, float, int, int)>(ADDR_CTILE_RENDER))(x, y, i, j);
	}

	// --- CGauge ---
	CGauge::CGauge(IValue* value) { set(value); }

	void CGauge::set(IValue* value) {
		if (this->value) SokuLib::DeleteFct(this->value);
		this->value = value;
	}

	void CGauge::set(const int* ptr, float offset, float length) {
		if (this->value) SokuLib::DeleteFct(this->value);
		this->value = (IValue*)SokuLib::NewFct(sizeof(CGaugeValue));
		new (this->value) CGaugeValue{(void*)0x85b570, (void*)ptr, offset, length};
	}

	void CGauge::set(const short* ptr, float offset, float length) {
		if (this->value) SokuLib::DeleteFct(this->value);
		this->value = (IValue*)SokuLib::NewFct(sizeof(CGaugeValue));
		new (this->value) CGaugeValue{(void*)0x85b574, (void*)ptr, offset, length};
	}

	CGauge::~CGauge() { if (value) SokuLib::DeleteFct(value); }
	void CGauge::setColor(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable_gauge[1]))(c); }
	void CGauge::setColor2(int c[4]) { (this->*union_cast<void(IColor::*)(int[])>(_vtable_gauge[2]))(c); }
	void CGauge::setColor3(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable_gauge[3]))(c); }

	void CGauge::setTexture(int texture, int texOffsetX, int texOffsetY, int width, int height, int anchorX, int anchorY) {
		(this->*union_cast<void(Sprite::*)(int, int, int, int, int, int, int)>(_vtable_gauge[4]))(texture, texOffsetX, texOffsetY, width, height, anchorX, anchorY);
	}

	void CGauge::setTexture2(int texture, int texOffsetX, int texOffsetY, int width, int height) {
		(this->*union_cast<void(Sprite::*)(int, int, int, int, int)>(_vtable_gauge[5]))(texture, texOffsetX, texOffsetY, width, height);
	}

	void CGauge::renderScreen(float left, float top, float right, float bottom) {
		(this->*union_cast<void(Sprite::*)(float, float, float, float)>(_vtable_gauge[6]))(left, top, right, bottom);
	}

	void CGauge::render(float x, float y) {
		(this->*union_cast<void(Sprite::*)(float, float)>(_vtable_gauge[7]))(x, y);
	}

	// --- CNumber ---
	CNumber::CNumber(IValue* value) { set(value); }

	void CNumber::set(IValue* value) {
		if (this->value) SokuLib::DeleteFct(this->value);
		this->value = value;
	}

	void CNumber::set(const char* ptr) {
		if (this->value) SokuLib::DeleteFct(this->value);
		this->value = (IValue*)SokuLib::NewFct(sizeof(CNumberValue));
		new (this->value) CNumberValue{(void*)0x8598e4, (void*)ptr};
	}

	void CNumber::set(const float* ptr) {
		if (this->value) SokuLib::DeleteFct(this->value);
		this->value = (IValue*)SokuLib::NewFct(sizeof(CNumberValue));
		new (this->value) CNumberValue{(void*)0x85b2ac, (void*)ptr};
	}

	void CNumber::set(const int* ptr) {
		if (this->value) SokuLib::DeleteFct(this->value);
		this->value = (IValue*)SokuLib::NewFct(sizeof(CNumberValue));
		new (this->value) CNumberValue{(void*)0x859284, (void*)ptr};
	}

	CNumber::~CNumber() { if (value) SokuLib::DeleteFct(value); }
	void CNumber::setColor(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable_number[1]))(c); }
	void CNumber::setColor2(int c[4]) { (this->*union_cast<void(IColor::*)(int[])>(_vtable_number[2]))(c); }
	void CNumber::setColor3(int c) { (this->*union_cast<void(IColor::*)(int)>(_vtable_number[3]))(c); }

	void CNumber::render(float val, float x, float y, int precision, bool abs) {
		(this->*union_cast<void(CNumber::*)(float, float, float, int, bool)>(ADDR_CNUMBER_RENDER))(val, x, y, precision, abs);
	}

	// --- CDesign ---
	CDesign::CDesign() {
		unknown0x2C = 0;
		unknown0x30 = 0;
	}
	void CDesign::setColor(int c)                   { (this->*union_cast<void(IColor::*)(int)>(_vtable_design[1]))(c); }
	void CDesign::setColor2(int c[4])               { (this->*union_cast<void(IColor::*)(int[])>(_vtable_design[2]))(c); }
	void CDesign::setColor3(int c)                  { (this->*union_cast<void(IColor::*)(int)>(_vtable_design[3]))(c); }
	void CDesign::loadResource(const char* a1)      { (this->*union_cast<void(CDesign::*)(const char*)>(_vtable_design[4]))(a1); }
	void CDesign::clear()                           { (this->*union_cast<void(CDesign::*)()>(_vtable_design[5]))(); }
	void CDesign::render(float x, float y, int id)  { (this->*union_cast<void(CDesign::*)(float, float, int)>(_vtable_design[6]))(x, y, id); }
	void CDesign::render2(float x, float y)         { (this->*union_cast<void(CDesign::*)(float, float)>(_vtable_design[7]))(x, y); }
	void CDesign::render3(int id)                   { (this->*union_cast<void(CDesign::*)(int)>(_vtable_design[8]))(id); }
	void CDesign::render4()                         { (this->*union_cast<void(CDesign::*)()>(_vtable_design[9]))(); }

	void CDesign::getById(CDesign::Object** ret, int id) { (this->*union_cast<void (CDesign::*)(CDesign::Object**, int)>(0x40cec0))(ret, id); }
	void CDesign::getById(CDesign::Sprite** ret, int id) { (this->*union_cast<void (CDesign::*)(CDesign::Sprite**, int)>(0x44e2b0))(ret, id); }

	// --- CFileList ---
	void CFileList::updateList()        { (this->*union_cast<void(CFileList::*)()>(_vtable_filelist[1]))(); }
	void CFileList::updateResources()   { (this->*union_cast<void(CFileList::*)()>(_vtable_filelist[2]))(); }
	void CFileList::clear()             { (this->*union_cast<void(CFileList::*)()>(_vtable_filelist[3]))(); }
	int CFileList::appendLine(String& out, void* unknown, SokuLib::Deque<String>& list, int index) {
		return (this->*union_cast<int(CFileList::*)(String&, void*, SokuLib::Deque<String>&, int)>(_vtable_filelist[4]))(out, unknown, list, index);
	}

	bool CFileList::goToParent() {
		return (this->*union_cast<bool(CFileList::*)()>(ADDR_CFILELIST_GOTO_PARENT))();
	}

	void CFileList::renderLine(float x, float y, int index) {
		return (this->*union_cast<void(CFileList::*)(float, float, int)>(ADDR_CFILELIST_RENDER_LINE))(x, y, index);
	}

	// --- CReplayList ---
	CReplayList::CReplayList() : CFileList() {
		fileFormat = "*.rep";
		basePath = currentPath = "replay";
		maxLength = 36;
		showDirs = true;
	}
	void CReplayList::updateList()      { (this->*union_cast<void(CFileList::*)()>(_vtable_replaylist[1]))(); }
	void CReplayList::updateResources() { (this->*union_cast<void(CFileList::*)()>(_vtable_replaylist[2]))(); }
	void CReplayList::clear()           { (this->*union_cast<void(CFileList::*)()>(_vtable_replaylist[3]))(); }
	int CReplayList::appendLine(String& out, void* unknown, SokuLib::Deque<String>& list, int index) {
		return (this->*union_cast<int(CFileList::*)(String&, void*, SokuLib::Deque<String>&, int)>(_vtable_replaylist[4]))(out, unknown, list, index);
	}

	// --- CProfileList ---
	CProfileList::CProfileList() : CFileList() {
		fileFormat = "profile/*.pf";
		maxLength = 24;
		extLength = 3;
	}
	void CProfileList::updateList()         { (this->*union_cast<void(CFileList::*)()>(_vtable_profilelist[1]))(); }
	void CProfileList::updateResources()    { (this->*union_cast<void(CFileList::*)()>(_vtable_profilelist[2]))(); }
	void CProfileList::clear()              { (this->*union_cast<void(CFileList::*)()>(_vtable_profilelist[3]))(); }
	int CProfileList::appendLine(String& out, void* unknown, SokuLib::Deque<String>& list, int index) {
		return (this->*union_cast<int(CFileList::*)(String&, void*, SokuLib::Deque<String>&, int)>(_vtable_profilelist[4]))(out, unknown, list, index);
	}

	// --- CMusicList ---
	CMusicList::CMusicList() : CFileList() {
		maxLength = 0;
		extLength = 0;
	}
	void CMusicList::updateList()       { (this->*union_cast<void(CFileList::*)()>(_vtable_musiclist[1]))(); }
	void CMusicList::updateResources()  { (this->*union_cast<void(CFileList::*)()>(_vtable_musiclist[2]))(); }
	void CMusicList::clear()            { (this->*union_cast<void(CFileList::*)()>(_vtable_musiclist[3]))(); }
	int CMusicList::appendLine(String& out, void* unknown, SokuLib::Deque<String>& list, int index) {
		return (this->*union_cast<int(CFileList::*)(String&, void*, SokuLib::Deque<String>&, int)>(_vtable_musiclist[4]))(out, unknown, list, index);
	}

	// --- CResultList ---
	CResultList::CResultList() : CFileList() {
		maxLength = 0;
		extLength = 0;
	}
	void CResultList::updateList()      { (this->*union_cast<void(CFileList::*)()>(_vtable_resultlist[1]))(); }
	void CResultList::updateResources() { (this->*union_cast<void(CFileList::*)()>(_vtable_resultlist[2]))(); }
	void CResultList::clear()           { (this->*union_cast<void(CFileList::*)()>(_vtable_resultlist[3]))(); }
	int CResultList::appendLine(String& out, void* unknown, SokuLib::Deque<String>& list, int index) {
		return (this->*union_cast<int(CFileList::*)(String&, void*, SokuLib::Deque<String>&, int)>(_vtable_resultlist[4]))(out, unknown, list, index);
	}
}