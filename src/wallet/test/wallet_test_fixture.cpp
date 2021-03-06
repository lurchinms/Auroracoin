// Copyright (c) 2009-2019 The Bitcoin Core developers
// Copyright (c) 2014-2019 The DigiByte Core developers
// Copyright (c) 2015-2019 The Auroracoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <wallet/test/wallet_test_fixture.h>

#include <wallet/db.h>

WalletTestingSetup::WalletTestingSetup(const std::string& chainName)
    : TestingSetup(chainName),
      m_wallet(m_chain.get(), WalletLocation(), WalletDatabase::CreateMock())
{
    bool fFirstRun;
    m_wallet.LoadWallet(fFirstRun);
    m_wallet.handleNotifications();

    m_chain_client->registerRpcs();
}