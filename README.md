# Experience Tables

Total experience for Table Top Role Playing Games (TTRPGs).

This program takes as input a file written in yaml, of the form:

    - character: Ron
      points: 1
      reason: Critical failure on Expeliarimus
    - character: Harry
      points: 2
      reason: Critical failure to resist On The Edge
    - character: Hermione
      points: 1
      reason: Saving these two knuckleheads.
    - character: Hermione
      points: 2
      reason: Saving these two knuckleheads.  Again.

And produces a summary of the experience which looks like:

    Ron:      1
    Harry:    2
    Hermione: 3

## Using It In Play

During the game session, record experience as it happens using your favorite text editor.  Make sure the file is valid yaml.  To report experience totals at the end of the session, run:

    ./experiencetab todays-experience-file.yaml

## Running Your Campaign

If you keep all of your experience files in a single folder, you can generate an experience summary for your entire campaign with:

    ./experiencetab experiencefolder

If you maintain a campaign website or wiki that uses markdown format, you can have output in markdown:

    ./experiencetab --markdown experiencefolder

The output will look something like:

    | Character | XP  |
    | --------- | --- |
    | Harry    | 2 |
    | Hermione | 3 |
    | Ron      | 1 |

It will render like:

| Character | XP  |
| --------- | --- |
| Harry    | 2 |
| Hermione | 3 |
| Ron      | 1 |



## Building

You will need:

* CMake version 3.13 or better (latest is bestest).  Be aware that Linux distributions tend to ship CMake well behind the development curve, so don't assume that just because you have the latest Linux you've got a recent enough CMake.  The good news is that it's very easy to build the latest CMake from source and install it on your system.

* Version 9+ of GCC or CLang, so that you have support for the c++ filesystem library.

* Make

### Configuring The Build

Create a folder below or outside of the root of your file checkout or archive expansion.  I usually create "build" below the root fo the repository.

    mkdir build
    cd build

Inside of the build folder, run 

    cmake -DYAML_CPP_BUILD_TESTS=off -DYAML_CPP_BUILD_TOOLS=off ..

If you are windows and you are not using Visual Studio, you will need to add `-G "Unix Makefiles"` to the cmake command.  If you are using Visual Studio, skip the build step here and build inside Visual Studio.

Build and confirm a good build with the included test suite.

    make && make test

That's it, you're done.  Copy the experiencetab program to a location in your path, and you're ready to rock and roll.
