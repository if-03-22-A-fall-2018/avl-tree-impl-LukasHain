#include <stdio.h>
#include "avl_tree.h"

Node insert(Node node, int key){
  if (node == 0){
      node = create_node(key);
  }

  if (key < get_key(node)){
      set_left(node, insert(get_left(node), key));
  } else if (key > get_key(node)){
      set_right(node, insert(get_right(node), key));
  } else {
      return node;
  }

  set_height(node, max(get_height(get_left(node)), get_height(get_right(node))) + 1);

  int balance = get_balance(node);
  if (balance > 1 && key < get_key(get_left(node))){
  printf("Inserting %d, applying rotate right on %d\n", key, get_key(node));
      return rotate_right(node);
  }
  if (balance < -1 && key > get_key(get_right(node))){
      printf("Inserting %d, applying rotate right on %d\n", key, get_key(node));
          return rotate_right(node);
  }
  if (balance > 1 && key > get_key(get_left(node))){
      set_left(node, rotate_left(get_left(node)));
      return rotate_right(node);
  }
  if (balance < -1 && key < get_key(get_right(node))){
      set_right(node, rotate_right(get_right(node)));
      return rotate_left(node);
  }
return node;
}

Node rotate_left(Node node){
    if (node == 0){
        return 0;
    }

    Node r = get_right(node);
    Node l = get_left(r);

    set_left(r, node);
    set_right(node, l);

    set_height(node, max(get_height(get_left(node)), get_height(get_right(node))) + 1);
    set_height(r, max(get_height(get_left(r)), get_height(get_right(r))) + 1);

    return r;
}

Node rotate_right(Node node)
{

}

int get_balance(Node node)
{

}
Node unbalanced_insert(Node root, int key)
{

}
int max(int n1, int n2)
{

}
