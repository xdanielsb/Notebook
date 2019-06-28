#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct node{
  node* son[10];
  bool is_end = false;
  node(){
  }
};
void insert( node *n, string &num, int pos = 0){
  if( pos == size( num)){
    n->is_end = true;
    return;
  }
  int id = num[ pos ] - '0';
  if( !n->son[id] ){
    n->son[id] = new node();
  }
  insert( n->son[id], num, pos+1);
}
bool contain(node *n, string &n1, int pos = 0){
  int id = n1[ pos ] - '0';
  if( n->is_end ) return true;
  if( !n->son[ id ]) return false;
  if( size(n1) -1 == pos ) return n->son[id];
  return contain( n->son[ id ], n1, pos+1);
}
