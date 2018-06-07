// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */

class UButton;
class UWidgetSwitcher;
class UWidget;
class UEditableTextBox;


UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()


public:
	UMainMenu(const FObjectInitializer & ObjectInitializer);

	void SetServerList(TArray<FString> ServerNames);


private:

		TSubclassOf<class UUserWidget> ServerRowClass;

		UPROPERTY(meta = (BindWidget))
		UButton *cmdHost=nullptr;

		UPROPERTY(meta = (BindWidget))
		UButton *cmdJoin=nullptr;

		UPROPERTY(meta = (BindWidget))
		UButton* cmdCancelJoinMenuButton;
		
		UPROPERTY(meta = (BindWidget))
		UButton* cmdConfirmJoinMenuButton;

		UPROPERTY(meta = (BindWidget))
		UButton* cmdQuitGame;

		UPROPERTY(meta = (BindWidget))
		UWidgetSwitcher* MenuSwitcher;

		UPROPERTY(meta = (BindWidget))
		UWidget* MainMenu;

		UPROPERTY(meta = (BindWidget))
		UWidget* JoinMenu;

		UPROPERTY(meta = (BindWidget))
		UPanelWidget* ServerList;

	
		UFUNCTION()
		void hostServer();

		UFUNCTION()
		void joinServer();

		UFUNCTION()
		void OpenJoinMenu();

		UFUNCTION()
		void OpenMainMenu();

		UFUNCTION()
		void QuitPressed();

		


protected :
		virtual bool Initialize();




	    

	

	
};
