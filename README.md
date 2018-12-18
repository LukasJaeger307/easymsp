# easymsp
A bunch of handy functions for MSP430 G-series MCUs. It is released under the free WTFPL and you can use it to simplify your own project. So far the following functions are supported:

- GPIO
- UART
- SPI
- DS18B20 thermometer

Since most distros are removing the MSP430-toolchain from their repos you need to install the toolchain supplied by TI. Just use a search engine you trust, you will find it. Make sure you install it in the `ti`-subfolder of your home directory (in my case _home/lukas/ti_). Furthermore, you probably need to insert the following line to the `.bashrc`-file located in your `home`-folder:

```sh
export MSP430="/home/your_username/ti"
export PATH="$PATH:$MSP430/bin"
```

When you have the prerequisites installed, you can build easymsp with a simple call of _make_. It builds a small demo app that reads the temperature from a DS18B20 thermometer and prints it on a UART console. If you need documentation, install doxygen, type 

```sh
make documentation
```

and see the docs in the _doc_ folder.

## Stripping down unwanted functions
Since the MSP430 is an MCU with a tiny memory, you may want to build a version of easymsp that contains only the features you absolutely need. In its default configuration, easymsp is build with all features activated. Let's assume, you don't need a DS18B20 thermometer in your project and want to customize easymsp for that, open _easymsp.h_ and locate the _defines_ that start with _EASYMSP_. Each of that lines toggles the feature it ends with. For example _EASYMSP\_DS18B20_ toggles the DS18B20 module. The tag _EASYMSP\_FULL_ is a helper macro that enables all easymsp-functions. If you comment it out as well as the DS18B20 macro, you'll get a version of easymsp without the DS18B20 module. You can disable all other modules analogously.
