#pragma once
#include "CommonInclude.h"
namespace steve
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		/*
		@param hdc - labd
		@param abc - asdf;
		@returns result
		*/
		static void Render(HDC hdc);
		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;
	};
}

