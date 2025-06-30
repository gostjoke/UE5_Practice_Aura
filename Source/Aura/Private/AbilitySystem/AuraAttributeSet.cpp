// This is a practice project, Free to use!


#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

/**
 * AbilitySystemComponent.h：GAS 系統核心之一，處理技能與屬性變更的類別。
 * UnrealNetwork.h：用於處理網路同步的 Unreal 引擎標頭檔。
 */

UAuraAttributeSet::UAuraAttributeSet()
{
	InitHealth(50.0f); // 初始化生命值為 100
    InitMaxHealth(100.0f); // 初始化最大生命值為 100
    InitMana(50.0f); // 初始化魔法值為 50
    InitMaxMana(50.0f); // 初始化最大魔法值為 50
}

// 3. 網路複製設定函式
void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const 
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Health, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Mana, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
    /*
        UAuraAttributeSet：這個類別。
        Health：你想同步的屬性。
        COND_None：沒有條件限制，任何情況都同步。
        REPNOTIFY_OnChanged：每次同步時都會執行 OnRep_Health，不論值有沒有變化。。
        REPNOTIFY_Always：只有在數值變化時才會觸發 OnRep_Health。
    */
}

// 同步變更的處理函式
void UAuraAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Health, OldHealth);
}

void UAuraAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxHealth, OldMaxHealth);
}

void UAuraAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Mana, OldMana);
}

void UAuraAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxMana, OldMaxMana);
}


