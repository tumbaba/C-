// Fill out your copyright notice in the Description page of Project Settings.


#include "LoadingScreen/LoadingScreenWidget.h"
#include "LoadingScreenWidget.h"

bool ULoadingScreenWidget::Initialize()
{
	return Super::Initialize();
}

void ULoadingScreenWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CheckResources(LoadingBackgroundImage);
	CheckResources(LoadingAnimationImage);
}

void ULoadingScreenWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void ULoadingScreenWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void ULoadingScreenWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

void ULoadingScreenWidget::CheckResources(UImage* InImage)
{
	if (UTexture2D* BrushTexture = Cast<UTexture2D>(InImage->GetBrush().GetResourceObject()))
	{
#if WITH_EDITOR
		if (BrushTexture->LODGroup != TextureGroup::TEXTUREGROUP_UI)
		{
			ensureMsgf(false, TEXT("%s Texture->LODGroup != TEXTUREGROUP_UI"), *InImage->GetName());
		}
#else
		BrushTexture->LODGroup = TextureGroup::TEXTUREGROUP_UI;
		BrushTexture->UpdateResource();
#endif
	}
}
