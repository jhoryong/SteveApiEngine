#pragma once
namespace steve
{
	namespace enums
	{
		enum class eLayerType
		{
			None,
			BackGround,
			//Tree 
			//character
			Player,
			Max = 16,
		};

		enum class eResourceType
		{
			Texture,
			AudioClip,
			Prefab,
			End
		};

		enum class eComponentType
		{
			Transform,
			SpriteRenderer,
			Script,
			Camera,
			End,
		};
	};
}