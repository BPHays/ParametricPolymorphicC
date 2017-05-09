
#define paramType(name, T)       name ## __ ## T ## __
#define paramType2(name, T1, T2) name ## __ ## T1 ## _x_ ## T2 ## __ 

#define fn(name, T)              paramType(name, T)
#define fn2(name, T1, T2)        paramType2(name, T1, T2)

#define interface(name, T)          name ## T ## Interface

#define m(name)                  methods->name
