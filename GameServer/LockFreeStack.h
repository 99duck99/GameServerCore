#pragma once

/* 
*  -------Single Thread-------

struct SListEntry
{
	SListEntry* next;
};

class Data
{
public:
	SListEntry _entry;

	int32 _hp;
	int32 _mp;
};

struct SListHeader
{
	SListEntry* next = nullptr;
};

void InitializeHead(SListHeader* header);

void PushEntrySList(SListHeader* header, SListEntry* entry);

SListEntry* PopEntrySList(SListHeader* header);

*/

DECLSPEC_ALIGN(16)
struct SListEntry
{
	SListEntry* next;
};

DECLSPEC_ALIGN(16)
struct SListHeader
{
	SListHeader()
	{
		alignment = 0;
		region = 0;
	}

	union
	{
		struct
		{
			uint64 alignment;
			uint64 region;
		} DUMMYSTRUCTNAME;
		struct
		{
			uint64 depth : 16; // 노드의 개수
			uint64 sequence : 48; // ABA 방지용 카운터
			uint64 reserved : 4; // 예약공간
			uint64 next : 60; // 다음 노드의 포인터 -> 16바이트 정렬이라 뒷 4개의 바이트는 무조건 0000
		}HeaderX64;
	};
};

void InitializeHead(SListHeader* header);

void PushEntrySList(SListHeader* header, SListEntry* entry);

SListEntry* PopEntrySList(SListHeader* header);