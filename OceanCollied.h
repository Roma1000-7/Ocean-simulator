//Romashka

#ifndef __OCEANCOLLIED_H__
#define __OCEANCOLLIED_H__
#include "OceanOb.h"
#include "OceanMovingOb.h"
#include "OceanFixedOb.h"

void Fish::collied(OceanOb* other){
    auto pHunter = dynamic_cast <Hunter*> (other);
    if(pHunter)
        life = 0;
}

void Hunter::collied(OceanOb* other){
    auto pFish = dynamic_cast <Fish*> (other);
    if(pFish)
        life = 1;
}

#endif
