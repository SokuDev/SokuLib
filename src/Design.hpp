#ifndef SOKULIB_DESIGN_HPP
#define SOKULIB_DESIGN_HPP

#include "Map.hpp"
#include "Memory.hpp"
#include "String.hpp"
#include "UnionCast.hpp"
#include <deque>
#include <list>
#include <vector>

namespace SokuLib {

	class IColor {
	public:
		virtual ~IColor() = default;
		virtual void setColor(int a1) = 0;
		virtual void setColor2(int a1[4]) = 0;
		virtual void setColor3(int a1) = 0;
	};

	class CSpriteBase : public IColor {
	public:
		int texture = 0;
		float vertexData[28];
		float sizeX, sizeY;
		float anchorX, anchorY;
		float scaleX, scaleY;
		float angle;

		// Textures are NOT deleted by the destructor
		virtual ~CSpriteBase() = default;
	};

	class CSprite : public CSpriteBase {
		inline static void** const _vtable = (void**)0x8576ac;
	public:
		virtual ~CSprite() = default;
		virtual void setColor(int c) override;
		virtual void setColor2(int c[4]) override;
		virtual void setColor3(int c) override;
		virtual void setTexture(int texture, int texOffsetX, int texOffsetY, int width, int height, int anchorX, int anchorY);
		virtual void setTexture2(int texture, int texOffsetX, int texOffsetY, int width, int height);
		virtual void renderScreen(float left, float top, float right, float bottom); // maybe its width/height instead of right/bottom
		virtual void render(float x, float y);
		// The next one seems to use untransformed vertex, but the function is not used in game, and the derivatives don't implement it. Probably is better just to remove it.
		//virtual void render8(float x, float y) { return (this->*union_cast<void*(CSprite::*)(float, float)>(_vtable[8]))(x, y); }
	};

	class CTile : public CSpriteBase {
		inline static void** const _vtable = (void**)0x85775c;
	public:
		float tileOffsetX, tileOffsetY;
		float tileWidth, tileHeight;

		CTile() = default;
		CTile(CTile& other);
		virtual ~CTile() = default;
		virtual void setColor(int a1) override;
		virtual void setColor2(int a1[4]) override;
		virtual void setColor3(int a1) override;

		void createSlices(int texture, int x, int y, int w, int h);
		void createSlices(int texture, int x, int y, int w, int h, int sX, int sY);
		void render(float x, float y, int i, int j);
	};

	class CGauge : public CSprite {
		inline static void** const _vtable = (void**)0x87109c;
	public:
		struct IValue { virtual float getValue() = 0; };

		float widthRatio, heightRatio;
		int unknown9C; // type?
		IValue* value = 0;

		CGauge() = default;
		CGauge(IValue* value); // takes control, use SokuLib::New
		void set(IValue* value); // takes control, use SokuLib::New
		void set(const int* ptr, int offset, int length);
		void set(const short* ptr, int offset, int length);

		virtual ~CGauge();
		virtual void setColor(int a1) override;
		virtual void setColor2(int a1[4]) override;
		virtual void setColor3(int a1) override;
		virtual void setTexture(int texture, int texOffsetX, int texOffsetY, int width, int height, int anchorX, int anchorY) override;
		virtual void setTexture2(int texture, int texOffsetX, int texOffsetY, int width, int height) override;
		virtual void renderScreen(float left, float top, float right, float bottom) override;
		virtual void render(float x, float y) override;
	};

	class CNumber : public IColor {
		inline static void** const _vtable = (void**)0x858c2c;
	public:
		struct IValue {
			virtual int getInt() = 0;
			virtual float getFloat() = 0;
		};

		char unknown[0x20];
		IValue* value = 0;
		CTile tiles;

		CNumber() = default;
		CNumber(IValue* value); // takes control, use SokuLib::New
		void set(IValue* value); // takes control, use SokuLib::New
		void set(const char* ptr);
		void set(const float* ptr);
		void set(const int* ptr);

		virtual ~CNumber();
		virtual void setColor(int a1) override;
		virtual void setColor2(int a1[4]) override;
		virtual void setColor3(int a1) override;

		// TODO find slice funtions
		void render(float val, float x, float y, int precision, bool abs);
	};

	class CDesign : public IColor {
		inline static void** const _vtable = (void**)0x857a30;
	public:
		class Object {
		public:
			float x1 = 0, y1 = 0, x2, y2;
			bool active;

			virtual ~Object() = 0;
			virtual void setColor(int a1) = 0;
			virtual void setColor2(int a1[4]) = 0;
			virtual void setColor3(int a1) = 0;
			virtual void renderPos(float x, float y) = 0;
			virtual void render() = 0;
			virtual void unknown6(int a1, int a2, int a3) = 0;
		};

		class Sprite : public Object { public: CSprite sprite; };
		class Gauge : public Object { public: CGauge gauge; };
		class Number : public Object { public: CNumber sprite; };

		// --- Data ---
		SokuLib::Vector<int> textures;
		SokuLib::List<Object*> objects;
		SokuLib::Map<int, Object*> objectMap;
		// the data below may be a iterator
		void* unknown0x2C;
		void* unknown0x30;

		CDesign();
		// Remember to call `clear` to release the resources
		virtual ~CDesign() = default;
		virtual void setColor(int a1) override;
		virtual void setColor2(int a1[4]) override;
		virtual void setColor3(int a1) override;
		virtual void loadResource(const char* a1);
		virtual void clear();
		virtual void render(float x, float y, int id);
		virtual void render2(float x, float y);
		virtual void render3(int id);
		virtual void render4();

		// TODO actually verify the difference
		void getById(CDesign::Object** ret, int id);
		void getById(CDesign::Sprite** ret, int id);
	};

	class CFileList {
		inline static void** const _vtable = (void**)0x858b44;
	public:
		SokuLib::Deque<String> names;
		SokuLib::Deque<char> types;
		SokuLib::Deque<int> textures;
		SokuLib::Deque<CTile> tiles;
		String fileFormat;
		String basePath; // unsure
		String currentPath;
		int maxLength;
		int extLength;
		bool showDirs;

		CFileList();
		// Remember to call `clear` to release the resources
		virtual ~CFileList() = default;
		virtual void updateList();
		virtual void updateResources();
		virtual void clear();
		virtual int appendLine(String& out, void* unknown, SokuLib::Deque<String>& list, int index);

		inline int getLength() { return this->names.size(); }
		bool goToParent(); // unsure
		void renderLine(float x, float y, int index);
	};

	class CReplayList : public CFileList {
		inline static void** const _vtable = (void**)0x858344;
	public:
		CReplayList();
		// Remember to call `clear` to release the resources
		virtual ~CReplayList() = default;
		virtual void updateList() override;
		virtual void updateResources() override;
		virtual void clear() override;
		virtual int appendLine(String& out, void* unknown, SokuLib::Deque<String>& list, int index) override;
	};

	class CProfileList : public CFileList {
		inline static void** const _vtable = (void**)0x858794;
	public:
		CProfileList();
		// Remember to call `clear` to release the resources
		virtual ~CProfileList() = default;
		virtual void updateList() override;
		virtual void updateResources() override;
		virtual void clear() override;
		virtual int appendLine(String& out, void* unknown, SokuLib::Deque<String>& list, int index) override;
	};

	class CMusicList : public CFileList {
		inline static void** const _vtable = (void**)0x85955c;
	public:
		SokuLib::Deque<String> unknownB4;
		SokuLib::Deque<String> unknownC8;

		CMusicList();
		// Remember to call `clear` to release the resources
		virtual ~CMusicList() = default;
		virtual void updateList() override;
		virtual void updateResources() override;
		virtual void clear() override;
		virtual int appendLine(String& out, void* unknown, SokuLib::Deque<String>& list, int index) override;
	};

	class CResultList : public CFileList {
		inline static void** const _vtable = (void**)0x859778;
	public:
		void* unknownB4;
		SokuLib::Deque<String> unknownB8;
		SokuLib::Deque<char> unknownCC;
		SokuLib::Deque<char> unknownE0;
		SokuLib::Deque<char> unknownF4;

		CResultList();
		// Remember to call `clear` to release the resources
		virtual ~CResultList() = default;
		virtual void updateList() override;
		virtual void updateResources() override;
		virtual void clear() override;
		virtual int appendLine(String& out, void* unknown, SokuLib::Deque<String>& list, int index) override;
	};
}

#endif //SOKULIB_DESIGN_HPP
