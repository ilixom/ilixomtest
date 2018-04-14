// Copyright (c) 2015 The Ilixomtest developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ILTDB_H
#define	ILTDB_H

#include "wallet/db.h"

#include <string>

/** Access to the wallet database (ilt.dat) */
class CSibDB : public CDB
{
public:
    CSibDB(const std::string& strFilename, const char* pszMode = "cr+") : CDB(strFilename, pszMode)
    {
    }

    bool WriteName(const std::string& key, const std::string &arr);
    bool ReadName(const std::string& key,  std::string &arr);
    bool EraseName(const std::string& key);
    
};
#endif	/* ILTDB_H */

