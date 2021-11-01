//
// Created by PinkySmile on 03/03/2021.
//

#include <d3d9.h>
#include <d3dx9tex.h>
#include <cmath>
#include "DrawUtils.hpp"
#include "TextureManager.hpp"

#ifndef _DEBUG
#define puts(x)
#define printf(...)
#define fprintf(...)
#endif

namespace SokuLib {
namespace DrawUtils
{
	DxSokuColor::DxSokuColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) noexcept :
		r(r),
		g(g),
		b(b),
		a(a)
	{
	}

	DxSokuColor::DxSokuColor(unsigned int color) noexcept :
		color(color)
	{
	}

	DxSokuColor::operator unsigned() const
	{
		return this->color;
	}

	DxSokuColor &DxSokuColor::operator=(unsigned int color)
	{
		this->color = color;
		return *this;
	}

	DxSokuColor DxSokuColor::operator+(const DxSokuColor &other) const
	{
		DxSokuColor result = *this;

		result += other;
		return result;
	}

	DxSokuColor &DxSokuColor::operator+=(const DxSokuColor &other)
	{
		this->a = std::ceil((other.a + this->a) / 2.);
		this->r = std::ceil((other.r + this->r) / 2.);
		this->g = std::ceil((other.g + this->g) / 2.);
		this->b = std::ceil((other.b + this->b) / 2.);
		return *this;
	}

	DxSokuColor DxSokuColor::operator*(const DxSokuColor &other) const
	{
		DxSokuColor result = *this;

		result *= other;
		return result;
	}

	DxSokuColor &DxSokuColor::operator*=(const DxSokuColor &other)
	{
		this->a = std::ceil((other.a * this->a) / 255.f);
		this->r = std::ceil((other.r * this->r) / 255.f);
		this->g = std::ceil((other.g * this->g) / 255.f);
		this->b = std::ceil((other.b * this->b) / 255.f);
		return *this;
	}

	const DxSokuColor DxSokuColor::White      {0xFF, 0xFF, 0xFF, 0xFF};
	const DxSokuColor DxSokuColor::Red        {0xFF, 0x00, 0x00, 0xFF};
	const DxSokuColor DxSokuColor::Blue       {0x00, 0x00, 0xFF, 0xFF};
	const DxSokuColor DxSokuColor::Green      {0x00, 0xFF, 0x00, 0xFF};
	const DxSokuColor DxSokuColor::Yellow     {0xFF, 0xFF, 0x00, 0xFF};
	const DxSokuColor DxSokuColor::Magenta    {0xFF, 0x00, 0xFF, 0xFF};
	const DxSokuColor DxSokuColor::Cyan       {0x00, 0xFF, 0xFF, 0xFF};
	const DxSokuColor DxSokuColor::Black      {0x00, 0x00, 0x00, 0xFF};
	const DxSokuColor DxSokuColor::Transparent{0x00, 0x00, 0x00, 0x00};

	Texture::Texture(int handle, const Vector2<unsigned> &size) noexcept :
		_handle(handle),
		_loaded(true),
		_size(size)
	{
	}

	Texture::~Texture() noexcept
	{
		this->destroy();
	}

	bool Texture::hasTexture() const noexcept
	{
		return this->_loaded;
	}

	void Texture::activate(int stage) const noexcept
	{
		if (this->hasTexture())
			SokuLib::textureMgr.setTexture(this->_handle, stage);
		else
			SokuLib::textureMgr.setTexture(0, stage);
	}

	void Texture::setHandle(int handle, const Vector2<unsigned> &size)
	{
		this->destroy();
		this->_loaded = true;
		this->_handle = handle;
		this->_size = size;
	}

	void Texture::swap(Texture &other)
	{
		int handle = this->_handle;
		bool loaded = this->_loaded;

		this->_handle = other._handle;
		this->_loaded = other._loaded;
		other._handle = handle;
		other._loaded = loaded;
	}

	void Texture::destroy()
	{
		if (this->_loaded && SokuLib::pd3dDev)
			SokuLib::textureMgr.remove(this->_handle);
		this->_loaded = false;
	}

	int Texture::releaseHandle()
	{
		this->_loaded = false;
		return this->_handle;
	}

	Vector2<unsigned> Texture::getSize() const
	{
		return this->_size;
	}

/*	int __fastcall u_mLoadImageLowerLevel(unsigned *puParm1, char *pcParm2,int **param_3,unsigned *param_4)
	{
		unsigned **ppiVar1;
		char cVar2;
		char *pcVar3;
		int *piVar4;
		char *pcVar5;
		unsigned uVar6;
		int iVar7;
		int iVar8;
		unsigned *pcVar9;
		unsigned uVar10;
		unsigned uVar11;
		bool bVar12;
		unsigned uVar13;
		int 0x3b4;
		int 0x3b0;
		int **0x3ac;
		unsigned *0x3a8;
		unsigned *0x3a4;
		unsigned char 0x3a0 [4];
		unsigned uStack924;
		int 0x398;
		char 0x394 [4];
		unsigned 0x390;
		unsigned 0x38c;
		int 0x380 [3];
		unsigned char 0x374 [60];
		char 0x338 [264];
		char 0x230 [260];
		char 0x12c [4];
		char 0x128 [268];
		unsigned 0x1c;
		int *0x14;
		unsigned char *puStack16;
		unsigned 0xc;

		0xc = 0xffffffff;
		puStack16 = (unsigned char *)0x8543f6;
		__asm mov EAX, FS:[0x0]
		__asm mov [0x14], EAX
		0x1c = *(int *)0x8943b8 ^ (unsigned)&0x3b4;
		__asm mov EAX, 0x14
		__asm mov FS:[0x0], EAX
		0x3ac = param_3;
		0x3a4 = param_4;
		0x3a8 = puParm1;
		0x3b0 = ((int (*)(int **, char *, unsigned *, unsigned *))0x409150)(param_3,pcParm2,param_4,puParm1);
		if (0x3b0 != -0x7789f794)
			goto LAB_0040911c;
		((void (__stdcall *)(void *, unsigned, unsigned, unsigned, unsigned))0x0082008B)(&0x398,0x20,3,0x41a090,0x41a0e0);
		0xc = 0;
		strcpy_s(reinterpret_cast<char *>(0x12c[1] + 3), 0x104, pcParm2);
		pcVar3 = pcParm2;
		do {
			cVar2 = *pcVar3;
			pcVar3 = pcVar3 + 1;
		} while (cVar2 != '\0');
		pcVar3[(int)(0x230 + (0x104 - (int)(pcParm2 + 1)))] = '\0';
		0x3b4 = 1;
		if (*(int *)0x896b8c != 0) {
			piVar4 = 0x380;
			iVar8 = 3;
			do {
				*piVar4 = *(int *)0x896b8c;
				piVar4 = piVar4 + 8;
				iVar8 = iVar8 + -1;
			} while (iVar8 != 0);
		}
		0x394[0] = '\0';
		iVar8 = *(int *)0x896b84;
		while (-1 < iVar8) {
			if (iVar8 == 0) {
				strcpy_s(0x338,0x105,pcParm2);
			}
			else {
				wsprintfA(0x338,"%s_%d.bmp",0x12c[1] + 3,iVar8);
			}
			if (0x8a0048 == '\0') {
				cVar2 = (*(char (__thiscall **)(int, char *))(0x398 + 4))(0x398, 0x338);
			}
			else {
				pcVar3 = 0x338;
				do {
					pcVar5 = pcVar3;
					pcVar3 = pcVar5 + 1;
				} while (*pcVar5 != '\0');
				strcpy_s(0x230,0x104,0x338);
				*(unsigned *)(pcVar5 + 0x104) = 0x3276632e;
				cVar2 = (*(char (__thiscall **)(int, char *))(0x398 + 0xc))(0x398, 0x230);
				param_4 = 0x3a4;
			}
			if (cVar2 != '\0') break;
			if (iVar8 == 0) {
				0xc = 0xffffffff;
				((void (__stdcall *)(void *, unsigned, unsigned, unsigned))0x00820028)(&0x398,0x20,3,0x41a0e0);
				goto LAB_0040911c;
			}
			iVar8 = iVar8 + -1;
		}
		bVar12 = iVar8 == *(int *)0x896b84;
		if (param_4 != NULL) {
			*param_4 = 0x390;
		}
		if (0x3a8 != NULL) {
			*0x3a8 = 0x38c;
		}
		if ((bVar12) && (iVar8 = 1, 1 < *(int *)0x896b80)) {
			piVar4 = 0x380 + 2;
			do {
				if (2 < iVar8) break;
				wsprintfA(0x338,"%s_%d.bmp",0x12c[1] + 3,*(int *)0x896b84 + iVar8);
				*(char *)(piVar4 + 1) = 0;
				if (*(int *)0x8a0048 == '\0') {
					pcVar9 = *(unsigned **)(*piVar4 + 4);
					pcVar3 = 0x338;
				}
				else {
					pcVar3 = 0x338;
					do {
						pcVar5 = pcVar3;
						pcVar3 = pcVar5 + 1;
					} while (*pcVar5 != '\0');
					strcpy_s(0x230,0x104,0x338);
					*(unsigned *)(pcVar5 + 0x104) = 0x3276632e;
					pcVar9 = *(unsigned **)(*piVar4 + 0xc);
					pcVar3 = 0x230;
				}
				cVar2 = (*(char (__thiscall **)(unsigned *, char *))pcVar9)(puParm1, pcVar3);
				if (cVar2 == '\0') break;
				0x3b4 = 0x3b4 + 1;
				iVar8 = iVar8 + 1;
				piVar4 = piVar4 + 8;
			} while (iVar8 < *(int *)0x896b80);
		}
		uVar11 = *(int *)0x8a0e74 & 0x20;
		uVar6 = 0x38c;
		if ((uVar11 != 0) && (uVar6 = 0x390, 0x390 < 0x38c)) {
			uVar6 = 0x38c;
			0x390 = 0x38c;
		}
		uVar10 = uVar6;
		if ((0x394[0] == ' ') || (0x394[0] == '\x18')) {
			if ((uVar11 != 0) && (uVar10 = 0x390, 0x390 < uVar6)) {
				uVar10 = uVar6;
				0x390 = uVar6;
			}
			EnterCriticalSection((LPCRITICAL_SECTION)0x8a0e14);
			uVar13 = 0x15;
		LAB_00409074:
			iVar8 = D3DXCreateTexture(SokuLib::pd3dDev, 0x390, uVar10, 0x3b4, 0,
						  static_cast<D3DFORMAT>(uVar13), static_cast<D3DPOOL>(1),
						  reinterpret_cast<LPDIRECT3DTEXTURE9 *>(0x3ac));
			LeaveCriticalSection((LPCRITICAL_SECTION)0x8a0e14);
			0x3b0 = iVar8;
			if ((-1 < iVar8) && (iVar8 = 0, 0 < 0x3b4)) {
				pcVar3 = 0x394;
				do {
					ppiVar1 = reinterpret_cast<unsigned int **>(0x3ac);
					iVar7 = (*(int (__thiscall **)(int *, int, unsigned char *, int, int))(**0x3ac + 0x4c))(*0x3ac,iVar8,0x3a0,0,0);
					if (iVar7 == 0) {
						if ((*pcVar3 == '\b') && (*(int *)0x896b8c != 0)) {
							*(int *)(pcVar3 + 0x14) = *(int *)0x896b8c;
						}
						((void (__thiscall *)(unsigned, char *, unsigned))0x41af70)(uStack924, pcVar3 + -4, uStack924);
						(*(void (__thiscall **)(unsigned *, unsigned))(**ppiVar1 + 0x50))(*ppiVar1, 0);
					}
					iVar8 = iVar8 + 1;
					pcVar3 = pcVar3 + 0x20;
				} while (iVar8 < 0x3b4);
			}
		}
		else {
			if ((0x394[0] == '\b') || (0x394[0] == '\x10')) {
				if ((uVar11 != 0) && (uVar10 = 0x390, 0x390 < uVar6)) {
					0x390 = uVar6;
					uVar10 = uVar6;
				}
				EnterCriticalSection((LPCRITICAL_SECTION)0x8a0e14);
				uVar13 = 0x19;
				goto LAB_00409074;
			}
		}
		0xc = 0xffffffff;
		((void (__stdcall *)(void *, unsigned, unsigned, unsigned))0x00820028)(&0x398,0x20,3,0x41a0e0);
	LAB_0040911c:
		__asm mov EAX, [0x14]
		__asm mov FS:[0x0], EAX
		iVar8 = ((int (*)())0x81fb35)();
		return iVar8;
	}


	int *CHandleManager_LoadTexture(int *param_2,char *param_3,unsigned *param_4,unsigned *param_5)
	{
		int **ppiVar1;
		int iVar2;
		int 0x4;

		0x4 = 0;
		__asm mov EDI, 0x89FF08;
		ppiVar1 = ((int **(__stdcall *)(int *))0x4026a0)(&0x4);
		*ppiVar1 = NULL;
		iVar2 = u_mLoadImageLowerLevel(param_5,param_3,ppiVar1,param_4);
		if (iVar2 < 0) {
			((void (*)(int))0x402810)(0x4);
			*param_2 = 0;
			return param_2;
		}
		*param_2 = 0x4;
		return param_2;
	}*/

constexpr unsigned FUN_402810    = 0x402810;
constexpr unsigned FUN_4026a0    = 0x4026a0;
constexpr unsigned FUN_409150    = 0x409150;
constexpr unsigned FUN_41af70    = 0x41af70;
constexpr unsigned FUN_81fb35    = 0x81fb35;
constexpr unsigned FUN_82008B    = 0x82008B;
constexpr unsigned FUN_820028    = 0x820028;

	__declspec(naked) int __fastcall u_mLoadImageLowerLevel()
	{
		__asm {
			PUSH       EBP
			MOV        EBP,ESP
			AND        ESP,0xfffffff8
			PUSH       -0x1
			PUSH       0x8543f6

			MOV        EAX,FS:[0x0]

			PUSH       EAX
			SUB        ESP,0x3a0

			MOV        EAX,0x8943b8
			MOV        EAX,[EAX]

			XOR        EAX,ESP
			MOV        dword ptr [ESP + 0x398],EAX

			PUSH       EBX
			PUSH       ESI
			PUSH       EDI
			MOV        EAX,0x8943b8
			MOV        EAX,[EAX]

			XOR        EAX,ESP
			PUSH       EAX
			LEA        EAX,[ESP + 0x3b0]

			MOV        FS:[0x0],EAX

			MOV        ESI,dword ptr [EBP + 0xC]
			MOV        EAX,dword ptr [EBP + 0x8]
			PUSH       ECX
			PUSH       ESI
			MOV        EDI,EDX
			PUSH       EDI
			PUSH       EAX
			MOV        dword ptr [ESP + 0x28],EAX
			MOV        dword ptr [ESP + 0x30],ESI
			MOV        dword ptr [ESP + 0x2C],ECX
			CALL       FUN_409150

			CMP        EAX,0x8876086c

			MOV        dword ptr [ESP + 0x14],EAX
			JNZ        LAB_0040911c

			PUSH       0x41a0e0
			PUSH       0x41a090

			PUSH       0x3
			PUSH       0x20
			LEA        EAX,[ESP + 0x3c]
			PUSH       EAX
			CALL       FUN_82008B

			PUSH       EDI
			LEA        ECX,[ESP + 0x2a0]

			PUSH       0x104

			PUSH       ECX
			MOV        dword ptr [ESP + 0x3C4],0x0
			CALL       strcpy_s

			MOV        EAX,EDI
			ADD        ESP,0xc
			LEA        EDX,[EAX + 0x1]
			LEA        EBX,[EBX]

		LAB_00408da0:
			MOV        CL,byte ptr [EAX]
			ADD        EAX,0x1
			TEST       CL,CL
			JNZ        LAB_00408da0
			SUB        EAX,EDX
			MOV        byte ptr [ESP + EAX + 0x298],CL

			MOV        ECX,0x896b8c
			MOV        ECX,[ECX]

			TEST       ECX,ECX
			MOV        dword ptr [ESP + 0x10],0x1
			JZ         LAB_00408dda

			LEA        EAX,[ESP + 0x44]
			MOV        EDX,0x3
			LEA        ECX,[ECX]
		LAB_00408dd0:
			MOV        dword ptr [EAX],ECX
			ADD        EAX,0x20
			SUB        EDX,0x1
			JNZ        LAB_00408dd0
		LAB_00408dda:
			MOV        EBX,0x896b84
			MOV        EBX,[EBX]

			XOR        EDX,EDX
			TEST       EBX,EBX
			MOV        byte ptr [ESP + 0x30],DL
			JL         LAB_00408ebe

		LAB_00408dee:
			TEST       EBX,EBX
			JNZ        LAB_00408e0a
			PUSH       EDI
			LEA        EDX,[ESP + 0x90]
			PUSH       0x105
			PUSH       EDX
			CALL       strcpy_s

			ADD        ESP,0xc
			JMP        LAB_00408e29
		LAB_00408e0a:
			PUSH       EBX
			LEA        EAX,[ESP + 0x2a0]

			PUSH       EAX
			LEA        ECX,[ESP + 0x94]
			PUSH       0x871058
			PUSH       ECX
			MOV        EAX, 0x8571D8
			CALL       [EAX]

			ADD        ESP,0x10
		LAB_00408e29:
			MOV        EAX, 0x8a0048
			CMP        byte ptr [EAX],0x0

			JZ         LAB_00408e90
			LEA        EAX,[ESP + 0x8c]

			LEA        EDX,[EAX + 0x1]
			LEA        ESP,[ESP]
		LAB_00408e40:
			MOV        CL,byte ptr [EAX]
			ADD        EAX,0x1
			TEST       CL,CL
			JNZ        LAB_00408e40
			SUB        EAX,EDX
			LEA        EDX,[ESP + 0x8c]

			PUSH       EDX
			MOV        ESI,EAX
			LEA        EAX,[ESP + 0x198]
			PUSH       0x104
			PUSH       EAX
			CALL       strcpy_s

			ADD        ESP,0xc
			MOV        dword ptr [ESP + ESI + 0x190],0x3276632e


			MOV        EDX,dword ptr [ESP + 0x2C]
			MOV        EAX,dword ptr [EDX + 0xc]
			LEA        ECX,[ESP + 0x194]

			PUSH       ECX
			LEA        ECX,[ESP + 0x30]
			CALL       EAX
			MOV        ESI,dword ptr [ESP + 0x20]
			JMP        LAB_00408ea5
		LAB_00408e90:
			MOV        EDX,dword ptr [ESP + 0x2C]
			MOV        EAX,dword ptr [EDX + 0x4]
			LEA        ECX,[ESP + 0x8c]

			PUSH       ECX
			LEA        ECX,[ESP + 0x30]
			CALL       EAX
		LAB_00408ea5:
			TEST       AL,AL
			JNZ        LAB_00408eba
			TEST       EBX,EBX
			JZ         LAB_00408f87

			SUB        EBX,0x1
			JNS        LAB_00408dee

		LAB_00408eba:
			MOV        DL,byte ptr [ESP + 0x30]
		LAB_00408ebe:
			MOV        ECX,0x896b84
			CMP        EBX,dword ptr [ECX]

			MOV        ECX,dword ptr [ESP + 0x34]
			SETZ       BL
			TEST       ESI,ESI
			JZ         LAB_00408ed1
			MOV        dword ptr [ESI],ECX
		LAB_00408ed1:
			MOV        ESI,dword ptr [ESP + 0x1C]
			TEST       ESI,ESI
			MOV        EAX,dword ptr [ESP + 0x38]
			JZ         LAB_00408edf
			MOV        dword ptr [ESI],EAX
		LAB_00408edf:
			TEST       BL,BL
			JZ         LAB_00408fe7

			MOV        EBX,0x1
			MOV        ESI,0x896b80
			CMP        dword ptr [ESI],EBX
			JLE        LAB_00408fe7

			LEA        ESI,[ESP + 0x4c]
		LAB_00408efc:
			CMP        EBX,0x3
			JGE        LAB_00408fdb

			MOV        EDX,0x896b80
			MOV        EDX,dword ptr [EDX]
			ADD        EDX,EBX
			PUSH       EDX
			LEA        EAX,[ESP + 0x2a0]
			PUSH       EAX
			LEA        ECX,[ESP + 0x94]
			PUSH       0x871058
			PUSH       ECX
			MOV        EAX,0x8571D8
			CALL       dword ptr [EAX]

			ADD        ESP,0x10
			MOV        EAX,0x8a0048
			CMP        byte ptr [EAX],0x0
			MOV        byte ptr [ESI + 0x4],0x0
			JZ         LAB_00408faf

			LEA        EAX,[ESP + 0x8c]
			LEA        EDX,[EAX + 0x1]
		LAB_00408f43:
			MOV        CL,byte ptr [EAX]
			ADD        EAX,0x1
			TEST       CL,CL
			JNZ        LAB_00408f43

			SUB        EAX,EDX
			LEA        EDX,[ESP + 0x8c]
			PUSH       EDX
			MOV        EDI,EAX
			LEA        EAX,[ESP + 0x198]
			PUSH       0x104
			PUSH       EAX
			CALL       strcpy_s

			MOV        dword ptr [ESP + EDI + 0x19C],0x3276632e
			MOV        EDX,dword ptr [ESI]
			MOV        EDX,dword ptr [EDX + 0xc]
			ADD        ESP,0xc
			LEA        EAX,[ESP + 0x194]
			PUSH       EAX
			JMP        LAB_00408fbc

		LAB_00408f87:
			PUSH       0x41a0e0
			PUSH       0x3
			PUSH       0x20
			LEA        ECX,[ESP + 0x38]
			PUSH       ECX
			MOV        dword ptr [ESP + 0x3c8],0xffffffff
			CALL       FUN_820028

			MOV        EAX,0x8876086c
			JMP        LAB_0040911c

		LAB_00408faf:
			MOV        EAX,dword ptr [ESI]
			MOV        EDX,dword ptr [EAX + 0x4]
			LEA        ECX,[ESP + 0x8c]
			PUSH       ECX

		LAB_00408fbc:
			MOV        ECX,ESI
			CALL       EDX

			TEST       AL,AL
			JZ         LAB_00408fdb

			ADD        dword ptr [ESP + 0x10],0x1

			ADD        EBX,0x1
			ADD        ESI,0x20
			MOV        EAX,0x896b80
			CMP        EBX,dword ptr [EAX]

			JL         LAB_00408efc

		LAB_00408fdb:
			MOV        EAX,dword ptr [ESP + 0x38]
			MOV        ECX,dword ptr [ESP + 0x34]
			MOV        DL,byte ptr [ESP + 0x30]
		LAB_00408fe7:
			MOV        ESI,0x8a0e74
			MOV        ESI,dword ptr [ESI]

			AND        ESI,0x20
			JZ         LAB_00408ffc
			CMP        ECX,EAX
			JNC        LAB_00408ffa
			MOV        ECX,EAX
			JMP        LAB_00408ffc
		LAB_00408ffa:
			MOV        EAX,ECX
		LAB_00408ffc:
			CMP        EDX,0x20
			JZ         LAB_00409045
			CMP        EDX,0x18
			JZ         LAB_00409045
			CMP        EDX,0x8
			JZ         LAB_00409014
			CMP        EDX,0x10
			JNZ        LAB_004090fa

		LAB_00409014:
			TEST       ESI,ESI
			MOV        EBX,ECX
			MOV        EDI,EAX
			JZ         LAB_00409026
			CMP        ECX,EAX
			JNC        LAB_00409024
			MOV        EBX,EAX
			JMP        LAB_00409026
		LAB_00409024:
			MOV        EDI,ECX
		LAB_00409026:
			PUSH       0x8a0e14
			MOV        EAX,0x85711C
			CALL       dword ptr [EAX]

			MOV        EAX,dword ptr [ESP + 0x18]
			MOV        ECX,dword ptr [ESP + 0x10]
			PUSH       EAX
			PUSH       0x1
			PUSH       0x19
			PUSH       0x0
			PUSH       ECX
			PUSH       EDI
			PUSH       EBX
			JMP        LAB_00409074
		LAB_00409045:
			TEST       ESI,ESI
			MOV        EDI,ECX
			MOV        EBX,EAX
			JZ         LAB_00409057
			CMP        ECX,EAX
			JNC        LAB_00409055
			MOV        EDI,EAX
			JMP        LAB_00409057
		LAB_00409055:
			MOV        EBX,ECX
		LAB_00409057:
			PUSH       0x8a0e14
			MOV        EAX,0x85711C
			CALL       dword ptr [EAX]

			MOV        EAX,dword ptr [ESP + 0x18]
			MOV        ECX,dword ptr [ESP + 0x10]
			PUSH       EAX
			PUSH       0x1
			PUSH       0x15
			PUSH       0x0
			PUSH       ECX
			PUSH       EBX
			PUSH       EDI
		LAB_00409074:
			MOV        EDX,0x8A0E30
			MOV        EDX,[EDX]

			PUSH       EDX
			CALL       D3DXCreateTexture //D3DXCreateTexture

			PUSH       0x8a0e14
			MOV        ESI,EAX
			MOV        EAX,0x857118
			CALL       dword ptr [EAX]

			TEST       ESI,ESI
			MOV        dword ptr [ESP + 0x14],ESI
			JL         LAB_004090fa
			XOR        EDI,EDI
			CMP        dword ptr [ESP + 0x10],EDI
			JLE        LAB_004090fa
			LEA        ESI,[ESP + 0x30]
		LAB_004090a1:
			MOV        EBX,dword ptr [ESP + 0x18]
			MOV        EAX,dword ptr [EBX]
			MOV        ECX,dword ptr [EAX]
			PUSH       0x0
			PUSH       0x0
			LEA        EDX,[ESP + 0x2c]
			PUSH       EDX
			PUSH       EDI
			PUSH       EAX
			MOV        EAX,dword ptr [ECX + 0x4c]
			CALL       EAX
			TEST       EAX,EAX
			JNZ        LAB_004090ee
			MOV        DL,byte ptr [ESI]
			CMP        EDX,0x8
			JNZ        LAB_004090d0
			MOV        EAX,0x896b8c
			MOV        EAX,[EAX]

			TEST       EAX,EAX
			JZ         LAB_004090d0
			MOV        dword ptr [ESI + 0x14],EAX
		LAB_004090d0:
			MOV        ECX,dword ptr [ESP + 0x28]
			PUSH       ECX
			MOV        ECX,dword ptr [ESP + 0x28]
			LEA        EAX,[ESI + -0x4]
			PUSH       EAX
			CALL       FUN_41af70

			MOV        EAX,dword ptr [EBX]
			MOV        ECX,dword ptr [EAX]
			MOV        EDX,dword ptr [ECX + 0x50]
			PUSH       0x0
			PUSH       EAX
			CALL       EDX
		LAB_004090ee:
			ADD        EDI,0x1
			ADD        ESI,0x20
			CMP        EDI,dword ptr [ESP + 0x10]
			JL         LAB_004090a1

		LAB_004090fa:
			PUSH       0x41a0e0
			PUSH       0x3
			PUSH       0x20
			LEA        EAX,[ESP + 0x38]
			PUSH       EAX
			MOV        dword ptr [ESP + 0x3C8],0xffffffff
			CALL       FUN_820028

			MOV        EAX,dword ptr [ESP + 0x14]
		LAB_0040911c:
			MOV        ECX,dword ptr [ESP + 0x3b0]

			MOV        dword ptr FS:[0x0],ECX

			POP        ECX
			POP        EDI
			POP        ESI
			POP        EBX
			MOV        ECX,dword ptr [ESP + 0x398]

			XOR        ECX,ESP
			CALL       FUN_81fb35

			MOV        ESP,EBP
			POP        EBP
			RET        0x8
		}
	}

	__declspec(naked) void CHandleManager_LoadTexture()
	{
		__asm {
			SUB        ESP,0x8
			PUSH       EDI
			LEA        EAX,[ESP + 0x8]
			MOV        EDI,ECX
			PUSH       EAX
			MOV        dword ptr [ESP + 0xC],0x0
			CALL       FUN_4026a0

			MOV        ECX,dword ptr [ESP + 0x18]
			MOV        EDX,dword ptr [ESP + 0x14]
			PUSH       ECX
			MOV        ECX,dword ptr [ESP + 0x20]
			PUSH       EAX
			MOV        dword ptr [EAX],0x0

			CALL       u_mLoadImageLowerLevel

			TEST       EAX,EAX
			JGE        LAB_00405082
			MOV        EDX,dword ptr [ESP + 0xC]
			PUSH       EDX
			MOV        EAX,EDI
			CALL       FUN_402810

			MOV        EAX,dword ptr [ESP + 2]
			MOV        dword ptr [EAX],0x0

			POP        EDI
			ADD        ESP,0x8
			RET        0x10
		LAB_00405082:
			MOV        EAX,dword ptr [ESP + 0x10]
			MOV        ECX,dword ptr [ESP + 0x8]
			MOV        dword ptr [EAX],ECX
			POP        EDI
			ADD        ESP,0x8
			RET        0x10
		}
	}

	bool Texture::loadFromFile(const char *path)
	{
		HRESULT result;
		int handle;
		D3DXIMAGE_INFO info;

		printf("Loading texture %s\n", path);
		if (FAILED(result = D3DXGetImageInfoFromFile(path, &info))) {
			fprintf(stderr, "D3DXGetImageInfoFromFile(\"%s\", %p) failed with code %li.\n", path, &info, result);
			return false;
		}

		LPDIRECT3DTEXTURE9 *pphandle = SokuLib::textureMgr.allocate(&handle);

		*pphandle = nullptr;
		if (FAILED(result = D3DXCreateTextureFromFileExA(
			SokuLib::pd3dDev,
			path,
			info.Width,
			info.Height,
			info.MipLevels,
			D3DUSAGE_RENDERTARGET,
			info.Format,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			0,
			&info,
			nullptr,
			pphandle
		))) {
			fprintf(stderr, "D3DXCreateTextureFromFile(%p, \"%s\", %p) failed with code %li.\n", SokuLib::pd3dDev, path, pphandle, result);
			SokuLib::textureMgr.deallocate(handle);
			return false;
		}
		printf("Texture handle: %x, Size: %ux%u\n", handle, info.Width, info.Height);
		this->setHandle(handle, {info.Width, info.Height});
		return true;
	}

	bool Texture::loadFromGame(const char *path)
	{
		int text = 0;
		Vector2<unsigned> size;

		printf("Loading texture %s\n", path);
		if (!SokuLib::textureMgr.loadTexture(&text, path, &size.x, &size.y) || !text) {
			puts("Couldn't load texture...");
			return false;
		}
		//if (!((unsigned *(__thiscall *)(SokuLib::TextureManager &, int *, const char *, unsigned *, unsigned *))&CHandleManager_LoadTexture)(SokuLib::textureMgr, &text, path, &size.x, &size.y) || !text) {
		//	puts("Couldn't load texture...");
		//	return false;
		//}
		this->setHandle(text, size);
		return true;
	}

	bool Texture::loadFromResource(HMODULE srcModule, LPCTSTR srcResource)
	{
		int id = 0;
		long int result;
		D3DXIMAGE_INFO info;

		printf("Loading resource %p from module %p\n", srcResource, srcModule);
		if (FAILED(result = D3DXGetImageInfoFromResource(srcModule, srcResource, &info))) {
			fprintf(stderr, "D3DXGetImageInfoFromResource(%p, %p, %p) failed with code %lx.\n", srcModule, srcResource, &info, result);
			return false;
		}

		LPDIRECT3DTEXTURE9 *pphandle = SokuLib::textureMgr.allocate(&id);

		*pphandle = nullptr;
		if (SUCCEEDED(D3DXCreateTextureFromResourceEx(
			SokuLib::pd3dDev,
			srcModule,
			srcResource,
			info.Width,
			info.Height,
			info.MipLevels,
			D3DUSAGE_RENDERTARGET,
			info.Format,
			D3DPOOL_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			0,
			&info,
			nullptr,
			pphandle
		))) {
			this->setHandle(id, {info.Width, info.Height});
			return true;
		}
		SokuLib::textureMgr.deallocate(id);
		return false;
	}

	bool Texture::createFromText(const char *str, SokuLib::SWRFont &font, Vector2<unsigned> size, Vector2<int> *realSize)
	{
		int text = 0;

		printf("Creating texture for text %s (size %u,%u)\n", str, size.x, size.y);
		if (!SokuLib::textureMgr.createTextTexture(
			&text, str, font, size.x, size.y,
			realSize ? &realSize->x : nullptr,
			realSize ? &realSize->y : nullptr
		) || !text) {
			puts("Failed");
			return false;
		}
		this->setHandle(text, size);
		return true;
	}

	Vector2<unsigned> RectangularRenderingElement::getSize() const
	{
		return this->_size;
	}

	Vector2<int> RenderingElement::getPosition() const
	{
		return this->_position;
	}

	void RenderingElement::setPosition(const Vector2<int> &newPos)
	{
		this->_position = newPos;
	}

	void RectangularRenderingElement::setSize(const Vector2<unsigned int> &newSize)
	{
		this->_size = newSize;
		this->setPosition(this->_position);
	}

	void RectangularRenderingElement::setPosition(const Vector2<int> &newPos)
	{
		RenderingElement::setPosition(newPos);

		auto center = this->_position + this->_size * 0.5;
		auto topLeft = this->_position.rotate(this->_rotation, center);
		auto topRight = (this->_position + Vector2<unsigned>{this->_size.x, 0}).rotate(this->_rotation, center);
		auto bottomLeft = (this->_position + Vector2<unsigned>{0, this->_size.y}).rotate(this->_rotation, center);
		auto bottomRight = (this->_position + this->_size).rotate(this->_rotation, center);

		this->_vertex[ this->_mirroring.x + this->_mirroring.y *  2].x = topLeft.x;
		this->_vertex[ this->_mirroring.x + this->_mirroring.y *  2].y = topLeft.y;
		this->_vertex[!this->_mirroring.x + this->_mirroring.y *  2].x = topRight.x;
		this->_vertex[!this->_mirroring.x + this->_mirroring.y *  2].y = topRight.y;
		this->_vertex[ this->_mirroring.x + this->_mirroring.y * -2 + 2].x = bottomRight.x;
		this->_vertex[ this->_mirroring.x + this->_mirroring.y * -2 + 2].y = bottomRight.y;
		this->_vertex[!this->_mirroring.x + this->_mirroring.y * -2 + 2].x = bottomLeft.x;
		this->_vertex[!this->_mirroring.x + this->_mirroring.y * -2 + 2].y = bottomLeft.y;

		if (this->_camera)
			for (auto &vertex : this->_vertex) {
				vertex.x += this->_camera->translate.x;
				vertex.y += this->_camera->translate.y;
				vertex.x *= this->_camera->scale;
				vertex.y *= this->_camera->scale;
			}
	}

	RectangularRenderingElement::RectangularRenderingElement(const SokuLib::Camera &camera) noexcept :
		_camera(&camera)
	{
	}

	void RectangularRenderingElement::setRect(const FloatRect &rect)
	{
		Vector2<int> pos{
			static_cast<int>(min(rect.x1, rect.x2)),
			static_cast<int>(min(rect.y1, rect.y2))
		};
		Vector2<unsigned> size{
			static_cast<unsigned int>(std::abs(rect.x1 - rect.x2)),
			static_cast<unsigned int>(std::abs(rect.y1 - rect.y2))
		};

		this->setSize(size);
		this->setPosition(pos);
	}

	void RectangularRenderingElement::rawSetRect(const Rect<Vector2<float>> &rect)
	{
		const Vector2<float> (&array)[4] = *reinterpret_cast<const Vector2<float>(*)[4]>(&rect);

		for (int i = 0; i < 4; i++) {
			this->_vertex[i].x = array[i].x;
			this->_vertex[i].y = array[i].y;
		}
	}

	void RectangularRenderingElement::setRotation(float angle)
	{
		this->_rotation = angle;
		this->setPosition(this->_position);
	}

	void RectangularRenderingElement::setMirroring(bool x, bool y)
	{
		this->_mirroring = {x, y};
		this->setPosition(this->_position);
	}

	void RectangularRenderingElement::setCamera(const Camera *camera)
	{
		this->_camera = camera;
	}

	const Vertex *RectangularRenderingElement::getVertex() const
	{
		return this->_vertex;
	}

	float RectangularRenderingElement::getRotation() const
	{
		return this->_rotation;
	}

	void GradiantRect::draw() const
	{
		Vertex vertexs[4];
		Vertex borders[5];

		for (int i = 0; i < 4; i++) {
			vertexs[i] = borders[i] = this->_vertex[i];
			vertexs[i].color = this->fillColors[i];
			borders[i].color = this->borderColors[i];
		}
		borders[4] = borders[0];
		SokuLib::textureMgr.setTexture(0, 0);
		SokuLib::pd3dDev->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertexs, sizeof(*vertexs));
		SokuLib::pd3dDev->DrawPrimitiveUP(D3DPT_LINESTRIP, 4, borders, sizeof(*borders));
	}

	GradiantRect::GradiantRect(const SokuLib::Camera &camera) noexcept :
		RectangularRenderingElement(camera)
	{
	}

	void RectangleShape::draw() const
	{
		GradiantRect::draw();
	}

	void RectangleShape::setFillColor(const DxSokuColor &color)
	{
		for (auto &fillColor : this->fillColors)
			fillColor = color;
	}

	void RectangleShape::setBorderColor(const DxSokuColor &color)
	{
		for (auto &borderColor : this->borderColors)
			borderColor = color;
	}

	DxSokuColor RectangleShape::getFillColor() const
	{
		return *this->fillColors;
	}

	DxSokuColor RectangleShape::getBorderColor() const
	{
		return *this->borderColors;
	}

	RectangleShape::RectangleShape(const SokuLib::Camera &camera) noexcept :
		GradiantRect(camera)
	{
	}

	void Sprite::draw() const
	{
		Vertex vertexs[4];

		for (int i = 0; i < 4; i++) {
			vertexs[i] = this->_vertex[i];
			vertexs[i].x -= 0.5;
			vertexs[i].y -= 0.5;
			vertexs[i].color = this->fillColors[i] * this->tint;
		}

		auto size = this->texture.getSize();

		if (size.x && size.y) {
			float left = static_cast<float>(this->rect.left) / size.x;
			float top = static_cast<float>(this->rect.top) / size.y;
			float right = static_cast<float>(this->rect.left + this->rect.width) / size.x;
			float bottom = static_cast<float>(this->rect.top + this->rect.height) / size.y;

			vertexs[3].u = vertexs[0].u = left;
			vertexs[2].u = vertexs[1].u = right;
			vertexs[1].v = vertexs[0].v = top;
			vertexs[2].v = vertexs[3].v = bottom;
			vertexs[2].x++;
			vertexs[1].x++;
			vertexs[2].y++;
			vertexs[3].y++;
		}
		this->texture.activate();
		SokuLib::pd3dDev->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertexs, sizeof(*vertexs));
	}

	Sprite::Sprite(const Camera &camera) noexcept :
		RectangularRenderingElement(camera)
	{
	}
}
}