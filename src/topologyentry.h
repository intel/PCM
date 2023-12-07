// SPDX-License-Identifier: BSD-3-Clause
// Copyright (c) 2022-, Intel Corporation

#pragma once

#include "types.h"

namespace pcm
{

struct PCM_API TopologyEntry // describes a core
{
    int32 os_id;
    int32 thread_id;
    int32 core_id;
    int32 module_id;
    int32 tile_id; // tile is a constalation of 1 or more cores sharing same L2 cache. Unique for entire system
    int32 die_id;
    int32 die_grp_id;
    int32 socket;
    int32 native_cpu_model = -1;
    enum DomainTypeID
    {
        InvalidDomainTypeID       = 0,
        LogicalProcessorDomain    = 1,
        CoreDomain                = 2,
        ModuleDomain              = 3,
        TileDomain                = 4,
        DieDomain                 = 5,
        DieGrpDomain              = 6,
        SocketPackageDomain       = 0xffff
    };
    enum CoreType
    {
        Atom = 0x20,
        Core = 0x40,
        Invalid = -1
    };
    CoreType core_type = Invalid;

    TopologyEntry() : os_id(-1), thread_id (-1), core_id(-1), module_id(-1), tile_id(-1), die_id(-1), die_grp_id(-1), socket(-1) { }
    const char* getCoreTypeStr()
    {
        switch (core_type)
        {
            case Atom:
                return "Atom";
            case Core:
                return "Core";
            case Invalid:
                return "invalid";
        }
        return "unknown";
    }
    static const char* getDomainTypeStr(const DomainTypeID & id)
    {
        switch (id)
        {
            case InvalidDomainTypeID: return "invalid";
            case LogicalProcessorDomain: return "LogicalProcessor";
            case CoreDomain: return "Core";
            case ModuleDomain: return "Module";
            case TileDomain: return "Tile";
            case DieDomain: return "Die";
            case DieGrpDomain: return "DieGroup";
            case SocketPackageDomain: return "Socket/Package";
        }
        return "unknown";
    }
};

}

