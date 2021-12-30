# osmanip

## Table of contents
- [Introduction](#introduction)
- [Documentation](#documentation)
- [List of features](#list-of-features)
  * [Colors and styles manipulation](#colors-and-styles-manipulation)
  * [Cursor navigation](#cursor-navigation)
  * [Terminal control sequences](#terminal-control-sequences)
  * [Progress bars](#progress-bars)

## Introduction

Here I want to present you *osmanip*: my personal C++ library containing useful output-stream tools to format and customize your output stream. Probably there are already some similar libraries in the web that do the same job, but since I personally don't like them at all I preferred writing my own code for that. Thanks to this you can manipulate the output stream of your program with colors, styles (ex: bold, italics, etc...) and helper tools like progress bars and CPU-usage monitor objects. Using this feaures may be very useful to better read error messages or special information you want to be sure other users see when they run your code, or to adorn your general output stream log.

This software has been built for Linux systems (it has been tested with Ubuntu and WSL). Its compatibility has not been tested with Windows or MacOS operating systems.

If you want to use this software in one of your project, please cite it. You can find the citation template [here](https://github.com/JustWhit3/osmanip/blob/main/CITATION.cff).

> **NOTE**: all the manipulators of this library are compatible with [iomanip](https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/std/iomanip).

## Documentation

In the [**doc**](https://github.com/JustWhit3/osmanip/blob/main/doc) folder useful documentation files are stored, in order to help the user learning how to properly use the library:
- [*Repository structure*](https://github.com/JustWhit3/osmanip/blob/main/doc/Repository%20structure.md): contains general information about the files and folders of the repository.
- [*Code structure*](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md): contains general information about the code structure of the library, therefore details on classes, functions and variables used in it.
- [*Download and install*](https://github.com/JustWhit3/osmanip/blob/main/doc/Download%20and%20install.md): a guide to download, install and run the library into your system.
- [*Todo*](https://github.com/JustWhit3/osmanip/blob/main/doc/Todo.md): contains a list of future implementations of the library.

## List of features

Here you can find examples of all the features supported in the current version of the manipulator and how to use them.
> **NOTE**: all the examples are written supposing to use the following directive:
> ```c++
> using namespace osm;
> ```
### Colors and styles manipulation

List of the supported color / style features (part of the output of the [*main.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/main.cpp) program):

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/output.png">

Blink string feature:

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/blink.gif" width="250" height="27">

If you want to change for example the output stream color into red you have to call the `feat` function and give it the `col` map as a first argument and the color name as the second one. See the following example:
```c++
cout << feat( col, "red" ) << "This stream is red!" << reset( "color" );
```
This will color the output stream in red until the `reset( "color" )` function is met again, in order to reset the output stream color.

It is possible to access a wider variety of colors by directly using the `RGB( int r, int g, int b )` function and the corresponding rgb color codes from [this page](http://www.aksiom.net/rgb.html). For example:
```c++
std::string DeepPink = RGB( 255, 20, 147 );

cout << DeepPink << "This stream is deep pink!" << reset( "color" );
```

You can also print mixed color and style strings:
```c++
cout << feat( sty, "underlined" ) << feat( col, "red" ) << "This is an underlined red string." << reset( "all" );
```
This will underline and color the output stream in red until the `reset( "all" )` function is met again, in order to reset all the output stream color / style.
> If you want to know all the available commands, visit the [code structure](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md) page.

### Cursor navigation

You can modify the cursor navigation in all the 4 directions (up, down, right, left) by using the `feat` function within the `crs` map, in this way:
```c++
cout << feat( crs, "left" ) << "Moving cursor on the left";
```
You can additionally add a third argument to the `feat` function, in order to increase the parameter of the ANSII code of the cursor navigation (see [*csmanip.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/csmanip.cpp)).
> If you want to know all the available commands, visit the [code structure](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md) page.

It is not so easy to show a simple example of this feature. Certainly, a very intuitive application is for progress bars creation, explained in the next section. See the progress bar update method definition in [*progress_bar.cpp*](https://github.com/JustWhit3/osmanip/blob/main/src/progress_bar.cpp) for more information.

### Terminal control sequences

You can add a terminal control sequency to your output by using the `feat`  function within the `tcs` map, in this way:
```c++
cout << feat( tcs, "bell" );
```
For example, the previous command will output a bell sound from your computer.
> If you want to know all the available commands, visit the [code structure](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md) page.

### Progress bars

From release [2.0.0](https://github.com/JustWhit3/osmanip/releases/tag/v2.0.0) of the library, also progress bars have been introduced. 

Main proprieties:

- Compatibile with any positive or negative variable of any standard type (integer, float, double and others).
- Maximum and minimum values can be set with any value you prefer and the progress bar will be self-built with respect to them.
- It can be fully customized regarding to your requirements.

Here you can find some examples about how to use them into your code.
> If you want to know all the available commands, visit the [code structure](https://github.com/JustWhit3/osmanip/blob/main/doc/Code%20structure.md) page.

Initialize and use a percentage progress bar:
```c++
ProgressBar <int> percentage_bar;
percentage_bar.setMin( 5 );
percentage_bar.setMax ( 46 );
percentage_bar.setStyle( "indicator", "%" );

cout << "This is a normal percentage bar: " << endl;
 for ( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
  {
   sleep_for( milliseconds( 100 ) );
   percentage_bar.update( i );
   //Do some operations...
  }
```
> **NOTE**: `sleep_for( milliseconds( 100 ) )` has been inserted to delay the loop in order to better visualize the progress bar into this .gif file. You don't need to use it in your code.

> **NOTE**: you can insert each `min` and `max` value you prefer, like also -3 and 52 for example, and the bar will work perfectly too.

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/normal_percentage.gif" width="400" height="55">

Add a message to a percentage bar and change its style:
```c++
percentage_bar.setMessage( " processing..." );
percentage_bar.setStyle( "indicator", "/100" );
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/message_percentage.gif" width="500" height="57">

Add CPU time consuming info when using a progress bar in loops:
```c++
cout << "This is a percentage bar with time consuming info: " << endl;
 for ( int i = percentage_bar.getMin(); i < percentage_bar.getMax(); i++ )
  {
   percentage_bar.setBegin();
   sleep_for( milliseconds( 100 ) );
   percentage_bar.update( i );
   //Do some operations...
   percentage_bar.setEnd();
  }
cout << endl << "Time needed to complete the previous cycle: " << percentage_bar.getTime() << " ms." << endl;
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/time_percentage.gif" width="500" height="80">

It is possible to add also colors and much more.

You can also create a classic loading bar:
```c++
ProgressBar <int> loading_bar;
loading_bar.setMin( 3 );
loading_bar.setMax ( 25 );
loading_bar.setStyle( "loader", "#" );
loading_bar.setBrackets( "{", "}" );
loading_bar.setMessage( "processing..." );

cout << "This is a normal loading bar: " << endl;
for ( int i = loading_bar.getMin(); i < loading_bar.getMax(); i++ )
 {
  sleep_for( milliseconds( 100 ) );
  loading_bar.update( i );
  //Do some operations...
 }
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/normal_loading.gif" width="400" height="55">

And customize it with messages and time-consuming info, like the previous percentage.

If using mixed bar styles, for example:
```c++
progress_bar.setStyle( "complete", "%", "#" );
```
you can create loading bar with percentage counter (mixed bar):

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/mixed_bar.gif" width="400" height="55">

You can also add new customized styles, both for indicator and loader:

```c++
progress_bar.addStyle( "indicator", "|100" );
progress_bar.addStyle( "loader", ">" );
progress_bar.setStyle( "complete", "|100", ">" );
```

<img src="https://github.com/JustWhit3/osmanip/blob/main/img/mixed_bar_add.gif" width="530" height="55">
