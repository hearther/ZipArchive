//
//  SSZipCommon.c
//  Pods
//
//  Created by Bunny Lin on 2017/5/26.
//
//

#include <stdio.h>
#include "SSZipCommon.h"

void zipProgress(long long doneSize)
{
    if (ocZipBlock){
        ocZipBlock(doneSize);
    }
}
