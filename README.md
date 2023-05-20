# ARGoS3 - Turtlebot 3 integration #

This repository contains the code that integrates the [ARGoS3 multi-robot simulator](http://www.argos-sim.info) and the [Turtlebot 3 robot](https://www.k-team.com/turtlebot3-iv).

This code allows you to simulate the Turtlebot 3 in ARGoS3, and to run ARGoS3 controllers on the real Turtlebot 3.

# Compilation Instructions #

## To Simulate The Turtlebot 3 in ARGoS3 ##

    $ mkdir build
    $ cd build
    $ cmake -DCMAKE_BUILD_TYPE=Release ../src
    $ make
    $ sudo make install
    
## To Run ARGoS3 Code on the Turtlebot 3 ##

First, you need to install the [light toolchain provided by K-Team](http://ftp.k-team.com/Turtlebot3/software/Gumstix%20COM%20Y/light_tools/poky-glibc-i686-turtlebot34-image-cortexa8hf-vfp-neon-toolchain-1.8.sh).

Next, you need to designate a folder where you'll install all the ARGoS-related binaries. Let's call this folder `${INSTALLPREFIX}`. Make sure the folder exists and it is writable by your user:

    $ mkdir -p ${INSTALLPREFIX}

To make ARGoS controllers work on the Turtlebot 3, you need to crosscompile the ARGoS core and the Turtlebot 3 plugin. In the following, we will assume that you have three directories:

| Variable        | Meaning                                     |
|-----------------|---------------------------------------------|
| `INSTALLPREFIX` | Where the compile code is installed         |
| `ARGOS3PATH`    | Where the ARGoS3 core code is stored        |
| `tb3PATH`      | Where the the code of this plugin is stored |

### Crosscompiling the ARGoS core ###

To compile the ARGoS core for the Turtlebot 3, follow these instructions:

    $ cd ${ARGOS3PATH}
    $ mkdir build_tb3
    $ cd build_tb3
    $ cmake -DCMAKE_TOOLCHAIN_FILE=${tb3PATH}/src/cmake/TargetTurtlebot3.cmake -DCMAKE_INSTALL_PREFIX=${INSTALLPREFIX} ../src
    $ make install

### Crosscompiling the Turtlebot 3 plugin ###

To compile the Turtlebot 3 plugin code, follow these instructions:

    $ export PKG_CONFIG_PATH=${INSTALLPREFIX}/lib/pkgconfig:${PKG_CONFIG_PATH}
    $ cd ${tb3PATH}
    $ mkdir build_tb3
    $ cd build_tb3
    $ cmake -DCMAKE_TOOLCHAIN_FILE=${tb3PATH}/src/cmake/TargetTurtlebot3.cmake -DCMAKE_INSTALL_PREFIX=${INSTALLPREFIX} ../src
    $ make install

