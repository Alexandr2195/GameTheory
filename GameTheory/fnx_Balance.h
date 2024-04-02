#pragma once
#include "fnx_BasicStrategy.h"

class fnx_Balance :
    public fnx_BasicStrategy
{
    FNX_CLASS_DEFAULT(fnx_Balance)

public:
    fnx_Balance     (void)              = delete    ;
    ~fnx_Balance    (void)  override    = default   ;

    fnx_Balance     (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;

private:
    int        CountBetrayal    ;
    int        CountCooperation ;
};

class fnx_BalanceGood :
    public fnx_BasicStrategy
{
    FNX_CLASS_DEFAULT(fnx_BalanceGood)

public:
    fnx_BalanceGood     (void)              = delete    ;
    ~fnx_BalanceGood    (void)  override    = default   ;

    fnx_BalanceGood     (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;

private:
    int        CountBetrayal        ;
    int        CountCooperation     ;

    float      ProcentBetrayal      ;
};

class fnx_BalanceEvil :
    public fnx_BasicStrategy
{
    FNX_CLASS_DEFAULT(fnx_BalanceEvil)

public:
    fnx_BalanceEvil     (void)              = delete    ;
    ~fnx_BalanceEvil    (void)  override    = default   ;

    fnx_BalanceEvil     (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;

private:
    int        CountBetrayal        ;
    int        CountCooperation     ;

    float      ProcentBetrayal      ;
};

class fnx_BalanceEvil2 :
    public fnx_BasicStrategy
{
    FNX_CLASS_DEFAULT(fnx_BalanceEvil2)

public:
    fnx_BalanceEvil2     (void)              = delete    ;
    ~fnx_BalanceEvil2    (void)  override    = default   ;

    fnx_BalanceEvil2     (int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy*  Copy        (void)  override;

private:
            int        CountBetrayal        ;
            int        CountCooperation     ;

            float      ProcentBetrayal      ;
    const   fnx_Choice FirstStep;
};