<div align="center">

  # <img src="https://raw.githubusercontent.com/aarikpokras/CxL/refs/heads/master/images/hero-tpn.png" alt="CxL" width="400" />

  The CxL Programming Language
</div>

<!--### Important security fixes were introduced in v2.7.2!
* Version 2.7.1 is affected by a serious security issue. Please update ASAP.-->

CxL is a general-purpose programming language for UNIX systems based on C++. It is more beginner-friendly and makes compiled languages less daunting. It focuses on being compact, fast, and straightforward. It aims to be the "go-to" language that people use when they want to write a program.

## Setting up
Clone the repository:
```
git clone https://github.com/aarikpokras/CxL
```

### For Linux, macOS and UNIX systems:
Enter the directory and run
```
sh configure.sh
```

### For Windows:
Keep `lib` and `cxlc.py` in your directory when compiling CxL programs.

It should be set up!\
Next, see [Your first CxL program](https://github.com/aarikpokras/CxL/wiki/Tutorials#your-first-cxl-program).

## Data types
See [using data](https://github.com/aarikpokras/CxL/wiki/Data#using-data) for more.

|Type|Description|Equivalent in C++|
|--|--|--|
|`str`|A string of characters|`char` arrays or `std::string`|
|`num`|A number|`double`, `float`, and `int`, all in one.|
|`strarr`|An array of `str`s|`string` arrays|

<!-- I've only been working on this for ten days 😭 -->
