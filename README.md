## Ray Tracing in one Weekend


### Chapter 4: Adding a sphere

In Chapter 4, Shirley provides the equation used to check whether a point lies on the surface of a sphere in a 3-dimensional Euclidian space.
It has to hold for 

```
x*x + y*y + z*z = r*r
```

Here, `r` is the radius of the sphere and `(x, y, z)` represents an arbitrary point - the previous wording is just another interpretation of the equation for a sphere `S` centered at the origin of radius `r`.


He then reminds us of the equation for the vector that points from a point `C` to a point `p` - in our case, `C` is the center of the sphere and `p` is a point on the surface of the sphere:

```
v = p - C
```

We know that the square of a vector `v = (x, y, z)` is the dot-product of the vector multiplied with itself, which ultimately is the square of its length, since

```
v . v = (x, y, z) . (x, y, z) = x*x + y*y + z*z = |v| * |v| 
```

(`.` denotes the operator for the dot-product here)

Given the equation for a sphere centered at the origin `C` we can thus conclude:

```
(p - C) . (p - C) = v . v = |v| * |v| = r * r 
```


