# Dynamic memory allocation
Dynamic memory allocation allows C++ programs to create data structures in the heap so that it is not limited by the stack's size.

## Dynamically allocating an array of dynamically allocated objects
Dynamically allocating an array is useful because it allows us to create a container of dynamic size in the heap. We have already seen how to dynamically create an array of primitive data types and objects as shown below.

```cpp
int* values = new int[10];
student* cpsc121 = new student[60];
```

However, it is also possible to dynamically create an array of pointers. This is especially useful when dealing with object pointers to allow polymorphism. The syntax might be confusing at first, but it just builds on what we already know.

First thing to consider is that we use the * during variable declartion to indicate the creation of a pointer to the specified data type. `int* values`, for example indicates that we create a pointer to an `int`. 

When arrays are dynamically allocated, the compiler reserves space that can contain a consecutive list of data with a certain data type. When we allocate memory using `new int[10]`, for example, the compiler looks for an available block of space to hold 10 integers that is around 40 bytes of memory (4 bytes x 10). 

The `new` keyword returns the address of the first element of the array. Essentially, this means the address returned is the address of the first element of the array with the specified data type. In our example, it will return the address of the first `int` in the array. This is the reason why we can assign this to an `int*`.

Now consider creating an array of `int` pointers (or `int*`). Every element of the array would hold the address of an `int` and can be written as `new int*[10]`. We can use the same pattern to create an array of object pointers. For example, `new student*[10]`.

What data type should we use to declare a variable to hold the dynamically created array of pointers? Going back to our prior discussion, we established that `int* values` can be used to store the address of the first `int` of a dynamically created `int` array. The difference now is that instead of storing the address of the first element that is a primitive data type or object, we are talking about an address.

If `int*` is a pointer to an `int`, then `int**` would be a pointer to an `int*` (the address of an integer). Similarly, we can use this notation to create a pointer to any object address. For example, `student**`. Putting these concepts together we can now create a dynamically allocated array of addresses and store the address of the first element of that array into a variable.

```cpp
int** value_locations = new int*[10];
student** cpsc121_locations = new student*[10];
```

The first statement creates an array of 10 `int*` (`int` pointers). The first element of that array is an `int*` therefore the data type of the variable `value_locations` should be a pointer to an `int*` (`int` pointer), thus `int**`. Similarly, `cpsc121` is a pointer that points to the first element of the array of `student*` (`student` pointers).

### Accessing elements of a dynamically created array of pointers
Take note that the array we created contains addresses instead of the values. Therefore elements accessed using the bracket notation or pointer arithmetic are themselves addresses. To display an element of the dynamically allocated array of `int` pointers, we would now need to retrieve the address using the bracket notation or pointer arithmetic and then dereference it.

```cpp
int i = 5;
int* values = new int[10]; // dynamic array of int
cout << values[i]; // bracket notation
cout << *(values+i); // pointer arithmetic
```

Although it looks more complex, we apply the same logic for a dynamically created array of object pointers

```cpp
int i = 5;
(*cpsc121_locations[i]).display(); // bracket notation and dereferencing to call method
cpsc121_locations[i]->display(); // bracket notation and arrow notation to call method
(*(*(cpsc121_locations+i))).display(); // pointer arithmetic and dereferencing to call method
(*(cpsc121_locations+i))->display(); // pointer arithmetic and arrow notation to call method
```

### Deallocating the dynamically created array of pointers
Each element of the dynamically created array is itself an address that needs to be deallocated. Therefore we should not only deallocate the space used by the array, but also each address contained by its elements. We can use a loop to traverse the array and deallocate each element then deallocate the array as shown below.

```cpp
for (int i = 0; i < 10; i++) {
  delete cpsc121_locations[i];
}
delete[] cpsc121_locations;
```
We use `delete` for each element of the array if it is the address of a single object. We use `delete[]` for the array.
