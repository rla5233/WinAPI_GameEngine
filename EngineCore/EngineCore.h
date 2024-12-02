#pragma once
#include <EnginePlatform/EngineWindow.h>
#include <EngineCore/UserCore.h>

class UUserCore;

// EngineCore Class
class UEngineCore
{
public:
	// constructor destructor
	UEngineCore();
	~UEngineCore();
	
	// delete Function
	UEngineCore(const UEngineCore& _Other) = delete;
	UEngineCore(UEngineCore&& _Other) noexcept = delete;
	UEngineCore& operator=(const UEngineCore& _Other) = delete;
	UEngineCore& operator=(UEngineCore&& _Other) noexcept = delete;

public:
	template<typename T>
	static void Start(HINSTANCE _Inst)
	{
		UEngineCore Core;
		T UserCore;
		Core.UserCorePtr = &UserCore;
		Core.EngineStart(_Inst);
	}

private:
	void EngineStart(HINSTANCE _Inst);

private:
	static UEngineWindow MainWindow;
	UUserCore* UserCorePtr = nullptr;

};