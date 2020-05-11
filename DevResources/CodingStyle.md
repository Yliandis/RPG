# Coding style convention

---

## Code formatting

* Always indent with **tabulations**, not spaces
* Return to a new line before opening a new block (`{}`)
* Use line spacings to separate statements that do distinct things
* Use spaces betweens objects and operators
* Write a space after each comma

### Flow-of-control statements

* Write a space after `if`, `while`, `switch` and `for`
* In `for` statements, let a space after and **before** expressions separators
* In `switch` statements, indent after `case:` and outdent after `break;`

### Classes

* When defining an object, write a space before calling the constructor (not before other functions)
* In constuctors initializer list, take one line per attribute and begin each line with `:` or `,`
* Separate each type of declarations (attributes, methods, type aliases) with the appropriate `public`, `private` or `protected` section

---

## Writing conventions

* Code in english
* Use logical and understandable variable names and write them in CamelCase
* Object and class names begin with an uppercase letter, attributes with `m_`, other names begin with a lowercase letter

### Comments

* Use C style comments (`/* */`) to separate global blocks, and C++ style comments (`//`) otherwise
* If a comment describes a block of code, write it overhead
* If it describes a unique line, write it afterwards, one the same line

---

## Code content

* Don't use `using namespace`
* Use `using` rather than `typedef`

### Declarations

* Don't use global or preprocessor variables for computations
* Declare only one variable per line
* Attach `*` or `&` to the type name
* As much as possible and if necessary, use `const`, `constexpr`, `inline`

###

* As much as possible and if necessary, use `static`, `inline`, `override`, `final`, `delete`, `default`

### Functions

* For unmodified functions parameters, use `const &` if the size of the parameter is variable

---

And don't forget, be **consistent** !