# pd-ndi

__pd-ndi__ is a Pure Data extensions that enables video transmission through NDI.  


[__Newtek NDI__](https://www.newtek.com/ndi/) (Network Device Interface) 
is a software standard for broadcasting high quality video and audio over network with low latency.

### Compilation and installation

##### Requirements
* Building process of pd-ndi is managed by [CMake](https://cmake.org/)
* Pd-ndi depends on Newtek NDI SDK which can be downloaded for free form [here](https://www.newtek.com/ndi/sdk/)

##### Compilation
* In main _CMakeLists.txt_ file edit configuration variables so that neccessary libraries and headers can be found durig compilation
* Execute following commands in root directory of pd-ndi:
    ```$xslt
    cmake .
    make
    ```
    Precompiled Windows library can be downloaded from github's releases tab.

##### Installation
* Copy _pd-ndi_ file from _bin_ directory to your _externals_ directory where all tour externals are located
* Add pd-ndi to the list of libraries loaded by Pure Data at startup (_File_ menu -> _preferences_ -> _startup_ -> _new_ -> type _pd-ndi_ -> _ok_ -> _ok_ -> DONE)


##### Have in mind that:
* NDI library file must be visible for pd-ndi also after compilation. Easiest way to make it so is to copy it to the installation folder of pd-ndi.
* Gem 0.93.3 distributed through Deken is 32bit-only external. Pd-ndi has to be built for 32bit(_-m32_ compilation flag), otherwise it won't work with this build of Gem.   

### Usage

To use pd-ndi with Gem just connect right outlet of _[gemframebuffer]_ to the left inlet of _[ndisender]_.
Remember to set dimmensions of NDI frame by sending _[dimen width height(_ to _[ndisender]_.\
You can also set desired framerate of NDI vroadcast by sending _[max-fps x(_ tp _[ndisender]_.

(__Note__: pd-ndi's main purpose is to be used with Gem's _[gemframebuffer]_ object, but implementation doesn't depend on Gem, so it should also work with other OpenGL  wrapping objects that can bang _[ndisender]_ object with GL_TEXTURE_2D as _[gemframebuffer]_ does)

#### TODO
* provide more NDI configuration options to PD object
* implement audio transmission
* help patch