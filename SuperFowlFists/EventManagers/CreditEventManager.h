#pragma once
#include "../SealEngine.h"
using namespace SealEngine;

class CreditEventManager : public MonoBehaviour {
public:
	void Update() override;
	//void LateUpdate() override;

private:
	CreditEventManager* _Clone()const;
};

