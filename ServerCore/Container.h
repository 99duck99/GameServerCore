#pragma once
#include "Types.h"
#include "Allocator.h"
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

template<typename T>
using Xvector = vector<T, StlAllocator<T>>;

template<typename T>
using Xlist = list<T, StlAllocator<T>>;

template<typename Key, typename Type, typename Pred = less<Key>>
using Xmap = map<Key, Type, Pred, StlAllocator<pair<Key, Type>>>;

template<typename Key, typename Pred = less<Key>>
using Xset = set<Key, Pred, StlAllocator<Key>>;

template<typename Type>
using Xdeque = deque<Type, StlAllocator<Type>>;

template<typename Type, typename Container = Xdeque<Type>>
using Xqueue = queue<Type, Container>;

template<typename Type, typename Container = Xvector<Type>, typename Pred = less<typename Container::value_type>>
using Xpriory_queue = priority_queue<Type, Container, Pred>;

using Xstring	= basic_string<char, char_traits<char>, StlAllocator<char>>;
using Xwstring	= basic_string<wchar_t, char_traits<wchar_t>, StlAllocator<wchar_t>>;

template <typename Key, typename Type, typename Hasher = hash<Key>, typename Keyeq = equal_to<Key>,
    typename Alloc = StlAllocator<pair<const Key, Type>>>
using Xhash_map = unordered_map<Key, Type, Hasher, Keyeq, Alloc>;

template <typename Key, typename Hasher = hash<Key>, typename Keyeq = equal_to<Key>,
    typename Alloc = StlAllocator<const Key>>
using Xhash_set = unordered_set<Key, Hasher, Keyeq, Alloc>;