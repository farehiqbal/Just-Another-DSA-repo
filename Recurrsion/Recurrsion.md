## Lets study recursion:

- Dealing with recursion requires the concepts of functions, so we need to have an idea of how fuctions work.

- While a function has not finished executing, it will remain in the stack.

- When a functions finishes executing, it is removed from stack, **and the flow of the program is
  restored to where that function was called.

#### Whhat is recursion?
- Recursion is simply function calling itself. 
- Takes space compleity O(n).

### Some key points:
- We need a base condition in recursion; a condition where function stops making new calls.

- Function takes separate memory for each call i.e when we change the argument, a new space is acquired.

- No base condition? function calls keep happening, stack filled again and again, memory exceeds
  resulting in the STACK-OVERFLOW.
