project('ctrelf', 'c',
  default_options: [
    'b_lto=true',
    'b_staticpic=false',
    'c_std=c17',
    'warning_level=3',
  ],
  license: ['GPL-2.0-or-later'],
  version: '0.0.1')

sources = files([
  'src/ctrelf.c'
])

header_files = files([
  'include/ctrelf.h',
])

install_subdir('include', install_dir: 'include', strip_directory: true)


lib = library(
  'ctrelf', sources,
  include_directories: 'include',
  install: true,
)

pkg = import('pkgconfig')

pkg.generate(lib,
  subdirs: [ 'ctrelf', '.' ]
)
