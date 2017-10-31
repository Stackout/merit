// Copyright (c) 2014-2017 The Merit Foundation developers
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MERIT_CORE_IO_H
#define MERIT_CORE_IO_H

#include "amount.h"

#include <string>
#include <vector>

class CBlock;
class CScript;
class CTransaction;
struct CMutableTransaction;
class uint256;
class UniValue;
enum opcodetype : short;

namespace referral
{
    class Referral;
}

// core_read.cpp
CScript ParseScript(const std::string& s);

std::string OpcodeToStr(
        const opcodetype opcode,
        const std::vector<unsigned char>& vch,
        const bool attempt_sighash_decode = false,
        const bool is_unspendable = false); 

std::string ScriptToAsmStr(
        const CScript& script,
        const bool fAttemptSighashDecode = false);

bool DecodeHexTx(
        CMutableTransaction& tx,
        const std::string& strHexTx,
        bool fTryNoWitness = false);

bool DecodeHexBlk(CBlock&, const std::string& strHexBlk);
uint256 ParseHashUV(const UniValue& v, const std::string& strName);
uint256 ParseHashStr(const std::string&, const std::string& strName);

std::vector<unsigned char> ParseHexUV(
        const UniValue& v,
        const std::string& strName);

// core_write.cpp
UniValue ValueFromAmount(const CAmount& amount);
std::string FormatScript(const CScript& script);

std::string EncodeHexTx(
        const CTransaction& tx,
        const int serializeFlags = 0);

void ScriptPubKeyToUniv(
        const CScript& scriptPubKey,
        UniValue& out,
        bool fIncludeHex);

void TxToUniv(
        const CTransaction& tx,
        const uint256& hashBlock,
        UniValue& entry,
        bool include_hex = true,
        int serialize_flags = 0);

void RefToUniv(
        const referral::Referral& tx,
        const uint256& hashBlock,
        UniValue& entry,
        bool include_hex = true,
        int serialize_flags = 0);

#endif // MERIT_CORE_IO_H
