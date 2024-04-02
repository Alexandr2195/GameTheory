#pragma once
#include "fnx_BasicStrategy.h"

class fnx_Dance_L :
    public fnx_BasicStrategy
{
     FNX_CLASS_DEFAULT(fnx_Dance_L)

public:
    fnx_Dance_L (void)              = delete    ;
    ~fnx_Dance_L(void)  override    = default   ;

    fnx_Dance_L(int inStartCoin, const char* inName);

    void	            Decision    (void)  override;
    void	            Reset       (void)  override;
    fnx_BasicStrategy* Copy         (void)  override;

private:
    fnx_Choice FirstStep;
};

class fnx_Dance_R :
    public fnx_BasicStrategy
{
    FNX_CLASS_DEFAULT(fnx_Dance_R)

public:
    fnx_Dance_R (void)              = delete;
    ~fnx_Dance_R(void)  override    = default;

    fnx_Dance_R(int inStartCoin, const char* inName);

    void	            Decision(void)  override;
    void	            Reset   (void)  override;
    fnx_BasicStrategy*  Copy    (void)  override;

private:
    fnx_Choice FirstStep;
};