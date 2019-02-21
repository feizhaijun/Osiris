#pragma once

#include "NetworkChannel.h"
#include "Utils.h"
#include "Vector.h"

struct PlayerInfo {
    unsigned long pad;
    union {
        unsigned long steamID64;
        unsigned int xuidLow;
        unsigned int xuidHigh;
    };
    char name[128];
    int userId;
    char steamIdString[20];
    char pad1[16];
    unsigned long steamId;
    char friendsName[128];
    bool fakeplayer;
    bool ishltv;
    unsigned int customfiles[4];
    unsigned char filesdownloaded;
};

class Engine {
public:
    constexpr auto getScreenSize(int& width, int& height) noexcept
    {
        callVirtualFunction<void(__thiscall*)(void*, int&, int&)>(this, 5)(this, width, height);
    }

    constexpr auto getPlayerInfo(int entityIndex, const PlayerInfo& playerInfo) noexcept
    {
        return callVirtualFunction<bool(__thiscall*)(void*, int, const PlayerInfo&)>(this, 8)(this, entityIndex, playerInfo);
    }

    constexpr auto getLocalPlayer() noexcept
    {
        return callVirtualFunction<int(__thiscall*)(void*)>(this, 12)(this);
    }

    constexpr auto getViewAngles(Vector& angles) noexcept
    {
        callVirtualFunction<void(__thiscall*)(void*, Vector&)>(this, 18)(this, angles);
    }

    constexpr auto setViewAngles(const Vector& angles) noexcept
    {
        callVirtualFunction<void(__thiscall*)(void*, const Vector&)>(this, 19)(this, angles);
    }

	constexpr auto getMaxClients() noexcept
	{
		return callVirtualFunction<int(__thiscall*)(void*)>(this, 20)(this);
	}

	constexpr auto isInGame() noexcept
	{
		return callVirtualFunction<bool(__thiscall*)(void*)>(this, 26)(this);
	}

    constexpr auto getNetworkChannel() noexcept
    {
        return callVirtualFunction<NetworkChannel*(__thiscall*)(void*)>(this, 78)(this);
    }
};
