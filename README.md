# ParametricPolymorphicC
Becasuse someone thought paste macros were a good thing to add

## Paste Macros
Paste macros are represented by ## in a macro definition and allow the concatenation of strings by the C preprocessor.
``` C
#define PASTE_MACRO(x, y) x ## _bar_ ## y

foo_bar_baz() {
  printf("foo\n");
}

int main() {
  PASTE_MACRO(baz, foo)();
}
```
