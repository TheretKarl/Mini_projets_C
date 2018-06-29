#ifndef structures
#define structures

typedef struct _list_char{
  char character;
  struct _list_char *next;
}list_char;

typedef struct _list_str{
  char *str;
  struct _list_str *next;
}list_str;

typedef struct _module{
  int energy;
  int speed;
  char *destination; // where he wants to go
  list_char *path; // a list used to go to location in order
}module;

typedef struct _point{
  int x;
  int y;
  module *carry;
  char *name;
  struct _point *left;
  struct _point *up;
  struct _point *right;
  struct _point *down;
}point;
  
#endif
