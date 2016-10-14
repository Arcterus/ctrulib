/**
 * @file exheader.h
 * @brief Structures describing extended headers as in use by the system
 */
#pragma once

#include <3ds/types.h>

typedef struct
{
	u32 text_addr;
	u32 text_size;
	u32 ro_addr;
	u32 ro_size;
	u32 data_addr;
	u32 data_size;
	u32 total_size;
} PACKED EXHEADER_prog_addrs;

typedef struct
{
	u8 reserved[5];
	u8 flag; // Maybe a feature - Bits 2-7 are unused. We could allow uh, custom flags here. Like zlib compression on code rather than lzss.
	u8 remasterversion[2];
} PACKED EXHEADER_systeminfoflags;

typedef struct
{
	u32 address;
	u32 nummaxpages;
	u32 codesize;
} PACKED EXHEADER_codesegmentinfo;

typedef struct
{
	u8 name[8];
	EXHEADER_systeminfoflags flags;
	EXHEADER_codesegmentinfo text;
	u8 stacksize[4];
	EXHEADER_codesegmentinfo ro;
	u8 reserved[4];
	EXHEADER_codesegmentinfo data;
	u32 bsssize;
} PACKED EXHEADER_codesetinfo;

typedef struct
{
	u64 programid[0x30];
} PACKED EXHEADER_dependencylist;

typedef struct
{
	u8 savedatasize[4];
	u8 reserved[4];
	u8 jumpid[8];
	u8 reserved2[0x30];
} PACKED EXHEADER_systeminfo;

typedef struct
{
	u8 extsavedataid[8];
	u8 systemsavedataid[8];
	u8 reserved[8];
	u8 accessinfo[7];
	u8 otherattributes;
} PACKED EXHEADER_storageinfo;

// New3DS speed is flags[1]:1

typedef struct
{
	u64 programid;
	u8 coreVersion[4]; // Kernel version required for this.
	u8 flag2;
	u8 flag1;
	u8 flag0; // CPU speed settings.
	u8 priority;
	u16 resourcelimitdescriptor[0x10];
	EXHEADER_storageinfo storageinfo;
	u64 serviceaccesscontrol[0x20];
	u8 reserved[0x1f];
	u8 resourcelimitcategory;
} PACKED EXHEADER_arm11systemlocalcaps;

typedef struct
{
	u32 descriptors[28];
	u8 reserved[0x10];
} PACKED EXHEADER_arm11kernelcapabilities;

typedef struct
{
	u8 descriptors[15];
	u8 descversion;
} PACKED EXHEADER_arm9accesscontrol;

typedef struct
{
	u8 signature[0x100];
	u8 ncchpubkeymodulus[0x100];
	EXHEADER_arm11systemlocalcaps arm11systemlocalcaps;
	EXHEADER_arm11kernelcapabilities arm11kernelcaps;
	EXHEADER_arm9accesscontrol arm9accesscontrol;
} PACKED EXHEADER_accessdesc;

typedef struct
{
	EXHEADER_codesetinfo codesetinfo;
	EXHEADER_dependencylist deplist;
	EXHEADER_systeminfo systeminfo;
	EXHEADER_arm11systemlocalcaps arm11systemlocalcaps;
	EXHEADER_arm11kernelcapabilities arm11kernelcaps;
	EXHEADER_arm9accesscontrol arm9accesscontrol;
	EXHEADER_accessdesc accessdesc;
} PACKED EXHEADER_header;
