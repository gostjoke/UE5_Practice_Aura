// This is a practice project, Free to use!

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"

#include "AuraEnemy.generated.h"
/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:

	AAuraEnemy();
	// 必須得從IEnemyInterface繼承過來
	virtual void HighlightActor() override; 
	virtual void UnHighlightActor() override;

};



