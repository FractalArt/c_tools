project('c_tools', 'c', 
  version: '0.1',
  default_options: ['c_std=c11', 'warning_level=3'],
  meson_version: '>=0.56')


# define the include directories
include_dirs = include_directories('include')

# define the dependencies of the project
deps = []

# install the headers
subdir('include/c_tools')
subdir('src')

# collect everything
libs = [libctools]

# compile the unit tests
subdir('unit_tests')


# generate pc file, so that other projects can include `c_tools`
pkg = import('pkgconfig')
pkg.generate(
  description: 'A collection of useful infrastructure to be used in C projects',
  name: meson.project_name(),
  version: meson.project_version(),
  libraries: libs,
  requires: deps,
  url: 'https://github.com/fractalart/c_tools'
)
