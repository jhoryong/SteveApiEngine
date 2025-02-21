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
			Animal,
			Player,
			Particle,
			Max = 16,
		};

		enum class eResourceType
		{
			Texture,
			AudioClip,
			Animation,
			Prefab,
			End
		};

		enum class eComponentType
		{
			Transform,
			SpriteRenderer,
			Animator,
			Script,
			Camera,
			End,
		};
	};
}