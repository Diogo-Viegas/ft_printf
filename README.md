# 🖨️ ft_printf – Custom Implementation of printf()

Recreating one of the most iconic functions in the C standard library.

## 🚀 About the Project

The goal of this project is to reimplement the printf() function from the C standard library. This includes handling formatted output with a variable number of arguments (variadic functions).

By doing this project, I explored how to parse format strings, manage flags, convert various types to strings, and output them reliably. This project is considered moderately difficult at 42 and is a foundational step in mastering low-level I/O handling in C.

## ⚙️ Technologies

Language: C

Compiler: cc with flags -Wall -Wextra -Werror

Build System: Makefile

Style: 42 Norminette

## 🧩 Project Structure

ft_printf.h – Header file

ft_printf.c – Main logic

src/ – Utility and conversion functions

Makefile – Compiles everything into libftprintf.a

## 🛠️ Features Implemented

### ✅ Mandatory Conversions

%c – Prints a single character

%s – Prints a string

%p – Prints a pointer address in hexadecimal

%d – Prints a signed decimal number

%i – Same as %d

%u – Prints an unsigned decimal number

%x – Prints a hexadecimal number (lowercase)

%X – Prints a hexadecimal number (uppercase)

%% – Prints a literal percent sign

### 🧪 Bonus (Optional)

If bonus was implemented:

-, 0, . and field width support

#, space and + flags under all conversions

## 📦 How to Compile

make        -->  compiles ft_printf and generates libftprintf.a \
make clean  --> removes object files \
make fclean --> removes object files and libftprintf.a \
make re     -->  rebuilds everything from scratch \
make bonus  --> compiles with bonus flags if implemented


## ✅ Results

All mandatory conversions implemented and passed

Code follows the 42 Norm and uses only allowed standard functions

Works consistently across different platforms

## 🧠 What I Learned

Working with variadic functions using va_start, va_arg, and va_end

Parsing format strings efficiently

Creating modular conversion handlers

Managing static libraries and proper compilation flags
