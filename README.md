# pd-ndi

__pd_ndi__ is a Pure Data extensions that enables video transmission through NDI.  


[__Newtek NDI__](https://www.newtek.com/ndi/) (Network Device Interface) 
is a software standard for broadcasting high quality video and audio over network with low latency.

[__Gem__](https://puredata.info/downloads/gem/) Graphics Environment for Multimedia for Pure Data

### Compilation and installation

##### Requirements
* Building process of pd_ndi is managed by [CMake](https://cmake.org/)
* Pd_ndi depends on Newtek NDI SDK which can be downloaded for free form [here](https://www.newtek.com/ndi/sdk/)
* Gem library is now required for _gem_ndisender.cpp_ compilation

##### Compilation
* In main _CMakeLists.txt_ file edit configuration variables so that necessary libraries and headers can be found durig compilation
* Execute following commands in root directory of pd_ndi:
    ```$xslt
    cmake .
    make
    ```
    Precompiled Windows and Mac library can be downloaded from github's releases tab.

##### Installation
* Copy _pd_ndi_ file from _bin_ directory to your _externals_ directory where all tour externals are located
* Add pd_ndi to the list of libraries loaded by Pure Data at startup (_File_ menu -> _preferences_ -> _startup_ -> _new_ -> type _pd_ndi_ -> _ok_ -> _ok_ -> DONE)


##### Have in mind that:
* NDI library file must be visible for pd_ndi also after compilation. Easiest way to make it so is to copy it to the installation folder of pd_ndi.
* Gem has to be added to the library list before pd_ndi

### Usage

* #### _[ndisender]_

    [_ndisender_] connected to [_gemhead_] will transmit what's before it in Gem's render chain.
    In case you are familiar with syphonserver for Gem, ndisender will work the same way.

* #### _[pix_ndisender]_

    To use _[pix_ndisender]_ object with Gem just connect right outlet of _[gemframebuffer]_ to the left inlet of _[pix_ndisender]_.
Remember to set dimensions of NDI frame by sending _[dimen $width $height (_  to _[pix_ndisender]_ (defaults are 256 by 256).\

    (__Note__: pix_ndisender's main purpose is to be used with Gem's _[gemframebuffer]_ object, but implementation doesn't depend on Gem, 
    so it should also work with other OpenGL  wrapping objects that can bang _[pix_ndisender]_ object with GL_TEXTURE_2D as _[gemframebuffer]_ does)


* You can also set desired framerate of NDI broadcast by sending _[fps $1 (_ to _[ndisender]_ or _[pix_ndisender]_ (30 fps by default).


#### TODO
* provide more NDI configuration options to PD object
* implement sender as Gen's record plugin
* implement audio transmission
* help patch
* ndi receiver