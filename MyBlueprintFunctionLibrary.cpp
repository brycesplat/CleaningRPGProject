// 2020 Purdue Polytechnic Institute


#include "MyBlueprintFunctionLibrary.h"

int32 UMyBlueprintFunctionLibrary::PlayerAttackDamage(EAttackType weak, EAttackType res, EAttackType attack, int32 damage) {
	if (attack == weak) {
		return damage * 2;
	}
	else if (attack == res) {
		return damage / 2;
	}
	else {
		return damage;
	}
}

int32 UMyBlueprintFunctionLibrary::PlayerStaminaUse(EAttackType weak, EAttackType res, EAttackType attack, int32 num) {
	if (attack == weak) {
		if (num >= 90) {
			return 1;
		}
		return 0;
	}
	else if (attack == res) {
		if (num >= 60) {
			return 2;
		}
		return 1;
	}
	else {
		if (num >= 80) {
			return 2;
		}
		if (num >= 20) {
			return 1;
		}
		return 0;
	}
	return 0;
}

int32 UMyBlueprintFunctionLibrary::CalculateHealth(int32 health, int32 damage) {
	int32 finalHealth = health - damage;
	if (finalHealth < 0) {
		finalHealth = 0;
	}

	return finalHealth;
}

int32 UMyBlueprintFunctionLibrary::CalculateDamage(float damage, float bonus)
{	
	return FMath::FloorToInt(damage + (damage * bonus));
}
