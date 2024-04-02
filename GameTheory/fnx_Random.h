#pragma once
#include "fnx_BasicStrategy.h"

class fnx_Random :
    public fnx_BasicStrategy
{
    FNX_CLASS_DEFAULT(fnx_Random)

public:
    fnx_Random  (void)              = delete;
    ~fnx_Random (void)  override    = default;

    fnx_Random  (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;
};

class fnx_RandomGood :
    public fnx_BasicStrategy
{
    FNX_CLASS_DEFAULT(fnx_RandomGood)

public:
    fnx_RandomGood  (void)              = delete;
    ~fnx_RandomGood (void)  override    = default;

    fnx_RandomGood  (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;
};

class fnx_RandomEvil :
    public fnx_BasicStrategy
{
    FNX_CLASS_DEFAULT(fnx_RandomEvil)

public:
    fnx_RandomEvil  (void)              = delete;
    ~fnx_RandomEvil (void)  override    = default;

    fnx_RandomEvil  (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;
};