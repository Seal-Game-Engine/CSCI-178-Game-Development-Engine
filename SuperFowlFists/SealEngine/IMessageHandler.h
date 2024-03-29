#pragma once
#include "SealPackages.h"

class IMessageHandler {
public:
	virtual bool TryHandleMessage(const HWND hWindow, const UINT, const WPARAM, const LPARAM) = 0;
	virtual void ResetOnNextFrame() = 0;
};