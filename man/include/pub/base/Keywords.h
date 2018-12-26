#ifndef HB92A1088_1C46_4501_A17B_AEE280D48E44
#define HB92A1088_1C46_4501_A17B_AEE280D48E44


#define ABSTRACT(...) virtual __VA_ARGS__ = 0

#define OVERRIDE(...) virtual __VA_ARGS__ override

#define EXTENDS(...) , ##__VA_ARGS__
#define IMPLEMENTS(...) EXTENDS(__VA_ARGS__)


#endif
