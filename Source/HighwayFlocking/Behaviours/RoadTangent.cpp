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

#include "../HighwayFlocking.h"
#include "RoadTangent.h"
#include "../Utils.h"

URoadTangent::URoadTangent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {

}

FVector URoadTangent::ProtectedGetDesiredVelocity(
		const UWorld* world,
		const FCamPacket& vehicle,
		const TArray<FCamPacket>& Neighbors,
		ARoadmap* Roadmap,
		EFlockingState& NextFlockingState){
	NextFlockingState = EFlockingState::FS_NoChange;
	FVector MyLocation = vehicle.Location;

	FVector RoadTangent = Roadmap->GetRoadTangentNearest(MyLocation);

	if (FVector::DotProduct(RoadTangent, vehicle.ForwardVector) < 0) {
		RoadTangent = -RoadTangent;
	}

	//DrawDebugCylinder(GetWorld(), MyLocation, MyLocation + WorldSteeringVector, 10, 10, FColor::Blue);

	return RoadTangent;
}
