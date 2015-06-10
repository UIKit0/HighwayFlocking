/* Copyright 2015 Sindre Ilebekk Johansen and Andreas Sløgedal Løvland

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at

 *     http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Behaviour.h"

#include "Avoid.generated.h"

UCLASS()
class UAvoid : public UBehaviour {
	GENERATED_UCLASS_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		float FrontStartDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		float FrontStartDistancePri1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		float FrontStartDistancePri2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		float FrontMinDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		float SideStartDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Variables)
		float SideMinDistance;

	virtual FVector ProtectedGetDesiredVelocity(
		const UWorld* world,
		const FCamPacket& vehicle,
		const TArray<FCamPacket>& Neighbors,
		ARoadmap* Roadmap,
		EFlockingState& NextFlockingState) override;
};
