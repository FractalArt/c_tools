# C-TOOLS

Implementing some data structures in C just to play around and learn.

***

## Compile

After cloning the repo run (this requires the [`meson`](https://mesonbuild.com/) build system to be available):

```sh
> mkdir build && cd build
> meson ..
> ninja install
```

What is really helpful is to configure the build to use an address sanitizer during development:

```sh
> meson configure -Db_sanitize=address
```

***

## Tests

Unit tests can be run with:

```sh
> ninja test 
```

***

## Licensing

`c_tools` is made available under the terms of the MIT License.

See the [LICENSE](LICENSE) file for license details.