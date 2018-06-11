// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

USTRUCT()
struct FServerData {

	GENERATED_BODY()

	FString Name;
	uint16 CurrentPlayers;
	uint16 MaxPlayers;
	FString HostUsername;


};

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

	void SetServerList(TArray<FServerData> ServerNames);

	void SelectIndex(uint32 Index);


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

		UPROPERTY(meta = (BindWidget))
		class UWidget* HostMenu;

		UPROPERTY(meta = (BindWidget))
		class UEditableTextBox* ServerHostName;

		UPROPERTY(meta = (BindWidget))
		class UButton* cmdCancelHostMenu;

		UPROPERTY(meta = (BindWidget))
		class UButton* cmdConfirmHostMenu;


	
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

		UFUNCTION()
		void OpenHostMenu();


		TOptional<uint32> SelectedIndex;

		void UpdateChildren();



protected :
		virtual bool Initialize();




	    

	

	
};
