//
// Created by PinkySmile on 27/07/2021.
//

#ifndef SWRSTOYS_KEYCOMBINATION_HPP
#define SWRSTOYS_KEYCOMBINATION_HPP

struct MovementCombination {
	/* 0x1        */ bool _66 : 1;
	/* 0x2        */ bool _44 : 1;
	/* 0x4        */ bool _29 : 1;
	/* 0x8        */ bool _27 : 1;
	/* 0x10       */ bool _28 : 1;
	/* 0x20       */ bool _dd : 1;
	/*            */ short padding;
};

struct CommandCombination {
	/* 0x1        */ bool _236a : 1;
	/* 0x2        */ bool _236b : 1;
	/* 0x4        */ bool _236c : 1;
	/* 0x8        */ bool _236d : 1;
	/* 0x10       */ bool _214a : 1;
	/* 0x20       */ bool _214b : 1;
	/* 0x40       */ bool _214c : 1;
	/* 0x80       */ bool _214d : 1;
	/* 0x100      */ bool _623a : 1;
	/* 0x200      */ bool _623b : 1;
	/* 0x400      */ bool _623c : 1;
	/* 0x800      */ bool _623d : 1;
	/* 0x1000     */ bool _421a : 1;
	/* 0x2000     */ bool _421b : 1;
	/* 0x4000     */ bool _421c : 1;
	/* 0x8000     */ bool _421d : 1;
	/* 0x10000    */ bool _412a : 1;
	/* 0x20000    */ bool _412b : 1;
	/* 0x40000    */ bool _412c : 1;
	/* 0x80000    */ bool _412d : 1;
	/* 0x100000   */ bool _4136a : 1;
	/* 0x200000   */ bool _4136b : 1;
	/* 0x400000   */ bool _4136c : 1;
	/* 0x800000   */ bool _4136d : 1;
	/* 0x1000000  */ bool _6314a : 1;
	/* 0x2000000  */ bool _6314b : 1;
	/* 0x4000000  */ bool _6314c : 1;
	/* 0x8000000  */ bool _6314d : 1;
	/* 0x10000000 */ bool _22a : 1;
	/* 0x20000000 */ bool _22b : 1;
	/* 0x40000000 */ bool _22c : 1;
	/* 0x80000000 */ bool _22d : 1;
};


#endif //SWRSTOYS_KEYCOMBINATION_HPP
