#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"

/**
In a strategic space game, asteroids can play a significant role in resource acquisition, mining, and tactical gameplay. To make the game more interesting and diverse, you can incorporate various types of asteroids with unique compositions, properties, and strategic importance. Here are some asteroid types and their potential compositions:

1. **Metallic Asteroids:**
   - Composition: Mostly composed of metals like iron, nickel, and platinum group metals.
   - Strategic Importance: Valuable for resource mining, as they yield a high amount of metals for construction and trade.

2. **Silicate Asteroids:**
   - Composition: Made up of silicate minerals, such as basalt or olivine.
   - Strategic Importance: Useful for harvesting minerals and rare gemstones. They can also be used for research into planetary formation.

3. **Carbonaceous Asteroids:**
   - Composition: Rich in carbon-based compounds, including organic molecules, water ice, and hydrocarbons.
   - Strategic Importance: Essential for water extraction, fuel production, and potential for discovering extraterrestrial life.

4. **Icy Asteroids:**
   - Composition: Composed primarily of water ice, with some volatile gases.
   - Strategic Importance: Valuable sources of water for life support, fuel, and hydroponic agriculture.

5. **Rare-Earth Element Asteroids:**
   - Composition: Contain a high concentration of rare-earth elements like neodymium, used in advanced technologies.
   - Strategic Importance: Highly sought after for advanced manufacturing and research purposes.

6. **Radioactive Asteroids:**
   - Composition: Contain radioactive materials like uranium or thorium.
   - Strategic Importance: Valuable for power generation, but they come with radiation hazards.

7. **Regolith-Covered Asteroids:**
   - Composition: A mix of different minerals and compounds, covered by a layer of loose regolith.
   - Strategic Importance: Challenging to mine due to the loose surface material but can yield a variety of resources.

8. **Hollowed Asteroids:**
   - Composition: Typically solid with hollowed-out caverns or tunnels.
   - Strategic Importance: Serve as potential hiding places, secret bases, or as points of interest for exploration.

9. **Magnetic Asteroids:**
   - Composition: Possess strong magnetic fields.
   - Strategic Importance: Can disrupt navigation systems or offer unique scientific research opportunities.

10. **Alien Artifact Asteroids:**
	- Composition: Unknown, but they contain mysterious alien technology or artifacts.
	- Strategic Importance: High risk and reward, as players may discover advanced technology or face unknown threats.

In your strategic space game, players could explore, mine, defend, or exploit these asteroid types to advance their objectives. Each asteroid type can offer a different set of challenges and opportunities, encouraging players to strategize and make decisions that affect their gameplay experience.

*/

UENUM(BlueprintType)
enum class XOreTypeEnum : uint8
{
	Metallic = 0 UMETA(DisplayName = "Metallic Asteroids"),

	Carbonaceous = 1 UMETA(DisplayName = "Carbonaceous Asteroids"),

	Silicate = 2 UMETA(DisplayName = "Silicate Asteroids"),

	Ice = 3 UMETA(DisplayName = "Icy Asteroids"),

	RareEarthElement = 4 UMETA(DisplayName = "Rare-Earth Element Asteroids"),

	Radioactive = 5 UMETA(DisplayName = "Radioactive Asteroids"),

	RegolithCovered = 6 UMETA(DisplayName = "Regolith-Covered Asteroids"),

	AlienArtifact = 7 UMETA(DisplayName = "Alien Artifact Asteroids")
};
