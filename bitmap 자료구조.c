//
//  10.c
//  Day_0605
//
//  Created by 전경안 on 2020/06/05.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define RETURN_ROOM(idx)    ((idx)>>(5))
#define RETURN_INDEX(idx) ((idx)&(31))
#define BIT_SIZE(x)         ((x)<<(5))
#define BIT_SET(set, idx)    ( (set[RETURN_ROOM(idx)]) |= (1 << (RETURN_INDEX(idx))) )
#define BIT_ISSET(set, idx) ((set[RETURN_ROOM(idx)]) & (1 << (RETURN_INDEX(idx))))
#define BIT_CLR(set, idx)    ((set[RETURN_ROOM(idx)]) &= ~(1 << (RETURN_INDEX(idx))))
typedef unsigned int bitset[4]; // 이 전 코드는 4바이트 동적 배열 할당만 가능하다는 단점이 있다. 이것을 동적 할당으로 바꿔라
// -->> int 는 8바이트이므로 최소 32비트이다 따라서 char로 해서 낭비를 최소화시킨다 ->  100 비트의 경우 104비트를 할당해서 4비트로 최소화 시킨다. 이 때 4비트마저도 효율적으로 사용하거나, 낭비를 없앨 수 있는 방법이 있을까?
#define BITSET_INITIALIZER {0,}
#define BIT_ZERO(set) \
do { for( int i = 0 ; i < 4 ; i ++) { (set[i]) = 0 ; }}while(0)

int main() {
    
    bitset leds = BITSET_INITIALIZER;
    BIT_SET(leds, 0);
    BIT_SET(leds, 31);
    BIT_SET(leds, 100);
    for (int i = 0; i < BIT_SIZE(sizeof(leds)/sizeof(leds[0])); i++) {
        if (BIT_ISSET(leds, i))
            printf("%d LED: ON\n", i);
        else
            printf("%d LED: OFF\n", i);
    }
    getchar();
    system("clear");
    
    BIT_CLR(leds, 31);
    for (int i = 0; i < BIT_SIZE(sizeof(leds)/sizeof(leds[0])); i++) {
        if (BIT_ISSET(leds, i))
            printf("%d LED: ON\n", i);
        else
            printf("%d LED: OFF\n", i);
    }
    BIT_ZERO(leds);
}


