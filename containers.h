
#define paramType(name, T) name ## __ ## T ## __
#define fn(name, T) paramType(name, T)
