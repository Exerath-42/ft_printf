# Ft_printf

This project is about recoding the famous printf C function.
```
$int ft_printf(const char * (restrict) format, ...);
```
## How to use

**Clone**
```
$git clone <repository url>
```
**Make**
```
$make
```


ft_printf can print different contents depending on conversions and flags. You can print using the following syntax:
```
%[flag][min-width].[precision][length modifier][conversion specifier]
```
#### Conversions:
```
- c    char
- s    char *
- p    void * (to print pointer's adress)
- f    floats
- u    unsigned int
- o    unsigned int (octal)
- x/X: unsigned int (hexadecimal)
- d/i: int
```
#### You can see the task file
[subject](ft-printf.en.subject.pdf)
