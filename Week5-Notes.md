## CS50 - Week 5 - [Data Structures](https://youtu.be/4IrUAqYKjIA)
A pointer is similar to an array, they both point to a specific location allocated in memory but an array is a large block of memory in a single location while a pointer points to a specific location in memory and it can be located anywhere in the memory.

Arrays free memory automatically but with pointers you have to make sure to free the memory allocation when you are done using it so the computer knows that it can reuse that memory location.

#### Linked List (list3.c)
Allows you to store a list of values, similar to an array, but with a linked list you can expand the size easier and faster. This is because you are allocating 2 blocks of memory per value. The second block of memory is just for containing the pointer that points to the memory location of your next value in the list. The last double block of memory in the list will always contain a NULL value because it is not pointing to anything but is there in the case that you want to add to this list.

**node:** Represents the double blocks of memory for each value.
- Each node contains:
  - The value to be stored in that node
    - Example: `int number;`
  - A pointer to point to the "next" value
    - Example: `struct node *next;`
- Example of how to set up a node:
  ```
  typedef struct node
  {
      int number:
      struct node *next;
  }
  node;
  ```

How to start a singly linked list:
- `node *list = NULL;` this will intialize the list with a NULL value, in turn creating an empty pointer.
- `node *n = malloc(sizeof(node));` allocates the memory for a new value, this is where the NULL pointer will point to next.
- `if (n != NULL)` this checks your edge case to make sure it is there.
- `(*n).number = 2;` to add a value to the list. The () is just to indicate order of operations so the computer knows to first go to `n`, then add the value of `2` in the memory location for `n`.
- `n->number = 2;` does the same thing as `(*n).number = 2;` but is much easier to read and better convention. This is called "arrow notation".
- `n->next = NULL;` creates the pointer for the next value, which is NULL since there is no value there yet.
- `list = n;` finally assign the new node (value) to the list.

Pointing to a new location with a value to add to list:
  ```
  node *tmp = list; // Makes a copy of where list is pointing.
  while (tmp->next != NULL)  // While the location it is pointing is not NULL...
  {
    tmp = tmp->next;  // tmp is now going to point to the next value.
  }
  tmp->next = n; // Assigns the new tmp pointer
  ```
  
Adding another pointer to the beginning of list:
  ```
  n->next = list;  // assigns the pointer from the new node to point to the first value in the list first.
  list = n;  // reassigns the list to point at the new node as its first value.
  ```
  
Have to always make sure that when you add a value at the beginning or in the middle of a linked list that you first have the new node point to the one that will be after it and then the pointer from the value before it can point to it.

Because linked list needs to search through each value in order until it finds the value it is searching for, you loss the ability to do binary search because the computer does not know where the middle of the linked list is. Therefore it has to do a linear search which creates a time complexity disadvantage. Making this now O(n) time complexity.

#### [Singly-Linked Lists](https://www.youtube.com/watch?v=zQI3FyWm144)
Through clever use of pointers, dynamic memory allocation (`malloc`), and structs, we can put the pieces together to develop a new kind of data structure that gives us the ability to grow and shrink a collection of like values to fit our needs. A singly linked list can only move in one direction since each node has only one pointer. This is best if you do not anticipate having to delete a single node from the list. This will take less bytes then the doubly linked list.

A linked list "node" is a special kind of struct with 2 members:
- Data of some data type (int, char, float, etc)
- A pointer to another node of the same type

  ```
  typedef struct sllist  // this is just a temp structure variable
  {
    VALUE val;  // creates the value parameter
    struct sllist* next;  // use the temp structure variable to create the pointer
  }
  sllnode;  // this is the variable you want to call the node
  ```

In this way, a set of nodes together can be thought of as forming a chain of elements that we can follow from beginning to end.

Operations:
1. Create a linked list when it doesn't already exist.
2. Search through a linked list to find an element.
3. Insert a new node into the linked list.
4. Since we are dynamically allocating memory to work with this structure, need to delete a single element from a linked list.
5. Since we are dynamically allocating memory to work with this structure, need to delete an entire linked list.

Pseudocode to create a linked list:
- sllnode* create(VALUE val);
  - example: `sllnode* new = create(6);` `new` refs the new node `create(6)` places the value of 6 in the new node
1. Dynamically allocate space for a new node.
2. Check to make sure we don't run out of memory.
3. Initialize the node's value
4. Initialize the node's next field.
5. Return a pointer to the newly created node.

Once you create a list you want to ALWAYS keep track of the very first element so you can refer to the other elements by following the chain without having to keep pointers in tack to every single element. You only need to keep track of the first one if they are all chained together.

Pseudocode to search through a linked list to find an element and return true or false:
- bool find(sllnode* head, VALUE val);
  - example: `bool exists = find(list, 6);`
1. Create a traversal pointer (create a copy of the original) pointing to the list's head.
2. If the current node's value field is what we're looking for, report success (true).
3. If not, set the traversal pinter to the next pointer in the list and go back to step 2.
4. If you've reached the end of the list, report failure (false).

Linked list do not have to be in any particular order. However the pointers do need to be in a continuous order to prevent a break in the chain. Once you break the chain you can not get back to those other values.

Pseudocode to insert a new node into a linked list:
- `sllnode* insert(sllnode* head, VALUE val);`
  - example: `list = insert(list, 12);`
1. Dynamically allocate space for a new node.
2. Check to make sure we didn't run out of memory.
3. Populate and insert the node at the beginning of the linked list. This is best practice if the linked list does not need to be in any particular order because it reduces the time complexity for inserting the node.
4. Return a pointer to the new head of the linked list. The pointer from the new node needs to point at the old head first and then you connect the pointer from the variable for the list to the new node. Needs to be done in this order to avoid a break in the chain.

Pseudocode to delete an entire linked list:
- `void destroy(node *head);`
  - example: `destory(list);`
1. If you've reached a NULL pointer, stop, you are at the end of the list. However, at this point the computer has gone through every node in the list and placed them in a stack as it goes through until it gets to the NULL pointer.
2. Delete the rest of the list. (delete/free everyone else then come back and free me) Once it has made it to the NULL pointer, the will delete/free that node first then work it's way back down the stack deleting/freeing each node as it backtracks, until it gets back to the head node.
3. Free the current node.
- Needs to be done in this order to avoid memory leakage because if we just deleted/freed the head, the chain would then be disconnected and nothing would be pointing to the what would be the new head. This needs to be done in a recursive manner to avoid that from happening.

#### [Doubly Linked List](https://youtu.be/FHMPswJDCvU)
Allows us to move forward and backward through the list, all by simply adding one extra pointer to our structure definition for each node. Therefore you will use more memory vs a singly linked list, but if you think you will need the ability to delete a single node within the list, you will need to use this type of linked list since the pointers point in both directions.

  ```
  typedef struct dllist  // this is just a temp structure variable
  {
    VALUE val;  // creates the value for the node
    struct dllist* prev;  // creates a previous pointer
    struct dllist* next;  // creates a next pointer
  }
  dllnode;  
  ```

Operations:
1. Create a linked list when it doesn't already exist.
2. Search through a linked list to find an element.
3. Insert a new node into the linked list.
4. Since we are dynamically allocating memory to work with this structure, need to delete a single element from a linked list.
5. Since we are dynamically allocating memory to work with this structure, need to delete an entire linked list.

Remeber, we can never break the chain when rearranging the pointers. Even if we need to have redundant pointers temporarlity, that's okay.

Pseudocode to insert a new node into a doubly linked list:
- `dllnode* insert(dllnode* head, VALUE val);`
  - example: `list = insert(list, 12);`
1. Dynamically allocate space for a new node.
2. Check to make sure we didn't run out of memory.
3. Populate and insert the node at the beginning of the linked list.
4. Fix the next pointer from the new node to the old head of the linked list.
5. Fix the previous pointer of the old head of the linked list to the new node.
6. Return a pointer to the new head of the linked list.

Pseudocode to delete a node from the middle of a doubly liked list:
- `void delete(dllnode* target);`
  - example: `delete(x);`
1. Fix the pointers of the surrounding nodes to "skip over" the target node.
   a. The next pointer of the target's previous node needs to point where the target's next pointer is pointing to.
   b. The previous pointer of the target's next node needs to point where the target's previous pointer is pointing.
2. Delete/free the target node.

Linked list, of both the singly and doubly linked varieties, support extremely efficient *insertion* and *deletion* of elements/nodes. These operations can be done in constant time which is a time complexity of O(1).

What is the downside? We've lost the ability to randomly-access list elements. Therefore, accessing a desired element may now take linear time of O(n). 

#### Trees
Similar to a linked list but instead of having to use a linear search to look for values you can use a binary search because now you start with the middle value at the top of the "tree", kind of like an inverted family tree, and then work your way down going left or right to find the value. 

How to define a node in a tree:
  ```
  typedef struct node
  {
    int number;  // value in the node
    struct node *left;  // creates a left pointer
    struct node *right;  // creates a right pointer
  }
  node;
  ```
  
Structure of a binary search tree is a "parent node" on top then a left "child node" and a right "child node". The children can also be called a "subtree"
  
Recusive Binary Tree: everything to the left is smaller, everything to the right is larger.

Binary search tree is the best method to use for recurision. Time complexity with this method is O(log n).

Coding a recursive binary search tree to look for the value 50:
  ```
  bool search(node *tree)  // creates a search variable that returns True or False
  {
    if (tree == NULL)  // check if there is any value at the parent/root node
    {
      return false;  // if no value, return false
    }
    
    else if (50 < tree->number)  // if the value of the node is greater than 50...
    {
      return search(tree->left);  // return the left child node
    }
    
    else if (50 > tree->number)  // if the value of the node is less than 50...
    {
      return search(tree->right); // return the right child node
    }
    
    else  // only thing left is... if the value of the node is 50...
    {
      return true;  // found our value, return true, indicating it does exsist.
    }
  }
  ```
  
#### Hash Tables
The best in time complexity if it is an ideal (create it with an algorith that creates a uniqueness that reduces the amount of searching, ie for names use the first 3 letters of the name vs just the first letter) hash table at O(1), but if it is not optimal, it is O(n) in time complexity. Also, if not optimal it could have a high space complexity. On average the time complexity is closer to O(1).

A combination of an array and a linked list inside of it. You start with an array-like structure and then for each value within the array-like structure there is a linked list with multiple values.

#### [Hash Tables](https://www.youtube.com/watch?v=nvzVHwrrub0)
Combines the random access ability of an array with the dynamism of a linked list. 

This means (assuming we define our hash table well):
- Insertion can start to tend toward a time complexity of O(1).
- Deletion can start to tend toward a time complexity of O(1).
- Lookup can start to tend toward a time complexity of O(1).

We are gaining the advantages of both types of data structures, while mitigating the disadvantages.

To get this performance upgrade, we create a new structure whereby when we insert data into the structure, the data itself gives us a clue about where we will find the data, should we need to later look it up.

The trade off is that hash tables are not great at ordering or sorting data, but if we don't care about that, then we're good to go!

A hash table is a combination of 2 things:
- A **hash function**, which returns an non-negitive integer value called a *hash code*.
- An **array** capable of storing data of the type we wish to place into the data structure.

The idea is that we run our data through the hash function, and then store the data in the element of the array represented but the returned hash code.

- example: 
  - `string hashtable[10];` gives us a hash table of strings with 10 elements.
  - `int x = hash("John");` will give you the location for the value where it should be in the hash table.
  - `hashtable[x] = "John";` assigns that location within the hash table to our *John* value for lookup later.

How to define a hash function? There really are no limits to the number of possibe hash functions. A good hash function should:
- Use only the data being hashed.
- Use all of the data being hashed.
- Be deterministic.
- Uniformly distribute data.
- Generate very different hash codes for very similar data.

Example of a hash function:
  ```
  unsigned int hash(char* str)
  {
    int sum = 0;
    for (int j = 0; str[j] != '\0'; j++)  // detirmines the end of the string
    {
      sum += str[j];  // Adds up all the ASCII values of the string
    }
    return sum % HASH_MAX;  // Mods the sum against the max length of the hash array
  }
  ```
  
Making your own hash functions is more of an art then science, better to search the internet for a good hash function vs trying to create one on your own. Just make sure to cite your sources for the code you use.

A **collision** occurs when 2 pieces of data, when run through the hash function, yield the same hash code. We probably want both pieces of data in the hash table, so we wouldn't simply overwrite the data that is already stored there. So we need to find a way to get both elements into the hash table while trying to preserve quick insertion and lookup.

One way to resolve collisions is through **linear probing**. With this method, if we have a collision, we try to place the data in the next consecutive element in the array (wrapping around the beginning if necessary) until we find a vacancy. That way, if we don't find what we're looking for in the first location, at least hopefully the element is somewhere nearby.

Linear probing is subject to a problem called **clustering**. Once there is a miss, 2 adjacent cells will contain data, making it more likely in the future that the cluster will grow. Even if we switch to another probing technique, we're still limited. We can only store as much data as we have locations in our array.

Another way to resolve collisions and the best way is **chaining**. It is a method that uses linked list. So, each element in the array will then have a pointer that points to the head of a linked list, therefore allowing you to store multiple values in each element of the array/hash table.

Now instead of our hash table being an array of 10 strings, we will make it an array of 10 nodes:
  `node* hashtable[10];`
  
Example of creating a node within our hash table:
- `hash("Joey");` returns 6
- `hash("Phoebe");` returns 6 also
- Now we have a collision
- Need to first allocate memory for "Joey"
- Add a pointer from 6 in the hash table to the "Joey" node
- Then allocate memory for a "Phoebe" node
- Point "Phoebe" next pointer to "Joey"
- Point the 6 pointer to the "Phoebe" node.
- Now we have just avoided a collision in hash 6.

#### Tries (retrival)
Spends one resource to save on another(ie more space to save on time complexity and vise versa). A tree where each of its nodes are array-like, meaning that each node contains an array of values vs a single value. This method gives you a O(1) in time complexity but it has a high space complexity.

#### [Tries](https://www.youtube.com/watch?v=MC-iQHFdEDI)
The key is guaranteed to be unique, and the value could be as simple as a Boolean that tells you whether the data exists in the structure. Tries combiine structures and pointers together to store data in an interesting way. The data to be searched for in the trie is a roadmap. If you can follow the map from beginning to end, the data exists in the trie. If you can't, it doesn't. Unlike with the hash table, there are no collisions, and no two pieces of data (unless they are identical) have the same path.

In a trie, the paths from a central **root** node to a **leaf** node (value), would be labeled with the key. 

To insert an element into the trie, simply build the correct path from the root to the leaf.

Example of creating a trie structure:
  ```
  typedef struct _trie
  {
    char university[20];  // The values
    struct _trie* paths[10];  // The array of pointers
  }
  trie;
  ```

Need to global define a trie root node variable and maintain a pointer to it at all times:
- example: `root = malloc(trie_node)`

#### Abstract Data Structures - Queues
First In First Out (FIFO) - the first one in is the first one out, like a line at a cash register.

There are 2 fundimental operations:
- enqueue: get in line (add to the end of queue)
- dequeue: get out of line (remove from the front of queue)

#### [Queues](https://youtu.be/3TmUv1uS92s)
A special type of structure that can be used to maintain data in an organized way. 

This data structure is commonly implemented in one of two ways:
- As an **array**
- As a **linked list**

The important rule to remember is that when data is added to the queue, it is tacked onto the end, and so if an element needs to be removed, the element at the front is the only one that can legally be removed.

- An array-based implementation:
  ```
  typedef struct _queue
  {
    VALUE array[CAPACITY];  // VALUE (data type of values) - [CAPACITY] (the size of the array)
    int front;  // The location of the first element in the array
    int size;  // The size of the array/number of elements in the array
  }
  queue;
  
  queue q;  // creates a queue type called q
  q.front = 0;  // assigns 0 as the 1st element in the array
  q.size = 0;  // assigns 0 as the length of the array
  ```
  - In a queue the way the computer knows what location to go to for the end of the queue/array, it sums the front and size of the queue/array. The sum is now the last element in the queue/array.
  - In this case, **enqueue** will add a new element to the start of the queue
  - `enqueue()` needs to:
    - Accept a pointer to the queue.
    - Accept data of type VALUE to be added to the queue.
    - Add that data to the queue at the end of the queue.
    - Change the size of the queue.
  - example of creating an enqueue function:
    `void enqueue(queue* q, VALUE data);` == `enqueue(<pointer to queue>, <data in the type VALUE>)`
  - example of using the enqueue function:
    `enqueue(&q, 28);`
  - You do not want to change the front of the queue/array, only the size of the queue/array.
  
  - In this case, **dequeue** will remove the element from the front of the queue/array.
  - `dequeue()` needs to:
    - Accept a pointer to the queue.
    - Change the location of the front of the queue/array.
    - Decrease the size of the queue.
    - Return the value that was removed from the queue.
  - example of using the dequeue function:
    `int x = dequeue(&q);`
  - Now you would be changing the front queue value to the next value in the queue/array, and the size of the queue/array will be decreased by 1.
  
  - Once you get to the end of the queue/array, you will need to mod the sum to start wrap back to the beginning of the queue/array because an array is a fixed size and you can not add on to the end of it.

- Doubly linked list-based implementation:
  ```
  typedef struct _queue
  {
    VALUE val;
    struct _queue *prev;
    struct _queue * next;
  }
  queue;
  
  
  ```
  - Just make sure to always maintain pointers to the head **and** tail of the linked list! (probably global)
  - In this case, **enqueue** will add a new element to the start of the queue
  - `enqueue()` needs to:
    - Dynamically allocate a new node.
    - Set its next pointer to NULL, set its previous pointer to the tail.
    - Set the tail's next pointer to the new node.
    - Move the tail pointer to the newly-created node.
  - example of creating an enqueue function:
    `void enqueue(queue* q, VALUE data);` == `enqueue(<pointer to queue>, <data in the type VALUE>)`
  - example of using the enqueue function:
    `enqueue(tail, 10);`

  - In this case, **dequeue** will remove the element from the front of the queue.
  - `dequeue()` needs to:
    - Traverse the lined list to its 2nd element (if it exists).
    - Delete/free the head of the list.
    - Move the head pointer to the (former) 2nd element.
    - Make that node's previous pointer point to NULL.
  - example of using the dequeue function:
    `int x = dequeue(head);`

#### Abstract Data Structures - Stacks
Last In First Out (LIFO) - the one on top of the stack (last one), is the first one out (first one), like a stack of trays or pancakes.

There are 2 fundimental operations:
- push: adds to the top of the stack
- pop: remove the top of the stack

#### [Stacks](https://youtu.be/hVsNqhEthOk)
A special type of structure that can be used to maintain data in an organized way. 

This data structure is commonly implemented in one of two ways:
- As an **array**
- As a **linked list**

The important rule to remember is that when data is added to the stack, it sits "on top", so if an element needs to be removed, the most recently added element is the only element that can legally be removed.

- An array-based implementation of a stack:
  ```
  typedef struct _stack
  {
    VALUE array[CAPACITY];  // VALUE (data type of values) - [CAPACITY] (the size of the array)
    int top;  // keeps track of the most recently added element
  }
  stack;
  
  stack s;  // creates a stack type called s
  s.top = 0;  // adds 0 to the top of the stack telling the computer that 0 is the top element
  ```
  - In this case, **push** will add a new element to the top of the stack
  - `push()` needs to:
    - Accept a pointer to the stack.
    - Accept data of type VALUE to be added to the stack.
    - Add that data to the stack at the top of the stack.
    - Change the location of the top of the stack.
  - example of creating the push function: 
    `void push(stack* s, VALUE data);` == `push(<pointer to stack>, <data in the type VALUE>)`
  - example of using the push function:
    `push(&s, 28);`

  - In this case, **pop** will remove the most recent element from the top of the stack
  - `pop()` needs to:
    - Accept a pointer to the stack.
    - Change the location of the top of the stack.
    - Return the value that was removed from the stack.
  - example of implenting the pop function: `VALUE pop(stack* s);`
  - example of using the pop function: `int x = pop(&s);`

- Singly linked list-based implementation:
  ```
  typedef struct _stack
  {
    VALUE val;  // value in the linked list
    struct _stack *next;  // the next pointer in the linked list for the value specified above
  }
  stack;
  ```
  - Make sure to ALWAYS maintain a pointer to the head of the linked list! If you define this pointer as a global varaible it will probably make it easier to maintain.
  - To **push**, dynamically allocate a new node, set it's next pointer to point to the current head of the list, then move the head pointer to the newly-created node.
  - example: `list = push(list, 12);` 
   
  - To **pop**, traverse (make a copy of) the linked list to its 2nd element (if it exists), free the head of the list, then move the head pointer to the (former) 2nd element.
  - example `pop(list);`
  - Being that you are adding elements to the beginning of the linked list, the head is always going to be the most recently added element, so in a stack the head will also be on the top of the stack. So `pop()` will always remove what is currently in the head location of the linked list.

#### Dictionary
Abstraction you can get on the top of a hash table. Has keys and values, called "key value pairs". 

- Key: links to a value
- Value: the value within that the key references.

#### [Data Structures](https://www.youtube.com/watch?v=3uGchQbk7g8)
There are pros and cons to the four major data structures.

- Arrays
  - Insertion is **bad** - lots of shifting to fit an element in the middle
  - Deletion is **bad** - lots of shifting after removing an element
  - Lookup is **great** - random access, constant time complexity
  - Relatively easy to sort
  - Relatively small size-wise
  - Stuck with a fixed size, no flexibility

- Linked list
  - Insertion is **easy** - just tack onto the front
  - Deletion is **easy** - once you find the element
  - Lookup is **bad** - have to rely on linear search
  - Relatively **difficult** to sort - unless you are willing to compromise on super-fast insertion and instead sort as you contruct
  - Relatively small size-wise (not as small as arrays)

- Hash tables
  - Insertion is a two-step process - hash, then add
  - Deletion is **easy** - once you find the element
  - Lookup is on average better than with linked lists because you have the benefit of a real-world constant factor
  - Not an ideal data structure if sorting is the goal - just use an array
  - Can run the gamut of size

- Tries
  - Insertion is **complex** - a lot of dynamic memory allocation, but gets easier as you go
  - Deletion is **easy** - just free a node
  - Lookup is **fast** - not quite as fast as an array, but almost
  - Already sorted - sorts as you build in almost all situations
  - Rapidly becomes **huge**, even with very little data present, not great if space is at a premium
