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
BTree< T, K > * minimum(BTree< T, K > * root)
{
  if (!root) {
    return root;
  }
  while (root->childs[0]) {
    root = root->childs[0];
  }
  return root;
}

template< class T, size_t K >
BTree< T, K > * maximum(BTree< T, K > * root)
{
  if (!root) {
    return root;
  }
  while (root->childs[K]) {
    root = root->childs[K];
  }
  return root;
}

template< class T, size_t K >
T value(BTreeIt< T, K > it)
{
  return it.current->val[it.s];
}

template< class T, size_t K >
BTreeIt< T, K > next(BTreeIt< T, K > it)
{
  BTree< T, K > next = it.curr;
  size_t ind = it.s;
  
  if (!next) {
    return {0, nullptr};
  }

  if (ind != K - 1) {
    if (next->childs[ind + 1]) {
      next = next->childs[ind + 1];
      next = minimum(next);
      ind = 0;
    } else {
      ++ind;
    }
  } else {
    if (next->childs[K]) {
      next = next->childs[K];
      next = minimum(next);
      ind = 0;
    } else {
      BTree< T, K > * parent = next->parent;
      while (parent) {
        bool is_found = false;
        for (size_t i = 0; i < K; ++i) {
          if (parent->childs[i] == next) {
            ind = i;
            is_found = true;
            break;
          }
        }
        if (is_found) {
          break;
        }
        next = parent;
        parent = next->parent;
      }
      next = parent;
    }
  }
  return {ind, next};
}

template< class T, size_t K >
BTreeIt< T, K > prev(BTreeIt< T, K > it)
{
  BTree< T, K > prev = it.curr;
  size_t ind = it.s;
  
  if (!prev) {
    return {0, nullptr};
  }

  if (ind != 0) {
    if (prev->childs[ind]) {
      prev = prev->childs[ind];
      prev = maximum(prev);
      ind = K - 1;
    } else {
      --ind;
    }
  } else {
    if (prev->childs[0]) {
      prev = prev->childs[0];
      prev = maximum(prev);
      ind = K - 1;
    } else {
      BTree< T, K > * parent = prev->parent;
      while (parent) {
        bool is_found = false;
        for (size_t i = K; i > 0; --i) {
          if (parent->childs[i] == prev) {
            ind = i - 1;
            is_found = true;
            break;
          }
        }
        if (is_found) {
          break;
        }
        prev = parent;
        parent = prev->parent;
      }
      prev = parent;
    }
  }
  return {ind, prev};
}

template< class T, size_t K >
bool hasNext(BTreeIt< T, K > it)
{
  return next(it).curr;
}

template< class T, size_t K >
bool hasPrev(BTreeIt< T, K > it)
{
  return prev(it).curr;
}

int main()
{}
