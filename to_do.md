# To Do list
## 180219
- Change direction to tuple see example 180219

```pyton
>>> import collections
>>> Point = collections.namedtuple('Point', ['x', 'y'])
>>> p = Point(1, y=2)
>>> p.x, p.y
1 2
>>> p[0], p[1]
1 2
```
