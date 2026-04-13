#include <cstddef>

template< class T, size_t K>
struct BTree {
  T val[K];
  BTree< T, K > * childs[K + 1];
  BTree< T, K > * parent;
};

template< class T, size_t K >
struct BTreeIt {
  size_t s;
  BTree< T, K > * current;
};

template< class T, size_t K >
T value(BTreeIt< T, K > it);

template< class T, size_t K >
BTreeIt< T, K > next(BTreeIt< T, K > it);

template< class T, size_t K >
BTreeIt< T, K > prev(BTreeIt< T, K > it);

template< class T, size_t K >
bool hasNext(BTreeIt< T, K > it);

template< class T, size_t K >
bool hasPrev(BTreeIt< T, K > it);

int main()
{}
