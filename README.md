# pd-ndi

__pd-ndi__ is a Pure Data extensions that enables video transmission through NDI.  


[__Newtek NDI__](https://www.newtek.com/ndi/) (Network Device Interface) 
is a software standard for broadcasting high quality video and audio with low latency over network.


### Compilation and installation

Building process of pd-ndi is managed by [CMake](https://cmake.org/)\
Pd-ndi depends on Newtek NDI SDK which can be downloaded for free form [here](https://www.newtek.com/ndi/sdk/).
 

### Usage

(Note: pd-ndi's main purpose is to be used with Gem's _gemframebuffer_ object, but implementation doesn't depend on Gem, 
       so it should also work with other OpenGL 
       wrapping objects that can bang _ndisender_ object with GL_TEXTURE_2D as _gemframebuffer_ does)

#### TODO
* provide more NDI configuration options to pd-object
* implement audio transmission