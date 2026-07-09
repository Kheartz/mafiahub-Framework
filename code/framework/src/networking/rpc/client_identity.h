/*
 * MafiaHub OSS license
 * Copyright (c) 2021-2023, MafiaHub. All rights reserved.
 *
 * This file comes from MafiaHub, hosted at https://github.com/MafiaHub/Framework.
 * See LICENSE file in the source repository for information regarding licensing.
 */

#pragma once

#include "rpc.h"

#include <string>

namespace Framework::Networking::RPC {
    // Client -> server after assets download: announces the player. Only honoured for an
    // authenticated connection (NetworkServer::IsAuthenticated).
    struct ClientIdentity {
        static constexpr const char *kIdentifier = "Framework::ClientIdentity";

        std::string name;
        std::string steamId;
        std::string discordId;
        std::string hardwareId;
        // Appended, not inserted: an older client sends four fields, so epicId underflows to empty
        // rather than shifting the other ids into each other's slots.
        std::string epicId;

        void Serialize(MafiaNet::BitStream *bs, bool write) {
            bs->Serialize(write, name);
            bs->Serialize(write, steamId);
            bs->Serialize(write, discordId);
            bs->Serialize(write, hardwareId);
            bs->Serialize(write, epicId);
        }
    };
} // namespace Framework::Networking::RPC
