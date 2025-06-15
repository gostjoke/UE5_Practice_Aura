// This is a practice project, Free to use!


#include "Character/AuraEnemy.h"

#include "Aura/Aura.h"

// need to go Project Setting and custom depth Enable with Stencil

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block); // Ignore visibility channel for the mesh
}

void AAuraEnemy::HighlightActor()
{
    GetMesh()->SetRenderCustomDepth(true); 
    GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED); // Set a custom stencil value for highlighting
    Weapon->SetRenderCustomDepth(true);
    Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED); // Set a custom stencil value for highlighting
}

void AAuraEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false); 
    Weapon->SetRenderCustomDepth(false);
}
