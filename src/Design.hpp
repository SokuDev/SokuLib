#ifndef SOKULIB_DESIGN_HPP
#define SOKULIB_DESIGN_HPP

#include "Map.hpp"
#include "Memory.hpp"
#include "Sprite.hpp"
#include "String.hpp"
#include "UnionCast.hpp"
#include <deque>
#include <list>
#include <vector>

namespace SokuLib {
	class CTile : public SpriteBase {
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

	class CGauge : public Sprite {
	public:
		struct IValue { virtual float getValue() = 0; };

		float widthRatio, heightRatio;
		int unknown9C; // type?
		IValue* value = 0;

		CGauge() = default;
		CGauge(IValue* value); // takes control, use SokuLib::New
		void set(IValue* value); // takes control, use SokuLib::New
		void set(const int* ptr, float offset, float length);
		void set(const short* ptr, float offset, float length);

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

		class Sprite : public Object { public: SokuLib::Sprite sprite; };
		class Gauge : public Object { public: SokuLib::CGauge gauge; };
		class Number : public Object { public: SokuLib::CNumber sprite; };

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

		// This seems to be the same, but got duplicated because some template type difference (probably const/non-const)
		void getById(CDesign::Object** ret, int id);
		void getById(CDesign::Sprite** ret, int id);
	};

	class CFileList {
	public:
		SokuLib::Deque<String> names;
		SokuLib::Deque<char> types;
		SokuLib::Deque<int> textures;
		SokuLib::Deque<CTile> tiles;
		String fileFormat;
		String basePath; // unsure
		String currentPath;
		int maxLength = 0;
		int extLength = 4;
		bool showDirs = false;

		CFileList() = default;
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
